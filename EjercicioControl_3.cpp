#include <iostream>
#include <string>
// Declare una variable de tipo númerica, convierta el contenido en un string

using namespace std ;
int main(){
    int entero = 10;
    float flotante = 10.5;
    string cadena = "";
    string cadena2 = "";
  
    cadena = to_string(entero);
    cadena2 = to_string(flotante);

    cout << "Esto es una cadena (int -> string ): " << cadena << endl;
    cout << "Esto es una cadena (float -> string ): " << flotante << endl;

    return 0;
}