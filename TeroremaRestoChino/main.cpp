#include <NTL/ZZ.h>
#include <iostream>
using namespace std;
using namespace NTL;

const int tam = 3;

ZZ mod(ZZ a, ZZ n) {
    if(a >= 0)
        return (a - (a/n)* n);
    else
        return (a - ((a/n)-1)*n);
}

ZZ mcd(ZZ a, ZZ b)
{
    ZZ temp;
    while (b != 0) {
        temp = b;
        b = mod(a,b);
        a = temp;
    }
    return ZZ(a);
}

ZZ euclidesExt(ZZ a, ZZ b)
{
    ZZ r1,r2,r,q,s,s1,s2,t,t1,t2,arr[3];
    r1=a;
    r2=b;
    r=0;
    q=0;
    s=0;
    s1=1;
    s2=0;
    t=0;
    t1=0;
    t2=1;
    arr[3];
    while(r2>0) {
        q = (r1/r2);
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        s = s1-q*s2;
        s1 = s2;
        s2 = s;
        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    arr[0] = r1;   // mcd (r1,r2)
    arr[1] = s1;   // x
    arr[2] = t1;   // y
    ZZ inv=s1;
    if(s1<0)
    inv=s1+b;
    return inv;
}

ZZ inversa(ZZ num, ZZ m) {

    num = mod(num,m);
    ZZ i;
    for (i=1; i<m; i++)
        if (mod((num*i), m) == 1)
            return i;
}

bool sonPrimos(ZZ *primo, ZZ tam){
    for(int i=0; i< tam ; i++ ){
        for(int j=i+1;j< tam ; j++){
            if(mcd(primo[i],primo[j])!=1 || primo[i]==primo[j] ){
               return false;
            }
        }
    }
    return true;
}
void restoChino(ZZ *ai, ZZ *pi ){
    ZZ Pi[tam];
    ZZ qi[tam];
    ZZ x0[tam];
    ZZ X = ZZ(0);
    ZZ P= ZZ(1);
    if(sonPrimos(pi,ZZ(tam))==1){
        //multilicar todos sus pi para la P resultante
        for(int i=0;i<tam ;i++){
            P=P*pi[i];
        }
        //Pi = P/pi
        for(int i=0; i <tam ;i++){
            Pi[i]=P/pi[i];
            qi[i]= inversa(Pi[i],pi[i]);
            x0[i]=ai[i]*Pi[i]*qi[i];
            x0[i]=mod(x0[i],P);
            X=X+x0[i];
        }
        cout << "Multiplicacion de la pi :" << endl;
        for (int i=0; i<tam ; i++){
            cout << "p" << i << " : "<<  pi[i] <<endl;
        }
        cout << "P = " << P <<endl;
        for (int i=0; i<tam ; i++){
            cout << "P" << i << " : "<< P <<" / "<< pi[i] << " = "<< Pi[i]<<endl;
        }
        X=mod(X,P);
        cout << "La solucion del sistema de ecuaciones es: " << endl;
        cout << "X = " << X << " + "<< P <<"k" ;
        cout << endl;
    }
}
int main()
{
    cout << "Teorema resto chino: " << endl;
    ZZ ai[tam] = {ZZ(2),ZZ(3),ZZ(2) };
    ZZ pi[tam] = {ZZ(3),ZZ(5),ZZ(7) };
    restoChino(ai, pi);
}
