/* HOJA DE TRABAJO #5

EJERCICIO # 1
En una librería se venden 4 modelos diferentes de cuadernos, con los siguientes precios:
 Modelo#1 – Q10.00
 Modelo#2 – Q15.00
 Modelo#3 – Q18.50
 Modelo#4 – Q25.00
Por otra parte, se tiene información sobre las ventas realizadas durante los últimos 30 días, estos
movimientos se deben de guardar en un archivo de la siguiente forma:
DIA1,MOD,CANT
DIA2,MOD,CANT
.
.
.
DIA30,MODELO,CANTIDAD
DIAi = Variable que representa el día que se efectuó la venta i (1 - 30)
MOD= Variable que representa código de Modelo que se vendió. (1 – 4)
CANT= Variable que representa la cantidad de unidades vendidas. 

El programa debe ser capaz de:

? Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo
    (modificación del archivo)
? Eliminación de un día especifico de venta (modificación del archivo)
? Calcular el total recaudado por modelo en los 30 días.
? Calcular cuál fue el modelo que se vendió mas en los 30 días 

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;

void insert_data_db();
void mp();
void eliminar();
void modificar();

int main(){	
	mp();		
}
void mp(){
	int resp;

	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Librería "<<"\n";
		cout<<" 2 - Eliminar Registro"<<"\n";
		cout<<" 3 - Modificar Registro"<<"\n";
		cout<<" 4 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}

		else if (resp==2){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==3){
			system("CLS");
			modificar();
		}
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void insert_data_db(){

    char modelo; 
	int cantidad ;     
	int dia; 
	int precio;
	
	
	//Ingreso de datos
	cout<<"Ingrese que tipo de cuadeno quiere de la libreria DEL 1 a 4 :  \n"<<endl;
	cout<<"Ingrese Modelo de cuaderno:  "<<endl;
	cin>>modelo;
	cout<<"Ingrese la catidad de cuaderno quiere:  "<<endl;
	cin>>cantidad;
	cout<<"pon el dia que compro el cuaderno:  "<<endl;
	cin>>dia;

	modelo=toupper(modelo);
	cantidad=toupper(cantidad);
	 if (modelo=='1'){
		 precio=cantidad*10;		
	
	}
	
	else if (modelo=='2'){
		precio=cantidad*15;
	
	}
	
	else if (modelo=='3'){
		precio=cantidad*18.50;
	
	}

	else if (modelo=='4'){
		precio=cantidad*25;

}	
	
	ofstream registrotienda;
	
	cout.precision(5);
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"cantidad:  "<<cantidad<<endl;
	cout<<"dia:   "<<dia<<endl;
	cout<<"\n\nPrecio a pagar del cuaderno:  "<<precio<<endl;
	//Grabar al archivo
	ofstream miarchivo;
	system("PAUSE");
	try {
		miarchivo.open("Libreria.txt",ios::out);
		miarchivo<<modelo<<"\t"<<cantidad<<"\t"<<precio<<"/t"<<dia<<endl;
		miarchivo.close();
		cout<<"Datos grabados en el archivo";
	}
	catch(exception X){
		cout<<"Error al grabar en el archivo";
		system("PAUSE");
	}

}

void eliminar(){
	ifstream db_a; 
	ofstream db_n; 
	int aux,oid,onota,flag;
	string onombre;
	remove("Temporal.txt");
	
	db_a.open("Libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
		
							
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Libreria.txt");
		rename("Temporal.txt","Libreria.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream db_a;  
	ofstream db_n; 
	int aux,oid,onota,flag,inota;
	string onombre;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("Libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese cuaderno a modificar: "<<endl;
		cin>>inota;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			db_n<<onombre<<"\t"<<oid<<"\t"<<inota<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
						
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Libreria.txt");
		rename("Temporal.txt","Libreria.txt");
	}	
	system("Pause");
}
