#include "undefStringAutomaton.h"

void undefStringAutomaton::S0(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void undefStringAutomaton::S1(const std::string &input) {
    if (index == input.size()) {
        return;
    }
    if (input[index] == '\n') {
        newLines++;
    }
    if (input[index] != '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void undefStringAutomaton::S2(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
    }
}