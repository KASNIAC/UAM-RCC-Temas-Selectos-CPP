#include <array>
#include <iostream>
#include <vector>

//Tenemos dos funciones que hacen exactamente lo mismo, pero reciben diferentes parámetros.
//ME GUSTARÍA TENER SOLO UNA FUNCION

template<typename T, size_t N>
void imprime(const std::array<T, N>& arr) {
   std::cout<<"Imprimiendo un std::array: ";
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

template<typename T>
void imprime(const std::vector<T>& arr) {
   std::cout<<"Imprimiendo un std::vector: ";
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

template<typename T>
void imprime(const T& arr) {
    std::cout<<"Imprimiendo otra cosa:"; //Si no tengo alguna de las funciones anteriores, caeran aquí
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

int main( ) {
   std::array<int, 5> a = { 1, 2, 3, 4, 5 };
   std::vector<int> v = { 1, 2, 3, 4, 5 };

   imprime(a);
   imprime(v);
}
