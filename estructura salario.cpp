//Programa creado por: Ulises Edgardo Coreas Huezo 
//Carnet: CH18030

				//librerias obligatorias utilizadas
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <math.h>

				//cuerpo del programa
using namespace std;				

		//structura de un empleado
struct Empleado{
		//variables utilizada
	int edad; //edad del trabaajador
	
	char cod[5]; //codigo del trabajador
	char nombre[50]; //nombre del trabajador
	char departamento [60]; //departamento de donde trabaja
	char puesto[60]; //puesto de trabajo
	
	float salbase;	//salario base
	float salliquido;	//salario liquido
	float isss;	//descuento del isss
	float afp;	//descuesto de la AFP
	float renta;	//descuento de la renta
	float totalprestamo;	//total del prestamo que debe
		
};

		//estructura de la surcusal
struct Sucursal{
		//variables utilizada
	int numsucursal;	//numero de la surcusal
	
	char nombresurcusal[60];	//nombre de la surcusal
	
};

		//proceso para sacar el valor del isss
float calisss(float sal,float tope)
{
			//variable del isss
int isss;
		//validacion 
	if(sal >= 600)
	{		//proceso para sacar el valor
		  isss = 600 * 0.30;
	}
		//validacion
	else
	{		//proceso para sacar el valor
		isss = sal * 0.30;
			}
return isss; //retorna a la variable indicada
}

		//proceso para sacar el valor de la AFP
float calafp (float sal,float afp)
{
		//proceso para sacar el valor
    afp = sal*0.0725;
    
    return afp;	//retorna a la variable indicada
}

		//proceso para sacar el valor de la renta
float calrenta (float sal, float renta)
{

	/*la renta se calcula mediente una tabla proporcinado por el ministerio de hacienda
	la cual se presenta a continuacion.
	
	a los que ganan de        a                         aplicar
	$0.01--------------------$472.00---------------------sin renta
	$472.01------------------$895.24---------------------10% sobre lo que sobrepasa de $472.00 mas cuota fija de $17.67
	$895.25------------------$2038.10--------------------20% sobre lo que sobrepasa de $895.24 mas cuota fija de $60.00
	$2038.11-----------------mas-------------------------30% sobre lo que sobrepasa de $2038.10 mas cuota fija de $253.37*/
	
		//validacion para sacar el valor de la renta
   if (sal >=0.01 && sal <=472.00){
    	cout << "no se aplica renta" << endl; 	//por la cantiad que gana no se le aplica la renta
	}
	else if (sal >=472.01 && sal <=895.24){		//por la cantiad que gana se le aplica 10%
		renta = ((sal - 472.00) * 0.1)+17.67;
	}
	else if (sal >=895.25 && sal <=2038.10){	//por la cantiad que gana se le aplica 20%
		renta = ((sal - 895.24) * 0.2)+60;
	}
	else if(sal >= 2038.11){					//por la cantiad que gana se le aplica 30%
		renta = ((sal - 2038.10) * 0.2)+253.37;
	}
    
return renta;	//retorna a la variable indicada
}


int main (int argc, char *argv[])
{
		//comando para asignar color al fondo y a las letras de la terminal
	system("color 81");
	
	int n; //numero de empleados
	
	Sucursal s; //llamado de una varriable desde una estructura
		
	cout << "Nombre de la sucursal"<<endl; //peticion del nombre de la surcusal donde trabaja
	cin>>s.nombresurcusal; //guarda el dato en la variable
	fflush(stdin); //comando para permitir signos y espacios
	
	cout << "Numero de la sucursal"<<endl; //petidion del numero de la surcusal donde trabaja
	cin>>s.numsucursal; //guarda el dato en la variable
	fflush(stdin);	//comando para permitir signos y espacios
		
	cout << "Cuantos empleados tiene?"<<endl; //peticion de cuantos empleados tiene la surcusal
	cin>>n;//guarda el dato en la variable
	
	Empleado e[n]; //llamado de una varriable desde una estructura

		//ciclo for para implementar la estructura empleado y la variable del numero de empleado
	for (int i = 0; i < n; i++)
	{
		
		cout<<"\t Empleado "<<i + 1 <<endl;
		
		int cp = 0; //prestamo que tiene
		int contador = 0; //contador para el ciclo while
		
		cout << "Departamento: "<<endl; //peticion del departamento donde
		cin>>e[i].departamento;//guarda el dato en la variable
		fflush(stdin); //comando para permitir signos y espacios
		
		cout << "Puesto: "<<endl; //peticion del puesto de trabajo
		cin>>e[i].puesto;//guarda el dato en la variable
		fflush(stdin); //comando para permitir signos y espacios
		
		cout << "Codigo: "<<endl; //peticion del codigo del empleado
		cin>>e[i].cod;//guarda el dato en la variable
		
		cout << "Nombre: "<<endl; //peticin del nombre del empleado
		cin>>e[i].nombre;//guarda el dato en la variable
		fflush(stdin);
		
		cout << "Edad: "<<endl; //peticion de la edad del empleado
		cin>>e[i].edad;//guarda el dato en la variable
		
		cout << "Salario base: "<<endl; //peticion del salario base del empleado
		cin>>e[i].salbase;//guarda el dato en la variable
		
		do{ // comienzo del ciclo
		
		cout << "Cuantos prestamos tiene el empleado?: "<<endl;	//peticion para saber cuantos prestamos tiene pendiente
		cin>>cp;//guarda el dato en la variable
		
		if (cp > 5){		//validacion para que no se pase del limite de prestamos, los cuales son 5 en este caso
			
			cout<<"La cantidad de prestamos no pueden ser mas de 5"<<endl;	//imprimira solo si se pasa del limite indicado
		
		}		
		}while(cp > 5); //fin del ciclo, y validacion para que retorne si se pasa del limite

		float totpres = 0; //representa el total de la suma de los prestamos
		float press = 0;	//representa la cantidad que se presto
		
		while(contador <= cp - 1) //ciclo para que se repita la peticion
		{
			do{	//comienzo del ciclo 
			
			cout << "Ingrese el monto del prestamo "<<contador + 1 <<endl;	//peticion de la cantidad que se presto
			cin>>press;//guarda el dato en la variable
			
			if (press <= e[i].salbase*0.2)		//validacion para saber si no se pasa del 20%
			{
				totpres = totpres + press;	//proceso para 
				e[i].totalprestamo = totpres; //asigna valor a la variable
			}
			else	//validacion si no se cumple el if
			{
				cout<<"El prestamo se pasa del limite, se pasa del 20%"<<endl;	//se imprimira solo si no se cumple el if
			}
			
			}while (press > e[i].salbase*0.2);	//fin del ciclo, y validacion para que retorne si se pasa del 20%
			
			contador++;	//detiene el ciclo
			
			
		}
		
		e[i].isss=calisss(e[i].salbase,0.03);	//se asigna valor al isss
		
		e[i].afp=calafp(e[i].salbase,0.0725);	//se asigna valor a la AFP
        
		e[i].renta=calrenta(e[i].salbase,0.1);	//se asigna valor a la renta
		
   		e[i].salliquido = (e[i].salbase - e[i].isss - e[i].afp - e[i].renta - e[i].totalprestamo); //se asigna valor al salario liquido
		
		cout<<endl; //comando para hacer el salto de linea
	}
	
		system("cls"); //comando para limpiar lo que se mostro en pantalla anterior mente
	 
	  for (int i=0; i<n; i++)	//ciclo para que se muestre dependiendo la cantidad de empleados
    {	
    
    	cout<<"\t Empleado "<<i + 1 <<endl;		//se imprime el valor
		
		cout << "Departamento: " << e[i].departamento << "\t"<<endl;	//se imprime el valor
		
		cout << "Puesto: " << e[i].puesto << "\t"<<endl;	//se imprime el valor
		
		cout << "Codigo: " << e[i].cod << "\t"<<endl;	//se imprime el valor
		
        cout << "Nombre: " << e[i].nombre << "\t"<<endl;	//se imprime el valor
        
		cout << "Edad: " << e[i].edad << "\t"<<endl;	//se imprime el valor
        
		cout << "Salario Base: $" << e[i].salbase << "\t"<<endl;	//se imprime el valor
        
		cout << "ISSS: $" << e[i].isss << "\t"<<endl;	//se imprime el valor
        
		cout << "AFP: $" << e[i].afp << "\t"<<endl;	//se imprime el valor
        
		cout << "Renta: $" << e[i].renta << "\t"<<endl;	//se imprime el valor
        
		cout << "Prestamo: $" << e[i].totalprestamo << "\t"<<endl;	//se imprime el valor
		
		cout << "Salario liquido: $" << e[i].salliquido << "\t"<<endl;	//se imprime el valor
		
		cout<<endl;	//comando para hacer el salto de linea
	}

		//comando para detener el programa
cin.get();
return EXIT_SUCCESS;
}
