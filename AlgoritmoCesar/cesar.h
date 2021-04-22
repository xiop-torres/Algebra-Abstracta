//#ifdef CESAR_H
#define CESAR_H 
#include <iostream>
#include <string>

using namespace std;
class cesar{
    private :
        string abcd; // alfabeto
        int clave; 
    public:
        cesar(int a){
            this-> abcd="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz "; //alfabeto
            this->clave = a ; 
        };
        ~cesar(){};
        string Cifrar(string mensaje ){
            string nuevo= "" ; // almacena el mensaje resultante 
            int posicion; // va inidicar posicion del recorrido 
            for(int i=0; i <mensaje.size() ; i++){
                posicion = funcionModulo((abcd.find(mensaje[i])+ clave),abcd.size());
                nuevo= nuevo + abcd.at(posicion);

            }
            return nuevo;

        };
        string Descifrar(string mensajeParaDecifrar){
            string nuevo = "" ; //almacena la palabra cifrada
            int posicion ; //indica posicion 
            for(int i=0 ;i < mensajeParaDecifrar.size();i++){
                posicion=funcionModulo((abcd.find(mensajeParaDecifrar[i])-clave),abcd.size());
                nuevo=nuevo + abcd.at(posicion);
            }
            return nuevo;
        };
        int funcionModulo(int a ,int b){
            int modulo = a - b*(a/b);
            if(modulo>=0){
                    return modulo;
            }
            modulo= modulo + b;
            return modulo;
        };
        
        

};


//#endif 
