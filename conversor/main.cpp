#include "conversorbases.h"
#include <stdlib.h>
#include <vector>
using namespace std;



int main()
{
   int A,B;
   char V[200];
    cout << "Digite a base A: ";
   cin >>A;
   cout << "Digite o numero a ser convertido: ";
   cin.clear();
   cin.ignore(INT_MAX,'\n');
   cin.getline(V,200);
   cout << "Digite a base B na qual sera convertido: ";
   cin>>B;
    ConversorBases *X = new ConversorBases();

   double basedecimal = X->converteParaDecimal(V,A);
   string resultado = X->converteParaBaseDesejada(basedecimal,B);
   cout <<"Resultado: "<< resultado << endl;
}
