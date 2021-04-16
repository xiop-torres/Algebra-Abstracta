#include <iostream>
#include <string>
//imprimir alrevez usando iterador 
using namespace std ;
int main(){
    string texto;
    cout << "Ingrese texto: ";
    getline(cin,texto);

    string::reverse_iterator iterador= texto.rbegin();

    while( iterador != texto.rend()){
        cout << *iterador;
        ++iterador;
    }
    return 0;
}