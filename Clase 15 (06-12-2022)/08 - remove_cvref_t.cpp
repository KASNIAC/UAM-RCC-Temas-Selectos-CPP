#include <array>
#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
void imprime(const T& arr) {
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

template<typename T>
auto suma(const T& arr) {
   //decltype(arr[0]) res = 0; //Esto no jala porque arr[0] devuelve un const T&
   //typename std::remove_cvref<decltype(arr[0])>::type res = 0; //Hay que ayudarle al compilador a decirle que se trata de una declaración :(
   std::remove_cvref_t<decltype(arr[0])> res = 0;
   for (int i = 0; i < arr.size( ); ++i) {
      res += arr[i];
   }
   return res;
}

int main( ) {
   std::array<int, 5> a = { 1, 2, 3, 4, 5 };
   std::vector<int> v = { 1, 2, 3, 4, 5 };

   imprime(a);
   imprime(v);
   std::cout << suma(a) << "\n";
   std::cout << suma(v) << "\n";

   std::vector<double> f = { 3.14, 2.78, 1.23, 9.99 };
   imprime(f);
   std::cout << suma(f) << "\n";
}
