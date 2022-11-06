#include "LineComment.h"

void LineComment::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineComment::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        S4(input);
    }
}

void LineComment::S2(const std::string &input) {
    if (index == input.size()) {
        Serr();
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

void LineComment::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else {
        S2(input);
    }
}

void LineComment::S4(const std::string &input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
    }
}
