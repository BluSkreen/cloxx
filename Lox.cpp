#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Cloxx {
private:

public:
    Cloxx();
    void runFile(const std::string& filename);
    void runPrompt();
    void run(const std::string &source);
};

int main(int argc, char *argv[]) {
    Cloxx cloxx;

    if (argc > 1) {
        cout << "Usage: cloxx [script]\n";
        exit(64);
    } else if (argc == 1) {
        cloxx.runFile(argv[1]);
    } else {
        cloxx.runPrompt();
    }

    return 0;
}

void Cloxx::runFile(const std::string& filename) {
    std::ifstream inputStream(filename);
    std::stringstream buffer;
    buffer << inputStream.rdbuf();
    cout << buffer.str();
}
