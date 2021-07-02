#include <iostream>
#include "RSA.h"
#include "op.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main(){
    string x="hola mundo";

    RSA a(526);
    cout << "P: " << a.P << endl;
    cout << "Q: " << a.Q << endl;

    cout << "N: " << a.N << "\n" << endl;
    cout << "phiN: " << a.phiN << endl;
    cout << "Publica :" << a.clavPublica << "\n" << endl;
    cout << "Privada :" << a.clavPrivada << "\n" << endl;

    string cifbloq=a.cifradobloques(x,a.clavPublica,a.N);
    cout << "mensaje cifrado:" << endl;
    cout << cifbloq << "\n" << endl;

    string decif=a.descifrado(cifbloq);
    cout << "mensaje descifrado:" << endl;
    cout << decif << endl;
 return 0;
}














