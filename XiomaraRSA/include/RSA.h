#ifndef RSA_H
#define RSA_H
#include<vector>
#include <sstream>
#include<string>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;
class rsa
{
    public:
        rsa();///SI
        rsa(int bits);///SI
        rsa(ZZ e,ZZ n);///SI
        rsa(ZZ p,ZZ q,ZZ d);
        //string functions
        string convertirZZtoString(ZZ );
        ZZ convertirStringToZZ(string );
        //funciones
        void generar_clave();///SI
        ZZ euclides(ZZ ,ZZ);///SI
        ZZ modulo(ZZ ,ZZ ); ///SI
        ZZ euclidesExtendido(ZZ a ,ZZ b); ///SI
        ZZ exponenciacionModular(ZZ,ZZ,ZZ); ///SI
        void mostrarMenu();

        string alfabetoToNumeros(string);
        void separarToNumeros(string cadena);
        ZZ cifradoEnBloques(string);
        string decifrado(ZZ mensajeCifrado);


        vector<ZZ> bloques;
        vector<ZZ> cifrados;
        //vector<ZZ> decifrado;
        vector<string> cifrado_pos;

        string enviar(vector<ZZ> );
    private:
        ZZ n,p,q,fi_n;
        ZZ e_clavePublica,d_claveprivada;
        int bit;
        string alfabeto="abcdefghijklmnopqrstuvwxyz ";
};

#endif // RSA_H
