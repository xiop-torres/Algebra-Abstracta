#include <iostream>
#include <string>

using namespace std ;
void ordSeleccion( string[], const size_t , bool (*)(string& ,string&));

void intercambiar (string*  const , string* const );
bool ascendente(string&, string&);
bool descendente(string&, string&);
int main(){
    int op;
    const size_t tam=13;
    string paises[tam]={" Peru " ," Canada "," Brazil "," Finlandia "," EEUU ",
    " Dinamarca "," Chile "," Bolivia "," Venezuela "," Afganistan ",
    " Italia "," Somalia "," Argentina "};


    cout << "1. Orden ascendente "<< endl ;
    cout << "2. Orden descendiente " << endl;
   
    cout << "Opcion : " ;
    cin >> op;
    cout << "Paises antes de ordenamiento : " ;

    for(size_t i=0 ; i < tam ;++i){
        cout << paises[i] ;
    }
    

    if(op==1){
        cout << "\nOrdenando ascendentemente : " ;
        ordSeleccion( paises , tam , ascendente);
        for(size_t i=0 ; i < tam ;++i){
        cout << paises[i] <<" ";
    }
        
        
    }
    else if (op==2){
        cout << "\nOrdenando descendientemente: ";
        ordSeleccion(paises,tam,descendente);
        for(size_t i=0 ; i < tam ;++i){
        cout << paises[i] <<" ";
    }
    }
    else {
        cout << "opcion incorrecta : " ;
    }

    return 0;
}

void ordSeleccion( string x[], const size_t tam , bool(*compare)(string& ,string&))
{
    for(size_t i=0 ; i < tam-1 ; ++i){//itera a travez de tm-1 elemntos
        size_t menorOmayor= i; //primerinidice 

        for(size_t index=i+1 ; index < tam ; ++index){
            if(!(*compare)(x[menorOmayor],x[index])){
                menorOmayor=index;
            }
        }
        intercambiar(&x[menorOmayor],&x[i]);
    }
    
}
//intercambia losvalores en las ubicaciones de memoria 
// a las que apuntan elemento1ptr y elemento2ptr
void intercambiar (string * const elemento1Ptr , string * const elemento2Ptr){
    string contenido = *elemento1Ptr;
    *elemento1Ptr = *elemento2Ptr;
    *elemento2Ptr =contenido;
}
bool ascendente( string& a, string& b){
    return a<b; // devuelve true si a es menor que b
}
bool descendente( string& a, string& b){
    return a>b; //devuelve true si a es mayor que b 
}