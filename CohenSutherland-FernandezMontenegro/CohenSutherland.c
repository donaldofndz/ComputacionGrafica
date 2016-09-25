/*

PRGRAMA ALGORITMO COHEN SUTHERLAND
FERNANDEZ MONTENEGRO JOSE DONALDO 
COMPUTACION GRAFICA 
GRUPO 2



*/

#include <stdio.h>
#include <stdlib.h>


//funcion que asigna valor binario
int valBin(int num1, int num2, int prim, int seg, int ter, int cuar);
int seleccionador(int num1, int num2);

//declarando estructura
struct Linea {
	int xini;
	int yini;
	char binini;
	int xfin;
	int yfin;
	char binfin;
};


int main(int argc, char const *argv[])
{
	//declarando variables 
	FILE * fp;
	int prim,seg,ter,cuar,aux,i,contador = 0;

	//abrindo el archivo
	fp = fopen ("input.txt", "r");

	//leyendo numero de lineas
	do
	{
		fscanf(fp, "%d %d", &prim,&seg);
	    contador++;
	 }while(feof(fp)!=1);
	 contador = contador/2;
	 //asignando cuantas lineas habra en el arreglo de variables 
	struct Linea *arreglo = malloc(sizeof(struct Linea) * contador);
	//inicio de documento
	rewind(fp);
	contador=0; //se reutiliza variable contador 

	//asignando valores a las estructuras

	do
	{
		fscanf(fp, "%d %d", &prim,&seg);
		fscanf(fp, "%d %d", &ter,&cuar);

		arreglo[contador].xini = prim;
		arreglo[contador].yini = seg;
		arreglo[contador].xfin = ter;
		arreglo[contador].yfin = cuar;

		system("clear");
	    contador++;

	 }while(feof(fp)!=1);

	 /*

	 for (i = 0; i < contador; i++)
	 {
	 	printf("%d ",arreglo[i].xini);
		printf("%d\n",arreglo[i].yini);
		printf("%d ",arreglo[i].xfin);
		printf("%d\n",arreglo[i].yfin);

	 }

	 */

	 printf("ALGORITMO DE COHEN SUTHERLAND\n");
	 printf("Haz ingresado %d lineas por medio de archivo\n", contador);
	 printf("Ingresa los puntos para los que se va a definir la ventana del siguiente modo x y \n");
	 printf("Primer punto: \n");
	 scanf("%d %d",&prim,&seg);
	 printf("Segundo Punto\n");
	 scanf("%d %d",&ter,&cuar);

	 if(prim > ter && seg > cuar){
	 	aux = prim;
	 	prim = ter;
	 	ter = aux;
	 	aux = seg;
	 	seg = cuar;
	 	cuar = aux;
	 }

	for (i = 0; i < contador; i++)
	{
		
		arreglo[i].binini = valBin(arreglo[i].xini,arreglo[i].yini,prim,seg,ter,cuar);
		arreglo[i].binfin = valBin(arreglo[i].xfin,arreglo[i].yfin,prim,seg,ter,cuar);
		
	}

	/*
	printf(" AQUI COMIENZA LA OTRA SECUENCIA\n");
	for (i = 0; i < contador; i++)
	{
		printf("%d\n", arreglo[i].binini);
		printf("%d\n", arreglo[i].binfin);
	}
	*/ 

	for (i = 0; i < contador; i++)
	{
		
		aux = seleccionador(arreglo[i].binini, arreglo[i].binfin);

		printf("La linea [%d] se ",i+1);

		if (aux == 0)
		{
			printf("dibuja\n");
		}else if(aux ==1){
			printf("recorta\n");
		}else{
			printf("descarta\n");
		}




	}


}

int seleccionador(int num1, int num2){

	if((num1|num2) == 0){
		return 0;
	}if((num1&num2) == 0){
		return 1;
	}else{
		return 2;
	}

}



int valBin(int num1, int num2, int prim, int seg, int ter, int cuar){

	if(num1 < prim){
		if(num2 < seg){
			return 6;
		}
		else if(num2 > cuar){
			return 10;
		} 
		else if(num2 == seg || num2 == cuar || (num2 >= seg && num2 <= cuar) ){
			return 2;
		}
	}else if (num1 > ter){
		if(num2 < seg){
			return 5;
		}
		else if(num2 > cuar){
			return 9;
		} 
		else if(num2 == seg || num2 == cuar || (num2 >= seg && num2 <= cuar) ){
			return 1;
		}
	} else if(num1 == prim || num1 == ter || (num1 >= prim && num1 <= ter) ){
		if(num2 < seg){
			return 4;
		}
		else if(num2 > cuar){
			return 8;
		} 
		else if(num2 == seg || num2 == cuar || (num2 >= seg && num2 <= cuar) ){
			return 0;
		}

	}

	return 0;
}
