
#include <cstdio>
#include <unistd.h>

using std::printf;
using std::fprintf;

void bufferedIO() {
    for (int i = 0; i < 5; ++i) {
        printf(".");
        sleep(1);
    }
}

void unbufferedIO() {
    for (int i = 0; i < 5; ++i) {
        fprintf(stderr, ".");
        sleep(1);
    }
}


int main() {
    //bufferedIO();
    unbufferedIO();
    return 0;
}
