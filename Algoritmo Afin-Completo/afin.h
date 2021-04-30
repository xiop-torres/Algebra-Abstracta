#ifndef AFIN_H
#define AFIN_H
#include <string>
#include <iostream>
#include "funciones.h"

using namespace std;
class Afin{
    private:
        int a, b ;
        int inversaA;
        void generarClaves(){
            b=funciones::aleatorio(alfabeto.size());
            do{
            a= funciones::aleatorio(alfabeto.size());
            }while(!funciones::inversaExiste(a,alfabeto.size()));
        };
    public:
        string alfabeto ="abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()";
        Afin(){
            generarClaves();
            cout << "a : " << a<< endl ;
            cout << "b : " << b<< endl ;
            
        };

        Afin(int a , int b){
            string alfabeto ="abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()";
            this->a=a;
            inversaA=funciones::inversa(a,alfabeto.size());
            this -> b=b;
        };
        /*
        string cifrado(string mensaje){
            string salida=" ";
            for(int i=0;i<mensaje.size();i++){
                size_t m= alfabeto.find(mensaje.at(i));
                salida += alfabeto.at(funciones::funcionModulo(a*m +b,alfabeto.size()));
            }

            return salida;
        };*/
        string cifrado(string mensaje){
            string salida=" ";
            int pos;
            for(int i=0;i<mensaje.size();i++){
                pos= alfabeto.find(mensaje.at(i));
                int x=funciones::funcionModulo((a*pos)+b,alfabeto.size());
                salida += alfabeto.at(x);
            }

            return salida;
        }; 

        string decifrado(string mensaje){
            string salida=" ";
            for(int i=0;i<mensaje.size();i++){
                size_t y= alfabeto.find(mensaje.at(i));
                salida += alfabeto.at(funciones::funcionModulo(inversaA*(y-b),alfabeto.size()));
            }
            return salida;
        };


    
};

#endif