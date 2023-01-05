#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> genera_fibonacci(int n) {
   std::vector<int> res;

   int temp[2] = { 0, 1 };
   for (int i = 0; i < std::min(2, n); ++i) {
      res.push_back(temp[i]);
   }
   for (int i = 2; i < n; ++i) {
      temp[i % 2] = temp[0] + temp[1];
      res.push_back(temp[i % 2]);
   }
   return res;
}

int main( ) {
   int n;
   std::cin >> n;

   auto v = genera_fibonacci(n);
   for (int valor : v) {
      std::cout << valor << "\n";
   }
}
