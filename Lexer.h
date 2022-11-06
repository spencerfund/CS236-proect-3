#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer {
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);

    std::vector<Token*> returnTokens();
    
    // TODO: add other public methods here

};

#endif // LEXER_H

