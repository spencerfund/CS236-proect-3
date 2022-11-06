#ifndef QUERIESAUTOMATA_H
#define QUERIESAUTOMATA_H

#include "Automaton.h"

class QueriesAutomata : public Automaton {
public:
    QueriesAutomata() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
};


#endif //QUERIESAUTOMATA_H
