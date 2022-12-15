#include <iostream>
#include <type_traits>

template<bool B, typename T1, typename T2>
struct selector_tipo;

template<typename T1, typename T2>
struct selector_tipo<true, T1, T2> {
   using tipo = T1;
};

template<typename T1, typename T2>
struct selector_tipo<false, T1, T2> {
   using tipo = T2;
};

/* En caso de existir esto y NO poder el typename habría problemas */
template<>
struct selector_tipo<true, char, char> {
   static int tipo;
};


//Declaramos un alias _t para evitar la notacion ::tipo
template<bool B, typename T1, typename T2>
using selector_tipo_t = typename selector_tipo<B, T1, T2>::tipo;
   //Debemos poner typename para especificar que se trata de un tipo y no de un
      //int, como la especialización del template<>
   //En versiones recientes ya no es necesario el typename



/* Evidencias de que aun hay lugares donde se usa typename:
template<bool B, typename T1, typename T2>
void f( ) {
   typename selector_tipo<B, T1, T2>::tipo a;
}
*/
int main( ) {
   //using tipo = selector_tipo<(2 < 1), int, double>::tipo;
   using tipo = selector_tipo_t<(2 < 1), int, double>;

   //Ya implementado b type_traits
   using ttipo = std::conditional_t<(2 < 1), int, double>;

   tipo n;

   //char* p = &n;  //Sólo para comprobar que funciona
}
