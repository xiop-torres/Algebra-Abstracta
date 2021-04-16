//strtok 
#include <stdio.h>
#include <string.h>

using namespace std;
int main ()
{
  char str[]="-Este.es,un;texto. ";
  char * pch;
  printf ("Divide objeto en tokens : \n",str);
  pch = strtok (str," ,.-;");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-;");
  }
    /*string texto;
    cout << "Ingrese una linea de texto : ";
    getline(cin,texto);

    
    size_t position= texto.find(".");
    while(position!=string::npos){
        texto.replace(position,1," ");
        position=texto.find(".",position+1);
    }
    cout << texto;
*/
  return 0;
}