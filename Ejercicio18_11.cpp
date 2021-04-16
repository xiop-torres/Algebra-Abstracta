#include <iostream>
#include <string>
// Escriba un programa que ntroduzca por separado un primer nombre
//y un apellido y q concatene los dos en un nuevo objeto string
using namespace std ;
int main(){
    string nombre;
    string apellido;
    string nombrecompleto;

    cout << "Ingrese el primer nombre : " ;
    getline(cin,nombre);

    cout << "Ingrese el apellido : " ;
    getline(cin,apellido);

    nombrecompleto.append(nombre).append(" ").append(apellido);
    cout << "El nombre completo es : " << nombrecompleto;
    return 0;
}