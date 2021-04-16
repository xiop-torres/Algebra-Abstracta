#include <iostream>
#include <string>

using namespace std ;
int main(){
    cout << "Ingrese un string :  ";
    string objeto;
    getline(cin,objeto);
    string caracter("*******");
    objeto.insert((objeto.length()/2),caracter);

    cout << "Ingresar nuevo string : " << objeto <<endl;

    return 0;
}