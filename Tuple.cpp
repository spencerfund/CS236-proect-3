#include "Tuple.h"

std::vector<std::string> Tuple::returnValues() {
    return rowValues;
}

Tuple::Tuple() {
}

Tuple::~Tuple() {

}

bool Tuple::operator<(const Tuple &rhs) const {
    return rowValues < rhs.rowValues;
}

void Tuple::addValue(std::string inVal) {
    rowValues.push_back(inVal);
}