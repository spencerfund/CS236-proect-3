#ifndef ADDAUTOMATA_H
#define ADDAUTOMATA_H

#include "Automaton.h"

class AddAutomata : public Automaton {
public:
    AddAutomata() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //ADDAUTOMATA_H
