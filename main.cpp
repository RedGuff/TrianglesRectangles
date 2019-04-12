#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    cout << "Il existe des triangles rectangles particuliers, avec uniquement des longueurs  en entiers." << endl;
    cout << "Par exemple : (3;4;5), (5;12;13), (20;21;29)..." << endl;
    cout << "Voici de quoi les trouver tous, dans une gamme donnée." << endl;
    int aMax = 100;
    int bMax = 100;
ofstream myfile;
  myfile.open ("100_100.txt");
if (!myfile.is_open())
  {
      cerr << "Erreur de fichier !" << endl;
  }else{
    for (int a = 1; a <= aMax; a++)
    {
for (int b = a; b <= bMax; b++) // int b = 1 => 3,4,5 et 4, 3, 5.
{
    if ( sqrt(a*a + b*b) == int(sqrt(a*a + b*b)))
    {
       myfile << a << " " << b << " " << sqrt(a*a + b*b)<< endl;
       // cout << a << " " << b << " " << sqrt(a*a + b*b) << endl;
    }
}
    }
  }
    myfile.close();
    return 0;
}
