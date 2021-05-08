#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int menu();
char* llenar_arreglo(int size);
char* secuencia(char* arreglo, int size);
void imprimir_arreglo(char* arreglo, int size);
char** llenar_matriz(int n, int m, int k);
int numero_random(int inicio, int limite);
void imprimir_matriz(char** matriz, int n, int m);
void ruta(int size, int n, int m, int k, int fila, int col);

int tamano;

int main() {
	int opcion;
	while((opcion = menu()) != 4) {
		switch(opcion) {
			case 1: {
				cout << endl;
				cout << "--Generar secuencia--" << endl;
				int num;
				cout << "Ingrese el size del arreglo: ";
				cin >> num;
				while(num <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese el size del arreglo: ";
					cin >> num;
					cout << endl;
				}
				char* arreglo = llenar_arreglo(num);
				char* sec = secuencia(arreglo, num);
				cout << endl;
				cout << "Cadena Ingresada: ";
				imprimir_arreglo(arreglo, num);
				cout << endl;
				cout << "Secuencia generada: ";
				imprimir_arreglo(sec, tamano);
				cout << endl;
				cout << endl;
				delete[] arreglo;
				delete[] sec;
				tamano = 0;
				break;
			}


			case 2: {
				cout << endl;
				cout << "--Matriz con Obstaculos--" << endl;
				int n, m, k;
				cout << "Ingrese n: ";
				cin >> n;
				while(n <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese n: ";
					cin >> n;
					cout << endl;
				}
				cout << "Ingrese m: ";
				cin >> m;
				while(m <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese m: ";
					cin >> m;
					cout << endl;
				}
				cout << "Ingrese k: ";
				cin >> k;
				while(k <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese m: ";
					cin >> m;
					cout << endl;
				}
				cout << endl;
				char** matriz = llenar_matriz(n, m, k);
				cout << "Matriz generada: " << endl;
				cout << endl;
				imprimir_matriz(matriz, n, m);
				cout << endl;
				for(int i = 0; i < n; i++) {
					delete[] matriz[i];
				}
				delete[] matriz;
				break;
			}

			case 3: {
				cout << endl;
				cout << "--Ruta--" << endl;
				int num;
				cout << "Ingrese el size del arreglo: ";
				cin >> num;
				while(num <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese el size del arreglo: ";
					cin >> num;
					cout << endl;
				}
				int n, m, k;
				cout << "Ingrese n: ";
				cin >> n;
				while(n <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese n: ";
					cin >> n;
					cout << endl;
				}
				cout << "Ingrese m: ";
				cin >> m;
				while(m <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese m: ";
					cin >> m;
					cout << endl;
				}
				cout << "Ingrese k: ";
				cin >> k;
				while(k <= 0) {
					cout << "Ingrese un numero no negativo" << endl;
					cout << "Ingrese m: ";
					cin >> m;
					cout << endl;
				}
				cout << endl;
				int fila, col;
				cout << "Coordenadas de inicio de ruta" << endl;
				cout << "Ingrese la fila: ";
				cin >> fila;
				while(fila < 0) {
					cout << "Ingrese un numero mayor o igual que 0" << endl;
					cout << "Ingrese la fila: ";
					cin >> fila;
					cout << endl;
				}
				cout << "Ingrese la columna: ";
				cin >> col;
				while(col < 0) {
					cout << "Ingrese un numero mayor o igual que 0" << endl;
					cout << "Ingrese la columna: ";
					cin >> col;
					cout << endl;
				}
				ruta(num, n, m, k, fila, col);
				cout << endl;
				break;
			}
		}//fin del switch
	}//fin del while
	return 0;
}

int menu() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Generar Secuencia" << endl;
	cout << "2. Matriz con Obstaculos" << endl;
	cout << "3. Ruta" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cout << endl;
	while(opcion <=0 || opcion > 4) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}

char* llenar_arreglo(int size) {
	char* arreglo = new char[size];
	char letra;
	cout << "Procure que las letras sean MAYUSCULAS" << endl;
	for(int i = 0; i < size; i++) {
		cout << "Ingrese el caracter [" << i << "]: ";
		cin >> letra;
		arreglo[i] = letra;
	}
	cout << endl;
	return arreglo;
}

char* secuencia(char* arreglo, int size) {
	int tam = 0;
	int size_digitos;
	char digitos[2];
	char digito[1];
	int aux;
	for(int i = 0; i < size; i++) {
		if((int)arreglo[i] >= 48 && (int)arreglo[i] <= 57) {
			if((int)arreglo[i+1] >= 48 && (int)arreglo[i+1] <= 57) {
				digitos[0] = arreglo[i];
				digitos[1] = arreglo[i+1];
				aux = atoi(digitos);
				tam += aux;
				digitos[0] = 0;
				digitos[1] = 0;
				aux = 0;
				i++;
			} else {
				digito[0] = arreglo[i];
				aux = atoi(digito);
				tam += aux;
				digito[0] = 0;
				aux = 0;
			}
		}
	}
	char* secuencia = new char[tam];
	int cont = 0;
	for(int i = 0; i < size; i++) {
		if(cont < tam) {
			if((int)arreglo[i] >= 48 && (int)arreglo[i] <= 57) {
				if((int)arreglo[i+1] >= 48 && (int)arreglo[i+1] <= 57) {
					digitos[0] = arreglo[i];
					digitos[1] = arreglo[i+1];
					aux = atoi(digitos);
					for(int j = 0; j < aux; j++) {
						secuencia[cont] = arreglo[i+2];
						cont++;
					}
					digitos[0] = 0;
					digitos[1] = 0;
					aux = 0;
				} else {
					digito[0] = arreglo[i];
					aux = atoi(digito);
					for(int j = 0; j < aux; j++) {
						secuencia[cont] = arreglo[i+1];
						cont++;
					}
					digito[0] = 0;
					aux = 0;
				}
			}
		}

	}
	tamano = tam;
	return secuencia;
}

void imprimir_arreglo(char* arreglo, int size) {
	cout << "[";
	for(int i = 0; i < size; i++) {
		if(i == size-1) {
			cout << "'" << arreglo[i] << "'" << "]";
		} else {
			cout << "'" << arreglo[i] << "'" << ",";
		}
	}
	cout << endl;
}

int numero_random(int inicio, int limite) {
	return inicio + (rand() % (limite - inicio));
}

char** llenar_matriz(int n, int m, int k) {
	//reservar el espacio de memoria
	char** matriz;
	matriz = new char*[n];
	for(int i = 0; i < n; i++) {
		matriz[i] = new char[m];
	}
	//llenar toda la matriz con guiones
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			*(*(matriz+i)+j) = '-';
		}
	}
	//generar las posiciones de los obstaculos y asignarlos a la matriz
	srand ((unsigned)time(0));
	int fila, col;
	for(int i = 0; i < k; i++) {
		fila = numero_random(0, n-1);
		col = numero_random(0, m-1);
		while(*(*(matriz+fila)+col) == '#') {
			fila = numero_random(0, n-1);
			col = numero_random(0, m-1);
		}
		*(*(matriz+fila)+col) = '#';
	}
	return matriz;
}

void imprimir_matriz(char** matriz, int n, int m) {
	for(int i = 0; i < n; i++) {
		cout << "| ";
		for(int j = 0; j < m; j++) {
			cout << "'" << *(*(matriz+i)+j) << "'" << " ";
		}
		cout << "|";
		cout << endl;
	}
}

void ruta(int size, int n, int m, int k, int fila, int col) {
	char* arreglo = llenar_arreglo(size);
	char* sec = secuencia(arreglo, size);
	cout << "Secuencia Ingresada por el Usuario: ";
	imprimir_arreglo(arreglo, size);
	cout << endl;
	cout << "Secuencia Transformada: ";
	imprimir_arreglo(sec, tamano);
	cout << endl;
	cout << "Matriz con n = " << n << ", m = " << m << ", k = " << k << endl;
	char** matriz = llenar_matriz(n, m, k);
	imprimir_matriz(matriz, n, m);
	cout << endl;
	cout << "Coordenadas de Inicio de la Ruta" << endl;
	cout << "Fila = " << fila << endl;
	cout << "Columna = " << col << endl;
	cout << endl;
	cout << "**ATENCION**" << endl;
	cout << "La ventana se limpiara para mostrar los pasos" << endl;
	cout << "Presiona enter para continuar" << endl;
	system("PAUSE");
	system("CLS");
	int pasos = 1;
	for(int i = 0; i < tamano; i++) {
		if(*(*(matriz+fila)+col) != '#' || (int)*(*(matriz+fila)+col) != 35) {
			if(sec[i] == 'U' || (int)sec[i] == 85) {
				*(*(matriz+fila)+col) = 186;
				if(*(*(matriz+(fila+1))+col) == 205) {
					if(*(*(matriz+(fila+1))+(col-1)) == 205 && *(*(matriz+(fila+1))+(col+1)) != 205) {
						*(*(matriz+(fila+1))+col) = 188;
					}
					if(*(*(matriz+(fila+1))+(col+1)) == 205 && *(*(matriz+(fila+1))+(col-1)) != 205) {
						*(*(matriz+(fila+1))+col) = 200;
					}
				}
				fila--;
			}
			if(sec[i] == 'D' || (int)sec[i] == 68) {
				*(*(matriz+fila)+col) = 186;
				if(*(*(matriz+(fila-1))+col) == 205) {
					if(*(*(matriz+(fila-1))+(col-1)) == 205 && *(*(matriz+(fila-1))+(col+1)) != 205) {
						*(*(matriz+(fila-1))+col) = 187;
					}
					if(*(*(matriz+(fila-1))+(col+1)) == 205 && *(*(matriz+(fila-1))+(col-1)) != 205) {
						*(*(matriz+(fila-1))+col) = 201;
					}
				}
				fila++;
			}
			if(sec[i] == 'R' || (int)sec[i] == 82) {
				*(*(matriz+fila)+col) = 205;
				if(fila+1 > n || *(*(matriz+fila+1)+(col-1)) != 186) {
					if(*(*(matriz+fila)+(col-1)) == 186) {
						*(*(matriz+fila)+(col-1)) = 200;
					}
				} else {
					if(*(*(matriz+fila)+(col-1)) == 186) {
						*(*(matriz+fila)+(col-1)) = 201;
					}
				}
				col++;
			}
			if(sec[i] == 'L' || (int)sec[i] ==76) {
				*(*(matriz+fila)+col) = 205;
				if(fila+1 > n || *(*(matriz+fila+1)+(col+1)) != 186) {
					if(*(*(matriz+fila)+(col+1)) == 186) {
						*(*(matriz+fila)+(col+1)) = 188;
					}
				} else {
					if(*(*(matriz+fila)+(col+1)) == 186) {
						*(*(matriz+fila)+(col+1)) = 187;
					}
				}
				col--;
			}
			cout << "Paso " << pasos << ":" << endl;
			imprimir_matriz(matriz, n, m);
			cout << endl;
			cout << "Presione enter para ver el siguiente paso" << endl;
			system("PAUSE");
			system("CLS");
			pasos++;
		}
	}
	cout << "Ruta Terminada" << endl;
	delete[] arreglo;
	delete[] sec;
	tamano = 0;
	for(int i = 0; i < n; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
}
