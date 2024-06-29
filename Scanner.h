#ifndef SCANNER_H
#define SCANNER_H

#include "Token.h"
#include <string>
#include <vector>

class Scanner {
private:
  std::string source;
  std::vector<Token> tokens;
  int start;
  int current;
  int line;

public:
  Scanner(std::string source);
  std::vector<Token> scanTokens();
};

#endif
