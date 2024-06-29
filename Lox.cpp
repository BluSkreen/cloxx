#include <fstream>
#include <iostream>
#include <sstream>
/* #include <string> */
using namespace std;

#include "Token.h"

class Cloxx {
private:
  void run(const std::string &source);
  void report(int line, string where, string message);

public:
  // Cloxx();
  void runFile(const std::string &filename);
  void runPrompt();

  void error(int line, string message);
  bool hadError = false;
};

int main(int argc, char *argv[]) {
  Cloxx cloxx;

  if (argc > 2) {
    cout << "Usage: cloxx [script]\n";
    exit(64);
  } else if (argc == 2) {
    cloxx.runFile(argv[1]);
  } else {
    cloxx.runPrompt();
  }

  return 0;
}

void Cloxx::runFile(const std::string &filename) {
  std::ifstream inputStream(filename);
  std::stringstream buffer;
  buffer << inputStream.rdbuf();
  cout << buffer.str();
  if (hadError)
    exit(65);
}

void Cloxx::runPrompt() {
  std::string line;
  for (;;) {
    cout << "> ";
    getline(cin, line);
    if (line == "")
      break;
    run(line);
    hadError = false;
  }
}

void Cloxx::run(const std::string &source) {
  Scanner scanner = new Scanner(source);
  List<Token> tokens = scanner.scanTokens();

  for (int i = 0; i < tokens.length(); i++) {
    cout << tokens[i] << "\n";
  }
}

void Cloxx::error(int line, string message) { report(line, "", message); }

void Cloxx::report(int line, string where, string message) {
  cerr << "[line " << line << "] Error" << where << ": " << message;
  hadError = true;
}
