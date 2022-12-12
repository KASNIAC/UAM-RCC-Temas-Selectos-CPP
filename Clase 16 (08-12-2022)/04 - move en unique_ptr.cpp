#include <iostream>
#include <memory>
#include <utility>

int main( ) {
   std::unique_ptr<int> p(new int);
   //std::unique_ptr<int> q = p; //imposible.thanos.jpg
   std::unique_ptr<int> q = std::move(p); //Sí compila, deja a p apuntando a nulo

   if(p == nullptr){
      std::cout<<"ok";
   }
}
