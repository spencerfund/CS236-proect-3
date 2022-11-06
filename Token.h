#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    LINE_COMMENT,
    UNDEFINED,
    E0F
};

class Token
{
private:
  TokenType type;
  std::string description;
  int lineNum;

public:
    Token(TokenType type, std::string description, int line);

    TokenType returnToken();
    std::string returnDescription();

    std::string toString();
    std::string enumToString(TokenType);
};

#endif // TOKEN_H

