#include <fstream>
#include <iostream>
//******************************************************************************
//Funci�n que muestra el men�
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

