#ifndef STRINGAUTOMATA_H
#define STRINGAUTOMATA_H

#include "Automaton.h"

class StringAutomata : public Automaton {
public:
    StringAutomata() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //STRINGAUTOMATA_H
