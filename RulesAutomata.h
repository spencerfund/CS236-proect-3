#ifndef RULESAUTOMATA_H
#define RULESAUTOMATA_H

#include "Automaton.h"

class RulesAutomata : public Automaton {
public:
    RulesAutomata() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif //RULESAUTOMATA_H
