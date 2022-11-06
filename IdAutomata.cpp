#include "IdAutomata.h"

void IdAutomata::S0(const std::string &input) {
    check.clear();
    if (isalpha(input[index])) {
        check.push_back(input[index]);
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomata::S1(const std::string &input) {
    if (std::isalpha(input[index])) {
        check.push_back(input[index]);
        inputRead++;
        index++;
        S1(input);
    }
    else if (std::isdigit(input[index])) {
        check.push_back(input[index]);
        inputRead++;
        index++;
        S1(input);
    }
    else {
        if (check == "Queries") {
            Serr();
        }
        else if (check == "Facts") {
            Serr();
        }
        else if (check == "Rules") {
            Serr();
        }
        else if (check == "Schemes") {
            Serr();
        }
    }
}

