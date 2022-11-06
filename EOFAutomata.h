#ifndef EOFAUTOMATA_H
#define EOFAUTOMATA_H

#include "Automaton.h"

class EOFAutomata : public Automaton {
public:
    EOFAutomata() : Automaton(TokenType::E0F) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //EOFAUTOMATA_H
