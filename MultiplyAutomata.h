#ifndef MULTIPLYAUTOMATA_H
#define MULTIPLYAUTOMATA_H

#include "Automaton.h"

class MultiplyAutomata : public Automaton {
public:
    MultiplyAutomata() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //MULTIPLYAUTOMATA_H
