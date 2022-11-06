#ifndef IDAUTOMATA_H
#define IDAUTOMATA_H

#include "Automaton.h"
#include <string>

class IdAutomata : public Automaton {
private:
    std::string check = "";
public:
    IdAutomata() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
};


#endif //IDAUTOMATA_H
