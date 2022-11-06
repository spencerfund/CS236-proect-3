#ifndef FACTSAUTOMATA_H
#define FACTSAUTOMATA_H

#include "Automaton.h"

class FactsAutomata : public Automaton {
public:
    FactsAutomata() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif //FACTSAUTOMATA_H
