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
    cin >> Nfil  ; // ingresa fila 
    cout << "Ingresar el nro de columnas : " ;
    cin >> Ncol  ; //ingrresa columna

    tam=mensaje.length(); //tamaño del string
    
    //cuando la diviion no sea exactadebe suma al nro de columa +1
    if(tam % Nfil > 0){
        Ncol++;
    }
    char matriz[Nfil][Ncol]; //creando matriz

    relleno= Ncol*Nfil -tam;
    
    mensaje.insert(tam, relleno , 'x');
    //==
    /*for(int =0 ; i < relleno ; i++){ 
        mensaje+="x" ;
    }*/
    for(int fil=0 ;fil <Nfil ; fil++){ // for para mover para las filas
        for(int col =0 ;col<Ncol; col++){ // para las columnas
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


