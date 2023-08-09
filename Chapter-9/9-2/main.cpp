#include <iostream>
#include <exception>

int main()
{
    double *p_x;

    try
    {
        p_x = new double[100000000000000];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    delete p_x;
    return 0;
}