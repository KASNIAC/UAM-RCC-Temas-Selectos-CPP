#include <algorithm>
#include <iostream>

// arreglo dinámico de enteros
struct vector {
   int* mem;
   int tam, cap;

   using tipo_elemento = int;
   using tipo_iterador = int*;
   using tipo_const_iterador = const int*;

   vector( )
   : vector(0) {
   }

   explicit vector(int n)
   : vector(n, 0) {
   }

   vector(int n, int v)
   : mem(new int[n]), tam(n), cap(n) {
      for (int i = 0; i < n; ++i) {
         mem[i] = v;
      }
   }

   vector(const vector& v)
   : mem(new int[v.tam]), tam(v.tam), cap(v.tam) {
      for (int i = 0; i < tam; ++i) {
         mem[i] = v.mem[i];
      }
   }

   vector(vector&& v)
   : mem(v.mem), tam(v.tam), cap(v.cap) {
      v.mem = nullptr, v.tam = 0, v.cap = 0;
   }

   ~vector( ) {
      delete[] mem;
   }

   void operator=(const vector& v) {
      if (this != &v) {
         vector temp = v;
         this->~vector( );
         new(this) vector(std::move(temp));
      }
   }

   void operator=(vector&& v) {
      if (this != &v) {
         vector temp = std::move(v);
         this->~vector( );
         new(this) vector(std::move(temp));
      }
   }

   int size( ) const {
      return tam;
   }

   int& operator[](int i) {
      return mem[i];
   }

   const int& operator[](int i) const {
      return mem[i];
   }

   void push_back(int v) {
      if (tam == cap) {
         int ncap = std::max(1, 2 * cap);
         int* temp = new int[ncap];
         for (int i = 0; i < tam; ++i) {
            temp[i] = mem[i];
         }
         delete[] mem;
         mem = temp, cap = ncap;
      }
      mem[tam++] = v;
   }

   int* begin( ) {
      return &mem[0];
   }

   const int* begin( ) const {
      return &mem[0];
   }

   int* end( ) {
      return &mem[0] + tam;
   }

   const int* end( ) const {
      return &mem[0] + tam;
   }
};

// lista enlazada dinámica de enteros
struct lista_enlazada {
   struct nodo {
      int valor;
      nodo* sig;
      nodo* ant;
   };

   template<typename TIPO_NODO>
   struct iterador_lista {
      TIPO_NODO* p;

      explicit iterador_lista(TIPO_NODO* actual)
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

   nodo fin = { -1, &fin, &fin };

   using tipo_elemento = int;
   using tipo_iterador = iterador_lista<nodo>;
   using tipo_iterador_const = iterador_lista<const nodo>;

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

   iterador_lista<nodo> begin( ) {
      return iterador_lista<nodo>(fin.sig);
   }

   iterador_lista<nodo> end( ) {
      return iterador_lista<nodo>(&fin);
   }

   iterador_lista<const nodo> begin( ) const {
      return iterador_lista<const nodo>(fin.sig);
   }

   iterador_lista<const nodo> end( ) const {
      return iterador_lista<const nodo>(&fin);
   }
};

// rango semiabierto de enteros
struct rango_semi {
   struct iterador_entero {
      int valor;

      explicit iterador_entero(int v)
      : valor(v) {
      }

      int operator*( ) const {
         return valor;
      }

      iterador_entero& operator++( ) {
         ++valor;
         return *this;
      }

      iterador_entero operator++(int) {
         auto copia = *this;
         ++valor;
         return copia;
      }

      int operator-(const iterador_entero& otro) {
         return valor - otro.valor;
      }

      bool operator==(const iterador_entero& otro) const {
         return valor == otro.valor;
      }
   };

   iterador_entero ini;
   iterador_entero fin;

   rango_semi(int i, int f)
   : ini(i), fin(f) {
   }

   iterador_entero begin( ) const {
      return ini;
   }

   iterador_entero end( ) const {
      return fin;
   }
};

void imprime(const auto& v) {
   for (auto actual : v) {
      std::cout << actual << " ";
   }
   std::cout << "\n";
}

template<typename T>
concept tiene_resta = requires(T a, T b) {
    { b - a } -> std::convertible_to<int>;
};

template<typename IT>
int distancia(IT it1, IT it2) {
   std::cout << "version general\n";
   int res = 0;
   while (it1 != it2) {
      ++it1;
      ++res;
   }
   return res;
}

template<typename IT> requires (tiene_resta<IT>)
int distancia(IT it1, IT it2) {
   std::cout << "version de resta\n";
   return it2 - it1;
}

int main( ) {
   vector arr;
   arr.push_back(5);
   arr.push_back(7);
   arr.push_back(8);
   arr.push_back(1);

   lista_enlazada li;
   li.push_back(5);
   li.push_back(7);
   li.push_back(8);
   li.push_back(1);

   rango_semi r(0, 4);

   std::cout << distancia(arr.begin( ), arr.end( )) << "\n";
   std::cout << distancia(li.begin( ), li.end( )) << "\n";
   std::cout << distancia(r.begin( ), r.end( )) << "\n";
}
