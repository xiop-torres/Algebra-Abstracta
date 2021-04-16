#include <iostream>

using namespace std ;

int diventeros(int a , int n){
    int r ;
    if (r >=0 ){
        int q=a/n; // a = q * n + r  -> a-(q*n) = r
        r = a - (q * n) ;
        return r ;
        cout << q ;
    }
    else {
        cout <<"salenegativo";
    }
}
int main(){
    int a,n ;
    cout<< " Ingrese a : " ,
    cin>> a;
    cout<< " Ingrese n : " ,
    cin>> n;
    cout << " El residuo es : " <<  diventeros(a,n);
    return 0 ;
}