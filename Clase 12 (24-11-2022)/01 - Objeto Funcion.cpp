// https://en.cppreference.com/w/cpp/language/operators
#include <algorithm>
#include <functional>
   // std::less       objeto funci�n que ejecuta <
   // std::greater    objeto funci�n que ejecuta >
   // std::less_than  objeto funci�n que ejecuta <=
   // etc...
#include <iostream>
                                      // predicado = funci�n que devuelve verdadero o falso
void bubblesort(int* ini, int* fin, auto pred) {
   int pasadas = (fin - ini) - 1;
   for (int i = 0; i < pasadas; ++i) {
      for (int* p = ini + 1; p < fin; ++p) {
         if (pred(*(p - 1), *p) == false) {
            std::swap(*(p - 1), *p);
         }
      }
   }
}

// objeto funci�n: struct que se hace pasar por funci�n, lo podr�amos usar en lugar de los declarados en #include <functional>
struct primero_menor {
   bool operator()(const auto& a, const auto& b) {
      return a < b;
   }
};

int main( ) {
   std::greater v;
   std::cout << v(1, 2) << "\n";
   std::cout << v(5, 3) << "\n";

   int arr[] = { 3, 1, 4, 8, 2, 5 };
   bubblesort(&arr[0], &arr[0] + 6, v); //bubblesort(&arr[0], &arr[0] + 6, primero_menor());

   for (int actual : arr) {
      std::cout << actual << " ";
   }
}
