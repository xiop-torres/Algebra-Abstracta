#include "RSA.h"
RSA::RSA(){
}
RSA::RSA(int bit)
{
    BIT=bit;
    while(P==Q){
        GenPrime(P,BIT); //funcion ZZ
        GenPrime(Q,BIT);
    }
    N=P*Q;
    fi_n=(P-1)*(Q-1);

    while(clavPublica==clavPrivada){
    clavPublica=genclavPublica();
    clavPrivada=genclavPrivada();
    }

}
RSA::RSA(ZZ e,ZZ n)
{
    clavPublica=e;
    N=n;
}
RSA::RSA(ZZ p, ZZ q,ZZ clavpriv_d)
{
    P=p;
    Q=q;
    N=P*Q;
    fi_n=(P-1)*(Q-1);
    clavPrivada=clavpriv_d;
}
void RSA::genclaves()
{
    clavPublica=genclavPublica();
    clavPrivada=genclavPrivada();
}
ZZ RSA::genclavPublica()
{
    while(true){
        ZZ e_ = GenPrime_ZZ(BIT);
        if ((euclides(e_,fi_n)==1) && e_<fi_n)
            return e_;
    }
}
ZZ RSA::genclavPrivada()
{
    ZZ D;
    return D=euclidesEx(clavPublica,fi_n);
}

string RSA::cifradobloques(string mensaje, ZZ publica, ZZ Nn)
{
    string cifrado;
    string n_tamString=convertirZZtoString(N);
    tam_n=n_tamString.size();
    string bloque;
    int pos;
    char ch;
    for(int i=0;i<mensaje.size();i++){
        ch=mensaje[i];
        pos=static_cast<int>(ch);
        bloque=bloque+normalizarStringAscii(pos);
        //cout << bloque << endl;
    }
    cout << "Ascii bloque: " << bloque << "\n" << endl;
    ZZ bloqueZZ;
    bloqueZZ=0;

    string aux;

    for(bloque;bloque.size()>0;){
        bool verify_bloque=true;
        while(verify_bloque)
        {
            if(bloqueZZ<N && aux.size()<=tam_n && bloque.size()!=0)
            {
                aux+=bloque.substr(0,3);
                bloqueZZ=convertirStringToZZ(aux);
                aux=convertirZZtoString(bloqueZZ);
                if(bloqueZZ< N && aux.size()<=tam_n)
                    bloque.erase(0,3);
            }
            else
            {
                if(bloque.size()!=0)
                    bloqueZZ/=1000;
                aux.clear();
                verify_bloque=false;
            }
        }
        ZZ x;
        x=exponenciacionModular(bloqueZZ,publica,Nn);

        string almacen;
        almacen=normalizar(x);
        cifrado+=almacen;
    }

    return cifrado;

}

string RSA::descifrado(string TextoC)
{
    string descifrado;
    string bloque_L;
    ZZ x;

    ZZ bloqueZZ;

    while(TextoC.size()>0)
    {
        bloqueZZ=0;
        string bloques_Ntam;
        bloques_Ntam+=TextoC.substr(0,tam_n);
        bloqueZZ=convertirStringToZZ(bloques_Ntam);
        TextoC.erase(0,tam_n);
        x=restochino(bloqueZZ);
        string x_str=convertirZZtoString(x);
        int tamx;
        tamx=x_str.size();

        if(tamx%3!=0){
            bloque_L+='0';
            bloque_L+=convertirZZtoString(x);
        }
        else{
            bloque_L+=convertirZZtoString(x);
        }
    }

    int ch;

    for(int i=0;i<bloque_L.size();i+=3){
        cout << "bloque L: " << bloque_L << endl;
        string bloqueTOint=bloque_L.substr(i,3);
        int pos=stoi(bloqueTOint);//para regresar al alfabeto
        ch=pos;
        cout << "ch: " << ch << endl;
        descifrado+=ch;
        cout << "descifrado:  " << descifrado << endl;
    }
    return descifrado;

}


string RSA::normalizarString(int num){
    string letraStringTemp = to_string(num);
    int letraTamTemp = letraStringTemp.size();
    int letraTam=2;
    string temp = "0";
    if(letraTam > letraTamTemp){
        for(int i=0;i<(letraTam-1);i++){
            letraStringTemp.insert(0,temp);
        }
    }
    return letraStringTemp;
}

string RSA::normalizar(ZZ num)
{
    string almacen;
    string Num_str=convertirZZtoString(num); //num a string
    int tam;
    tam=Num_str.size();
    int diferencia=tam_n-tam;
    if(diferencia)
    {
        for(int i=0;i<diferencia;i++)
        {
            almacen+="0";
        }
        almacen+=Num_str;
    }
    else
    {
        almacen+=Num_str;
    }
    return almacen;
}

string RSA::normalizarStringAscii(int num){
    string letraStringTemp = to_string(num);
    int letraTamTemp = letraStringTemp.size();
    int letraTam=3;
    int relleno=0;
    if(letraTamTemp==2)
        relleno=2;
    else if(letraTamTemp==1)
        relleno=1;
    string temp = "0";
    if(letraTam > letraTamTemp){
        for(int i=0;i<(letraTam-relleno);i++){
            letraStringTemp.insert(0,temp);
        }
    }
    return letraStringTemp;
}

ZZ RSA::restochino(ZZ T)
{
    ZZ descompP=modulo(clavPrivada,P-1);
    ZZ descompQ=modulo(clavPrivada,Q-1);
    ZZ M1,M2;
    M1=N/P;
    M2=N/Q;
    ZZ M1inv,M2inv;
    M1inv=euclidesEx(M1,P);
    M2inv=euclidesEx(M2,Q);
    ZZ Tp,Tq;
    Tp=modulo(T,P);
    Tq=modulo(T,Q);
    ZZ Mp,Mq;
    Mp=exponenciacionModular(Tp,descompP,P);
    Mq=exponenciacionModular(Tq,descompQ,Q);
    ZZ x1,x2;
    x1=modulo((Mp*M1inv*M1),N);
    x2=modulo((Mq*M2inv*M2),N);
    return modulo((x1+x2),N);

}

ZZ RSA::ferman(ZZ a,ZZ m){
      if (euclides(a, m) != 1) {
        cout << "no tiene inverso";
    }
    else {
        return exponenciacionModular(a,m-2,m);
    }

}

ZZ RSA::fermat_peque(ZZ pos,ZZ e,ZZ p){
    if(PrimeTest(p,10)&& euclides(pos,p)==1){
        if((p-1) == e)
            return to_ZZ(1);
        if(p<e){
            return exponenciacionModular(pos,e,p);
        }
    }
}
RSA m;

ZZ RSA::modulo(ZZ a, ZZ b)
{
    ZZ q=ZZ(a/b);
	ZZ r=ZZ(a-(q*b));
	if(r<ZZ(0)){
		q=q-1;
		r=r+b;
	}
	return r;
}
ZZ RSA::euclides(ZZ a, ZZ b)
{
    ZZ temporal;
    while (b!=0){
        temporal=b;
        b=modulo(a,b);
        a=temporal;
    }
    return a;
}
ZZ RSA::inversa(ZZ num, ZZ m)
{
    num = modulo(num,m);
    ZZ i;
    for (i=1; i<m; i++)
       if (modulo((num*i), m) == 1)
          return i;
}

ZZ RSA::exponenciacionModular(ZZ base, ZZ exp, ZZ modi)
{
    ZZ resultado_total;
    resultado_total = 1;
    ZZ mod_dos;
    mod_dos=2;
    while (exp != 0) {
        if (modulo(exp,mod_dos)!= 0)
            resultado_total = modulo((resultado_total * base) , modi);
        exp = exp/ 2;
        base = modulo((base * base) , modi);
    }
    return resultado_total;
}
ZZ RSA::euclidesEx(ZZ a, ZZ b)
{
    ZZ r1=a,r2=b,r=ZZ(0),q=ZZ(0),s=ZZ(0),s1=ZZ(1),s2=ZZ(0),t=ZZ(0),t1=ZZ(0),t2=ZZ(1),arr[3];
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
    arr[0] = r1;
    arr[1] = s1;
    arr[2] = t1;
    ZZ inversa=s1;
    if(s1<0)
        inversa=s1+b;
    return inversa;
}

ZZ RSA::convertirStringToZZ(string string_)
{
    ZZ number(NTL::INIT_VAL, string_.c_str());
    return number;
}

string RSA::convertirZZtoString(ZZ numero_)
{
    stringstream x;
    x << numero_;
    return x.str();
}

bool RSA::convertir(char letra){
      if (letra>=65&&letra<=90)//printf("es una LETRA NAYUSCULA\n ");
         return 1;
      if (letra>=97&&letra<=122)//printf("es una letra minuscula\n");
         return 1;
      if (letra>=123&&letra<=255)//printf("es un simbolo\n ");
         return 1;
      if (letra>=48&&letra<=57)//printf("es un numero\n ");
         return 1;
       else
         return 0;
}

long RSA::witness(const ZZ& num_a_probar, const ZZ& num_aleatorio)
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

bool RSA::PrimeTest(const ZZ& numero, long num_de_pruebas)
{
   if (numero <= 1) return 0;
   PrimeSeq s;
   long p;

   p = s.next();
   while (p && p < 2000) {
      if ((numero % p) == 0) return (numero== p);
      p = s.next();
   }
   ZZ x;
   long i;

   for (i = 0; i < num_de_pruebas; i++) {
      x = RandomBnd(numero);
      if (witness(numero, x))
         return 0;
   }

   return 1;
}




