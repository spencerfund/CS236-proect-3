#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <string>

class Header {
private:
    std::vector<std::string> columnNames;
public:
    Header() = default;
    Header(std::vector<std::string> inColNames);
    ~Header() = default;
    std::vector<std::string> getColNames();
    void setColNames(std::vector<std::string> newNames);
};


#endif //HEADER_H
