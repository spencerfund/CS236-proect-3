#include "Relation.h"
#include <iostream>

Relation::Relation(std::string inputName, Header inputColNames) {
    name = inputName;
    columnNames = inputColNames;
}

std::string Relation::GetName() {
    return name;
}

void Relation::AddTuple(Tuple newTuple) {
    tuples.insert(newTuple);
}

void Relation::toString() {
    std::vector<std::string> attributes = columnNames.getColNames();
    for (Tuple t : tuples) {
        std::vector<std::string> values = t.returnValues();
        int checkSize = values.size();
        std::cout << "  " << attributes.at(0) << "=" << values.at(0);
        if (checkSize > 1) {
            for (unsigned int i = 1; i < attributes.size(); i++) {
                std::cout << "," << attributes.at(i) << "=" << values.at(i);
            }
        }
        std::cout << std::endl;
    }
}

Relation Relation::select1(int colIndex, std::string value) {
    Relation returnRel(name, columnNames);
    std::vector<std::string> selectedRow;
    for (Tuple t : tuples) {
        selectedRow = t.returnValues();
        if (selectedRow.at(colIndex) == value) {
            returnRel.AddTuple(t);
        }
        selectedRow.clear();
    }
    return returnRel;
}

Relation Relation::select2(int colIndex1, int colIndex2) {
    Relation returnRel(name, columnNames);
    std::vector<std::string> selectedRow;
    for (Tuple t : tuples) {
        selectedRow = t.returnValues();
        if (selectedRow.at(colIndex1) == selectedRow.at(colIndex2)) {
            returnRel.AddTuple(t);
        }
        selectedRow.clear();
    }
    return returnRel;
}

Relation Relation::project(std::vector<int> colsToProject) {
    std::vector<std::string> nameCols;
    if (colsToProject.size() == 0) {
        Header emptyH;
        return Relation(name, emptyH);
    }
    for (unsigned int i = 0; i < colsToProject.size(); i++) {
        nameCols.push_back(std::to_string(colsToProject.at(i)));
    }
    Header returnH(nameCols);
    Relation returnRel(name, nameCols);
    std::vector<std::string> selectedRow;
    for (Tuple t : tuples) {
        Tuple newT;
        selectedRow = t.returnValues();
        for (unsigned int i = 0; i < colsToProject.size(); i++) {
            for (unsigned j = 0; j < selectedRow.size(); j++) {
                if (colsToProject.at(i) == static_cast<int>(j)) {
                    newT.addValue(selectedRow.at(j));
                }
            }
        }
        returnRel.AddTuple(newT);
        selectedRow.clear();
    }
    return returnRel;
}

Relation Relation::rename(std::vector<std::string> newColNames) {
    if (newColNames.size() == 0) {
        return Relation(name, columnNames);
    }
    Header  newNames = columnNames;
    newNames.setColNames(newColNames);
    Relation returnRel(name, newNames);
    for (Tuple t : tuples) {
        Tuple newT = t;
        returnRel.AddTuple(newT);
    }
    return returnRel;
}

std::string Relation::countTuples() {
    int numTuples = 0;
    for (Tuple t : tuples) {
        numTuples++;
    }
    return std::to_string(numTuples);
}
