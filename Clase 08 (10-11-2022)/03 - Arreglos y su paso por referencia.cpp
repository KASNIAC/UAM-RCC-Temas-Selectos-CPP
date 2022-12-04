#include <iostream>

//int arr[] también compilará porque es equivalente a tomar un apuntador.
void f(int arr[5]) {
   arr[0] = 2;
   std::cout << sizeof(arr) << "\n";
}

int main( ) {
   int arr[5] = { 7, 7, 7, 7, 7 };
   f(arr);
   std::cout << arr[0] << "\n";
   std::cout << sizeof(arr) << "\n";
}


/*
#include <iostream>

struct s{
    int n;
    int arr[];
};

int main( ) {

}
*/
