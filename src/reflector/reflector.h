//
// Created by David van Erkelens on 11/10/2021.
//

#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <map>

namespace Enigma::Reflector {
    class Reflector {
    private:
        const char *_mapping;

        explicit Reflector(const char *mapping);

    public:
        /**
         * Reflect a single character
         * @param input
         * @return char
         */
        char reflect(char input) const;

        /**
         * Shorthand function for the reflector configurations as historically used
         * @return Reflector
         */
        static Reflector B();
    };
}

#endif //ENIGMA_REFLECTOR_H
