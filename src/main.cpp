#include <string>
#include <iostream>
#include "MyUtility.hpp"
int main(int argc, char* argv[]) { 
    std::string url;

    if (argc > 1) {
        url = argv[1];
    }
    else {
        std::cout << "URL: ";
        std::getline(std::cin, url);
    }

    MyUtility app;
    app.process(url);
}
