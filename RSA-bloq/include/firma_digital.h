#ifndef FIRMA_DIGITAL_H
#define FIRMA_DIGITAL_H


class firma_digital
{
    private:
        ZZ p,q,n,fn,d,e;
        ZZ e_Clavepublica;
        ZZ n_Clavepublica;

        ZZ dp,dq,P1,P2,q1,q2;
    public:
		string alfabeto ="abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        long long sizeAlfabeto = alfabeto.size();
        FirmaDigital();
        FirmaDigital(ZZ,ZZ,ZZ,ZZ);
        void generarClaves(int);

};

#endif // FIRMA_DIGITAL_H
