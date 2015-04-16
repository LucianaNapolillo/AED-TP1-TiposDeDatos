/* Permite ingresar una determinada cantidad de personas y, calcula sus edades, el promedio y quién es la de mayor edad.
* Luciana Napolillo
* 15/04/2015
*/

#include <iostream>
using namespace std;

int main() {

	string c = "\u2666 ", nombre, apellido, mayorNombreCompleto;
	int cantidadPersonas, contadorPersonas=0, dia, mes, anio, diaActual, mesActual, anioActual, edad, edades=0, mayor=0;
	bool cumplioAnios;	
	double promedio;

	bool diaValido(int dia);
	bool mesValido(int mes);
	bool anioValido(int anio, int anioActual);
	bool fechaValida(int dia, int mes, int anio);

	cout << "¿Cuántas personas desea ingresar?: ";
	cin >> cantidadPersonas;

	cout << "\nIngrese la fecha actual: ";
	do {
		do {
			cout << "\n\tDia: ";
			cin >> diaActual;
		} while(!diaValido(diaActual));
		do {
			cout << "\tMes: ";
			cin >> mesActual;
		} while(!mesValido(mesActual));
		
			cout << "\tAño: ";
			cin >> anioActual;
	} while (!fechaValida(diaActual,mesActual,anioActual));
	
	do {
		cout << c << "Ingresa el nombre de la persona nro. " << contadorPersonas + 1 << ": ";
		cin >> nombre;
		cout << c << "Ingresa el apellido: ";
		cin >> apellido;
		cout << endl << c << "Ingresa la fecha de nacimiento: ";
		
		do {
			do {
				cout << "\n\tDia: ";
				cin >> dia;
			} while (!diaValido(dia));

			do {
				cout << "\tMes: ";
				cin >> mes;
			} while (!mesValido(mes));
			do {
				cout << "\tAño: ";
				cin >> anio;
			} while (!anioValido(anio, anioActual));
		} while (!fechaValida(dia,mes,anio));

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

		contadorPersonas++;
	} while(contadorPersonas < cantidadPersonas);

	promedio = double(edades) / double(cantidadPersonas);

	cout << endl << endl << c << "El promedio de edades es " << promedio << endl;
	cout << c << "La persona con mayor edad es " << mayorNombreCompleto << endl;

}

bool diaValido (int dia) {
	if (dia > 0 && dia <= 31) {
		return 1;
	} else {
		cout << "Ingrese un día válido!\n";
		return 0;
	}
}

bool mesValido (int mes) {
	if (mes > 0 && mes <= 12) {
		return 1;
	} else {
		cout << "Ingrese un mes válido!\n";
		return 0;
	}
}

bool anioValido (int anio, int anioActual) {
	if (anio > 0 && anio <= anioActual) {
		return 1;
	} else {
		cout << "Ingrese un año válido!\n";
		return 0;
	}
}

bool fechaValida (int dia, int mes, int anio) {
	if (mes == 2) {
		if (anio%4 == 0 && (anio%100 != 0 || anio%400 == 0)) {
			if (dia <= 29) {
				return 1; 
			} else {
				cout << "Fecha inválida!\n";
				return 0;
			}
		} else {
			if (dia <= 28) {
				return 1;
			} else {
				cout << "Fecha inválida!\n";
				return 0;
			}
		}
	} else {
		return 1;
	}
}