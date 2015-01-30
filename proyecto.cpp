#include <iostream>
#include <conio>
#include <math>
#include <fstream>
#include <windows>
#include <stdio>
//******************************************************************************
//Función que muestra el menú
//******************************************************************************
int menu(){
	clrscr();
	int op;

   cout<<"PROYECTO"<<endl;
   cout<<"1. Generar tablas de verdad con dos entradas"<<endl;
   cout<<"2. Ver tablas de verdad con dos entradas"<<endl;
   cout<<"3. Generar y ver tabla con n entradas"<<endl;
   cout<<"4. Salir"<<endl;
	cout<<"   Opcion: ";cin>>op;
   return op;
}

//Función que genera la tabla de verdad AND

void generarAnd(int lineas,int nEntradas){
   ofstream fs("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs<<cadena<<endl;
   }

	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs<<"AND"<<endl;
	}
	//Genera la tabla de verdad AND
   for(int i=1;i<=lineas;i++){
   	bool and=1;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

	      if(digito==0)
         	and=0;
     	   fs<<digito<<"  ";
	   }
      fs<<and<<endl;
   }

 //Reemplaza los archivos
   fs.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera la tabla de verdad OR

void generarOr(int lineas,int nEntradas){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }


	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs2<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs2<<"OR"<<endl;
	}
	//Genera la tabla de verdad OR
   for(int i=1;i<=lineas;i++){
   	bool or=0;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

	      if(digito==1)
         	or=1;
     	   fs2<<digito<<"  ";
	   }
      fs2<<or<<endl;
   }

   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}

//******************************************************************************
//Función que genera la tabla de verdad NOT
//******************************************************************************
void generarNot(){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }

	//Genera el encabezado
   fs2<<"X NOT"<<endl;
   fs2<<"0 1"<<endl;
   fs2<<"1 0"<<endl;


   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera la tabla de verdad XOR

void generarXor(int lineas,int nEntradas){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }


	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs2<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs2<<"XOR"<<endl;
	}
	//Genera la tabla de verdad XOR
   int vDigitos[10];
   for(int i=1;i<=lineas;i++){
   	bool xor=0;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

         vDigitos[j]=digito;

     	   fs2<<digito<<"  ";
	   }

      xor=vDigitos[1];
      for(int k=1;k<nEntradas;k++){
      	if(((xor==0)&&(vDigitos[k+1]==0))||((xor==1)&&(vDigitos[k+1]==1)))
         	xor=0;
         else
         	xor=1;
      }

      fs2<<xor<<endl;
   }

   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera la tabla de verdad NOR

void generarNor(int lineas,int nEntradas){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }


	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs2<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs2<<"NOR"<<endl;
	}
	//Genera la tabla de verdad NOR
   for(int i=1;i<=lineas;i++){
   	bool nor=1;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

	      if(digito==1)
         	nor=0;
     	   fs2<<digito<<"  ";
	   }
      fs2<<nor<<endl;
   }

   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera la tabla de verdad NAND

void generarNand(int lineas,int nEntradas){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }


	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs2<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs2<<"NAND"<<endl;
	}
	//Genera la tabla de verdad NAND
   int vDigitos[10];
   for(int i=1;i<=lineas;i++){
   	bool nand=1;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

         vDigitos[j]=digito;

     	   fs2<<digito<<"  ";
	   }

      nand=vDigitos[1];
      for(int k=1;k<nEntradas;k++){
      	if((nand==1)&&(vDigitos[k+1]==1))
         	nand=1;
         else
         	nand=0;
      }

      fs2<<nand<<endl;
   }

   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera la tabla de verdad X-NOR

void generarXnor(int lineas,int nEntradas){
   ofstream fs2("nombre2.txt");
   ifstream fe("nombre.txt");
   char cadena[128];

   //Copia el contenido de nombre.txt a nombre2.txt
   while(!fe.eof()) {
      fe.getline(cadena, 128);
      fs2<<cadena<<endl;
   }


	//Genera el encabezado
   for(int i=1;i<=nEntradas;i++){
   	fs2<<"X"<<i<<" ";
	   if(i==nEntradas)
     	fs2<<"X-NOR"<<endl;
	}
	//Genera la tabla de verdad X-NOR
   int vDigitos[10];
   for(int i=1;i<=lineas;i++){
   	bool xnor=0;
      for(int j=nEntradas;j>=1;j--){
	     	int divisor=pow(2,j);
     	   int digito;
        	digito=(i%divisor);

	      if(digito<=(divisor/2)){
            if(digito==0)
     	      	digito=1;
        	   else
        			digito=0;
	      }
         else
     	   	digito=1;

         vDigitos[j]=digito;

     	   fs2<<digito<<"  ";
	   }

      xnor=vDigitos[1];
      for(int k=1;k<nEntradas;k++){
      	if(((xnor==0)&&(vDigitos[k+1]==0))||((xnor==1)&&(vDigitos[k+1]==1)))
         	xnor=1;
         else
         	xnor=0;
      }

      fs2<<xnor<<endl;
   }

   //Reemplaza los archivos
   fs2.close();
   fe.close();
   DeleteFile("nombre.txt");
   rename("nombre2.txt","nombre.txt");
}


//Función que genera tablas de verdad con n entradas

void generarTablasNEntradas(int nEntradas,int op){
   ofstream fs("nombre.txt");
   fs.close();
   char cadena[128];
   int lineas = pow(2,nEntradas);

   if(op==1){
	   generarAnd(lineas,nEntradas);
   }

   if(op==2){
	   generarOr(lineas,nEntradas);
   }

   if(op==3){
	   generarNot();
   }

   if(op==4){
	   generarXor(lineas,nEntradas);
   }

   if(op==5){
	   generarNor(lineas,nEntradas);
   }

   if(op==6){
	   generarNand(lineas,nEntradas);
   }

   if(op==7){
	   generarXnor(lineas,nEntradas);
   }

   ifstream fe("nombre.txt");

   while(!fe.eof()) {
      fe.getline(cadena, 128);
      cout << cadena << endl;
   }
   fe.close();
}


//Función que genera y permite ver tablas de verdad con n entradas

void verGenerarTablasNEntradas(){
   clrscr();
   cout<<"VER Y GENERAR TABLAS CON N ENTRADAS: "<<endl;
   int entradas=3;
   int op;
   do{
   	cout<<"Seleccione la tabla de verdad que desea generar y ver: "<<endl;
      cout<<"1. AND"<<endl;
      cout<<"2. OR"<<endl;
      cout<<"3. NOT"<<endl;
      cout<<"4. XOR"<<endl;
      cout<<"5. NOR"<<endl;
      cout<<"6. NAND"<<endl;
      cout<<"7. X-NOR"<<endl;
   	cout<<"   Opcion: ";cin>>op;
   }while((op>7)||(op<1));

   do{
   	if(op!=3){
			cout<<"Ingrese cuantas entradas desea: ";
         cin>>entradas;
      }
   }while ((entradas<2)||(entradas>6));

   generarTablasNEntradas(entradas,op);
}


//Función que genera tablas de verdad con 2 entradas

void generarTablas2Entradas(){
	clrscr();

   ofstream fe("nombre.txt");
   char cadena[128];

   //Genera el encabezado
   fe<<"2ENTRADAS"<<endl;
   fe.close();


   generarAnd(4,2);
   generarOr(4,2);
   generarNot();
   generarXor(4,2);
   generarNor(4,2);
   generarNand(4,2);
   generarXnor(4,2);
   char dir[50];

	int tamano;
   GetModuleFileName( NULL, dir, 50 );
   tamano=strlen(dir);
   for(int i=1;i<=17;i++)
	   dir[tamano-i]=NULL;
 	cout<<"Las  tablas han sido generadas y almacenadas:"<<endl<<"En el archivo 'nombre.txt'"<<endl<<"En la direccion "<<dir;
}


//Función que permite ver si el archivo existe o no

bool existe(){
    FILE *archivo;
    archivo= fopen("./nombre.txt","rb");
    if(archivo!=NULL){
      fclose(archivo);
      return 1;
    }
    else{
    	fclose(archivo);
    	return 0;
    }
}
//Función que permite ver tablas de verdad con 2 entradas

void verTablas2Entradas(){
	clrscr();
   if(existe()==1){
	   char cadena[128];
	   ifstream fe("nombre.txt");
  	   fe.getline(cadena, 128);
		if(strcmp(cadena,"2ENTRADAS")==0){
      	cout<<"TABLAS DE VERDAD CON DOS ENTRADAS"<<endl;
         cout<<"*********************************"<<endl;
		   while(!fe.eof()) {
   		   fe.getline(cadena, 128);
      		cout << cadena << endl;
         }
		}
      else{
	      char op;
   		cout<<"Las tablas no estan generadas, desea crearlas? (s/n)"; cin>>op;
      	if (op=='s')
	       {
          fe.close();
          generarTablas2Entradas();
          }
      }
   	fe.close();
   }
   else{
   	char op;
   	cout<<"Las tablas no estan generadas, desea crearlas? (s/n)"; cin>>op;
      if (op=='s')
      	generarTablas2Entradas();
   }
}


//Función que realiza una acción según un valor ingresado

void realizarAccion(int op){
	switch(op){
   	case 1:
      	generarTablas2Entradas();
         getch();
         break;

      case 2:
      	verTablas2Entradas();
         getch();
         break;

      case 3:
      	verGenerarTablasNEntradas();
         getch();
         break;
   }
}


//Función principal

void main(){
   int opcion=0;
	while (opcion!=4){
		opcion=menu();
   	realizarAccion(opcion);
   }
}
