#include <iostream>

int main(){
   // variable de sólo lectura
   const int a = 5;

   // constante en tiempo de compilación
   constexpr int b = 5;

   int n;
   std::cin >> n;

   const int m = n;       // OK
   constexpr int h = n;   // MAL
}
