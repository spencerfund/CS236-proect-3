#include "Database.h"
#include "Tuple.h"

void Database::AddRelation(Relation newRel) {
    std::string relName = newRel.GetName();
    rels.insert({relName,newRel});
}

Relation* Database::GetRelation(std::string relationName) {
    Relation returnRel = rels[relationName];
    auto* newReturnRel = new Relation;
    *newReturnRel = returnRel;
    return newReturnRel;
}

Relation Database::GetRelationCopy(std::string relationName) {
    Relation returnRel = rels[relationName];
    return returnRel;
}

void Database::addTupleToRel(std::string relationName, Tuple inTuple) {
    rels[relationName].AddTuple(inTuple);
}
