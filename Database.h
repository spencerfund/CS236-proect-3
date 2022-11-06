#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <map>
#include "relation.h"

class Database {
private:
    std::map<std::string, Relation> rels;
public:
    void AddRelation(Relation newRelation);
    Relation* GetRelation(std::string relationName);
    Relation GetRelationCopy(std::string relationName);
    void addTupleToRel(std::string relationName, Tuple inTuple);
};


#endif //DATABASE_H
