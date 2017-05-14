#ifndef NODOAVL_H
#define NODOAVL_H
#include "Nodo.h"

class NodoAvl {
private:
   int dato;
   NodoAvl *izdo;
   NodoAvl *dcho;
   int fe;
public:
   NodoAvl(int valor) {
      dato = valor;
      izdo = dcho = NULL;
      fe = 0;
   }
   NodoAvl(int valor, int vfe) {
      dato = valor;
      izdo = dcho = NULL;
      fe = vfe;
   }
   NodoAvl(NodoAvl* ramaIzdo,int valor, NodoAvl* ramaDcho) {
      dato = valor;
      izdo = ramaIzdo;
      dcho = ramaDcho;
      fe = 0;
   }

   NodoAvl(NodoAvl* ramaIzdo, int vfe, int valor,
   NodoAvl* ramaDcho)
   {
   dato = valor;
   izdo = ramaIzdo;
   dcho = ramaDcho;
   fe = vfe;
   }
   // operaciones de acceso
   int valorNodo(){ return dato; }
   NodoAvl* subarbolIzdo(){ return izdo; }
   NodoAvl* subarbolDcho(){ return dcho; }
   void nuevoValor(int d){ dato = d; }
   void ramaIzdo(NodoAvl* n){ izdo = n; }
   void ramaDcho(NodoAvl* n){ dcho = n; }
   void visitar(){ cout << dato << endl;}
   void Pfe(int vfe) { fe = vfe;}
   int Ofe(){ return fe;}
};

#endif // NODOAVL_H
