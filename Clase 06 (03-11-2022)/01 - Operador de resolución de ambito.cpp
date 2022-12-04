#include<iostream> 
 
int n = 5; 
int main(){ 
   int n = 7; 
   { 
      int n = 34; 
      std::cout<<::n; 
   } 
}
