#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

const double PI = 3.14159265358979323846;

int main() {
    srand(time(NULL));
    int cycles = 5;
    double res = 0.001;
    int size = 100;
    int nframes = 64;
    int delay = 8;
    double freq = (double)rand() / RAND_MAX * 3.0;
    double phase = 0.0;
    #include <iostream>
    #include <fstream> // Include the necessary header file

    // ...

    std::ofstream out("output.txt"); // Declare and initialize the 'out' variable

    // ...

    out.put(size & 0xff);
    out.put((size >> 8) & 0xff);
    out.put(0x80);
    out.put(0);
    out.put(0);
    out.put(0);
    out.put(0);
    out.put(0xff);
    out.put(0xff);
    out.put(0xff);
    out.put(0);
    out.put(0);
    out.put(0x21);
    out.put(0xf9);
    out.put(4);
    out.put(9);
    out.put(0);
    out.put(0);
    out.put(0);
    for (int i = 0; i < nframes; i++) {
        out.put(0x2c);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(size & 0xff);
        out.put((size >> 8) & 0xff);
        out.put(0);
        out.put(0);
        out.put(0x80);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0x2c);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(size & 0xff);
        out.put((size >> 8) & 0xff);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0x21);
        out.put(0xf9);
        out.put(4);
        out.put(9);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(delay);
        out.put(0);
        out.put(0x2c);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(size & 0xff);
        out.put((size >> 8) & 0xff);
        out.put(0);
        out.put(0);
        out.put(0x80);
        out.put(0);
        std::vector<std::vector<int>> frames(nframes, std::vector<int>(size * size)); // Declare and initialize the 'frames' variable

        out.put(0);
        out.put(0);
        out.put(0);
        out.put(0x21);
        out.put(0xf9);
        out.put(4);
        out.put(9);
        out.put(0);
        out.put(0);
        out.put(0);
        out.put(delay);
        out.put(0);
        for (int j = 0; j < size * size; j++) {
            out.put(frames[i][j]);
        }
    }
    out.put(0x3b);
    out.close();
    return 0;
}