#include <iostream>

template<typename T>
struct remueve_cvref {
   using tipo = T;
};

template<typename T>
struct remueve_cvref<const T&> {
   using tipo = T;
};

template<typename T>
struct remueve_cvref<const T&&> {
   using tipo = T;
};

template<typename T>
struct remueve_cvref<T&> {
   using tipo = T;
};

template<typename T>
struct remueve_cvref<T&&> {
   using tipo = T;
};

template<typename T>
using remueve_cvref_t = remueve_cvref<T>::tipo;

int main( ) {
   remueve_cvref<const int&>::tipo n = 5;
   n = 7;

   remueve_cvref_t<const int&> m = 5;
   m = 7;
}
