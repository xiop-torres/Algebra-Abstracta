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
        Afin emisor(3,5);
        cout << emisor.cifrado("hola") << endl;
    }
    else if(opcion==2){
        Afin receptor(3,5);
        Afin emisor;
        //cout << receptor.cifrado("itscool") << endl;
        cout << receptor.decifrado("avmf")<< endl;
    }
    else{
        cout << "Opcion incorrecta.Intentar nuevamente" <<endl;
    }
    return 0;
}
