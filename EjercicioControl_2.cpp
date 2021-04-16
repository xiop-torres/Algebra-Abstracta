/*Ingrese una cadena de texto que contenga números:
Por ejemplo:

548365842358

Convierta el string en una variable de tipo entera
*/
#include <iostream>
#include <string>

using namespace std ;
int main(){
    string numeros;
    cout << " Ingrese un cadena de texto : " << endl ;
    cin >> numeros ;

    cout <<" Tu numero en (int) es : " << atoi(numeros.c_str());
    return 0;
}