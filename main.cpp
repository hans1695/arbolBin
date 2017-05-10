#include <iostream>
#include "ArbolBin.h"
using namespace std;

int main()
{
   ArbolBin a;
   a.agregar(15);
   a.agregar(7);
   a.agregar(16);
   a.agregar(14);
   a.agregar(17);
   a.agregar(13);
   a.print();
   cout<<endl;
   a.eliminar(20);
   a.print();
   cout<<endl;
   return 0;
}
