#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "Arbolbinario.h"
#include "NodoAVL.h"

class ArbolAVL: public Arbolbinario {
   public:

   private:
      Nodo* rotacionII(Nodo* n,Nodo *n1);
      Nodo* rotacionDD(Nodo* n,Nodo *n1);
      Nodo* rotacionDI(Nodo* n,Nodo *n1);
      Nodo* rotacionID(Nodo* n,Nodo *n1);
      Nodo* insertar(Nodo *r,int elemento, bool &hc);
};

#endif // ARBOLAVL_H
