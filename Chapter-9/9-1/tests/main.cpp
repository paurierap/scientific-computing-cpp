#include "../lib/Exception.hpp"
#include "../lib/FileNotOpenException.hpp"
#include "../lib/OutOfRangeException.hpp"
#include <fstream>
#include <iostream>
#include <string>

void Readfile(const std::string &filename, double x[], double y[])
{
    std::ifstream read_file(filename.c_str());

    if (!read_file.is_open())
    {
        throw(FileNotOpenException("File can't be opened"));
    }

    int n = 4;
    for (int i = 0; i < 4; i++)
    {
        if (i >= n)
        {
            throw(OutOfRangeException("Index is out of range"));
        }

        read_file >> x[i] >> y[i];
    }

    read_file.close();
    std::cout << filename << " read successfully\n";
}

int main()
{
    double x[4], y[4];
    std::string file = "Output.dat";
    bool repeat = true;

    // An infinite loop helps catching the exceptions multiple times, otherwise it just gives an uncaught exception.

    // Have a look at the code patiently, it is a bit complicated to fuly understand.

    // For every try, there is a CATCH!
    while (repeat)
    {
        try
        {
            Readfile(file, x, y);
            repeat = false;
        }
        catch (FileNotOpenException &FNOex)
        {
            FNOex.PrintDebug();
            std::cout << "Could not open " + file << std::endl;
            std::cout << "Give alternative location\n";
            std::cin >> file;
        }
        catch (OutOfRangeException &OORex)
        {
            OORex.PrintDebug();
            std::cout << "Allocated arrays are too small" << std::endl;
            std::cout << "Give alternative size for container arrays" << std::endl;
            int n;
            std::cin >> n;
            double x[n], y[n];

            /*x = new double[n];
            y = new double[n];

            delete[] x;
            delete[] y;*/
        }
    }

    return 0;
}