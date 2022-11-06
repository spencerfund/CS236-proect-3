#ifndef COMMENTAUTOMATA_H
#define COMMENTAUTOMATA_H

#include "Automaton.h"

class CommentAutomata : public Automaton {
public:
    CommentAutomata() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif //COMMENTAUTOMATA_H
