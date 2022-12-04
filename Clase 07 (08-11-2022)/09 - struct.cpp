#include<iostream>

struct fecha{
    int dia;
    int mes , ano;
    std::string mensaje;
};

/*
struct {
    int w,z;
}prueba;
*/

int main(){
/*
    fecha f1;
    f1.dia=8;
    f1.mes=8;
    f1.ano=8;
    f1.mensaje=":(";

    //Se inicializan según el orden de declaración
    fecha f2 ={8,11,2022,"hola"};

    //Se copia cada miembro por omisión
    fecha f3=f2;

    //Los demas campos valen 0 o nulo
    fecha f4={8,11};

    //También se puede declarar así:
    fecha f5={.dia=8, .mes = 11, .ano = 2022, .mensaje = ":("};

*/


    //prueba.w = 9;


    struct {
        int x,y;
    }v;

    v.x=2;
    v.y=5;

    punto v2 = {9,8};
    std::cout<<v.x<<" "<<v.y<<"\n";
}
