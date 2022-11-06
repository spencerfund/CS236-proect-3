#include "StringAutomata.h"

void StringAutomata::S0(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomata::S1(const std::string &input) {
    if (index == input.size()) {
        Serr();
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

void StringAutomata::S2(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
    }
}