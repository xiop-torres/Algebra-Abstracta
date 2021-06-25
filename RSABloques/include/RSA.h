#ifndef RSA_H
#define RSA_H
#include "op.h"
#include <iostream>
#include <string>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;
using namespace NTL;

class RSA
{
    public:
        RSA(); //si
        RSA(int bits); //si
        RSA(ZZ _p, ZZ _q,ZZ clavpriv); //si
        RSA(ZZ _e,ZZ _n);//si

        void genclaves(); //si
        ZZ genclavPublica(); //si
        ZZ genclavPrivada();//si

        ZZ cifrado(string T,ZZ clavePublica,ZZ N);
        string cifradobloques(string T, ZZ clavPublica, ZZ N);
        string descifrado(string TC);
        ZZ restochino(ZZ T);
        //ZZ ferman(ZZ n, ZZ p);
        //ZZ fermat_peque(ZZ pos,ZZ e,ZZ p);

        string normalizarString(int num);
        string normalizarStringAscii(int num);
        string normalizar(ZZ num);

        string alfabeto="abcdefghijklmnopqrstuvwxyz";
        int tamalf=alfabeto.size();
////////////////////////////////////////////////////////////////
        vector<ZZ> num;
        void prime(int cor,int cor2,int n);
        ZZ primo(ZZ num);
        ZZ gene_prime(int n_primos,int pos);
/////////////////////////////////////////////////////////////////

        ZZ clavPublica;
        ZZ clavPrivada;

        ZZ P;
        ZZ Q;
        ZZ N;
        int tamN;
        ZZ phiN;
        int BIT;

    private:
};

#endif // RSA_H
