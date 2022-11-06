#include "Parameter.h"
#include <vector>
#include <iostream>
#include <string>

Parameter::Parameter(std::string inputContent) {
    content = inputContent;
    if (inputContent.at(0) == '\'') {
        isConstant = true;
    }
    else {
        isConstant = false;
    }
}

Parameter::~Parameter() {

}

void Parameter::toString() {
    std::cout << content;
}

std::string Parameter::returnContent() {
    return content;
}

bool Parameter::returnIsConstant() {
    return isConstant;
}
