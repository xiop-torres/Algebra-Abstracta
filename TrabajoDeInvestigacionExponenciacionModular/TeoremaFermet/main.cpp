
#include <NTL/ZZ.h>
using namespace NTL;
#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;
ZZ mod(ZZ a, ZZ n)
{
    if(a >= 0)
        return (a - (a/n)* n);
    else
        return (a - ((a/n)-1)*n);
}
ZZ expomod(ZZ base, ZZ exp, ZZ m)
{
    ZZ result;
    result = 1;
    ZZ dos;
    dos=2;
    while (exp != 0) {
        if (mod(exp,dos)!= 0)
            result = mod((result * base) , m);
        exp = exp/ 2;
        base = mod((base * base) , m);
    }
    return result;
}
ZZ euclides(ZZ m, ZZ n)
{
    while (n!=0){
        ZZ t;
        t=n;
        n=mod(m,n);
        m=t;
    }
    return m;
}
long witness(const ZZ& num_a_probar, const ZZ& num_aleatorio)
{
   ZZ m, y, z;
   long j, k;

   if (num_aleatorio == 0) return 0;
   k = 1;
   m = num_a_probar/2;
   while (m % 2 == 0) {
      k++;
      m /= 2;
   }
   z = PowerMod(num_aleatorio, m, num_a_probar);
   if (z == 1) return 0;

   j = 0;
   do {
      y = z;
      z = (y*y) % num_a_probar;
      j++;
   } while (j < k && z != 1);

   return z != 1 || y != num_a_probar-1;
}
bool PrimeTest(const ZZ& num_a_probar, long num_de_pruebas)
{
   if (num_a_probar <= 1) return 0;
   PrimeSeq s;
   long p;

   p = s.next();
   while (p && p < 2000) {
      if ((num_a_probar % p) == 0) return (num_a_probar == p);
      p = s.next();
   }
   ZZ x;
   long i;

   for (i = 0; i < num_de_pruebas; i++) {
      x = RandomBnd(num_a_probar);
      if (witness(num_a_probar, x))
         return 0;
   }

   return 1;
}
ZZ fermat_peque(ZZ pos,ZZ e,ZZ p){
    if(PrimeTest(p,10)&& euclides(pos,p)==1){
        if((p-1) == e)
            return to_ZZ(1);
        if(p<e){
            return expomod(pos,e,p);
        }
    }
}
int main()
{
    cout << fermat_peque(ZZ(3),ZZ(12),ZZ(11));
    return 0;
}

