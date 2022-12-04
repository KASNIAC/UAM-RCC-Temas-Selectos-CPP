#include <iostream>
#include <type_traits>
#include <utility>

template<typename T>
std::common_type_t<T, decltype(std::declval<T>( ) + 0LL)>
f(T n) {
   if (n > 2) {
      return n;
   } else {
      return n + 8LL;
   }
}

int main( ) {
   std::cout << f(5);
}
