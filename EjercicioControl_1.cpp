/* divida en bloques 
ingrese cadena de carcateres
ingresar x teclado numero de caracteres clave
d)si el bloque esta incompleto , completar con X x ejemp -  sXXX
e) guardar resultado en un string separando con una *
ejempl Inte*nte *anal*izar* mas* pro*fund*amen*te l*os m*ensa*jes *reci*bido*sXXX
f) guardar el resultado (divido en bloques) en un vector string */


#include <iostream>
#include <string>
using namespace std ;

void divisionBloques( string , int);

int main(){
    
    string cadena;
    int clave ;
    cout << " Ingresar cadena de caracrteres: " ;
    getline(cin,cadena);
    cin.ignore();
    cout << "Ingresar clave : " ;
    cin >> clave ;
    
    divisionBloques(cadena,clave) ;
    
    return 0;
}

void divisionBloques( string cadena , int clave ){
    string relleno("XXX");
    int tam = cadena.length(); 
    for(int i=0 ; i < tam ;i++){
        if(i%clave==0 )
            cout <<endl ;
            cout << cadena[i];
            if(cadena[i] < cadena[1] ){
                cadena.append("xxx");
            }
        
    }
}

