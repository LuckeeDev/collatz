#include <vector>
#include <stdexcept>

namespace collatz {
    int next(int n) {
        if (n < 1) {
            throw std::invalid_argument("n should be a positive integer");
        }

        if (n % 2 == 0) {
            return n / 2;
        } else {
            return 3 * n + 1;
        }
    }

    std::vector<int> sequence(int n) {
        if (n < 1) {
            throw std::invalid_argument("n should be a positive integer");
        }

        std::vector<int> v{};

        while (n != 1) {
            v.push_back(n);
            n = next(n);
        }

        v.push_back(1);

        return v;
    }
}
