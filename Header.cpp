#include "Header.h"

std::vector<std::string> Header::getColNames() {
    return columnNames;
}

Header::Header(std::vector<std::string> inColNames) {
 columnNames = inColNames;
}

void Header::setColNames(std::vector<std::string> newNames) {
 for (unsigned int i = 0; i < columnNames.size(); i++) {
     columnNames.at(i) = newNames.at(i);
 }
}
