//
// Created by David van Erkelens on 11/10/2021.
//

#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H


#include "configuration.h"

namespace Enigma::Rotor {
    class Rotor {
    private:
        Configuration _configuration;
        int _offset;

        Rotor *_nextRotor = nullptr;
    public:
        Rotor(const Configuration &configuration, char startPosition);

        Rotor(const Configuration &configuration, char startPosition, Rotor *nextRotor);

        void rotate();

        char forward(char input) const;

        char backward(char input) const;
    };
}
#endif //ENIGMA_ROTOR_H
