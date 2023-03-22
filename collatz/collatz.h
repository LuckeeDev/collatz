#include <vector>

#ifndef SFML_PLAYGROUND_COLLATZ_H
#define SFML_PLAYGROUND_COLLATZ_H

namespace collatz {
    /**
     * Basic implementation of the logic governing the Collatz sequence.
     * @param n the current point of the Collatz sequence.
     * @return the next integer in the Collatz sequence.
     */
    int next(int n);

    /**
     * Implementation of the Collatz sequence as a vector.
     * @param n the starting point of the Collatz sequence.
     * @return the full sequence as a vector.
     */
    std::vector<int> sequence(int n);
}

#endif //SFML_PLAYGROUND_COLLATZ_H
