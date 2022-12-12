// https://en.cppreference.com/w/cpp/header/type_traits
// https://en.cppreference.com/w/cpp/types/is_pointer
#include <iostream>

template<typename T>
struct es_apuntador {
   static constexpr bool valor = false;
};

template<typename T>
struct es_apuntador<T*> {
   static constexpr bool valor = true;
};

template<typename T>
constexpr bool es_apuntador_v = false;

template<typename T>
constexpr bool es_apuntador_v<T*> = true;

int main( ) {
   std::cout << es_apuntador_v<int> << "\n";
   std::cout << es_apuntador_v<int*> << "\n";
   std::cout << es_apuntador_v<char*> << "\n";
   std::cout << "\n";
   std::cout << es_apuntador<int>::valor << "\n";
   std::cout << es_apuntador<int*>::valor << "\n";
   std::cout << es_apuntador<char*>::valor << "\n";
}

/*
#include <iostream>

template<typename T>
constexpr bool es_apuntador_v = false;

template<typename T>
constexpr bool es_apuntador_v<T*> = true;

template<>
constexpr bool es_apuntador_v<int*> = true;

int main( ) {
   std::cout << es_apuntador_v<int> << "\n";
   std::cout << es_apuntador_v<int*> << "\n";
   std::cout << es_apuntador_v<char*> << "\n";
}

*/
