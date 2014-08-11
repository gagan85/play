/**
 * Author: Sam Zhao <sam@cs.brown.edu>
 */
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <climits>
#include <vector>

using std::cout;
using std::size_t;
using std::vector;

void cleanUp(void* mallocPtrs[], size_t mallocCount) {
    for (size_t i = 0; i < mallocCount; ++i) {
        free(mallocPtrs[i]);
    }
}

void cleanUp(const vector<void*>& mallocPtrs) {
    for (size_t i = 0; i < mallocPtrs.size(); ++i) {
        free(mallocPtrs.at(i));
    }
}

int main(int argc, char** argv) {

    //const long NUM_MALLOCS = 1 << (10 + 2); // 1024 * 4 malloc calls.
    const size_t NUM_MALLOCS = LONG_MAX; // 1024 * 4 malloc calls.
    long pageSize = sysconf(_SC_PAGE_SIZE);
    vector<void*> mallocPtrs;

    for (size_t i = 0; i < NUM_MALLOCS; ++i) {
        //mallocPtrs[i] = malloc(static_cast<size_t>(pageSize));
        void* p = malloc(static_cast<size_t>(pageSize));
        if (p == NULL) {
            cout << "Malloc failed at count: " << i << ", total size: " << i * pageSize << "B\n";
            cleanUp(mallocPtrs);
            return 0;
        }  else {
            mallocPtrs.push_back(p);
        }
    }

    cout << "Malloc succeeded at count: " << NUM_MALLOCS << ", total size: " << NUM_MALLOCS * pageSize << "B\n";

    cleanUp(mallocPtrs);
    return 0;
}
