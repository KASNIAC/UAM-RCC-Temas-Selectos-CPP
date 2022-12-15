#include <iostream>

struct base {
   void f( ) {
      std::cout << "base::f\n";
   }
};

struct derivado : base {
   void f( ) {
      std::cout << "derivado::f\n";
   }
};

int main( ) {}
   std::cout << sizeof(base) << " " << sizeof(derivado) << "\n"; // 8 8 ¡(Con virtual cambian a 16 y 16)!

   base b;
   //b.f( );
   derivado d;
   //d.f( );
   std::cout << "\n";


   base* p = &b;
   p->f( );

   derivado* q = &d;
   q->f( );

   base* t = &d;
   t->f( ); //Yo no sé aún que es un derivado::f :(
            // actualmente llama a base::f queremos que llame a derivado::f
}
