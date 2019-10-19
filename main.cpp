#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


int pgcd(int a, int b) // Probablement plus lent qu'avec les modulos, mais peut-être plus simple. // https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide
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

int pgcd(int a, int b, int c)
{   return pgcd(pgcd(a, b), c); // Surcharge !
}

int main()
{   cout << "Il existe des triangles rectangles particuliers, avec uniquement des longueurs en entiers." << endl;
    cout << "Par exemple : (3;4;5), (5;12;13), (20;21;29)..." << endl;
    cout << "Voici de quoi les trouver tous (sauf les multiples), jusque 2 valeurs maximales." << endl;
    int aMax = 21;
    int bMax = 21;
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
                {   c = int(sqrt(a*a + b*b));
                    if (pgcd(a,b,c)==1) // (3;4;5) oui ; (6;8;10) : non. // Calcul séparé, après le "if sqrt ..." pour économiser l calcul des PGCD si cela peut être évité.
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
