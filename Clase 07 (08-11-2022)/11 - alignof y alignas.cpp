#include <iostream>

/*
struct  prueba {
   alignas(8) char  c;
   int n;
};
*/


struct  prueba {
   alignas(8) char  c; //alignof(prueba) vale ahora 8 y no 4
   int n;
};


int main( ) {
   std::cout << sizeof(char) << " "
             << alignof(char) << "\n";

   std::cout << sizeof(int) << " "
             << alignof(int) << "\n";

   std::cout << sizeof(prueba) << " "
             << alignof(prueba) << "\n";
}


