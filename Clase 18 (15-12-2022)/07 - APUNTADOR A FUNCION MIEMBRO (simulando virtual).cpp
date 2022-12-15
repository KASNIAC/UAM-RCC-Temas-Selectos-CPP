#include <iostream>

template<typename R, typename T, typename... P>
using mem_fptr = R(T::*)(P...);

template<typename R, typename... P>
using fptr = R(*)(P...);

struct base {
   mem_fptr<void, base> pf;
   int n1;

   base( )
   : pf(&base::f_impl) {
   }

   base(mem_fptr<void, base> p)
   : pf(p) {
   }

   void f( ) {
      (this->*pf)( );
   }

   void f_impl( ) {
      std::cout << "base::f\n";
   }
};

struct derivado : base {
   int n2;

   derivado( )
   : base(static_cast<mem_fptr<void, base>>(&derivado::f_impl)) {
   }

   void f_impl( ) {
      std::cout << "derivado::f\n";
   }
};

int main( ) {
   std::cout << sizeof(mem_fptr<void, base>) << "\n";

   std::cout << sizeof(base) << " "
             << sizeof(derivado) << "\n";

   derivado d;
   base* p = &d;
   p->f( );
}
