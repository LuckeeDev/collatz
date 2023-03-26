#include <SFML/Graphics.hpp>
#include "collatz/collatz.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "events/events.h"

int main() {
    int n{};

    sf::RenderWindow window{{800, 600}, "Collatz visualizer"};
    window.setPosition(sf::Vector2i(10, 50));

    tgui::Gui gui{window};

    auto edit_box = tgui::EditBox::create();
    edit_box->setAlignment(tgui::EditBox::Alignment::Right);
    edit_box->onTextChange(&events::onTextCallback, std::ref(n));
    edit_box->setMaximumCharacters(3);

    auto button = tgui::Button::create("Run");
    button->onPress(&events::onPressCallback, std::ref(n));

    gui.add(edit_box);
    gui.add(button);

    gui.mainLoop();
}