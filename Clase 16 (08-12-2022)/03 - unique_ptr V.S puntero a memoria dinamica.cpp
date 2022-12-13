#include <iostream>
#include <memory>

struct ejemplo {
   ejemplo( ) {
      std::cout << "constructor\n";
   }
   ~ejemplo( ) {
      std::cout << "destructor\n";
   }
};

void k( ) {
   std::unique_ptr<ejemplo> p(new ejemplo);
   std::unique_ptr<ejemplo[]> q(new ejemplo[3]);
}

void h( ) {
   std::unique_ptr<ejemplo> p(new ejemplo( )); //Invocar� a los destructores y ya no habr� fuga de memoria
}

//Cuidado al pedir arreglos con std::unique_ptr, no olvidar el []
void g( ) {
   std::unique_ptr<ejemplo[]> p(new ejemplo[5]);
}

void f( ) {
   ejemplo* p = new ejemplo( );
   delete p; //Sin este habr�a fuga de memoria!

   /*
   ejemplo* p = new ejemplo[2];
   delete[] p;
   */
}

int main( ) {
   /*
   f( );
   f( );
   f( );
   */

   //g();

   /*
   h( );
   h( );
   h( );
   */

   k();
}
