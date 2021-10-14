cmake_minimum_required(VERSION 3.20)
project(enigma)

set(CMAKE_CXX_STANDARD 20)

add_executable(enigma main.cpp src/macine.cpp src/macine.h src/rotors/rotor.cpp src/rotors/rotor.h src/reflector/reflector.cpp src/reflector/reflector.h src/plugboard/plugboard.cpp src/plugboard/plugboard.h src/rotors/configuration.cpp src/rotors/configuration.h src/helpers/validation.h src/helpers/validation.cpp src/plugboard/configuration.cpp src/plugboard/configuration.h)
