#include <iostream>
#include <string>
#include "events.h"
#include <TGUI/TGUI.hpp>
#include "../collatz/collatz.h"

namespace events {
    void onTextCallback(int &n, const tgui::String &value) {
        auto str = value.toStdString();

        auto integer = std::stoi(str);

        n = integer;
    }

    void onPressCallback(const int &n) {
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
    }
}