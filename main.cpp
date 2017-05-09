#include <iostream>
#include "ArbolBin.h"
using namespace std;

int main()
{
   ArbolBin a;
   a.agregar(7);
   a.agregar(2);
   a.agregar(11);
   a.agregar(1);
   a.agregar(12);
   a.agregar(3);
   a.agregar(10);
   a.print();
   a.eliminar(3);
   cout<<endl;
   a.print();
   a.agregar(0);
   cout<<endl;
   a.print();
   return 0;
}
