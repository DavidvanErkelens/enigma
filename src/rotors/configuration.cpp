//
// Created by David van Erkelens on 13/10/2021.
//
// Rotor configurations taken from https://www.codesandciphers.org.uk/enigma/rotorspec.htm
//

#include <iostream>
#include "configuration.h"

namespace Enigma::Rotor {
    Configuration::Configuration(const char *mapping, char notch) : _mapping(mapping), _notch(notch) {
        _reverseMapping = new char[26];
        for (int i = 0; i < 26; i++) {
            _reverseMapping[(int) _mapping[i] - (int) 'A'] = (char) (i + 'A');
        }
    }

    const char *Configuration::getMapping() const {
        return _mapping;
    }

    const char *Configuration::getReverseMapping() const {
        return _reverseMapping;
    }

    char Configuration::getNotch() const {
        return _notch;
    }

    Configuration Configuration::I() {
        return {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'R'};
    }

    Configuration Configuration::II() {
        return {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'F'};
    }

    Configuration Configuration::III() {
        return {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'W'};
    }

    Configuration Configuration::IV() {
        return {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'};
    }

    Configuration Configuration::V() {
        return {"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'};
    }
}



