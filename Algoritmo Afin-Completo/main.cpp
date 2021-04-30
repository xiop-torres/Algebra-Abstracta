#include <iostream>
#include <string>
#include "afin.h"

using  namespace std;
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
        cout << "Ingresar el mensaje a cifrar: ";
        getline(cin,mensaje);
        Afin receptor(32,21);
        
        cout << receptor.cifrado(mensaje) << endl;
    }
    else if(opcion==2){
        cin.ignore();
        string mensajeDe;
        cout << "Ingrese mensaje a decifrar: " ;
        getline(cin,mensajeDe);

        Afin receptor(32,21);
        //Afin emisor;
        //cout << receptor.cifrado("itscool") << endl;

        cout << receptor.decifrado(mensajeDe)<< endl;
    }
    else{
        cout << "Opcion incorrecta.Intentar nuevamente" <<endl;
    }
    return 0;
}
