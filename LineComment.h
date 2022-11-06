#ifndef LINECOMMENT_H
#define LINECOMMENT_H

#include "Automaton.h"

class LineComment : public Automaton {
public:
    LineComment() : Automaton(TokenType::LINE_COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif //LINECOMMENT_H
