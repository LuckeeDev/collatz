#include "events.h"

#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/Label.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "../collatz/collatz.h"
#include "../ui/ui.h"

namespace events {
void onTextCallback(int &n, tgui::String const &value) {
  auto str = value.toStdString();

  auto integer = std::stoi(str);

  n = integer;
}

void onPressCallback(int const &n, tgui::CanvasSFML::Ptr &canvas) {
  auto v = collatz::sequence(n);
  auto last = --v.end();

  std::cout << "[";

  for (auto it = v.begin(); it < v.end(); it++) {
    std::cout << *it;

    if (it != last) {
      std::cout << ", ";
    }
  }

  std::cout << "]" << std::endl;

  auto steps = v.size();

  auto xSpacing = (ui::WIDTH - 50) / static_cast<float>(steps);

  auto max = *std::max_element(v.begin(), v.end());

  auto ySpacing = (ui::HEIGHT - 100) / static_cast<float>(max);

  //  sf::CircleShape circle;
  sf::Font font;

  font.loadFromFile("arial.ttf");

  sf::RectangleShape yAxis(sf::Vector2f(ui::HEIGHT, 2));
  yAxis.setPosition(50, 0);
  yAxis.setFillColor(sf::Color::Black);
  yAxis.rotate(90);

  sf::RectangleShape xAxis(sf::Vector2f(ui::WIDTH, 2));
  xAxis.setPosition(0, ui::HEIGHT - 50);
  xAxis.setFillColor(sf::Color::Black);

  canvas->clear(tgui::Color::White);
  canvas->draw(yAxis);
  canvas->draw(xAxis);

  std::vector<sf::Vertex> points;

  points.reserve(steps);

  for (unsigned long i = 0; i < steps; i++) {
    float xPos = xSpacing * static_cast<float>(i) + 50.f;
    float yPos = 50 + (static_cast<float>(max - v[i])) * ySpacing;

    sf::Text text;
    text.setString(std::to_string(i + 1));
    text.setPosition(xPos, ui::HEIGHT - 40);
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setCharacterSize(18);

    sf::Vertex vertex(sf::Vector2f(xPos, yPos), sf::Color::Black);

    points.push_back(vertex);

    sf::Text label;
    label.setString(std::to_string(v[i]));
    label.setPosition(xPos, yPos);
    label.setFillColor(sf::Color::Black);
    label.setFont(font);
    label.setCharacterSize(18);

    canvas->draw(label);

    canvas->draw(text);
  }

  canvas->draw(&points[0], steps, sf::LineStrip);

  canvas->display();
}
}  // namespace events