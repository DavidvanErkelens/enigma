//
// Created by David van Erkelens on 11/10/2021.
//

#include "rotor.h"
#include <cctype>

namespace Enigma::Rotor {
    Rotor::Rotor(const Configuration &configuration, char startPosition) : _configuration(configuration) {
        _offset = (int) toupper(startPosition) - (int) 'A';
    }

    Rotor::Rotor(const Configuration &configuration, char startPosition, Rotor *nextRotor) :
            Rotor(configuration, startPosition) {
        _nextRotor = nextRotor;
    }

    void Rotor::rotate() {
        char currentPosition = (char) (_offset + (int) 'A');
        if (currentPosition == _configuration.getNotch() && _nextRotor != nullptr) {
            _nextRotor->rotate();
        }

        _offset = (_offset + 1) % 26;
    }

    char Rotor::forward(char input) const {
        int index = ((toupper(input) - (int) 'A') + _offset) % 26;
        char mapped = _configuration.getMapping()[index];
        return (char) (((mapped - (int) 'A' - _offset + 26) % 26) + (int) 'A');
    }

    char Rotor::backward(char input) const {
        int index = ((toupper(input) - (int) 'A') + _offset) % 26;
        char mapped = _configuration.getReverseMapping()[index];
        return (char) (((mapped - (int) 'A' - _offset + 26) % 26) + (int) 'A');
    }
}


