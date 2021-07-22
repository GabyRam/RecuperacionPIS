//////////--MARLON ARAELY CASTILLO GARC�A CARNET: 4890-18-20988--/////////////

////////PROGRAMA PARA EL CONTROL DE SERVICIOS DEL HOTEL LAS ESTRELLAS/////////

/////////////////DECLARACION DE LIBRERIAS A UTILIZAR/////////////////////////

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

///////////////--DECLARACION DE ESTRUCTURAS Y VARIABLES--/////////////////////
struct sHabitacion {
	int fecha,fecha2, num;
   char nombre[30];
   char tipo[30];
   char estado[20];
}vHabitacion;

struct cafeteria {
	int precio, total;
   char alimento[50];
   char refaccion[50];
}cmenu;

struct cuarto {
	char dato[30];
   int tiempo,num;
}dservicio;

struct quejas {
	char datos[50];
   char tipo[30];
}vQuejas;

/*****************************************************************************/
/***************---------------MENU PRINCIPAL---------------******************/
void menu (){
	system("cls");
   printf("\tHOTEL GRAN PALACE\n\n");
   printf("SERVICIOS DEL HOTEL\n\n");
   printf("1.HABITACIONES\n");
   printf("2.CAFETERIA\n");
   printf("3.SERVICIO AL CUARTO\n");
   printf("4.QUEJAS\n");
   printf("5.Finalizar\n");
  }
/*****************************************************************************/
/*****************-------------HABITACIONES------------***********************/
void Habitacion (){
	system("cls");
   printf("1.Crear Archivo de Habitacion");
   printf("\n2.Reservar");
   printf("\n3.Inactivar/Activar");
   printf("\n4.Monitoreo de Habitaciones");
   printf("\n5.Regresar\n");
  }
void CrearArchivo(FILE *Archivo){
	Archivo=fopen("habitaciones.txt", "wb");
   if(!Archivo){
   	Archivo=fopen("habitaciones.txt", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(Archivo);
}

void InsertarDatos(FILE *Archivo){

	system("cls");
   char cod[10];
   Archivo = fopen("habitaciones.txt", "ab+");
   if(Archivo == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor cre�lo");
      return;
	}
		printf("Nombre del Cliente:");
   	printf("");
   	gets(vHabitacion.nombre);
	  	printf("Fecha Llegada:");
   	printf("");
   	vHabitacion.fecha=atoi(gets(cod));
      printf("Numero de Habitacion:");
      printf("");
      vHabitacion.num=atoi(gets(cod));
   	printf("Tipo de Habitacion:");
  		printf("");
   	gets(vHabitacion.tipo);
      printf("Fecha de Salida:");
  		printf("");
   	vHabitacion.fecha2=atoi(gets(cod));
   fwrite(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
   fclose(Archivo);
}
void encabezado()
{
   system("cls");
   printf("--------------------------------------------------------------------------------------------------");
   printf("--------------------------------------------------------------------------------------------------");
   printf("--------------------------------------------------------------------------------------------------");
   printf("Registro\n");
   printf("Cliente\n");
   printf("Llegada\n");
   printf("No Hab.\n");
   printf("Habitacion\n");
   printf("Salida\n");
   printf("Estado\n");
   getch();

}
void VerDatos(FILE *Archivo)
{
	system("cls");
   encabezado();
   int numero=1;
   Archivo =fopen("habitaciones.txt", "rb");
   if(Archivo == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
   while(!feof(Archivo))
   {  printf("%d", numero);
      printf("%s", vHabitacion.nombre);
      printf("%d", vHabitacion.fecha);
      printf("%d", vHabitacion.num);
      printf("%s", vHabitacion.tipo);
      printf("%d", vHabitacion.fecha2);
      printf("%s", vHabitacion.estado);
      fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
      numero ++;
   }
  fclose(Archivo);
    getch();
}

void Activar(FILE *Archivo)
{   system("cls");
    Archivo =fopen("habitaciones.txt","rb+");
    if (Archivo == NULL)
        exit(1);
    printf("\nIngrese el numero de la habitacion para inactivar o activar:");
    int cod;
    scanf("%i", &cod);
    int existe=0;
   fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
    while(!feof(Archivo))
    {
        if (cod==vHabitacion.num)
        {
           printf("%s", vHabitacion.nombre);
           printf("%d", vHabitacion.num);
           printf("%s", vHabitacion.tipo);
           printf("\nIngrese el Estado de la Habitacion:");
           scanf("%s",&vHabitacion.estado);
           int pos=ftell(Archivo)- sizeof(vHabitacion);
           fseek(Archivo,pos,SEEK_SET);
           fwrite(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
           printf("Se realizo el cambio en el Estado de la Habitacion\n");
           existe=1;
           break;
        }
         fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
    }
    if (existe==0)
    printf("No existe una habitacion con dicho numero\n");
    fclose(Archivo);
    getch();
    }

void mHabitacion (){

	int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archivo;
    while(!exit){
	Habitacion();
   printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: CrearArchivo(archivo); break;
         case 2: InsertarDatos(archivo); break;
         case 3: Activar(archivo); break;
         case 4: VerDatos(archivo); break;
        	case 5: exit = 1; break;
         default: printf("Opcion no valida");
         getch();
      }
      }
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/*****************------------CAFETERIA----------------***********************/
void MenuC(){
	system("cls");
   printf("1.Crear Nuevo Archivo de Menu\n");
   printf("2.Mostrar Menu\n");
   printf("3.Modificar Menu\n");
   printf("4.Monitoreo de Cafeteria\n");
   printf("5.Regresar\n");

  }
void CrearArchCa(FILE *ArchivoC){
	ArchivoC=fopen("cafeteria.txt", "wb");
   if(!ArchivoC){
   	ArchivoC=fopen("cafeteria.txt", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(ArchivoC);
}

void IngresarDatos(FILE *ArchivoC){

	system("cls");
   char cod[4];
   ArchivoC = fopen("cafeteria.txt", "ab+");

   if(ArchivoC == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor cre�lo");
      return;
	}
		printf("Ingrese el Alimento:");
   	printf("");
   	gets(cmenu.alimento);
	  	printf("Ingrese Refaccion:");
   	printf("");
      gets(cmenu.refaccion);
   	printf("Ingrese el Precio:");
  		printf("");
		cmenu.precio=atoi(gets(cod));
      printf("Ingrese el Total de Existencias:");
  		printf("");
   	cmenu.total=atoi(gets(cod));
   fwrite(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
   fclose(ArchivoC);
}
void encabezadoC()
{
	system("cls");
	printf("---------------------------------------------------------------------------------------");
	printf("---------------------------------------------------------------------------------------");
   printf("---------------------------------------------------------------------------------------");
   printf("Registro\n");
	printf("Alimento\n");
   printf("Refaccion\n");
   printf("Precio\n");
   printf("Existencia\n");
   getch();

}
void VerDatosC(FILE *ArchivoC)
{
	system("cls");
   encabezadoC();
   int numero=1;
   ArchivoC =fopen("cafeteria.txt", "rb");
   if(ArchivoC == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
   while(!feof(ArchivoC))
   {  printf("%d", numero);
      printf("%s", cmenu.alimento);
      printf("%s", cmenu.refaccion);
      printf("%d", cmenu.precio);
      printf("%d", cmenu.total);
      fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
      numero ++;
   }
  fclose(ArchivoC);
    getch();
}
void Modificacion(FILE *ArchivoC)
{   system("cls");
    ArchivoC =fopen("cafeteria.txt","rb+");
    if (ArchivoC == NULL)
        exit(1);
    printf("Ingrese el numero de registro de la opcion a modificar:");
    int cod;
    scanf("%i", &cod);
    int existe=0;
   fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
    while(!feof(ArchivoC))
    {
        if (cod==cmenu.precio)
        {
           printf("%s", cmenu.alimento);
           printf("%s", cmenu.refaccion);
           printf("%d", cmenu.precio);
           printf("%d", cmenu.total);
           printf("\nIngrese el nuevo alimento:");
           scanf("%s",&cmenu.alimento);
           printf("\nIngrese la nueva refaccion:");
           scanf("%s",&cmenu.refaccion);
           printf("\nIngrese el nuevo precio:");
           scanf("%d",&cmenu.precio);
           printf("\nIngrese el nuevo total de existencias:");
           scanf("%d",&cmenu.total);
           int pos=ftell(ArchivoC)- sizeof(cmenu);
           fseek(ArchivoC,pos,SEEK_SET);
           fwrite(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
           printf("Se modifico los datos\n");
           existe=1;
           break;
        }
         fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
    }
    if (existe==0)
        printf("No existe una opcion con dicho numero\n");
    fclose(ArchivoC);
    getch();
    }
void mCafeteria (){
int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archivoC;
    while(!exit){
	MenuC();
   printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
         case 1: CrearArchCa(archivoC); break;
         case 2: IngresarDatos(archivoC); break;
         case 3: Modificacion(archivoC); break;
         case 4: VerDatosC(archivoC); break;
        	case 5: exit = 1; break;
         default: printf("Opcion no valida");
         getch();
      }
   }
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/***********--------------SERVICIO AL CUARTO--------------*******************/
void Servicio (){

	system("cls");
   printf("1.Crear Archivo de Servicios\n");
   printf("2.Solicitar Servicio Limpieza, Alimentos, Masajes\n");
   printf("3.Monitoreo de Servicios\n");
   printf("4.Regresar al Menu Principal\n");
   }
void NuevoArchivo (FILE *Servi){
	Servi=fopen("servicios.txt", "wb");
   if(!Servi){
   Servi=fopen("servicios.txt", "rb");
   printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(Servi);
}

void Datos(FILE *Servi){
 system("cls");
   char cod[10];
   Servi = fopen("servicios.txt", "ab+");
   if(Servi == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor cre�lo");
      return;
	}
      printf("----------Servicio de Limpieza, Alimentos y Masajes-------------");
		printf("\nQue Servicio desea en su Habitacion:");
   	printf("");
   	gets(dservicio.dato);
	  	printf("\nIngrese los minutos en que requiere el servicio:");
   	printf("");
   	dservicio.tiempo=atoi(gets(cod));
      printf("\nIngrese el Numero de Habitacion:");
      printf("");
      dservicio.num=atoi(gets(cod));
      fwrite(&dservicio, sizeof(struct cuarto), 1, Servi);
      printf("\nEn un momento se atendera el servicio Solicitado...."); getch();
   fclose(Servi);
}
void EncServicios()
{
	system("cls");
	printf("--------------------------------------------------------------------------------------------------");
	printf("--------------------------------------------------------------------------------------------------");
   printf("--------------------------------------------------------------------------------------------------");
   printf("Registro\n");
	printf("Servicio\n");
   printf("Tiempo (Minutos)\n");
   printf("No Habitacion\n");
   printf("Estado\n");
   getch();

}
void MonitoreoServicios(FILE *Servi)
{
	system("cls");
   EncServicios();
   int numero=1;
   Servi =fopen("servicios.txt", "rb");
   if(Servi == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&dservicio, sizeof(struct cuarto), 1, Servi);
   while(!feof(Servi))
   {  printf("%d", numero);
      printf("%s", dservicio.dato);
      printf("%d", dservicio.tiempo);
      printf("%d", dservicio.num);
      fread(&dservicio, sizeof(struct cuarto), 1, Servi);
      numero ++;
   }
  fclose(Servi);
    getch();
}

void mServicio (){
int opcion;
	char Cop[2];
	int exit = 0;
   FILE *servi;
   while(!exit){
	Servicio();
   printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: NuevoArchivo(servi); break;
         case 2: Datos(servi); break;
         case 3: MonitoreoServicios(servi); break;
         case 4: exit = 1; break;
         default: printf("Opcion no valida");
         getch();
      }
      }
 }
/*****************************************************************************/
/*********************------------QUEJAS----------****************************/
void Quejas (){
	system("cls");
   printf("1.Crear un Nuevo Archivo de Quejas\n");
   printf("2.Ingresar Queja\n");
   printf("3.Monitoreo de Quejas\n");
   printf("4.Volver al Menu Principal\n");
   }

void CrearQuejas (FILE *archQ){
archQ=fopen("quejas.txt", "wb");
	if(!archQ){
   	archQ=fopen("quejas.txt", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nYa existe un archivo con este nombre");
      }getch();
      fclose(archQ);
   }
void IngresarQuejas (FILE *archQ){
   system("cls");
   archQ = fopen("quejas.txt", "ab+");

   if(archQ == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor crear un archivo");
      return; getch();
   }
   	printf("---------Por Favor Ingrese un Comentario o Queja de los Servicios---------");
      printf("\n----------------Especifique de que tipo Administrativo/Tecnico------------");
      printf("\nIngrese el tipo de Queja:");
      gets(vQuejas.tipo);
      printf("\nDetalle la Queja:");
      gets(vQuejas.datos);
   fwrite(&vQuejas, sizeof(struct quejas), 1, archQ);
   	printf("\nRegistro Completo..."); getch();
   fclose(archQ);
   }
void encQuejas(){
         system("cls");
         printf("------------------MONITOREO DE LAS QUEJAS DEL SERVICIO DEL HOTEL LAS ESTRELLAS--------------------");
			printf("--------------------------------------------------------------------------------------------------");
   		printf("--------------------------------------------------------------------------------------------------");
   		printf("Registro\n");
			printf("Administrativo/Tecnico\n");
   		printf("Queja\n");
         getch();
}

void verQuejas (FILE *archQ){
	system("cls");
   encQuejas();
   int numero=1;
   archQ = fopen ("quejas.txt", "rb");
   if(archQ == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor crear un archivo");
      return; getch();
   }
   fread(&vQuejas, sizeof(struct quejas), 1, archQ);
   while(!feof(archQ))
   {
      printf("%d", numero);
      printf("%s", vQuejas.tipo);
      printf("%s", vQuejas.datos);
      fread(&vQuejas, sizeof(struct quejas), 1, archQ);
      numero ++;
   }
   fclose(archQ);
   getch();
}
void mQuejas (){


	int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archQ;
    while(!exit){
	Quejas();
   printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: CrearQuejas(archQ); break;
         case 2: IngresarQuejas(archQ); break;
         case 3: verQuejas(archQ); break;
        	case 4: exit = 1; break;
         default: printf("Opcion no valida");
         getch();
      }
      }

}
/****************************************************************************/
/****************------------FUNCION PRINCIPAL------------******************/
int main()
{
	int opcion;
   char Cop[2];
  int exit = 0;
  while(!exit)
  {
      menu();
      printf("Opcion:");
      opcion = atoi(gets(Cop));
      switch(opcion)

      {
       	case 1: mHabitacion(); break;
         case 2: mCafeteria(); break;
         case 3: mServicio(); break;
         case 4: mQuejas(); break;
         case 5: exit = 1; break;
         default: printf("Opcion no valida");
         getch();
      }
  }
}

