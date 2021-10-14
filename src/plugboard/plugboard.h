//
// Created by David van Erkelens on 11/10/2021.
//

#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include "configuration.h"

namespace Enigma::PlugBoard {
    class PlugBoard {
    private:
        const char *_mapping;
    public:
        /**
         * Create plugboard
         * @param config
         */
        explicit PlugBoard(Configuration config);

        /**
         * Map a single character
         * @param input
         * @return output
         */
        char map(char input);
    };
}


#endif //ENIGMA_PLUGBOARD_H
