#include "Scanner.h"
#include "Token.h"
#include <vector>

Scanner::Scanner(std::string sourceV) {
  source = sourceV;
}

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }

  tokens.push_back(new Token(TokenType::LOX_EOF, "", nullptr, line));
  return tokens;
}
