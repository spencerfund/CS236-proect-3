#ifndef RIGHTPARENAUTOMATA_H
#define RIGHTPARENAUTOMATA_H

#include "Automaton.h"

class RightParenAutomata : public Automaton{
public:
    RightParenAutomata() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //RIGHTPARENAUTOMATA_H
