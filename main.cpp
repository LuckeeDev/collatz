#include <SFML/Graphics.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "collatz/collatz.h"
#include "events/events.h"
#include "ui/ui.h"

int main() {
  int n{};

  sf::RenderWindow window{{ui::WIDTH, ui::HEIGHT}, "Collatz visualizer"};
  window.setPosition(sf::Vector2i(10, 50));

  tgui::Gui gui{window};

  auto edit_box = tgui::EditBox::create();
  edit_box->setAlignment(tgui::EditBox::Alignment::Right);
  edit_box->onTextChange(&events::onTextCallback, std::ref(n));
  edit_box->setMaximumCharacters(3);

  auto canvas = tgui::CanvasSFML::create({ui::WIDTH, ui::HEIGHT});
  canvas->clear(sf::Color::White);

  auto button = tgui::Button::create("Run");
  button->onPress(&events::onPressCallback, std::ref(n), std::ref(canvas));

  gui.add(canvas);
  gui.add(edit_box);
  gui.add(button);

  gui.mainLoop();
}