#include "EOFAutomata.h"

void EOFAutomata::S0(const std::string& input) {
    if (input[index] == EOF) {
        inputRead = 1;
    }
    else {
        Serr();
    }
}