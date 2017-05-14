#include <iostream>
#include "Arbolbinario.h"
#include "ArbolAVL.h"
#include <ctime>
using namespace std;

int main() {
   srand(time(NULL));
   ArbolAVL a;
   int n;
   for(int i=0;i<50;i++){
      n = rand()%100 + 1;
      try{
         a.insertar(n);
         cout<<"Se inserto el "<<n<<endl;
      } catch (const char *cad){
         cout<<"No se inserto el "<<n<<endl;
      }
   }
   a.imprimir();

   for(int i=0;i<50;i++){
      n = rand()%100 + 1;
      try{
         a.eliminar(n);
         cout<<"Se elimino el "<<n<<endl;
      } catch (const char *cad){
         cout<<"No se encontro el "<<n<<endl;
      }
   }

   a.imprimir();
   return 0;
}
