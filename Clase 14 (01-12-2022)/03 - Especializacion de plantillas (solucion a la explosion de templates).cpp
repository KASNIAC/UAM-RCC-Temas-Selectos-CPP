#include <algorithm>
#include <iostream>
#include <new>
#include <string>
#include <type_traits>

//----------------------------Plantilla General para T-------------------------
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
         new(this) vector(std::move(v));
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

//-----------------------------Especialización total para void*---------------------
template<>
class vector<void*> {
   void** mem;
   int tam, cap;

public:
   vector( )        // constructor delegador
   : vector(0) {
   }

   vector(int n)
   : vector(n, nullptr) {
   }

   vector(int n, void* v)
   : mem(new void*[n]), tam(n), cap(n) {
      for (int i = 0; i < n; ++i) {
         mem[i] = v;
      }
   }

   vector(const vector& v)
   : mem(new void*[v.tam]), tam(v.tam), cap(v.tam) {
      for (int i = 0; i < tam; ++i) {
         mem[i] = v.mem[i];
      }
   }

   vector(vector&& v)
   : mem(v.mem), tam(v.tam), cap(v.cap) {
      v.mem = nullptr, v.tam = 0, v.cap = 0;
   }

   ~vector( ) {
      std::cout << "en la especializacion de void*\n";
      delete[] mem;
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
         new(this) vector(std::move(v));
      }
   }

   int size( ) const {
      return tam;
   }

   void*& operator[](int i) {
      return mem[i];
   }

   void* const& operator[](int i) const {
      return mem[i];
   }

   void push_back(void* v) {
      if (tam == cap) {
         int ncap = std::max(1, 2 * cap);
         auto temp = new void*[ncap];
         for (int i = 0; i < tam; ++i) {
            temp[i] = mem[i];
         }
         delete[] mem;
         mem = temp, cap = ncap;
      }
      mem[tam++] = v;
   }
};

//---------------------------Especialización parcial para T*--------------------------
template<typename T>
class vector<T*> {
   vector<void*> v;

public:
   vector(auto... p)
   : v(p...) {
   }

   vector(const vector&) = default;
   vector(vector&&) = default;

   int size( ) const {
      return v.tam;
   }

   T*& operator[](int i) {
      return (T*&)v.mem[i];
   }

   T* const& operator[](int i) const {
      return (T* const&)v.mem[i];
   }

   void push_back(T* p) {
      v.push_back(p);
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
   vector<int> v1;
   vector<char*> v2;
   vector<void*> v3;
}
