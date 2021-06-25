#include "RSA.h"
RSA::RSA(){
}
RSA::RSA(int bits)
{
    BIT=bits;
//    while(P==Q){
//    GenPrime(P,BIT);
//    GenPrime(Q,BIT);
//    }
    P = gene_prime(3,1);
    Q = gene_prime(3,2);

    N=P*Q;
    phiN=(P-1)*(Q-1);

    while(clavPublica==clavPrivada){
    clavPublica=genclavPublica();
    clavPrivada=genclavPrivada();
    }

}
RSA::RSA(ZZ _e,ZZ _n)
{
    clavPublica=_e;
    N=_n;
}
RSA::RSA(ZZ _p, ZZ _q,ZZ clavpriv)
{
    P=_p;
    Q=_q;
    N=P*Q;
    phiN=(P-1)*(Q-1);
    clavPrivada=clavpriv;
}
void RSA::genclaves()
{

    clavPublica=genclavPublica();
    clavPrivada=genclavPrivada();

}

ZZ RSA::genclavPublica()
{

    while(true){
        ZZ E_aux = GenPrime_ZZ(BIT);
        if ((euclides(E_aux,phiN)==1) && E_aux<phiN)
            return E_aux;
    }
}

ZZ RSA::genclavPrivada()
{
    ZZ D_aux;
    return D_aux=euclidesEx(clavPublica,phiN);
}



string RSA::cifradobloques(string Texto, ZZ publica, ZZ Nn)
{
    string cifrado;
    string Ntam_aux=convZZtoS(N);
    tamN=Ntam_aux.size();
    string bloque;
    int pos;
    char ch;
    for(int i=0;i<Texto.size();i++){
        ch=Texto[i];
        pos=static_cast<int>(ch);
        bloque+=normalizarStringAscii(pos);
    }
    cout << "letras: " << bloque << "\n" << endl;
    ZZ bloqueZZ;
    bloqueZZ=0;

    string aux;

    for(bloque;bloque.size()>0;){
        bool verify_bloque=true;
        while(verify_bloque)
        {
            if(bloqueZZ<N && aux.size()<=tamN && bloque.size()!=0)
            {
                aux+=bloque.substr(0,3);
                bloqueZZ=convStoZZ(aux);
                aux=convZZtoS(bloqueZZ);
                if(bloqueZZ< N && aux.size()<=tamN)
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
        x=expomod(bloqueZZ,publica,Nn);

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
        bloques_Ntam+=TextoC.substr(0,tamN);
        bloqueZZ=convStoZZ(bloques_Ntam);
        TextoC.erase(0,tamN);
        x=restochino(bloqueZZ);
        string x_str=convZZtoS(x);
        int tamx;
        tamx=x_str.size();

        if(tamx%3!=0){
            bloque_L+='0';
            bloque_L+=convZZtoS(x);
        }
        else{
            bloque_L+=convZZtoS(x);
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
    string Num_str=convZZtoS(num);
    int tamNum;
    tamNum=Num_str.size();
    int diferencia=tamN-tamNum;
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
    ZZ descompP=mod(clavPrivada,P-1);
    ZZ descompQ=mod(clavPrivada,Q-1);
    ZZ M1,M2;
    M1=N/P;
    M2=N/Q;
    ZZ M1inv,M2inv;
    M1inv=euclidesEx(M1,P);
    M2inv=euclidesEx(M2,Q);
    ZZ Tp,Tq;
    Tp=mod(T,P);
    Tq=mod(T,Q);
    ZZ Mp,Mq;
    Mp=expomod(Tp,descompP,P);
    Mq=expomod(Tq,descompQ,Q);
    ZZ x1,x2;
    x1=mod((Mp*M1inv*M1),N);
    x2=mod((Mq*M2inv*M2),N);
    return mod((x1+x2),N);

}

ZZ RSA::ferman(ZZ a,ZZ m){
      if (euclides(a, m) != 1) {
        cout << "no tiene inverso";
    }
    else {
        return expomod(a,m-2,m);
    }

}

ZZ RSA::fermat_peque(ZZ pos,ZZ e,ZZ p){
    if(PrimeTest(p,10)&& euclides(pos,p)==1){
        if((p-1) == e)
            return to_ZZ(1);
        if(p<e){
            return expomod(pos,e,p);
        }
    }
}

////////////////////primo//////////////////////////////////////////////

void RSA::prime(int cor,int cor2,int n){
    srand__( mp3(cor) );
    for(int i=0; i<n; i++ ){
        //cout<<(_rand_()<<123)<<endl;
        num.push_back(_rand_()<<cor2);
        srand__( _rand_());

    }
}

ZZ RSA::primo(ZZ num){
    ZZ uno;
    uno = num;
    while(!PrimeTest(uno,10)){
        uno+=1;
    }
    //cout<<uno<<endl;
    return uno;
}

ZZ RSA::gene_prime(int n_primos,int pos){
    prime(43,23,n_primos);
    return primo(num[pos]);
}






