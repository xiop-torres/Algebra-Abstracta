#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <fstream>
using namespace std;
using namespace NTL;
ZZ aleatorio()
{
    time_t t;
    srand((unsigned)time(&t));
    int res = rand();//
    return to_ZZ(res);

}
ZZ modulo(ZZ a,ZZ n)
{
    if(abs(a)==abs(n))
        return to_ZZ("0");
    if(a<0 && (a+n)!=0)
    {
        ZZ xd;
        xd = a +n*(((-1*a)/n)+1);
        if(xd == n)
        {
            return to_ZZ("0");
        }
        return xd;
    }
    return (a-n*(a/n));
}
ZZ expo_modular_rapida(ZZ a,ZZ k,ZZ n)
{
    ZZ b;
    b = conv<ZZ>(1);
    if(k==0)
        return b;
    ZZ A;
    A = a;
    if(bit(k,0)==1)
        b=a;

    int tamano;
    tamano = NumBits(k);
    for(int i=1;i<tamano;i++)
    {
        A = modulo(A*A,n);
        if(bit(k,i)==1)
        {
            b = modulo(A*b,n);
        }
    }
    return b;
}
bool testPrimalidadMillerRabin(ZZ n,int loops)
{
    ZZ a;
    a = n - to_ZZ("1");
    vector<ZZ> values;
    int i=0;
    while(a != 0)
    {
        i++;
        a /= to_ZZ("2");
        if(a>>1<<1 != a)
        {
            values.push_back(to_ZZ(i));
            values.push_back(a);
        }
    }
    //values.push_back(to_ZZ(i));
    //values.push_back(a);
    ZZ s = values[0];
    ZZ r = values[1];
    ZZ j;
    for(j =0;j<loops;j++)
    {
        ZZ rndom = modulo(aleatorio(),n-2)+2;
        ZZ y = expo_modular_rapida(rndom,r,n);
        if(y != 1 && y!= n - to_ZZ("1"))
        {
            ZZ j = to_ZZ("1");
            while(j<=s-to_ZZ("1") && y!=n-to_ZZ("1"))
            {
                y = expo_modular_rapida(y,to_ZZ("2"),n);
                if(y == 1)
                {
                    return 0;  // es falso
                }
                j++;
            }
            if(y != n-to_ZZ("1"))
                return false;
        }
    }
    return true;
}
int main()
{
    ZZ c;
    c= 2147483647; //32 bits
    cout << testPrimalidadMillerRabin(c,32); // Si retorna 1 es primo , si retorna 0 no es primo
    cout << endl;
    ZZ a;
    a= 2147483642;
    cout << testPrimalidadMillerRabin(a,32); // no es primo
    return 0;
}
