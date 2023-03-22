#include <SFML/Graphics.hpp>
#include "collatz/collatz.h"
#include <iostream>

int main() {
    int n;

    std::cout << "Insert a number\n";
    std::cin >> n;

    auto v = collatz::sequence(n);
    auto last = --v.end();

    std::cout << "[";

    for (auto it = v.begin(); it < v.end(); it++) {
        std::cout << *it;

        if (it != last) {
            std::cout << ", ";
        }
    }

    std::cout << "]";
}