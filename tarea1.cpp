#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
int main(){
    string mensaje, cifrado= "" ; 
    int Ncol;
    int Nfil; 
    int tam;
    int k=0 , relleno;
    cout<< "Ingresar mensaje : " ;
    getline(cin,mensaje);

    cout << "Ingresar el nro de filas : " ;
    cin >> Nfil  ;

    tam=mensaje.length();
    Ncol = tam / Nfil;

    if(tam % Nfil > 0){
        Ncol++;
    }
    char matriz[Nfil][Ncol];

    relleno= Ncol*Nfil -tam;
    
    mensaje.insert(tam, relleno , 'x');
    //==
    /*for(int =0 ; i < relleno ; i++){ 
        mensaje+="x" ;
    }*/
    for(int fil=0 ;fil <Nfil ; fil++){
        for(int col =0 ;col<Ncol; col++){
            matriz[fil][col]= mensaje[k];
            k++;
            cout << matriz[fil][col] << " " ;
        }
        cout << endl ;
    }

    //imprime el mensaje codificado

    for(int col=0 ;col <Ncol ; col++)
    {
        for(int fil=0;fil<Nfil ;fil++){
            cifrado+=matriz[fil][col];
        }
    }

    cout << " El texto cifrado es : " << cifrado << endl;
    return 0;
}