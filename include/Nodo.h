#ifndef NODO_H
#define NODO_H
#include <cstdlib>

class Nodo {
private:
   int dato;
   Nodo *izdo;
   Nodo *dcho;
   int fe;
public:
   Nodo(int valor) {
      dato = valor;
      izdo = dcho = NULL;
      fe = 0;
   }

   Nodo(Nodo* ramaIzdo, int valor, Nodo* ramaDcho) {
      dato = valor;
      izdo = ramaIzdo;
      dcho = ramaDcho;
      fe = 0;
   }

   Nodo(int valor,int vfe) {
      dato = valor;
      izdo = dcho = NULL;
      fe = vfe;
   }

   Nodo(Nodo* ramaIzdo, int vfe , int valor, Nodo* ramaDcho){
      dato = valor;
      izdo = ramaIzdo;
      dcho = ramaDcho;
      fe = vfe;
   }

   int valorNodo(){ return dato; }
   Nodo* hijoIzdo(){ return izdo; }
   Nodo* hijoDcho(){ return dcho; }

   void nuevoValor(int d){ dato = d; }
   void ramaIzdo(Nodo* n){ izdo = n; }
   void ramaDcho(Nodo* n){ dcho = n; }

   void Pfe(int vfe) { fe = vfe;}
   int Ofe(){ return fe;}
};
#endif // NODO_H
