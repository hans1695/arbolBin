#include "ArbolAVL.h"

Nodo* ArbolAVL::rotacionII(Nodo *n, Nodo *n1) {
   n->ramaIzdo(n1->hijoDcho());
   n1->ramaDcho(n);

   if(n1->Ofe() == -1) {
      n->Pfe(0);
      n1->Pfe(0);
   } else {
      n->Pfe(-1);
      n1->Pfe(1);
   }
   return n1;
}

Nodo* ArbolAVL::rotacionDD(Nodo *n, Nodo *n1) {
   n->ramaDcho(n1->hijoIzdo());
   n1->ramaIzdo(n);

   if (n1->Ofe() == +1) {
      n->Pfe(0);
      n1->Pfe(0);
   }else {
      n->Pfe(+1);
      n1->Pfe(-1);
   }
   return n1
}

Nodo* ArbolAVL::rotacionDI(Nodo *n, Nodo *n1) {
   Nodo *n2 = n1->hijoIzdo();
   n->ramaDcho(n2->hijoIzdo());
   n2->ramaIzdo(n);
   n1->ramaIzdo(n2->hijoDcho());
   n2->ramaDcho(n1);

   if (n2->Ofe() == +1)
      n->Pfe(-1);
   else
      n->Pfe(0);

   if (n2->Ofe() == -1)
      n1->Pfe(+1);
   else
      n1->Pfe(0);
   n2->Pfe(0);
   return n2;
}

Nodo* ArbolAVL::rotacionID(Nodo *n, Nodo *n1) {
   Nodo *n2 = n1->hijoDcho();
   n->ramaIzdo(n2->hijoDcho());
   n2->ramaDcho(n);
   n1->ramaDcho(n2->hijoIzdo());
   n2->ramaIzdo(n1);
   if (n2->Ofe() == +1)
      n1->Pfe(-1);
   else
      n1->Pfe(0);
   if (n2->Ofe() == -1)
      n->Pfe(1);
   else
      n->Pfe(0);
   n2->Pfe(0);
   return n2;
}
