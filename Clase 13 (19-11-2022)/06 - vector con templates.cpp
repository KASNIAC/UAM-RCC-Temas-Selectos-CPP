#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
class vector {
   static_assert(std::is_trivially_destructible_v<T>);

   T* mem;
   int tam, cap;

public:
   vector( )        // constructor delegador
   : vector(0) {
   }

   vector(int n)
   : vector(n, T( )) {
   }

   vector(int n, const T& v)
   : mem(new T[n]), tam(n), cap(n) {
      for (int i = 0; i < n; ++i) {
         mem[i] = v;
      }
   }

   vector(const vector& v)
   : mem(new T[v.tam]), tam(v.tam), cap(v.tam) {
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
         T* temp = new T[v.tam];
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

   T& operator[](int i) {
      return mem[i];
   }

   const T& operator[](int i) const {
      return mem[i];
   }

   void push_back(T v) {
      if (tam == cap) {
         int ncap = std::max(1, 2 * cap);
         T* temp = new T[ncap];
         for (int i = 0; i < tam; ++i) {
            temp[i] = mem[i];
         }
         delete[] mem;
         mem = temp, cap = ncap;
      }
      mem[tam++] = std::move(v);
   }
};

template<typename T>
void imprime(const vector<T>& v) {
   for (int i = 0; i < v.size( ); ++i) {
      std::cout << v[i] << " ";
   }
   std::cout << "\n";
}

// guía de deducción
// vector( ) -> vector<int>;

struct s {
   s( ) {
      std::cout << "constructor\n";
   }
   ~s( ) {
      std::cout << "destructor\n";
   }
};

int main( ) {
   vector<int> v;

   /*vector<std::string> v1;
   v1.push_back("hola");
   v1.push_back("como");
   v1.push_back("estan");
   imprime(v1);

   vector<s> v2;
   v2.push_back(s( ));
   v2.push_back(s( ));
   v2.push_back(s( ));
   v2.push_back(s( ));
   v2.push_back(s( ));
   std::cout << "----\n"; */
}
