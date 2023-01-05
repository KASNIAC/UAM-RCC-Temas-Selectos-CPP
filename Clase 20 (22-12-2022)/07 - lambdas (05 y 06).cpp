#include <algorithm>
#include <iostream>
#include <vector>

void genera(int n, auto funcion) {
   int temp[2] = { 0, 1 };
   for (int i = 0; i < std::min(2, n); ++i) {
      funcion(temp[i]);
   }
   for (int i = 2; i < n; ++i) {
      temp[i % 2] = temp[0] + temp[1];
      funcion(temp[i % 2]);
   }
}

int main( ) {
   auto saluda = []( )->void { //el void es opcional
      std::cout << "hola\n";
   };
   saluda( );
   saluda( );
   saluda( );

   int n;
   std::cin >> n;

   genera(n, [](int n)->void { //el void es opcional
      std::cout << n << "\n";
   }); // retrollamadas (callbacks)

   std::vector<int> res;
   genera(n, [&](int n)->void {
      res.push_back(n);
   });
}
