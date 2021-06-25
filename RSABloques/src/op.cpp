#include "op.h"
#include "RSA.h"
RSA m;
ZZ mod(ZZ a, ZZ n)
{
    if(a >= 0)
        return (a - (a/n)* n);
    else
        return (a - ((a/n)-1)*n);
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

ZZ inversa(ZZ num, ZZ m)
{
    num = mod(num,m);
    ZZ i;
    for (i=1; i<m; i++)
       if (mod((num*i), m) == 1)
          return i;
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



ZZ euclidesEx(ZZ a, ZZ b)
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
//hasta aqui
ZZ convStoZZ(string str)
{
    ZZ number(NTL::INIT_VAL, str.c_str());
    return number;
}

string convZZtoS(ZZ num)
{
    stringstream x;
    x << num;
    return x.str();
}

/////////////////////////////////////////////////////

bool convertir(char Q){
      if (Q>=65&&Q<=90)//printf("es una LETRA NAYUSCULA\n ");
         return 1;
      if (Q>=97&&Q<=122)//printf("es una letra minuscula\n");
         return 1;
      if (Q>=123&&Q<=255)//printf("es un simbolo\n ");
         return 1;
      if (Q>=48&&Q<=57)//printf("es un numero\n ");
         return 1;
       else
         return 0;
}

/////////////////////////////////////////////////////////
void foo(){
    this_thread::sleep_for(10ms);
}
///////////////////////////espa parte de has deberia de ir a al rsa por wue nos da problemas en la ubivacion del vector

ZZ siguiente;
void srand__( ZZ  semilla )
{
  siguiente = semilla;
}

ZZ _rand_( )
{
    vector<ZZ> pseudo_num;
    vector<thread> v;
    for(int n = 0; n < 4; ++n)
        v.emplace_back(foo);

    hash<thread::id> hasher;
    for(auto& t : v) {
        //cout << "lib number " << t.get_id() << " mmmmmnum " << hasher(t.get_id())+ 5656565 << '\n';
        pseudo_num.push_back(conv<ZZ>(hasher(t.get_id())));
        t.join();
    }

//     for(int i=0; i<pseudo_num.size(); i++){
//        cout<<pseudo_num[i]<<endl;
//    }

  siguiente = siguiente*( pseudo_num[0] + pseudo_num[1]);
  return conv<ZZ>((siguiente/65536) % (RAND_MAX-1));
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
