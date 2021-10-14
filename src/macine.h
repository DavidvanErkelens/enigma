//
// Created by David van Erkelens on 11/10/2021.
//

#ifndef ENIGMA_MACINE_H
#define ENIGMA_MACINE_H

#include <list>
#include "rotors/rotor.h"
#include "plugboard/plugboard.h"
#include "reflector/reflector.h"
#include "plugboard/configuration.h"

namespace Enigma {
    class Machine {
    private:
        PlugBoard::PlugBoard _plugBoard;
        std::list<Rotor::Rotor> _rotors;
        Reflector::Reflector _reflector;

        /**
         * Add a rotor. Rotors should be added left-to-right.
         * @param configuration
         * @param startPosition
         */
        void addRotor(Rotor::Configuration configuration, char startPosition);

        /**
         * Translate a alphabetical character according to the current settings of the Enigma machine
         * @param c the character to translate
         * @return  the translated character
         */
        char translate(char c);

    public:
        /**
         * Create a new instance of the Enigma Machine
         * @param plugBoardConfig
         */
        Machine(PlugBoard::Configuration plugBoardConfig);

        /**
         * Process a string though the Enigma machine
         * @param input the string to encode / decode
         * @return string containing the result
         */
        std::string process(const char *input);
    };
}

#endif //ENIGMA_MACINE_H
