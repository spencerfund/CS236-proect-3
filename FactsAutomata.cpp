#include "FactsAutomata.h"

void FactsAutomata::S0(const std::string &input) {
    if (input[index] == 'F') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomata::S1(const std::string &input) {
    if (input[index] == 'a') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void FactsAutomata::S2(const std::string &input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void FactsAutomata::S3(const std::string &input) {
    if (input[index] == 't') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void FactsAutomata::S4(const std::string &input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}