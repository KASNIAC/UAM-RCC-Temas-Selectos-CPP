#include <iostream>

//jala porque no depende de nada externo
constexpr int f( ) {
   int res = 0;
   for (int i = 1; i <= 5; ++i) {
      res += i;
   }
   return res;
}

int main( ) {
   int arr[f( )];
}
