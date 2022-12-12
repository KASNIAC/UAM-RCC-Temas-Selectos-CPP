#include <iostream>
#include <memory>
#include <utility>

struct ejemplo {
   ejemplo( ) {
      std::cout << "constructor por defecto\n";
   }
   ejemplo(const ejemplo& e) {
      std::cout << "constructor por copia\n";
   }
   ejemplo(ejemplo&& e) {
      std::cout << "constructor por movimiento\n";
   }
};

//Pq la otra no jalaba? :(

template<typename T, typename... P>
std::unique_ptr<T> crea_unico(P&&... params) {
   return std::unique_ptr<T>(new T(std::forward<P>(params)...));
}


int main( ) {
   ejemplo a;
   //ejemplo b(a);
   //ejemplo c(std::move(a));
      //   new ejemplo(a);
      //   new ejemplo(std::move(a));

   crea_unico<ejemplo>(a);
   crea_unico<ejemplo>(std::move(a));
}
