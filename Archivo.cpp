#include "Archivo.h"
#include<iostream>
using namespace std;

Archivo::Archivo(){
}

bool Archivo::cargarJugador(Jugador jugador){

    FILE *p = fopen("records.dat","wb");
    if(p==NULL){
        cout<<"error al cargar el archivo";
    }
    bool ok = fwrite(&jugador, sizeof(Jugador),1,p);
    if(ok){
        cout<<"Archivo guardado exitosamente";
    }
    else{
        cout<<"Error al guardar el archivo";
    }
    fclose(p);
    return 0;

}

Jugador Archivo::leerRegistro(int pos){
    Jugador obj;
    FILE *p = fopen("records.dat","rb");
    if(p==NULL){
        cout<<"error al leer el archivo";
    }
    fseek(p,pos*sizeof obj,0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
