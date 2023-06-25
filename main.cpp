#include <iostream>
#include <fstream>
#include <math.h>
#include "pgcd.hpp"
using namespace std;



int main()
{   cout << "Il existe des triangles rectangles particuliers, avec uniquement des longueurs \nen entiers." << endl;
    cout << "Par exemple : (3;4;5), (5;12;13), (20;21;29)..." << endl;
    cout << "Voici de quoi les trouver tous (sauf les multiples), jusque 2 valeurs maximales." << endl;
    int aMax = 42;
    int bMax = 42;
    cout << "La gamme de valeurs est ici en partant de 1 jusque " << aMax << " et de 1 jusque " << bMax << "." << endl;
    int c = 0;
    ofstream myfile;
    string file = to_string(aMax) + "_" + to_string(bMax) +".txt";
    myfile.open (file.c_str());
    if (!myfile.is_open())
    {   cerr << "Erreur de fichier !" << endl;
    }
    else
    {   for (int a = 1; a <= aMax; a++)
        {   for (int b = a; b <= bMax; b++) // int b = 1 => 3,4,5 et 4, 3, 5.
            {   if ( sqrt(a*a + b*b) == int(sqrt(a*a + b*b)))
                {   c = sqrt(a*a + b*b);
                    if (pgcd3(a,b,c)==1) // (3;4;5) oui ; (6;8;10) : non. // Calcul séparé, après le "if sqrt ..." pour économiser l calcul des PGCD si cela peut être évité. Des compilateurs le font automatiquement
                    {   cout  << a << " " << b << " " << c << endl;
                        myfile << a << " " << b << " " << c << endl;
                    }
                }
            }
        }
    }
    myfile.close();
    return 0;
}
