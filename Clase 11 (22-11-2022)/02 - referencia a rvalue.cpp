// https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe
#include <iostream>
#include <utility> //Para std::move

//Con la referencia a rvalue ya se puede hacer esto con una constante
void f(int&& a) {
   a += 1;
}

int main( ) {
   f(5);
   /*
   //Ya no compilará debido al && de la función :0
      int a = 5;
      f(a);
      std::cout << a;

   //Pero mediante un cast, ya se podría pasar un lvalue a rvalue
      //Lo siquiente equivale a usar std::move
      int a = 5;
      f(static_cast<int&&>(a));
      std::cout << a;
   */


   int a = 5;
   f(std::move(a));
   std::cout << a;

}
