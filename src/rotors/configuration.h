//
// Created by David van Erkelens on 13/10/2021.
//

#ifndef ENIGMA_ROTOR_CONFIGURATION_H
#define ENIGMA_ROTOR_CONFIGURATION_H

namespace Enigma::Rotor {
    class Configuration {
    private:
        const char *_mapping;
        char *_reverseMapping;
        char _notch;

        Configuration(const char *mapping, char notch);

    public:
        /**
         * The originally provided mapping as 26-character string, indicating replacement characters for input
         * @return const char *
         */
        const char *getMapping() const;

        /**
         * The reverse of the originally provided mapping
         * @return const char *
         */
        const char *getReverseMapping() const;

        /**
         * The notch character, which will trigger a rotation of the next rotor
         * @return
         */
        char getNotch() const;

        /**
         * Shorthand functions for the I, II, III, IV, V Rotor configurations as historically used
         * @return
         */
        static Configuration I();
        static Configuration II();
        static Configuration III();
        static Configuration IV();
        static Configuration V();
    };
}

#endif //ENIGMA_ROTOR_CONFIGURATION_H
