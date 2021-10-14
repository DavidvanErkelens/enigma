//
// Created by David van Erkelens on 14/10/2021.
//

#include "configuration.h"

namespace Enigma::PlugBoard {

    Configuration::Configuration(const char *mapping) : _mapping(mapping) {
    }

    const char *Configuration::getMapping() const {
        return _mapping;
    }
}
