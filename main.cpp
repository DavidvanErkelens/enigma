#include <iostream>
#include "src/macine.h"

int main() {
    Enigma::PlugBoard::Configuration plugBoardConfig("");
    Enigma::Machine enigma(plugBoardConfig);
    Enigma::Machine copy(plugBoardConfig);

    std::string output = std::move(enigma.process("GLUPF HVCJC MMUK TQG HL"));
    std::cout << "Output: " << output << std::endl;

    std::string input = std::move(copy.process(output.c_str()));
    std::cout << "Output reversed: " << input << std::endl;

    return 0;
}
