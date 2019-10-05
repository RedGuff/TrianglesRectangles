#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    cout << "Il existe des triangles rectangles particuliers, avec uniquement des longueurs  en entiers." << endl;
    cout << "Par exemple : (3;4;5), (5;12;13), (20;21;29)..." << endl;
    cout << "Voici de quoi les trouver tous, dans une double gamme de valeurs." << endl;
    int aMax = 50;
    int bMax = 50;
ofstream myfile;
string file = to_string(aMax) + "_" + to_string(bMax) +".txt";
  myfile.open (file.c_str());
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
