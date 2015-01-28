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


//******************************************************************************
//Función que genera tablas de verdad con 2 entradas
//******************************************************************************
void generarTablas2Entradas(){
	clrscr();
	cout<<"GENERAR TABLAS CON DOS ENTRADAS";
}

//******************************************************************************
//Función que permite ver tablas de verdad con 2 entradas
//******************************************************************************
void verTablas2Entradas(){
	clrscr();
	cout<<"VER TABLAS CON DOS ENTRADAS";
}
