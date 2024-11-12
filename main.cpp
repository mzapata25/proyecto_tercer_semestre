#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team{
	private:
		string nombre;
		int puntos;
		int golesFavor;
		int golesContra;
		int difGoles;
	public:
		Team();
		Team(string, int, int, int);
		void printData();
		void etiquetas(string[]);
		void ordenaMergeString(Team[], int);
		void mergeSplitString(vector<string>&, vector<string>&, int, int);
		void mergeArrayString(vector<string>&, vector<string>&, int, int, int);
		void copyArrayString(vector<string>&, vector<string>&, int, int);
		void getArrayString(Team[], string[], int);
		void ordenaMerge(Team[], int, int);
		void mergeSplit(vector<int>&, vector<int>&, int, int);
		void mergeArray(vector<int>&, vector<int>&, int, int, int);
		void copyArray(vector<int>&, vector<int>&, int, int);
		void getArray(Team[], int[], int);
		void swapString(string[], int, int);
		void swap(int[], int, int);
};

Team::Team(){
	nombre = "01. FC Barcelona";
	puntos = 33;
	golesFavor = 40;
	golesContra = 12;
	difGoles = golesFavor - golesContra;
}

Team::Team(string n, int p, int gf, int gc){
	nombre = n;
	puntos = p;
	golesFavor = gf;
	golesContra = gc;
	difGoles = gf-gc;
}

void Team::etiquetas(string arrL[]){
	for(int i = 0; i <= 4; i++){
		cout << arrL[i] << "	";
		if(i == 0){
			cout << "                	";
		}
	}
}

void Team::printData(){
	cout << endl << nombre << "		";
	cout << puntos << "	";
	cout << golesFavor << "	";
	cout << golesContra << "	";
	cout << difGoles << "	";
}


void Team::getArrayString(Team arr[], string newArray[], int el){
	if(el==0){
		for(int i{0}; i<20;i++){
			newArray[i] = arr[i].nombre;
		}
	}
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

void Team::ordenaMergeString(Team arr[], int way){
	string newArray[20];
	getArrayString(arr, newArray, 0);
	vector<string> v(newArray, newArray + 20);
	vector<string> tmp(v.size());
	mergeSplitString(v, tmp, 0, v.size() - 1);
	//De menor a mayor
	if(way == 0){
		for(int i = 0; i < 20; i++){
			arr[i].printData();
		}
	}
	cout << endl << endl;
	//De mayor a menor
	if(way == 1){
		for(int i = 19; i >= 0; i--){
			arr[i].printData();
		}
	}
}

void Team::mergeSplitString(vector<string> &A, vector<string> &B, int low, int high) {
	int mitad = (high-low) / 2;
	if(low < high){
		int mitad = (high+low) / 2;
		mergeSplitString(A, B, low, mitad);
		mergeSplitString(A, B, mitad + 1, high);
		mergeArrayString(A, B, low, mitad, high);
	}
}


void Team::mergeArrayString(vector<string> &A, vector<string> &B, int low, int mid, int high) {
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
		
	copyArrayString(A, B, low, high);
}

void Team::copyArrayString(vector<string> &A, vector<string> &B, int low, int high) {
	int i = low;
	int limit = high;
	for(i; i <= limit; i++){
		A[i] = B[i];
	}
}

void Team::ordenaMerge(Team arr[], int el, int way){
	Team tElim{"", -100, -200, -100};
	int newArray[20];
	getArray(arr, newArray, el);
	vector<int> v(newArray, newArray + 20);
	vector<int> tmp(v.size());
	mergeSplit(v, tmp, 0, v.size() - 1);
	//De menor a mayor
	if(way == 1){
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 20; j++){
				if(el==2){
					if(v[i] == arr[j].golesFavor){
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==3){
					if(v[i] == arr[j].golesContra){
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==4){
					if(v[i] == arr[j].difGoles){
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
		for(int i = 19; i >= 0; i--){
			for(int j = 19; j >= 0; j--){
				if(el==2){
					if(v[i] == arr[j].golesFavor){
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==3){
					if(v[i] == arr[j].golesContra){
						arr[j].printData();
						arr[j] = tElim;
						break;
					}
				}
				if(el==4){
					if(v[i] == arr[j].difGoles){
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

void Team::swapString(string arr[], int i, int j) {
	string aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

void Team::swap(int arr[], int i, int j) {
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}


int main() {
    int element = 0;
	int command;
	int way;
	while(command != 5){
		string arrayLabels[5] = {"Equipo", "Pts", "GF", "GC", "DG"};
		Team t01{};
		t01.etiquetas(arrayLabels);
		Team t02{"02. Real Madrid	", 27, 25, 11};
		Team t03{"03. At. Madrid	", 26, 19, 7};
		Team t04{"04. Villarreal	", 24, 23, 19};
		Team t05{"05. Osasuna	", 21, 17, 20};
		Team t06{"06. Athletic	", 20, 19, 13};
		Team t07{"07. Real Betis	", 20, 14, 12};
		Team t08{"08. Real Sociedad", 18, 11, 10};
		Team t09{"09. RCD Mallorca", 18, 10, 10};
		Team t10{"10. Girona	", 18, 16, 17};
		Team t11{"11. Celta Vigo	", 17, 10, 22};
		Team t12{"12. Rayo Vallecano", 16, 13, 13};
		Team t13{"13. Sevilla	", 15, 12, 18};
		Team t14{"14. Leganes	", 14, 13, 16};
		Team t15{"15. Alaves	", 13, 14, 22};
		Team t16{"16. UD Las Palmas", 12, 16, 22};
		Team t17{"17. Getafe	", 10, 8, 11};
		Team t18{"18. RCD Espanyol", 10, 11, 22};
		Team t19{"19. Valladolid	", 9, 10, 25};
		Team t20{"20. Valencia CF	", 7, 8, 17};
		Team arregloEquipos[20] {t01,t02,t03,t04,t05,t06,t07,t08,t09,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20};
		for(int i{0}; i < 20; i++){
			if(i==17){
				cout << endl << "		--- Zona de descenso ---";
			}
			arregloEquipos[i].printData();
		}
		cout << endl << endl;
		cout << "Para ordenar por puntuacion, introduce 1, para goles a favor, 2, para goles en contra, 3, para diferencia de goles, 4." << endl;
		cout << "Para salir introduce tan solo el numero 5." << endl;
		cin >> command;
		if(command == 5 or command == 5){
			break;
		}
		cout << endl << "Para orden ascendente, introduzca 1, para orden descendente, introduzca 0" << endl;
		cin >> way;
		cout << endl << endl;
		t01.etiquetas(arrayLabels);
		if(command == 1){
			t01.ordenaMergeString(arregloEquipos, way);
		}
		else if (command > 1 and command < 5){
			t01.ordenaMerge(arregloEquipos, command, way);
		}
		cout << endl << endl;
	}
    return 0;
}
