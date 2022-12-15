#include <iostream>

template<typename R, typename T, typename... P>
using mem_fptr = R(T::*)(P...);

template<typename R, typename... P>
using fptr = R(*)(P...);

struct base {
   fptr<void> pf;
   int n1;

   base( )
   : pf(&base::f_impl) {
   }

   base(fptr<void> p)
   : pf(p) {
   }

   void f( ) {
      pf( );
   }

   static void f_impl( ) {
      std::cout << "base::f\n";
   }
};

struct derivado : base {
   int n2;

   derivado( )
   : base(static_cast<fptr<void>>(&derivado::f_impl)) {
   }

   static void f_impl( ) {
      std::cout << "derivado::f\n";
   }
};

int main( ) {
   std::cout << sizeof(base) << " "
             << sizeof(derivado) << "\n";

   derivado d;
   base* p = &d;
   p->f( );
}
