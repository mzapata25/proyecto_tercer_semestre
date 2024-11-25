#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#define EQUIPOS "equipos.csv"

using namespace std;

class Team{
	private:
		int posicion;
		string nombre;
		int puntos;
		int golesFavor;
		int golesContra;
		int difGoles;
	public:
		Team();
		Team(int, string, int, int, int);
		void asignaDatos(Team[]);
		void printData();
		void etiquetas(string[]);
		void ordenaMerge(Team[], int, int, int[]);
		void mergeSplit(vector<int>&, vector<int>&, int, int);
		void mergeArray(vector<int>&, vector<int>&, int, int, int);
		void copyArray(vector<int>&, vector<int>&, int, int);
		void getArray(Team[], int[], int);
		void reemplazarCampo(const string&, Team[]);
};

Team::Team(){
	posicion = 1;
	nombre = "FC Barcelona";
	puntos = 33;
	golesFavor = 40;
	golesContra = 12;
	difGoles = golesFavor - golesContra;
}

Team::Team(int po, string n, int pu, int gf, int gc){
	posicion = po;
	nombre = n;
	puntos = pu;
	golesFavor = gf;
	golesContra = gc;
	difGoles = gf-gc;
}

void Team::asignaDatos(Team arr[]){
	int i = 0;
	ifstream archivo(EQUIPOS);
	string linea;
	char delimitador = ',';
	getline(archivo, linea);
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string nom, pun, golF, golC;
        // Extraer todos los valores de esa fila
		getline(stream, nom, delimitador);
		arr[i].nombre = nom;
        getline(stream, pun, delimitador);
		arr[i].puntos = stoi(pun);
        getline(stream, golF, delimitador);
		arr[i].golesFavor = stoi(golF);
        getline(stream, golC, delimitador);
		arr[i].golesContra = stoi(golC);
		arr[i].difGoles = arr[i].golesFavor - arr[i].golesContra;
		i++;
    }
	archivo.close();
}



void Team::etiquetas(string arrL[]){
	for(int i = 0; i <= 5; i++){
		cout << arrL[i] << "	";
		if(i == 1){
			cout << "                ";
		}
	}
}

void Team::printData(){
	cout << left << endl << setw(7) << posicion << " "
    << setw(23) << nombre << " "
    << setw(8) << puntos
    << setw(8) << golesFavor
    << setw(8) << golesContra
    << setw(8) << difGoles;
}


void Team::getArray(Team arr[], int newArray[], int el){
	if(el==1){
		for(int i{0}; i<20;i++){
			newArray[i] = arr[i].puntos;
		}
	}
	else if(el==2){
		for(int i{0}; i<20;i++){
			newArray[i] = arr[i].golesFavor;
		}
	}
	else if(el==3){
		for(int i{0}; i<20;i++){
			newArray[i] = arr[i].golesContra;
		}
	}
	else if(el==4){
		for(int i{0}; i<20;i++){
			newArray[i] = arr[i].difGoles;
		}
	}
}


void Team::ordenaMerge(Team arr[], int el, int way, int arrP[]){
	Team tElim{0, "", -100, -200, -100};
	int newArray[20];
	getArray(arr, newArray, el);
	vector<int> v(newArray, newArray + 20);
	vector<int> tmp(v.size());
	mergeSplit(v, tmp, 0, v.size() - 1);
	//De menor a mayor
	if(way == 1){
		int aux = 20;
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 20; j++){
				if(el==1){
					if(v[i] == arr[j].puntos){
						arr[j].posicion = aux;
						arrP[j] = arr[j].posicion;
						if(i==3){
							cout << endl << "		--- Zona de descenso ---";
						}						
						arr[j].printData();
						arr[j] = tElim;
						aux--;
						break;
					}
				}				
				if(el==2){
					if(v[i] == arr[j].golesFavor){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==3){
					if(v[i] == arr[j].golesContra){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==4){
					if(v[i] == arr[j].difGoles){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
			}
		}
	}
	cout << endl << endl;
	//De mayor a menor
	if(way == 0){
		int aux = 1;		
		for(int i = 19; i >= 0; i--){
			for(int j = 19; j >= 0; j--){
				if(el==1){
					if(v[i] == arr[j].puntos){
						arr[j].posicion = aux;
						arrP[j] = arr[j].posicion;
						arr[j].printData();
						if(i==3){
							cout << endl << "		--- Zona de descenso ---";
						}						
						arr[j] = tElim;
						aux++;
						break;
					}
				}					
				if(el==2){
					if(v[i] == arr[j].golesFavor){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==3){
					if(v[i] == arr[j].golesContra){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==4){
					if(v[i] == arr[j].difGoles){
						arr[j].posicion = arrP[j];
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
			}
		}
	}
}

void Team::mergeSplit(vector<int> &A, vector<int> &B, int low, int high) {
	int mitad = (high-low) / 2;
	if(low < high){
		int mitad = (high+low) / 2;
		mergeSplit(A, B, low, mitad);
		mergeSplit(A, B, mitad + 1, high);
		mergeArray(A, B, low, mitad, high);
	}
}


void Team::mergeArray(vector<int> &A, vector<int> &B, int low, int mid, int high) {
	int i_ordenado = low;
	int i = low;
	int j = mid + 1;
	
	while(i <= mid && j <= high){
		if(A[i] <= A[j]){
			B[i_ordenado] = A[i];
			i++;
		}
		else{
			B[i_ordenado] = A[j];
			j++;
		}
		i_ordenado++;
	}
	while(i <= mid){
		B[i_ordenado] = A[i];
		i++;
		i_ordenado++;
	}
	while(j <= high){
		B[i_ordenado] = A[j];
		j++;
		i_ordenado++;
	}
		
	copyArray(A, B, low, high);
}

void Team::copyArray(vector<int> &A, vector<int> &B, int low, int high) {
	int i = low;
	int limit = high;
	for(i; i <= limit; i++){
		A[i] = B[i];
	}
}



void Team::reemplazarCampo(const string& archivo, Team arr[]) {
    int variable = 0;
	string nombreEquipo;
	cout << endl << "Introduce el nombre del equipo a modificar, EXACTAMENTE como se lee en la tabla, includios mayusculas y espacios." << endl;
	cin.ignore();
	getline(cin, nombreEquipo, '\n');
	ifstream entrada(archivo);

    string archivoTemporal = "temp.csv"; // Archivo temporal
    ofstream salida(archivoTemporal);

    string linea;
    char delimitador = ',';
    bool encontrado = false;
	
	cout << endl << "Para modificar nombre de equipo, introduce 1." << endl;
	cout << "Para modificar puntos de equipo, introduce 2." << endl;
	cout << "Para modificar goles a favor de equipo, introduce 3." << endl;
	cout << "Para modificar goles en contra de equipo, introduce 4." << endl;
	cin >> variable;
    // Leer encabezados y escribirlos en el archivo temporal
    if (getline(entrada, linea)) {
        salida << linea << endl;
    }

    // Procesar las líneas del archivo
    while (getline(entrada, linea)) {
        stringstream stream(linea);
        string nombre, puntos, golesFavor, golesContra;
        getline(stream, nombre, delimitador);
        getline(stream, puntos, delimitador);
        getline(stream, golesFavor, delimitador);
        getline(stream, golesContra, delimitador);
		//cout << nombre << "		" << nombreEquipo << endl;

        if (nombre == nombreEquipo) {
            encontrado = true;
			if(variable==1){
				string nuevoNombre;
				cout << endl <<"Introduce nuevo nombre:" << endl;
				cin >> nuevoNombre;
				nombre = nuevoNombre;
			}
			else if(variable==2){
				int nuevosPuntos;
				cout << endl <<"Introduce nueva cantidad de puntos:" << endl;
				cin >> nuevosPuntos;
				puntos = to_string(nuevosPuntos);
			}
			else if(variable==3){
				int nuevosGolesF;
				cout << endl <<"Introduce nuevos goles a favor:" << endl;
				cin >> nuevosGolesF;
				golesFavor = to_string(nuevosGolesF);
				difGoles = stoi(golesFavor) - stoi(golesContra);
			}
			else if(variable==4){
				int nuevosGolesC;
				cout << endl <<"Introduce nuevos goles en contra:" << endl;
				cin >> nuevosGolesC;
				golesContra = to_string(nuevosGolesC);
				difGoles = stoi(golesFavor) - stoi(golesContra);
			}
        }

        // Escribir la línea (modificada o no) en el archivo temporal
        salida << nombre << delimitador << puntos << delimitador << golesFavor << delimitador << golesContra << endl;
    }

    entrada.close();
    salida.close();

    // Reemplazar el archivo original con el archivo temporal
    if (encontrado) {
		if (remove(archivo.c_str()) != 0 || rename(archivoTemporal.c_str(), archivo.c_str()) != 0) {
            //cerr << "Error al reemplazar el archivo original." << endl;
        } else {
            //cout << "Campo actualizado con éxito." << endl;
        }
	}
    else {
        //cerr << "Equipo no encontrado. No se realizaron cambios." << endl;
        remove(archivoTemporal.c_str()); // Eliminar archivo temporal
    }
}


int main() {
	int element = 0;
	int command;
	int modifier;
	int way;
	int arrPos[20];
		string arrayLabels[6] = {"Pos.", "Equipo", "Pts", "GF", "GC", "DG"};
		Team t01{};
		Team t02{};
		Team t03{};
		Team t04{};
		Team t05{};
		Team t06{};
		Team t07{};
		Team t08{};
		Team t09{};
		Team t10{};
		Team t11{};
		Team t12{};
		Team t13{};
		Team t14{};
		Team t15{};
		Team t16{};
		Team t17{};
		Team t18{};
		Team t19{};
		Team t20{};
		Team arregloEquipos[20] {t01,t02,t03,t04,t05,t06,t07,t08,t09,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20};
		//t01.reemplazarCampo(EQUIPOS, "FC Barcelona", 60);
		t01.asignaDatos(arregloEquipos);
		//t01.reemplazarCampo(EQUIPOS, 0);
		t01.etiquetas(arrayLabels);
		t01.ordenaMerge(arregloEquipos,1,0, arrPos);
	while(command != 5){
		string arrayLabels[6] = {"Pos.", "Equipo", "Pts", "GF", "GC", "DG"};
		t01.asignaDatos(arregloEquipos);
		cout << endl << endl;
		cout << "Para ordenar por puntuacion, introduce 1" << endl;
		cout << "Para goles a favor, introduce 2" << endl;
		cout << "Para goles en contra, introduce 3" << endl;
		cout << "Para diferencia de goles, introduce 4" << endl;
		cout << endl << "Para salir introduce tan solo el numero 5." << endl;
		cout << "Para modificar algun registro, introduce 6." << endl;
		cin >> command;
		if(command == 5){
			break;
		}
		else if(command == 6){
			t01.reemplazarCampo(EQUIPOS, arregloEquipos);
		}
		else{
			cout << endl << "Para orden ascendente, introduzca 1, para orden descendente, introduzca 0" << endl;
			cin >> way;
			cout << endl << endl;
			t01.etiquetas(arrayLabels);
			if (command > 0 and command < 5){
				t01.ordenaMerge(arregloEquipos, command, way, arrPos);
			}
			cout << endl << endl;
		}
	}
    return 0;
}
