#include <algorithm>
#include <iostream>
#include <vector>

void genera_fibonacci(int n, auto funcion) {
   int temp[2] = { 0, 1 };
   for (int i = 0; i < std::min(2, n); ++i) {
      funcion(temp[i]);
   }
   for (int i = 2; i < n; ++i) {
      temp[i % 2] = temp[0] + temp[1];
      funcion(temp[i % 2]);
   }
}

void imprime(int n) {
   std::cout << n << "\n";
}

std::vector<int> global;
void guarda(int n) {
   global.push_back(n);
}

int main( ) {
   int n;
   std::cin >> n;

   genera_fibonacci(n, imprime);
   genera_fibonacci(n, guarda);
}
