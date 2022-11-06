#include "CommentAutomata.h"

void CommentAutomata::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomata::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        S4(input);
    }
}

void CommentAutomata::S2(const std::string &input) {
    if (index == input.size()) {
        return;
    }
    if (input[index] == '\n') {
        newLines++;
    }
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomata::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else {
        S2(input);
    }
}

void CommentAutomata::S4(const std::string &input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
    }
}
