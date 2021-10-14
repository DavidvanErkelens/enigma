//
// Created by David van Erkelens on 14/10/2021.
//

#include <cstring>

bool is_in_pairs(const char *mapping) {
    for (int i = 0; i < strlen(mapping); i++) {
        int otherIndex = (mapping[i] - (int) 'A');
        if (mapping[otherIndex] != (char) (i + 'A')) {
            return false;
        }
    }

    return true;
}
