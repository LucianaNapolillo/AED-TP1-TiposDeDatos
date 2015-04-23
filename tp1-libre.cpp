/* Permite ingresar una determinada cantidad de personas y, calcula sus edades, el promedio y quién es la de mayor edad.
* Luciana Napolillo
* 15/04/2015
*/

#include <iostream>
using namespace std;

int main() {

	string c = "\u2666 ", nombre, apellido, mayorNombreCompleto;
	int cantidadPersonas=0, dia, mes, anio, diaActual, mesActual, anioActual, edad, edades=0, mayor=0;
	bool cumplioAnios;	
	double promedio;
	char respuesta;

	cout << "\nIngrese la fecha actual: ";
	cout << "\n\tDia: ";
	cin >> diaActual;
	cout << "\tMes: ";
	cin >> mesActual;
	cout << "\tAño: ";
	cin >> anioActual;
		
	do {
		cout << endl << c << "Ingresa el nombre de la persona nro. " << cantidadPersonas + 1 << ": ";
		cin >> nombre;
		cout << c << "Ingresa el apellido: ";
		cin >> apellido;
		cout << c << "Ingresa la fecha de nacimiento: ";
		cout << "\n\tDia: ";
		cin >> dia;
		cout << "\tMes: ";
		cin >> mes;

		do {
			cout << "\tAño: ";
			cin >> anio;
		} while (anio <= 0 || anio >= anioActual);
		
		cumplioAnios = (mesActual > mes || (mesActual == mes && diaActual == dia));
		
		if (cumplioAnios) {
			edad = anioActual - anio;
		} else {
			edad = anioActual - anio - 1;
		}

		edades = edades + edad;

		if (edad > mayor) {
			mayor = edad;
			mayorNombreCompleto = nombre + " " + apellido;
		}

		cantidadPersonas++;
		if (cantidadPersonas >= 2) {	//los cálculos sólo se pueden realizar con al menos dos personas
			cout << "\n¿Desea ingresar mas personas? S/N: ";
			cin >> respuesta;
		}
	} while(cantidadPersonas < 2 || respuesta == 's' || respuesta == 'S');

	promedio = double(edades) / double(cantidadPersonas);

	cout << endl << endl << c << "El promedio de edades es " << promedio << endl;
	cout << c << "La persona con mayor edad es " << mayorNombreCompleto << endl;

}