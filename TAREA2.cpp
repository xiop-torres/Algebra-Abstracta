#include<iostream>
#include<string>
using namespace std;

string Cifrado(string mensaje,int key ){ // 
    
    int x;
    x= (key*2)-2;
    for(int i=0; i<=x/2 ; i++){
        for(int j=0 ;j < mensaje.length() ; j++ ){
            if(j%x==i || j%x==x-i )
                cout << mensaje[j];
        }
    }
}
string Descifrado(string textoencrip,int key){
    
}

int main()
{  
    cout << "1. Encriptar\n2. Descencriptar\nChoose(1,2): ";
    int choice;
    cin >> choice; // para elegir
    cin.ignore();

    if (choice == 1){
        cout << endl << "Encryption" << endl;
        cout << Cifrado("helloworld" , 4 );  // ingresa el mensaje y la clave 

    } else if (choice == 2) {
        cout << endl << "Decryption" << endl;
        //cout << Descifrado("")

    } else {
        cout << endl << "Invalid Choice" << endl;
    }

    return 0;

}
