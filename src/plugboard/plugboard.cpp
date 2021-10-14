//
// Created by David van Erkelens on 11/10/2021.
//

#include "plugboard.h"
#include <cctype>
#include <cstring>

namespace Enigma::PlugBoard {
    PlugBoard::PlugBoard(Configuration config) : _mapping(config.getMapping()) {
    }

    /**
     * Map a single character
     * @param input
     * @return
     */
    char PlugBoard::map(char input) {
        // Translate to uppercase
        char upperCase = (char) toupper(input);

        // Check where the input character occurs in the mapping
        const char *location = strchr(_mapping, upperCase);

        // Return the input character if not defined in the mapping
        if (location == nullptr) {
            return upperCase;
        }

        // Get the offset in the mapping
        int offset = location - _mapping;

        // If the offset is even, return the character after the input character in the mapping...
        if (offset % 2 == 0) {
            return _mapping[offset + 1];
        }

        // ...if uneven, return the character before
        return _mapping[offset - 1];
    }
}
