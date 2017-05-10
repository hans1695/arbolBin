#include "ArbolBin.h"

ArbolBin::~ArbolBin()
{
   destroy(raiz);
}

void ArbolBin::destroy(Nodo *n) {
   if(n != NULL){
      destroy(n->hIzq);
      destroy(n->hDer);
      delete n;
   }
}

bool ArbolBin::agregar(Nodo *&root,int a){
   if(root != NULL){
      if(root->valor == a){
         return false;
      } else if(a < root->valor){
         return agregar(root->hIzq,a);
      } else {
         return agregar(root->hDer,a);
      }
   } else {
      root = new Nodo(a);
      return true;
   }
}

void ArbolBin::print(Nodo *root){
   if(root != NULL){
      print(root->hIzq);
      cout<<root->valor<<" "<<((root->hDer!=NULL)?root->hDer->valor:-1)<<" "<<((root->hIzq!=NULL)?root->hIzq->valor:-1)<<endl;
      print(root->hDer);
   }
}

/*ArbolBin::Nodo* ArbolBin::buscar(Nodo *root,int a){
   if(root != NULL){
      if(root->valor == a){
         return root;
      } else if(a < root->valor) {
         return buscar(root->hIzq,root,a);
      } else {
         return buscar(root->hDer,root,a);
      }
   } else {
      return NULL;
   }
}*/

ArbolBin::Nodo* ArbolBin::eliminar(Nodo *&root,int a){
   if(root != NULL){
      if(root -> valor == a){
         if(root->hDer == NULL && root->hIzq == NULL){
            return eliminar0(root);
         } else if((root->hDer == NULL && root->hIzq != NULL) || (root->hIzq == NULL && root->hDer != NULL)){
            return eliminar1(root);
         } else {
            return eliminar2(root);
         }
      } else if(a < root->valor) {
         root->hIzq = eliminar(root->hIzq,a);
         return root;
      } else {
         root->hDer = eliminar(root->hDer,a);
         return root;
      }
   } else {
      return root;
   }
}

ArbolBin::Nodo* ArbolBin::eliminar0(Nodo *&root){
   delete root;
   return NULL;
}

ArbolBin::Nodo* ArbolBin::eliminar1(Nodo *&root){
   Nodo *n;
   if(root->hIzq != NULL)
      n = root->hIzq;
   else
      n = root->hDer;
   delete root;
   return n;
}

ArbolBin::Nodo* ArbolBin::eliminar2(Nodo *&root){
   Nodo *mm = mayorMenores(root);
   root->valor = mm->valor;
   delete mm;
   return root;
}

ArbolBin::Nodo* ArbolBin::mayorMenores(Nodo *&n){
    Nodo *p = n->hIzq,*padre = NULL;
    while(p->hDer != NULL){
        padre = p;
        p = p->hDer;
    }
    if(padre == NULL)
        n->hIzq = p->hIzq;
    else
        padre->hDer = p->hIzq;
    return p;
}

/*template <class T>
void ArbolBin::cale(T a){
   Nodo *n = buscar(raiz,a);
   cout<<n->valor<<" "<<n->hIzq->valor<<" "<<n->hDer->valor<<endl;
}*/
