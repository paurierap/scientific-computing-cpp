// Testing the complex class

#include <iostream>
#include "../include/complex.h"

int main()
{
    Complex z(2, 3);
    Complex w(z), x(3);
    Complex y;
    Complex **A;

    A = new Complex *[3];

    for (int i = 0; i < 3; ++i)
    {
        A[i] = new Complex[3];
    }

    std::cout << z << std::endl;
    std::cout << real(z) << " " << imag(z) << std::endl;
    std::cout << w << std::endl;
    std::cout << w.conjugate() << std::endl;
    w.set2conj();
    std::cout << w << std::endl;
    std::cout << x << std::endl;
    std::cout << y.pow_n(3) << std::endl;
    std::cout << x.pow_n(0) << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}