#include <string>
#include "Token.h"

Token::Token(TokenType typeV, std::string lexemeV, Object literalV, int lineV) {
    type = typeV;
    lexeme = lexemeV;
    literal = literalV;
    line = lineV;
}
