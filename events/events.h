#include <TGUI/TGUI.hpp>

#ifndef COLLATZ_EVENTS_H
#define COLLATZ_EVENTS_H

namespace events {
    void onTextCallback(int &n, const tgui::String &value);

    void onPressCallback(const int &n);
}

#endif //COLLATZ_EVENTS_H
