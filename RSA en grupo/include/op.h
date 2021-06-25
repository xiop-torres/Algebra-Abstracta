#ifndef OP_H_INCLUDED
#define OP_H_INCLUDED
#include"RSA.h"
#include <NTL/ZZ.h>
#include<iostream>
#include<string>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;
using namespace NTL;
    ZZ euclides(ZZ m, ZZ n);
    ZZ euclidesEx(ZZ a, ZZ b);
    ZZ inversa(ZZ num, ZZ mod);
    ZZ expomod(ZZ base, ZZ exp, ZZ mod);
    ZZ mod(ZZ a, ZZ n);
    ZZ convStoZZ(string str);
    string convZZtoS(ZZ num);
    //////////////////////////////////////////////////////////////////////
    bool convertir(char Q);
    ZZ mp3(int cor);
    ZZ _rand_( void );
    void srand__( ZZ semilla );
    void foo();
    void hash_();
    //////////////////////////////
    long witness(const ZZ& num_a_probar, const ZZ& num_aleatorio);
    bool PrimeTest(const ZZ& num_a_probar, long num_de_pruebas);


#endif // OP_H_INCLUDED
