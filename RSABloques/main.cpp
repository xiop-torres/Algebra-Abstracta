#include <iostream>
#include "RSA.h"
#include "op.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main(){

    string x="holacomoestas";

    RSA a(8); // nro bits
    cout << "P: " << a.P << endl;
    cout << "Q: " << a.Q << endl;

    cout << "N: " << a.N << "\n" << endl;
    cout << "phiN: " << a.phiN << endl;
    cout << "Publica :" << a.clavPublica << "\n" << endl;
    cout << "Privada :" << a.clavPrivada << "\n" << endl;

    string cifbloq=a.cifradobloques(x,a.clavPublica,a.N);
    cout << "Cifrando Mensaje:" << endl;
    cout << cifbloq << "\n" << endl;

    string decif=a.descifrado(cifbloq);
    cout << "Decifrando Mensaje:" << endl;
    cout << decif << endl;

 return 0;
}














