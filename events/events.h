#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/String.hpp>

#ifndef COLLATZ_EVENTS_H
#define COLLATZ_EVENTS_H

namespace events {
void onTextCallback(int &n, tgui::String const &value);

void onPressCallback(int const &n, tgui::CanvasSFML::Ptr &canvas);
}  // namespace events

#endif  // COLLATZ_EVENTS_H
