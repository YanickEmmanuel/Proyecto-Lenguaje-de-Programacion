#include <fstream>
#include <iostream>
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
