#include "pila.hpp"
#include <sstream>
void Pila::push(ElementoPila *x){
   lista.push_front(x);
}
ElementoPila* Pila::pop(){
   ElementoPila* x = *lista.begin();
   lista.erase(lista.begin());
   return x;
};
int Pila::top(){
   ElementoPila *x = *lista.begin();
   int y = x->numero();
   return y;     
};
void Pila::muestra(){
   list <ElementoPila*>::reverse_iterator it;
   ElementoPila *x;
   cout << "Pila: ";
   for (it= lista.rbegin(); it != lista.rend(); it++){
      x= *it;
      x->muestra2();
   }
   cout << endl;
};
