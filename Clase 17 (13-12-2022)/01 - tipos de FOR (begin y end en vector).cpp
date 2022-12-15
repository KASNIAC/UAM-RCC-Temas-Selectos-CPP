#include <algorithm>
#include <iostream>

// arreglo dinámico de enteros
class vector {
   int* mem;
   int tam, cap;

public:
   using tipo_elemento = int;
   using tipo_iterador = int*;

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

int main( ) {
   vector v;
   v.push_back(5);
   v.push_back(7);
   v.push_back(1);
   v.push_back(8);

   //Este for camina sobre los indices
   for (int i = 0; i < v.size( ); ++i) {
      std::cout << v[i] << " ";
   }
   std::cout << "\n";

   //Este for camina sobre los apuntadores
   for (auto p = v.begin( ); p != v.end( ); ++p) {
      std::cout << *p << " ";
   }
   std::cout << "\n";

   for (int actual : v) {
      std::cout << actual << " ";
   }
   std::cout << "\n";
}
