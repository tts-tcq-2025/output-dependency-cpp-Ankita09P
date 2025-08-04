#include <iostream>
#include <sstream>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() {
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    
    // Redirect cout to buffer
    std::cout.rdbuf(buffer.rdbuf());

    int result = printColorMap();

    // Restore original stream
    std::cout.rdbuf(oldCoutStreamBuf);

    std::string output = buffer.str();

    // Check the number of lines (should be 25)
    int lineCount = std::count(output.begin(), output.end(), '\n');
    assert(lineCount == 25);

    // Check presence of a known output line
    assert(output.find("0 | White | Blue") != std::string::npos);
    assert(output.find("24 | Violet | Slate") != std::string::npos);

    // Check return value
    assert(result == 25);

    std::cout << "All is well (maybe!)\n";
}

int main() {
    testPrintColorMap();
    return 0;
}
