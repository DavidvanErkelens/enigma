//
// Created by David van Erkelens on 14/10/2021.
//

#ifndef ENIGMA_PLUGBOARD_CONFIGURATION_H
#define ENIGMA_PLUGBOARD_CONFIGURATION_H

namespace Enigma::PlugBoard {
    class Configuration {
    private:
        const char *_mapping;

    public:
        Configuration(const char *mapping);

        const char *getMapping() const;
    };
}


#endif //ENIGMA_PLUGBOARD_CONFIGURATION_H
