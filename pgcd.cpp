#include <iostream>
#include "pgcd.hpp"
using namespace std;

int pgcd2(int a, int b) // Probablement plus lent qu'avec les modulos, mais peut-être plus simple. // https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide
{   while (a!=b)
    {   if (a>b)
        {   a = a - b;
        }
        else
        {   b = b - a;
        }
    }
    return a;
}

int pgcd3(int a, int b, int c)
{   return pgcd2(pgcd2(a, b), c);
}
