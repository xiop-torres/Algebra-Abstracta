#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    int i,j;
    //int N=100;
    int n=100;
    vector <bool> esPrimo(n,true);
    //bool esPrimo[n]; //tabala q indica si un numero es primo
    for(i=0 ;i <n; i++){
        esPrimo[i]=true;
    }
    for(i=2;i <n ;i++){
        if (esPrimo[i]){
            // multiplos no va
            //i*2 ,i*3 ,i*4
            for(j =2 ; i*j <n ; j++){
                esPrimo[i*j] =false;
            }
        }
    }
    ofstream archivo("primos.txt");
    for(i=2; i <n;i++){
        if(esPrimo[i]){
            archivo << i << endl;
        }
    }
    cout << endl;
    return 0;
}