//
// Created by David van Erkelens on 11/10/2021.
//

#include <sstream>
#include "macine.h"

namespace Enigma {
    Machine::Machine(PlugBoard::Configuration plugBoardConfig) :
            _plugBoard(plugBoardConfig),
            _reflector(Reflector::Reflector::B()) {
        addRotor(Rotor::Configuration::I(), 'M');
        addRotor(Rotor::Configuration::II(), 'C');
        addRotor(Rotor::Configuration::III(), 'K');
    }

    /**
     * Add a rotor. Rotors should be added left-to-right.
     * @param configuration
     * @param startPosition
     */
    void Machine::addRotor(Rotor::Configuration configuration, char startPosition) {
        // Get pointer to the previously added rotor (might be null)
        Rotor::Rotor *prev = _rotors.empty() ? (Rotor::Rotor *) nullptr : &(_rotors.back());

        // Construct the new rotor
        _rotors.emplace_back(configuration, startPosition, prev);
    }

    /**
     * Process a string though the Enigma machine
     * @param input the string to encode / decode
     * @return string containing the result
     */
    std::string Machine::process(const char *input) {
        std::stringstream output;
        for (const char &c: std::string(input)) {
            output << translate(c);
        }
        return output.str();
    }

    /**
     * Translate a alphabetical character according to the current settings of the Enigma machine
     * @param c the character to translate
     * @return  the translated character
     */
    char Machine::translate(char c) {

        // Return the input character if the character is not alphabetical
        if (toupper(c) < 'A' || toupper(c) > 'Z') {
            return c;
        }

        // Rotate the first rotor (this will rotate other rotors if notches are reached)
        _rotors.back().rotate();

        // Translate though the plug board
        char result = _plugBoard.map(c);

        // Loop over the rotors, right-to-left, and apply forward translation
        for (auto it = _rotors.crbegin(); it != _rotors.crend(); it++) {
            result = it->forward(result);
        }

        // Pass through the reflector
        result = _reflector.reflect(result);

        // Loop over rotors, left-to-right, and apply backward translation
        for (auto it = _rotors.cbegin(); it != _rotors.cend(); it++) {
            result = it->backward(result);
        }

        // Final pass through the plug board
        return _plugBoard.map(result);
    }
}
