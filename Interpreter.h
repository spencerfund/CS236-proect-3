#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"
#include "Predicate.h"


class Interpreter {
private:
    DatalogProgram program;
    Database dBase;
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
public:
    Interpreter(DatalogProgram inProgram);
    ~Interpreter();

    void InterpretSchemes();
    void InterpretFacts();
    Relation evaluatePredicate(Predicate* p);
    Relation selectPredicate(Predicate* p);
    void InterpretQueries();
};


#endif //INTERPRETER_H
