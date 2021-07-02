#ifndef RSA_H
#define RSA_H
#include "op.h"
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace NTL;

class RSA
{
    public:
        RSA();
        RSA(int bit);
        RSA(ZZ,ZZ,ZZ);
        RSA(ZZ,ZZ);

        void genclaves();
        ZZ genclavPublica();
        ZZ genclavPrivada();

        ZZ cifrado(string T,ZZ clavePublica,ZZ N);
        string cifradobloques(string T, ZZ clavPublica, ZZ N);
        string descifrado(string TC);
        ZZ restochino(ZZ T);
        ZZ ferman(ZZ n, ZZ p);
        ZZ fermat_peque(ZZ pos,ZZ e,ZZ p);

        string normalizarString(int num);
        string normalizarStringAscii(int num);
        string normalizar(ZZ num);

        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
        int tamalf=alfabeto.size();

        //FUNCIONES
        ZZ euclides(ZZ m, ZZ n);///SI
        ZZ euclidesEx(ZZ a, ZZ b);///SI
        ZZ inversa(ZZ num, ZZ mod);///SI
        ZZ exponenciacionModular(ZZ base, ZZ exp, ZZ mod);///SI
        ZZ modulo(ZZ a, ZZ n);///SI
        //CONVERTIR
        ZZ convertirStringToZZ(string string_); ///SI
        string convertirZZtoString(ZZ numero_); ///SI
        // Aleatorio
        bool convertir(char Q);
        //////////////////////////////
        long witness(const ZZ& num_a_probar, const ZZ& num_aleatorio);
        bool PrimeTest(const ZZ& num_a_probar, long num_de_pruebas);


        ZZ clavPublica;
        ZZ clavPrivada;

        ZZ P;
        ZZ Q;
        ZZ N;
        int tam_n;
        ZZ fi_n;
        int BIT;


};

#endif // RSA_H
