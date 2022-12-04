#include <iostream>

auto suma1(auto... param) {
   return (0 + ... + param);
}


auto suma2( ) {
   return 0;
}
auto suma2(auto p1, auto... ps) {
   return p1 + suma2(ps...);
}


auto suma3(auto p1, auto... ps) {
   if constexpr(sizeof...(ps) == 0) { //No compila si no tiene el constexpr
      return p1;
   } else {
      return p1 + suma3(ps...);
   }
}

int main( ) {
   std::cout << suma1(1, 2, 3, 4, 5) << "\n";
   std::cout << suma2(1, 2, 3, 4, 5) << "\n";
   std::cout << suma3(1, 2, 3, 4, 5) << "\n";
}
