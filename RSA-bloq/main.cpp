#include <iostream>
#include "RSA.h"
#include "op.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main(){
    string x="hola mundo hola mundo ";

    RSA a(8);

    int opcion;
    do{
        cout << "1. Cifrar y decifrar: " << endl;
        cout << "2. Generar Claves: " << endl;
        cout << "3. Salir " << endl;
        cout << "Opcion: " << endl;
        cin>> opcion;

        switch(opcion){
            case 1:{

                cout << "\nMensaje  es : "<< x << endl ;
                string cifradobloq=a.cifradobloques(x,a.clavPublica,a.N);
                cout << "Mensaje cifrado es :" << endl;
                cout << cifradobloq << endl;
                cout << endl;

                cout << "\nMnsaje a decifrar: " ;
                string decifrado=a.descifrado(cifradobloq);
                cout << "Mensaje Descifrado:" << endl;
                cout << decifrado << endl;

            }
            case 2:{
                cout << "El valor de P: " << a.P << endl;
                cout << endl;
                cout << "El valor de Q: " << a.Q << endl;
                cout << endl ;
                cout << "El valor de N: " << a.N << "\n" << endl;
                cout << "El valor de fi_n: " << a.fi_n << endl;
                cout << "Clave Publica e:" << a.clavPublica << "\n" << endl;
                cout << "Clave Privada d:" << a.clavPrivada << "\n" << endl;

            }

        }
    }
    while(opcion!=4);
 return 0;
}














