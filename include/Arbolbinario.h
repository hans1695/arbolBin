#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"
#include <iostream>

using namespace std;

class Arbolbinario {
public:
   Arbolbinario() { raiz = NULL;}
   Arbolbinario(Nodo *r){raiz = r;}
   virtual ~Arbolbinario();
   void imprimir() {imprimir(raiz); cout<<endl;}
   Nodo* buscar(int elemento) {return buscar(raiz,elemento);}
   virtual void insertar(int elemento) {raiz = insertar(raiz,elemento);}
   virtual void eliminar(int elemento) {raiz = eliminar(raiz,elemento);}

   void Praiz( Nodo *r) {raiz = r;}
   Nodo * Oraiz(){return raiz;}
   Nodo raizArbol(){
      if(raiz)return *raiz;
      else throw "arbol vacio";
   }

   bool esVacio() {return raiz == NULL;}

   Nodo* hijoIzdo() {
      if(raiz) return raiz->hijoIzdo();
      else throw "arbol vacio";
   }

   Nodo* hijoDcho() {
      if(raiz) return raiz->hijoDcho();
      else throw "arbol vacio";
   }

   Nodo* nuevoArbol(Nodo* ramaIzqda, int dato, Nodo* ramaDrcha) {
      return new Nodo(ramaIzqda, dato, ramaDrcha);
   }
private:
   void imprimir(Nodo*);
   Nodo* buscar(Nodo *r,int elemento);
   Nodo* insertar(Nodo *r,int elemento);
   Nodo* eliminar(Nodo *r,int elemento);
   Nodo* reemplazar(Nodo *r);
   void destroy(Nodo *r);
   Nodo *raiz;
};
#endif // ARBOLBINARIO_H
