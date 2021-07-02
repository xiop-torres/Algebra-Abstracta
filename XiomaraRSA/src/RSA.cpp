#include "RSA.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

rsa::rsa(int bit){
    this->bit=bit;
    p = 17;
    q = 59;
    n=p*q;
    fi_n=(p-1)*(q-1);
    generar_clave();
    mostrarMenu();
}
rsa::rsa(ZZ e,ZZ N){
    this->n=N;
    this->e_clavePublica=e;
}
rsa::rsa(ZZ p,ZZ q,ZZ d){
    p=p;
    q=q;
    n=p*q;
    fi_n=(p-1)*(q-1);
    d_claveprivada=d;
}
/*
RSA::RSA()
{
    this->e=13;
    this->d=1459;
    this->n=1829;
}*/
string rsa::convertirZZtoString(ZZ number){
    stringstream ss;
    ss<<number;
    string num;
    ss>>num;
    return num;
};
ZZ rsa::convertirStringToZZ(string number){
    stringstream ss;
    ss<<number;
    ZZ input;
    ss>>input;
    return input;
};
void rsa::generar_clave(){
    e_clavePublica=3;
    d_claveprivada=619;
    n = 1003;
};
ZZ rsa::cifradoEnBloques(string mensaje){
    string mensaje_cifrado;
    ZZ mensaje_cifradoZZ;
    ZZ pos ;
    int letras= alfabeto.find(mensaje);
    pos=conv<ZZ>(letras);
    mensaje_cifradoZZ=exponenciacionModular(pos,e_clavePublica,n);
    return mensaje_cifradoZZ;
};
/*
string rsa::decifrado(ZZ mensajeCifrado){
    string mensaje_decifrado_string;
    ZZ mensaje_decifrado;

    mensaje_decifrado_string=alfabeto[modulo(conv<ZZ>(mensaje_decifrado),alfabeto.size())];
    mensaje_decifrado = exponenciacionModular(m_cifrado,d,n);
    return mensaje_decifrado;
}*/
//UNCIONES
ZZ rsa::modulo(ZZ a,ZZ b){
    ZZ q=ZZ(a/b);
	ZZ r=ZZ(a-(q*b));
	if(r<ZZ(0)){
		q=q-1;
		r=r+b;
	}
	return r;
};
ZZ rsa::euclides(ZZ a,ZZ b){
    ZZ t;
    while (b!=0){
        t=b;
        b=modulo(a,b);
        a=t;
    }
    return a;
};
ZZ rsa::exponenciacionModular(ZZ base, ZZ exp, ZZ mod){
    ZZ resultado;
    resultado=1;
    ZZ mod2;
    mod2=2;
    while (exp != 0) {
        if (modulo(exp,mod2)!= 0)
            resultado = modulo((resultado * base) , mod);
        exp = exp/ 2;
        base = modulo((base * base) , mod);
    }
    return resultado;

};
ZZ rsa::euclidesExtendido(ZZ a ,ZZ b){
    ZZ r1=a,r2=b,r=ZZ(0),q=ZZ(0),s=ZZ(0),s1=ZZ(1),s2=ZZ(0);
    ZZ t=ZZ(0),t1=ZZ(0),t2=ZZ(1),arr[3];

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
    ZZ inversa=s1;
    if(s1<0)
        inversa=s1+b;

    return inversa;
};

void rsa::mostrarMenu(){
    string mensaje;
    ZZ e;
    ZZ n;
    string enNumero;
    cout << "E: " ;
    cin>>e;
    cout << endl;
    cout << "N: " ;
    cin>> n;
    rsa receptor(e,n);// para cifrar se necesita clave publica y n del recepto
    cout << "\nMensaje: ";
    cin>> mensaje;

    enNumero = alfabetoToNumeros(mensaje);
    separarToNumeros(enNumero);

    for(int i=0;i<bloques.size();i++){
        cifrados.push_back(receptor.exponenciacionModular(bloques[i],e,n));
    }
    enviar(cifrados);


}
string rsa::alfabetoToNumeros(string mensaje){
    string numero;
    int i;
    for(i=0; i<mensaje.size(); i++){
        string letra = to_string(alfabeto.find(mensaje[i]));
        if(letra.size()!=2) // rellena con 0
            letra='0'+letra;
        numero =numero + letra;
    }
    return numero;
}
void rsa::separarToNumeros(string cadena){ ///0214120407041704
    string N = convertirZZtoString(n); ///1003 a string
    int tam = N.size(); ///lee tam de 1003 = 4

    cout <<cadena<<endl; ///0214120407041704

    for(int i=0; cadena.size()>=tam; i++){
        ZZ tem = convertirStringToZZ(cadena.substr(tam)); ///subcadena de posicion 0 hasta 4
        cout << "tem: " << tem << "   i: " << i<<  endl;
        if(tem < n){
            cadena.erase(0,tam);
            bloques.push_back(tem);
        }

        else{
            tem = convertirStringToZZ(cadena.substr(0,tam-1));
            cadena.erase(0,tam-1);
            bloques.push_back(tem);
        }
        if(cadena.size() < tam){
            tem = convertirStringToZZ(cadena);
            if(tem!=0)
                bloques.push_back(tem);
        }

    }
    for(int i=0; i<bloques.size(); i++){
        cout <<bloques[i]<<" ";
    }
}

string rsa::enviar(vector<ZZ> cifrados){
    string N = convertirZZtoString(n);
    string cifrado_final;
    int tam = N.size();
    for(int i=0; i<cifrados.size(); i++){
        string temp = convertirZZtoString(cifrados[i]);
        while(temp.size()!=tam){
                temp = '0' + temp;
        }
        cout <<"\n"<<temp<<endl;
        cifrado_pos.push_back(temp);
    }

    for(int i=0; i<cifrado_pos.size(); i++){
        //cout <<cifrado_pos[i]<<" ";
        cifrado_final+=cifrado_pos[i];
    }
    cout <<"String final cifrado : "<<cifrado_final<<endl;
}
