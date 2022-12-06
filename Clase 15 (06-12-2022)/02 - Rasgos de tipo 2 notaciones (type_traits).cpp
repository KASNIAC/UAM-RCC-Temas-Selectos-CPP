// https://en.cppreference.com/w/cpp/header/type_traits
// https://en.cppreference.com/w/cpp/types/is_pointer
#include <iostream>
#include <type_traits>

int main( ) {
   //Dos notaciones diferentes para la misma cosa
   std::cout << std::is_pointer<int>::value << "\n";
   std::cout << std::is_pointer_v<int> << "\n";
   std::cout << "\n";
   std::cout << std::is_pointer<int*>::value << "\n";
   std::cout << std::is_pointer_v<int*> << "\n";
}
