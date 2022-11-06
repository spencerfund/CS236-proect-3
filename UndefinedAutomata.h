#ifndef UNDEFINEDAUTOMATA_H
#define UNDEFINEDAUTOMATA_H

#include "Automaton.h"

class UndefinedAutomata : public Automaton {
public:
    UndefinedAutomata() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //UNDEFINEDAUTOMATA_H
