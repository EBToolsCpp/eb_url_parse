#include <iostream>
#include "EBUrlParser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    EBUrlParser p;
    p.Parse("https://www.baidu.com:443/my/demo?aa=bb&cc=dd");
    p.PrintResult();
    return 0;
}
