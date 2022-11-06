#ifndef LEFTPARENAUTOMATA_H
#define LEFTPARENAUTOMATA_H

#include "Automaton.h"

class LeftParenAutomata : public Automaton {
public:
    LeftParenAutomata() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //LEFTPARENAUTOMATA_H
