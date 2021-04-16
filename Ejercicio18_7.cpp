#include <iostream>
#include <string>
//cifrado simple
using namespace std ;
const string rot13(const string);
const string rotDescifrado( const string);

int main(){
    string mensaje,encriptado; 
    int clave = 13;
    
    
    cout << " 1. Cifrar mensaje  " << endl ;
    cout << " 2. Decifrar mensaje " <<endl ;
    int op;
    cout << "Ingresar opcion : ";
    cin >> op;
    if(op ==1){
        cin.ignore();
        cout << "Ingrese mensaje a cifrar: " ;
        getline(cin,mensaje);
        
        cout << "Mensaje cifrado : " << rot13(mensaje) ;
    }
    else if  (op ==2){
        cin.ignore();
        cout << "Ingrese mensaje encriptado : " ;
        getline(cin,encriptado);
        
        cout << "Descifrando mensaje  : " << rotDescifrado(encriptado) << endl ;
    }
    else{
        cout << " Opcion incorrecta " << endl ;
    }
    
    return 0;
}
//Pregunta A
const string rot13(const string mensaje){
   
    string::const_iterator iterador=mensaje.begin(); //inicializado al comienzo 

    string resultado = " ";

    while(iterador!=mensaje.end()){ // hasta fin de cadena
        int ascii = *(iterador++);

        if((ascii >= 97 && ascii <110 ) || (ascii >= 65 && ascii <78)){ // a A - M m
            ascii = ascii +13; 
        }
        else if((ascii >= 110 && ascii <=122 ) || (ascii >= 78 && ascii <=90)){ // N n - Z z
            ascii = ascii - 13; 
        }
        resultado  +=  ascii ;
    }
    return resultado;
}
//Pregunta b
const string rotDescifrado(const string encriptado){
    string::const_iterator iterador=encriptado.begin(); //inicializado al comienzo 

    string resultado = " ";

    while(iterador!=encriptado.end()){ // hasta fin de cadena
        int ascii = *(iterador++);

        if((ascii >= 97 && ascii <110 ) || (ascii >= 65 && ascii <78)){ // a A - M m
            ascii = ascii -13; 
        }
        else if((ascii >= 110 && ascii <=122 ) || (ascii >= 78 && ascii <=90)){ // N n - Z z
            ascii = ascii + 13; 
        }
        resultado  +=  ascii ;
    }
    return resultado;
}

//PREGUNTA C 
/*Si no conociera la clave para el descifrado ¿ que tan dificil cree usted que serìa quebrantar el codigo?
- El valor de la clave se necesita obligatoriamente para poder hacer el descifrado , si no se necesitaria
hacer bastantes combinaciones.*/