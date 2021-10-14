//
// Created by David van Erkelens on 11/10/2021.
//

#include "reflector.h"
#include "../helpers/validation.h"

namespace Enigma::Reflector {
    Reflector::Reflector(const char *mapping) : _mapping(mapping) {
        if (!is_in_pairs(mapping)) {
            throw std::runtime_error("reflector configuration is not in pairs");
        }
    }

    char Reflector::reflect(char input) const {
        char upperCase = (char) toupper(input);

        return _mapping[(int) upperCase - (int) 'A'];
    }

    Reflector Reflector::B() {
        return Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    }
}
