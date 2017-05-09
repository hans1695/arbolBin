#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include <cstdlib>
#include <iostream>
using namespace std;

class ArbolBin
{
private:
   class Nodo {
      friend class ArbolBin;
   private:
      int valor;
      Nodo *hIzq,*hDer;
   public:
      Nodo(int a,Nodo *hi = NULL,Nodo *hd = NULL): valor(a),hIzq(hi), hDer(hd) {}
   };
public:
   ArbolBin(): raiz(NULL) {}
   virtual ~ArbolBin();
   void print() {print(raiz);}
   void agregar(int a) {agregar(raiz,a);}
   void eliminar(int a) {eliminar(raiz,a);}
private:
   void agregar(Nodo *&root,int a);
   void destroy(Nodo *);
   void print(Nodo *);
   Nodo* eliminar(Nodo *&root,int a);
   Nodo* eliminar0(Nodo *&root);
   Nodo* eliminar1(Nodo *&root);
   Nodo* eliminar2(Nodo *&root);
   Nodo* buscar(Nodo *root,int a);
   Nodo *raiz;
};

#endif // ARBOLBIN_H
