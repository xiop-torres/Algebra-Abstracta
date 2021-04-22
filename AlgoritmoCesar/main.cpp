#include <iostream>
#include <string>
#include "cesar.h"
using namespace std;
int main(){
    int opcion;
    cout << "Ingrese una opcion (1-2): " << endl;
    cout << "1. Encriptar: " <<endl ;
    cout << "2. Desencriptar: " << endl ;
    cout << "Opcion nro : " ;
    cin >> opcion;

    if(opcion==1){
        cin.ignore();
        string mensaje;
        int clave;
        cout << " Ingrese el mensaje a cifrar: " ;
        getline(cin,mensaje);
        cout << "Ingrese una clave : " ;
        cin >> clave;
        cesar encriptado(clave); //crea objeto
        cout << encriptado.Cifrar(mensaje) <<endl;
    }
    else if(opcion==2){
        cin.ignore();
        string mensajeDe;
        int claveDe;
        cout << " Ingrese el mensaje a decifrar: " ;
        getline(cin,mensajeDe);
        cout << "Ingrese una clave : " ;
        cin >> claveDe;
        cesar desencriptar(claveDe);
        cout << desencriptar.Descifrar(mensajeDe)<< endl ;
    }
    else{
        cout << "Opcion incorrecta.Intentar nuevamente" <<endl;
    }
    return 0;
}
