#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std ;
using namespace NTL;

class rsa
{
    private:
        ZZ d;
        ZZ e;
        ZZ fiN;
        ZZ p;
        ZZ q;
        ZZ n;
        string alfabeto= "abcdefghijklmnopqrstuvwxyz";

    public:
        rsa(int bits){
            cout << " El # de bits es : " << bits;
            //bits para rsa

        }; //generar bits

        rsa(ZZ N ,ZZ e){
            long long size=alfabeto.size();
            this->n=N;
            this->e=e;
        }; //lee clave

        ZZ exponenciacion(ZZ,ZZ);
        string cifrar(string);
        string decifrar_mensaje(string);

        ///FUNCIONES
        void generarClaves(int nbits){
            char nombre[55];
            ofstream directorioPublico;
            ofstream e;
            ofstream N;
            ofstream p;
            ofstream q;

            directorioPublico.open("directorioPublico.txt");
            cout <<"nombre :" << endl;
            cin >> nombre;

        }
        ZZ generar_aleatorio( ZZ lim){
             srand (time(NULL));
            return mod(ZZ(rand()),lim-1)+1;
        };
        ZZ euclidesExtendido(ZZ, ZZ);
        ZZ mcd(ZZ x ,ZZ y){
            ZZ g=ZZ(1);
            while(evenCheck(x)&&evenCheck(y)){
            x=x>>1;
            y=y>>1;
            g=g<<1;
            }
            while(x!=0){
                while(evenCheck(x))
                    x=x>>1;
                while(evenCheck(y))
                    y=y>>1;
            ZZ t=valorAbs((x-y))>>1;
            if(x>=y){
                x=t;
            }
            else y=t;
            }
            return (g*y);

        }; //si
        ZZ mod(ZZ a,ZZ b){
            ZZ q= ZZ(a/b);
            ZZ r= ZZ(a-(q*b));
            if(r<0){
                q--;
                r=r+b;
            }
            return r;
        };// si
        ZZ inversa(ZZ r1, ZZ r2){
            ZZ s1=ZZ(1);
            ZZ s2=ZZ(0);
            ZZ b=ZZ(r2);

            ZZ a=ZZ(r1);
            ZZ t1=ZZ(0);
            ZZ t2=ZZ(1);

            if(inversaCheck(r1,r2)){
                while(r2>0){
                    ZZ q =r1/r2;
                    ZZ r=r1-q*r2;
                    r1=r2;
                    r2=r;
                    ZZ s=s1-q*s2;
                    s1=s2;
                    s2=s;
                    ZZ t=t1-q*t2;
                    t1=t2;
                    t2=t;
                }
                if(s1>0){
                    return s1+=b;
                }
                return s1;
            }
            else
            cout << "No existe una inversa" << endl;
            return ZZ(0);
        }; //si
        ZZ valorAbs(ZZ x){
            if(x<0){
                return (x*(-1));
            }
            return ZZ(x);
        };//si
        bool inversaCheck(ZZ x,ZZ y){
            if(evenCheck(x)&&evenCheck(y))
                return 0;
            while(x!=0){
                while(evenCheck(x))
                    x=x>>1;
                while(evenCheck(y))
                    y=y>>1;
                ZZ t=valorAbs((x-y))>>1;
                if(x>=y)
                    x=t;
                else y=t;
            }
            return y==1;
        };
        bool evenCheck(ZZ x){
            ZZ r=(x>>1)<<1;
            if(r>0){
                r= ZZ(2)+r;
            }
            return r==x;
        };//si

};

#endif // RSA_H
