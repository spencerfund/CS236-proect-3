#include "SchemesAutomata.h"

void SchemesAutomata::S0(const std::string &input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S1(const std::string &input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S2(const std::string &input) {
    if (input[index] == 'h') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S3(const std::string &input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S4(const std::string &input) {
    if (input[index] == 'm') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S5(const std::string &input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomata::S6(const std::string &input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}
