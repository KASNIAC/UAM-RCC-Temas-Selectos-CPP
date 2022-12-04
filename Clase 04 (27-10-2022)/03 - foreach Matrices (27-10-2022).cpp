#include <iostream>


int main( ) {
   int a[4][2] = {
      { 1, 2 },
      { 3, 4 },
      { 5, 6 },
      { 7, 8 }
   };
   for (auto [n1, n2] : a) {
      std::cout << n1 << " " << n2 << "\n";
   }
}

/*
#include <iostream>
#include <vector>

int main( ) {
   for (std::vector<int> v = { 1, 2, 3 }; int actual : v) {
      std::cout << actual << " ";
   }
}
*/
