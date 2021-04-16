#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

int main(){
    string respuesta;
    int w=0;
    const int palabra = 4;

    do{
        const char body[]="o/|\\|/\\";
        string palabras[palabra] = {"BOLIVIA","JAPON","VENEZUELA","CANADA"};
        string xword(palabras[w].length(), 'X');
        string::iterator i, ix =xword.begin(); //ejecuta desde el comienzo

        char letras[26]={'\0'};

        //declarano variables

        int n=0;
        int xcount=xword.length();
        bool found=false;
        bool solved = false ;
        int offset = 0 ;
        int bodycount=0 ;
        bool hung =false;

        
    }
}
