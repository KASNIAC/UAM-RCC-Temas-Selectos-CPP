#include <array>
#include <initializer_list>
#include <iostream>
#include <vector>

template<typename T>
struct mi_vector {
   T* mem;
   int tam, cap;

   mi_vector(std::initializer_list<T> lista)
   : mem(new T[lista.size( )]), tam(lista.size( )), cap(lista.size( )) {
      int indice = 0;
      for (const auto& actual : lista) {
         mem[indice++] = actual;
      }
   }

   //...
};

int main( ) {
   mi_vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 0 };

   //std::array<int, 5> a = { 1, 2, 3, 4, 5 };
   //std::vector<int> v = { 1, 2, 3, 4, 5 };
}
