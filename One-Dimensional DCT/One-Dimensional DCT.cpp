#include <iostream>
#include <sstream>
#include "transformMatrix.h"
bool running = true;
std::string inputString;

int main()
{
    std::cout << "One-Dimensional DCT Transform.\n";
    while (running) {
        std::cout << "Enter up to 10 integers. X to close:\n";
        std::getline(std::cin, inputString);
        if (inputString != "X" && inputString != "x") {
            std::stringstream inputStream(inputString);
            transformMatrix mat(inputStream);
            mat.print();
        }
        else {
            running = false;
        }
    }
    std::cout << "Closing...\n";
}