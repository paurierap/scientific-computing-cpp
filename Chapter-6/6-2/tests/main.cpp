#include <iostream>
#include "../include/matrix.h"

int main()
{
    Matrix A, B(1, 2, 3, 4);
    Matrix C(B);

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << C.det() << std::endl;
    std::cout << C.inv() << std::endl;
    std::cout << C + B << std::endl;
    std::cout << B * 4.5 - C * 1.3 << std::endl;

    return 0;
}