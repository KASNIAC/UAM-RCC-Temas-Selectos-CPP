#include <iostream>

union prueba {
   char arr[4];
   float x;
   int n;
};

int main( ) {
   prueba u;
   u.arr[0] = '@';
   u.arr[1] = '#';
   u.arr[2] = '$';
   u.arr[3] = '?';
   std::cout << u.n << "\n";

   u.n = 23;
   for(int i= 0; i<4; i++){
      std::cout<<u.arr[i]<<"<-\n";
   }

   std::cout << std::hex << u.n << "\n";
   std::cout << u.x;
}

