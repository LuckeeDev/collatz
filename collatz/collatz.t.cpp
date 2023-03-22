#include "collatz.h"
#include "../test/doctest.h"
#include <stdexcept>
#include <cstdlib>

TEST_CASE("Testing the collatz namespace functions") {
    SUBCASE("Testing the next function") {
        CHECK((collatz::next(8) == 4));
        CHECK((collatz::next(3) == 10));
        CHECK((collatz::next(311) == 934));

        CHECK_THROWS_AS(collatz::next(0), std::invalid_argument);
        CHECK_THROWS_AS(collatz::next(-12), std::invalid_argument);
    }

    SUBCASE("Testing the sequence function") {
        CHECK((collatz::sequence(4) == std::vector<int>{4, 2, 1}));
        CHECK((collatz::sequence(12) == std::vector<int>{12, 6, 3, 10, 5, 16, 8, 4, 2, 1}));
        CHECK((collatz::sequence(17) == std::vector<int>{17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1}));

        CHECK_THROWS_AS(collatz::sequence(0), std::invalid_argument);
        CHECK_THROWS_AS(collatz::sequence(-54), std::invalid_argument);
    }

    SUBCASE("Testing the sequence function with a random number") {
        auto random = std::rand() % 1000 + 1;

        auto sequence = collatz::sequence(random);
        auto last = --sequence.end();

        CHECK((*last == 1));
    }
}