#include <algorithm>
#include <iostream>
#include <new>
#include <string>
#include <type_traits>

template<typename T>
class vector {
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
   : mem((T*)operator new(sizeof(T) * n)), tam(n), cap(n) {
      for (int i = 0; i < n; ++i) {
         new(&mem[i]) T(v);   // placement new
      }
   }

   vector(const vector& v)
   : mem((T*)operator new(sizeof(T) * v.tam)), tam(v.tam), cap(v.tam) {
      for (int i = 0; i < tam; ++i) {
         new(&mem[i]) T(v.mem[i]);   // placement new
      }
   }

   vector(vector&& v)
   : mem(v.mem), tam(v.tam), cap(v.cap) {
      v.mem = nullptr, v.tam = 0, v.cap = 0;
   }

   ~vector( ) {
      for (int i = 0; i < tam; ++i) {
         mem[i].~T( );
      }
      operator delete(mem);
   }

   void operator=(const vector& v) {
      if (this != &v) {
         vector temp(v);
         this->~vector( );
         new(this) vector(std::move(temp));
      }
   }

   void operator=(vector&& v) {
      if (this != &v) {
         this->~vector( );
         new (this) vector(std::move(v));
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
         T* temp = (T*)operator new(sizeof(T) * ncap);
         for (int i = 0; i < tam; ++i) {
            new (&temp[i]) T(std::move(mem[i]));
            mem[i].~T( );
         }
         operator delete(mem);
         mem = temp, cap = ncap;
      }
      new (&mem[tam++]) T(std::move(v));
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
   vector<std::string> v1;
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
   std::cout << "----\n";
}
