#include<iostream>
//https://stackoverflow.com/questions/119123/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member
struct X
{
    short s; /* 2 bytes */
             /* 2 padding bytes */
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 3 padding bytes */
};

struct Y
{
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
    short s; /* 2 bytes */
};

struct Z
{
    int   i; /* 4 bytes */
    short s; /* 2 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
};

int main(){
    const int sizeX = sizeof(struct X); /* = 12 */
    const int sizeY = sizeof(struct Y); /* = 8 */
    const int sizeZ = sizeof(struct Z); /* = 8 */

    std::cout<<"sizeX: "<<sizeX<<"\n";
    std::cout<<"sizeY: "<<sizeY<<"\n";
    std::cout<<"sizeZ: "<<sizeZ<<"\n";
}
/*
struct prueba{
    char c;
    int n;
};

int main(){
    std::cout<<sizeof(prueba);
}
*/
