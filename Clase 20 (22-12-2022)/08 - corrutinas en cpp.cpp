// https://racc.mx/uam/home/2022-o/tslp/corutina.cpp <- Para escribir corutinas (similar a lo que hace JS)

#include <coroutine>
#include <exception>
#include <iostream>

template<typename T>
struct generador {
   struct promise_type;
   using corutina = std::coroutine_handle<promise_type>;
   struct promise_type {
      T valor;

      generador get_return_object( ) {
         return corutina::from_promise(*this);
      }
      std::suspend_always initial_suspend( ) noexcept {
         return { };
      }
      std::suspend_always final_suspend( ) noexcept {
         return { };
      }
      void unhandled_exception( ) {
         return;
      }
      std::suspend_always yield_value(auto v) {
         valor = std::move(v);
         return { };
      }
      void return_void( ) {
         return;
      }
   };

   corutina ejecutor;
   bool cache;

   generador(corutina m)
   : ejecutor(m), cache(false) {
   }

   ~generador( ) {
      ejecutor.destroy( );
   }

   bool disponible( ) {
      if (!cache) {
         ejecutor( );
         cache = !ejecutor.done( );
      }
      return cache;
   }

   T obten( ) {
      disponible( ), cache = false;
      return std::move(ejecutor.promise( ).valor);
   }
};

generador<uint64_t> fibonacci(int n) {
   uint64_t arr[2] = { 0, 1 };
   for (int i = 0; i < std::min(n, 2); ++i) {
      co_yield arr[i];
   }
   for (int i = 2; i < n; ++i) {
      arr[i % 2] = arr[0] + arr[1];
      co_yield arr[i % 2];
   }
}

int main( ) {
   auto generador = fibonacci(10);
   for (int i = 0; generador.disponible( ); ++i) {
      std::cout << generador.obten( ) << "\n";
   }
}
