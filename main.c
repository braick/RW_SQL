#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>
//#include "rutinas.c"
#include "cabeceras.h"
#define clr system("cls")


    	
int main(int argc, char *argv[]) {

    sqlite3 *db;//puntero a la base de datos
    
    
    int res=14;
    while(res!=0){
	char fname[50];
	printf("Introduzca el nombre de la base de datos (extension incluida)\n");
	scanf("%s",fname);
	clr;
	opn(&db,fname,&res);
	//clr;
	}
	
	int selector=1;
	do {
	printf("Que operacion desea realizar sobre la base de datos?\n");
	printf("1=> Ubicaciones segun el proyecto\n");
	printf("2=> Total de horas trabajadas de cada departamento\n");
	scanf("%d",&selector);
	clr;
	
	if(selector==1){
		sele1(db);//llama funcion selccion 1

	}
	else if(selector==2){
		sele2(db);//llama funcion seleccion 2
	}else{
		printf("Entrada no valida\n");
		system("Pause");
		clr;
	}
} while(!(selector==1 || selector==2));
	
    sqlite3_close(db);
    system("pause");
}
