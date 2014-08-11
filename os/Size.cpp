/*
 * Author: Sam Zhao <sam@cs.brown.edu>
 */
#include <iostream>
#include <climits>

using std::cout;
using std::size_t;

int main(int argc, char** argv) {
    cout << "size_t:\t" << sizeof(size_t) << "\n";
    cout << "SIZE_MAX:\t" << SIZE_MAX << "\n";

    cout << "long:\t" << sizeof(long) << "\n";
    cout << "LONG_MAX:\t" << LONG_MAX << "\n";
    cout << "ULONG_MAX:\t" << ULONG_MAX << "\n";

    cout << "UINT_MAX:\t" << UINT_MAX << "\n";

    return 0;
}
