#include <cctype>
#include <iostream>
#include "undefStringAutomaton.h"
#include "Lexer.h"
#include "AddAutomata.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "EOFAutomata.h"
#include "FactsAutomata.h"
#include "IdAutomata.h"
#include "LeftParenAutomata.h"
#include "MultiplyAutomata.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "QueriesAutomata.h"
#include "RightParenAutomata.h"
#include "RulesAutomata.h"
#include "SchemesAutomata.h"
#include "StringAutomata.h"
#include "UndefinedAutomata.h"
#include "LineComment.h"
#include "CommentAutomata.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for (unsigned int i = 0; i < automata.size(); ++i) {
        delete automata.at(i);
    }
    automata.clear();

    for (unsigned int i = 0; i < tokens.size(); ++i ) {
        delete tokens.at(i);
    }
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomata());
    automata.push_back(new RightParenAutomata());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MultiplyAutomata());
    automata.push_back(new AddAutomata());
    automata.push_back(new SchemesAutomata());
    automata.push_back(new FactsAutomata());
    automata.push_back(new RulesAutomata());
    automata.push_back(new QueriesAutomata());
    automata.push_back(new IdAutomata());
    automata.push_back(new StringAutomata());
    automata.push_back(new undefStringAutomaton());
    automata.push_back(new LineComment());
    automata.push_back(new CommentAutomata());
    automata.push_back(new UndefinedAutomata());
    automata.push_back(new EOFAutomata());
}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;

    while (!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(maxRead);

        while (!input.empty() && std::isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                lineNumber += 1;
                input.erase(0, 1);
            }
            else if (std::isspace(input.at(0))) {
                input.erase(0, 1);
            }
        }//Handle whitespace

        if (input.empty()) {
            break;
        }

        for (unsigned int i = 0; i < automata.size(); ++i) {
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }
        if (maxRead > 0) {
            Token *token = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(token);
        }

        else {
            maxRead = 1;
            UndefinedAutomata *temp = new UndefinedAutomata();
            Token *token = temp->CreateToken(input.substr(0,1), lineNumber);
            tokens.push_back(token);
            delete temp;
        }
        input.erase(0, maxRead);
    }
    EOFAutomata *tempAuto = new EOFAutomata();
    Token *EFtoken = tempAuto->CreateToken("", lineNumber);
    tokens.push_back(EFtoken);
    delete tempAuto;

    for (unsigned int i = 0; i < tokens.size(); ++i) {
        if (tokens.at(i)->returnToken() == TokenType::COMMENT) {
            delete tokens.at(i);
            tokens.erase(tokens.begin()+i);
            i -= 1;
        }
        else if (tokens.at(i)->returnToken() == TokenType::LINE_COMMENT) {
            delete tokens.at(i);
            tokens.erase(tokens.begin()+i);
            i -= 1;
        }
    }

}

std::vector<Token*> Lexer::returnTokens() {
    return tokens;
}
