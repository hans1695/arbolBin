#include "Arbolbinario.h"

void Arbolbinario::destroy(Nodo *r){
   if(r != NULL){
      destroy(r->hijoIzdo());
      destroy(r->hijoDcho());
      delete r;
   }
}

Arbolbinario::~Arbolbinario(){
   destroy(raiz);
   raiz = NULL;
}

void Arbolbinario::imprimir(Nodo *r){
   if(r != NULL){
      imprimir(r->hijoIzdo());
      cout<<r->valorNodo()<<" ";
      imprimir(r->hijoDcho());
   }
}

Nodo* Arbolbinario::buscar(Nodo *r, int elemento){
   if(r == NULL)
      return NULL;
   else if(elemento == r->valorNodo())
      return r;
   else if(elemento < raiz->valorNodo())
      return buscar(r->hijoIzdo(),elemento);
   else
      return buscar(r->hijoDcho(),elemento);
}

Nodo* Arbolbinario::insertar(Nodo *r,int elemento){
   if(r == NULL)
      r = new Nodo(elemento);
   else if(elemento < r->valorNodo()){
      Nodo *iz;
      iz = insertar(r->hijoIzdo(),elemento);
      r->ramaIzdo(iz);
   } else if(elemento > r->valorNodo()){
      Nodo *dr;
      dr = insertar(r->hijoDcho(),elemento);
      r->ramaDcho(dr);
   } else
      throw "Nodo repetido...";
   return r;
}

Nodo* Arbolbinario::eliminar(Nodo *r,int elemento){
   if(r == NULL)
      throw "Ese dato no se encuentra en el arbol...";
   else if(elemento < r->valorNodo()){
      Nodo *iz;
      iz = eliminar(r->hijoIzdo(),elemento);
      r->ramaIzdo(iz);
   } else if(elemento > r->valorNodo()){
      Nodo *dr;
      dr = eliminar(r->hijoDcho(),elemento);
      r->ramaDcho(dr);
   } else {
      Nodo *q = r;
      if(q->hijoIzdo() == NULL)
         r = q->hijoDcho();
      else if(q->hijoDcho() == NULL)
         r = q->hijoIzdo();
      else
         q = reemplazar(q);
      delete q;
   }
   return r;
}

Nodo* Arbolbinario::reemplazar(Nodo *r){
   Nodo *a = r->hijoIzdo(),*p = r;
   while(a->hijoDcho() != NULL){
      p = a;
      a = a->hijoDcho();
   }
   r->nuevoValor(a->valorNodo());
   if(p == r)
      p->ramaIzdo(a->hijoIzdo());
   else
      p->ramaDcho(a->hijoIzdo());
   return a;
}
