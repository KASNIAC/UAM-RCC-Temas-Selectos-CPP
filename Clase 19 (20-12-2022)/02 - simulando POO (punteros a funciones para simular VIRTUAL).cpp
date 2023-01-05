#include <iostream>

template<typename T>
using tipo = T;

tipo<void(*)( )> vtbl_base[3];
tipo<void(*)( )> vtbl_derivado[3];

struct base {
   tipo<void(*)( )>* vtbl;
   int n1;

   base( )
   : vtbl(&vtbl_base[0]) {
   }

   base(tipo<void(*)( )>* p)
   : vtbl(p) {
   }

   void f( ) {
      vtbl[0]( );
   }

   void g( ) {
      vtbl[1]( );
   }

   void h( ) {
      vtbl[2]( );
   }

   static void f_impl( ) {
      std::cout << "f de base\n";
   }

   static void g_impl( ) {
      std::cout << "g de base\n";
   }

   static void h_impl( ) {
      std::cout << "h de base\n";
   }
};

struct derivado : base {
   int n2;

   derivado( )
   : base(&vtbl_derivado[0]) {
   }

   static void f_impl( ) {
      std::cout << "f de derivado\n";
   }

   static void g_impl( ) {
      std::cout << "g de derivado\n";
   }

   static void h_impl( ) {
      std::cout << "h de derivado\n";
   }
};

int main( ) {
   vtbl_base[0] = &base::f_impl;
   vtbl_base[1] = &base::g_impl;
   vtbl_base[2] = &base::h_impl;
   vtbl_derivado[0] = &derivado::f_impl;
   vtbl_derivado[1] = &derivado::g_impl;
   vtbl_derivado[2] = &derivado::h_impl;

   std::cout << sizeof(base) << " "
             << sizeof(derivado) << "\n";

   derivado d;
   base* p = &d;
   p->f( );
   p->g( );
   p->h( );
}
