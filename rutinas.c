#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>
#define clr system("cls");


//funcion de apertura de la base de datos
void opn(sqlite3 **b, char _fname[], int *_res){
	
	 *_res = sqlite3_open_v2(_fname, b, SQLITE_OPEN_READWRITE,NULL);
	 //printf("%d\n",*_res);
    if (*_res)
    {
        fprintf(stderr,"La base de datos no existe ==> %s\n", sqlite3_errmsg(*b));
        system("pause");
        clr;
        //exit(0);
    }
    else
    {
        fprintf(stderr, "Base de datos OK\n\n");
    }
}


//funcion callback de SQL
static int selectCb(char _outM[50][10][200], int argc, char **argv, char **colNames)
{
    static int i=0;//iteradores del array
    int n=0;
    
	for(n=0; n<argc; n++){
    	
		strcpy(_outM[i][n],argv[n]);
   	
	}
	i++;	

    return 0;
}



//funcion lectura base de datos
void readDB(sqlite3 *b, char _outM[50][10][200],char *_sql){
	char *error = 0;
	//char *sql;//comando sql
	int res;
	int *r;
	//sql = "SELECT Nombre_Pila, Apellido_1, Nombre_Dpto, Proy_Numero FROM Empleado, Departamento, Proyecto WHERE Empleado.Numero_Dpto=Departamento.Num_Dpto AND Empleado.Numero_Dpto=Proyecto.Numero_Dpto;";
	//sql = "SELECT Nombre_Pila, Apellido_1, Proy_Ubicacion, Proy_Numero FROM Empleado, Proyecto WHERE Empleado.Numero_Dpto=Proyecto.Numero_Dpto;";
	res = sqlite3_exec(b, _sql, selectCb, _outM, &error);

	if (res != SQLITE_OK)
    {
        fprintf(stderr, "Error: %s\n\n", error);
		sqlite3_free(error);
    }
    else
    {
        fprintf(stdout, "Consulta realizada con exito \n\n");
    }
}

//funcion comando SQL 1
void sele1(sqlite3 *bd){
	
		char *sql="SELECT Nombre_Pila, Apellido_1, Proy_Ubicacion, Proy_Numero FROM Empleado, Proyecto WHERE Empleado.Numero_Dpto=Proyecto.Numero_Dpto;";
		int s=0;
    	char outM[50][10][200]={};//esto puede almacenar 10 campos, 50 registros, de 200 caracteres cada uno (implementar memoria dinamica luego?)
    	readDB(bd, outM,sql);
    	do {
		printf("Que desea hacer con la informacion extraida?\n");
    	printf("1=> Mostrar por pantalla\n");
		printf("2=> Escribir en un fichero\n");
		scanf("%d",&s);
		clr;
		
		if(s==1){
		 
		printf("El empleado:\t");
		printf("Trabaja en:\t");
		printf("Asociado al Proy No:\n");
		
		
		
		int i=0;
		while(outM[i][0][0]!='\0'){
			printf("%s",outM[i][0]);
			printf(",");
			printf("%s\t",outM[i][1]);
			printf("%s    \t",outM[i][2]);
			printf("%s\n",outM[i][3]);
			i++;
		}
		
		}else if(s==2){
			
			FILE *fp;
			fp=fopen("Salida_BD.txt","w+");
			
			fprintf(fp,"El empleado:\t");
			fprintf(fp,"Trabaja en:\t");
			fprintf(fp,"Asociado al Proy No:\n");
		
		
		
			int i=0;
			while(outM[i][0][0]!='\0'){
				
			fprintf(fp,"%s",outM[i][0]);
			fprintf(fp,",");
			fprintf(fp,"%s\t",outM[i][1]);
			fprintf(fp,"%s    \t",outM[i][2]);
			fprintf(fp,"%s\n",outM[i][3]);
			i++;
		}
		fclose(fp);
		printf("Escritura correcta\n");
		
		
		}else{
		printf("Entrada no valida\n");
		system("Pause");
		clr;
		}	
	} while(!(s==1 || s==2));
		
	}
	

//funcion comando SQL 2
void sele2(sqlite3 *bd){
		
		char *sql="SELECT Nombre_Dpto, sum(Horas) FROM (SELECT Nombre_Dpto, Numero_Dpto, Horas FROM Empleado, Trabaja_En, Departamento WHERE Trabaja_En.ID_Empleado=Empleado.ID_Empleado AND Empleado.Numero_Dpto=Departamento.Num_Dpto) GROUP By Numero_Dpto;";
		int s=0;
    	char outM[50][10][200]={};//esto puede almacenar 10 campos, 50 registros, de 200 caracteres cada uno (implementar memoria dinamica luego?)
    	readDB(bd, outM,sql);
    	do{
		printf("Que desea hacer con la informacion extraida?\n");
    	printf("1=> Mostrar por pantalla\n");
		printf("2=> Escribir en un fichero\n");
		scanf("%d",&s);
		clr;
		
		if(s==1){
		 
		printf("El Departartamento:\t");
		printf("Tiene un total de horas:\n");
		
		
		
		int i=0;
		while(outM[i][0][0]!='\0'){
			printf("%s\t\t",outM[i][0]);
			printf("%s\n",outM[i][1]);
			i++;
		}
		
		}else if(s==2){
			
			FILE *fp;
			fp=fopen("Salida_BD.txt","w+");
			
			fprintf(fp,"El Departartamento:\t");
			fprintf(fp,"Tiene un total de horas:\n");
		
		
		
			int i=0;
			while(outM[i][0][0]!='\0'){
				
			fprintf(fp,"%s\t\t",outM[i][0]);
			fprintf(fp,"%s\n",outM[i][1]);
			i++;
		}
		fclose(fp);
		printf("Escritura correcta\n");
		
		
		}else{
		printf("Entrada no valida\n");
		system("Pause");
		clr;
		}	
	} while(!(s==1 || s==2));
		}
		

