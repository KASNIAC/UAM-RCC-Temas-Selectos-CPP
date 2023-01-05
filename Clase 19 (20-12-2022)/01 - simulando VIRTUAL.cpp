#include <iostream>

template<typename T>
using tipo = T;

struct base {
   tipo<void(*)( )> pf; //void(*pf)( ) ; //<- Notacion fea
   tipo<void(*)( )> pg;
   int n1;

   base( )
   : pf(&base::f_impl),
     pg(&base::g_impl) {
   }

   base(tipo<void(*)( )> ppf,
        tipo<void(*)( )> ppg)
   : pf(ppf), pg(ppg) {
   }

   void f( ) {
      pf( );
   }

   void g( ) {
      pg( );
   }

   static void f_impl( ) {
      std::cout << "f de base";
   }

   static void g_impl( ) {
      std::cout << "g de base";
   }
};

struct derivado : base {
   int n2;

   derivado( )
   : base(&derivado::f_impl,
          &derivado::g_impl) {
   }

   static void f_impl( ) {
      std::cout << "f de derivado\n";
   }

   static void g_impl( ) {
      std::cout << "g de derivado";
   }
};

int main( ) {
   std::cout << sizeof(base) << " "
             << sizeof(derivado) << "\n";

   derivado d;
   base* p = &d;
   p->f( );
   p->g( );
}

