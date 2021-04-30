#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class funciones{
    public:
        static bool even(int a){
            int r=(a>>1)<<1;
            if (r<0) r=2+r;
            return r==a;
        };
        static int valAbs(int a){
            if (a<0) return (a*-1);
            return a;
        };
                

        static int inversa(int r1 , int r2){
            int s1=1;
            int s2=0;
            int b=r2;

            int a=r1;
            int t1=0;
            int t2=1;

            if(inversaExiste(r1,r2)){
                while(r2>0){
                    int q=r1/r2;
                    int r=r1-q*r2;
                    r1=r2;
                    r2=r;
                    int s = s1-q*s2;
                    s1=s2;
                    s2=s;
                    int t=t1-q*t2;
                }
                if(s1>0) return funcionModulo(s1,b);
                return s1; 
            }
            else cout << "No existe una inversa para este num" << endl ;
            return 0;
        };
        static bool inversaExiste(int x, int y){
            if(even(x)&&even(y))
                return 0;
            while(x!=0){
                while(even(x)) x=x>>1;
                while(even(y)) y=y>>1;
                int t=valAbs((x-y))>>1;
                if(x>=y) x=t;
                else y=t;
            }
            return y==1;
        };    
        static int euclides(int x, int y){
            int g=int(1);
            while(even(x)&&even(y)){
                x=x>>1;
                y=y>>1;
                g=g<<1;
            }
            while(x!=0){
                while(even(x)){
                    x=x>>1;
                }
                while(even(y))
                    {y=y>>1;
                }
                int t=valAbs((x-y))>>1;
                if(x>=y)
                   x=t;
                   
                else y=t;     
            }
            return(g*y);
        };
        
        static int funcionModulo(int a , int b){
            int modulo = a - b*(a/b);
            if(modulo>=0){
                    return modulo;
            }
            modulo= modulo + b;
            return modulo;
        };
        static int aleatorio(int lim){
            srand(time(NULL));
            return funcionModulo(rand(),lim-2)+1;
        };
      

};

#endif 