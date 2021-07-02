#include "firma_digital.h"

firma_digital::firma_digital()
{
    //ctor
}

firma_Digital::FirmaDigital(ZZ n_ ,ZZ e_ , ZZ d_ , ZZ n)
{
	long long sizeAlfabeto = alfabeto.size();
	this->n = n;
	this->d = d_;
	n_Clavepublica = n_;
	e_Clavepublica = e_;
}
 void firma_digital::generarClaves(int);
