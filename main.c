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
	
	int selector=0;
	printf("¿Que operacion desea realizar sobre la base de datos?\n");
	printf("1=> Ubicaciones segun el proyecto\n");
	printf("2=> Total de horas trabajadas de cada departamento\n");
	scanf("%d",&selector);
	clr;
	
	if(selector==1){
		sele1(db);  //NO PUEDO METERLO EN OTRA FUNCION

	}
	else if(selector==2){
		sele2(db);
	}else{
		printf("Entrada no valida\n");
	}
    
	
    sqlite3_close(db);
}
