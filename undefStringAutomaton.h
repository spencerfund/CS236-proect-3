#ifndef UNDEFSTRINGAUTOMATON_H
#define UUNDEFSTRINGAUTOMATON_H

#include "Automaton.h"

class undefStringAutomaton : public Automaton {
public:
    undefStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //UNDEFSTRINGAUTOMATON_H
