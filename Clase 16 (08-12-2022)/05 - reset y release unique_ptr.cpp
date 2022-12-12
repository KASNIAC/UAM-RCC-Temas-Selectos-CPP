#include <iostream>
#include <memory>
#include <utility>

struct ejemplo {
   ejemplo( ) {
      std::cout << "constructor\n";
   }
   ~ejemplo( ) {
      std::cout << "destructor\n";
   }
};

void g( ) {
   std::unique_ptr<ejemplo> p(new ejemplo);

   //--------------------------.reset()-------------------------------------------
   //Ok, ya me cayó gordo el otro, lo mato y ahora apunto a uno nuevo
   //p.reset(new ejemplo);
      //p.reset( );  //No construyo uno nuevo, solo lo mato porque me cayó gordo.


   //-----------------------Evitar usar .release()--------------------------------
   ejemplo* q = p.release( );
   delete q; //Damelo hermanito, yo lo borro por tí (alguna librería podría llegar a usarlo).
}

int main( ) {
   std::unique_ptr<int> p(new int);
   std::unique_ptr<int> q = std::move(p);

   g( );
   g( );
}
