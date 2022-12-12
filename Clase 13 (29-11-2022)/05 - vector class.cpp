#include <algorithm>
#include <iostream>

class vector {
   int* mem;
   int tam, cap;

public:
   vector( )        // constructor delegador
   : vector(0) {
   }

   vector(int n)
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
         int* temp = new int[v.tam];
         delete[] mem;
         mem = temp, tam = v.tam, cap = v.tam;
         for (int i = 0; i < v.tam; ++i) {
            mem[i] = v.mem[i];
         }
      }
   }

   void operator=(vector&& v) {
      if (this != &v) {
         delete[] mem;
         mem = v.mem, tam = v.tam, cap = v.cap;
         v.mem = nullptr, v.tam = 0, v.cap = 0;
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
};

void imprime(const vector& v) {
   for (int i = 0; i < v.size( ); ++i) {
      std::cout << v[i] << " ";
   }
   std::cout << "\n";
}

int main( ) {
//PRUEBA 1
   vector v1;        // vacío
   vector v2(5);     // cinco ints que valen 0
   vector v3(5, 7);  // cinco ints que valen 7

   imprime(v1);
   imprime(v2);
   imprime(v3);
   vector v4 = v3;
   v4[0] = -8;
   imprime(v3);
   imprime(v4);
   vector v5 = std::move(v3);
   imprime(v3);
   imprime(v5);

   for (int i = 0; i < 15; ++i) {
      v5.push_back(i);
   }
   imprime(v5);
}
