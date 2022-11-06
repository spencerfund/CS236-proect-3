#ifndef TUPLE_H
#define TUPLE_H
#include <vector>
#include <string>

class Tuple {
private:
    std::vector<std::string> rowValues;
public:
    Tuple();
    ~Tuple();

    void addValue(std::string);
    std::vector<std::string> returnValues();
    bool operator< (const Tuple &rhs) const;
};


#endif //TUPLE_H
