#include "Jugador2.h"
#include "Archivo.h"
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include <string.h>
using namespace std;


//void cargarCadena(char *caracteres, int tam){
//    int i;
//    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
//    for(i=0; i<tam;i++){
//        caracteres[i]=cin.get();
//        if(caracteres[i]=='\n')break;
//    }
//    caracteres[i]='\0';
//    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
//}

Archivo::Archivo() {
    strcpy(nombre, "records.dat");
}

Archivo::Archivo(const char *n) {
    strcpy(nombre, n);
}
int Archivo::contarRegistros(){
    FILE *p;
    p=fopen("records.dat","rb");
    if(p==NULL){
        std::cout<<"ERROR DE ARCHIVO"<<std::endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes/sizeof(Jugador2);
}

bool Archivo::grabarArchivo(Jugador2 obj){

       FILE *p;
    p=fopen("records.dat", "ab");
    if(p==NULL){
       std:: cout<<"ERROR DE ARCHIVO"<<std::endl;
        return false;
    }
    fwrite(&obj, sizeof (Jugador2), 1, p);
    fclose(p);

        return true;

    }


Jugador2 Archivo::leerRegistro(int pos){
    Jugador2 obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        std::cout<<"ERROR DE ARCHIVO"<<std::endl;

        return obj;
    }
    fseek(p, pos * sizeof(Jugador2), 0);
    fread(&obj, sizeof (Jugador2), 1, p);
    fclose(p);
    return obj;
}



int Archivo::leerPuntajeJugador(){
Jugador2 objJug;
objJug=leerRegistro(0);
int puntaje=objJug.getPuntos();
return puntaje;
}

/*void Archivo::mostrarTodosJugadores(const char* filename) {
    int cantRegistros=contarRegistros();
    if (cantRegistros == -1) return;
    Jugador2 obj;

     FILE *p;
    p = fopen(filename, "rb");
    if (p == NULL) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }
    for(int i=0;i<cantRegistros;i++){
        obj=leerRegistro(i);
      obj.mostrarDatos();
        std::cout << "------------------" << std::endl;

    }
    fclose(p);
    }
*/
