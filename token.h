#include <string>

class Token {
private:
    TokenType type;
    string lexeme;
    Object literal;
    int line;

public:
    Token(TokenType typeV, std::string lexemeV, Object literalV, int lineV);
};
