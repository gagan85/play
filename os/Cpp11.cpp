#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::string;
using std::to_string;

int main(int argc, char** argv) {

    string foo = "foo" + to_string(11);
    cout << foo << "\n";

    return 0;
}
