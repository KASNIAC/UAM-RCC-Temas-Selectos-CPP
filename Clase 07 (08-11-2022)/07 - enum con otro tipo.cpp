#include <iostream>
#include <stdint.h>

enum dia : int8_t {
   LUN, MAR, MIE, JUE, VIE, SAB, DOM
};

int main( ) {
   dia d = MIE;
   std::cout << sizeof(d)<<"\n";
   std::cout << sizeof(dia)<<"\n";

   //Por omisión ocurren conversione simplicitas entre enumeradores e int:
   std::cout<<LUN + 1<<"\n";
}
