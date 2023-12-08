#include <string>
#include "token.h"

Token::Token(TokenType typeV, std::string lexemeV, Object literalV, int lineV) {
    type = typeV;
    lexeme = lexemeV;
    literal = literalV;
    line = lineV;
}
