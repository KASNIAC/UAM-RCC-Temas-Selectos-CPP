#include <iostream>

struct nodo {
   int valor;
   nodo* sig;
   nodo* ant;
};

struct iterador_lista {
   nodo* p;

   explicit iterador_lista(nodo* actual)
   : p(actual) {
   }

   int operator*( ) const {
      return (*p).valor;
   }

   void operator++( ) {
      p = (*p).sig;
   }

   bool operator==(const iterador_lista& otro) const {
      return p == otro.p;
   }
};

struct lista_enlazada {
   nodo fin = { -1, &fin, &fin };

   using tipo_elemento = int;
   using tipo_iterador = iterador_lista;

   void insert(nodo* p, int v) {
      nodo* t = new nodo{ v, p, p->ant };
      p->ant->sig = t;
      p->ant = t;
   }

   void erase(nodo* p) {
      p->ant->sig = p->sig;
      p->sig->ant = p->ant;
      delete p;
   }

   void push_back(int v) {
      insert(end( ).p, v);
   }

   void pop_back( ) {
      erase(end( ).p->ant);
   }

   iterador_lista begin( ) {
      return iterador_lista(fin.sig);
   }

   iterador_lista end( ) {
      return iterador_lista(&fin);
   }
};

int main( ) {
   lista_enlazada li;
   li.push_back(5);
   li.push_back(7);
   li.push_back(8);
   li.push_back(1);

   for (int actual : li) {
      std::cout << actual << " ";
   }
}
