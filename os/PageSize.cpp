/*
 * Author: Sam Zhao <sam@cs.brown.edu>
 */
#include <iostream>
#include <unistd.h>

int main(int arc, char** argv) {
    std::cout << sysconf(_SC_PAGE_SIZE) << "\n";

    return 0;
}
