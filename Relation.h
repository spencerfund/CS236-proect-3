#ifndef RELATION_H
#define RELATION_H
#include <vector>
#include <string>
#include "Header.h"
#include "Tuple.h"
#include <set>

class Relation {
private:
    std::string name;
    Header columnNames;
    std::set<Tuple> tuples;
public:
    Relation() = default;
    Relation(std::string inputName, Header inputColNames);
    ~Relation() = default;

    std::string GetName();
    void AddTuple(Tuple newTuple);
    void toString();

    Relation select1(int colIndex, std::string value);
    Relation select2(int colIndex1, int colIndex2);
    Relation project(std::vector<int> colsToProject);
    Relation rename(std::vector<std::string> newColNames);
    std::string countTuples();

};


#endif //RELATION_H
