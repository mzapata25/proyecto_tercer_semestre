#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

void swapString(string arr[], int i, int j) {
	string aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

void ordenaBurbujaAscendente(int arr[], int tam) {
	int size = tam;
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void ordenaBurbujaAscendenteString(string arr[], int tam) {
	int size = tam;
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapString(arr, j, j + 1);
			}
		}
	}
}

void ordenaBurbujaDescendente(int arr[], int tam) {
	int size = tam;
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void ordenaBurbujaDescendenteString(string arr[], int tam) {
	int size = tam;
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				swapString(arr, j, j + 1);
			}
		}
	}
}

void etiquetas(string arrL[]){
	for(int i = 0; i <= 4; i++){
		cout << arrL[i] << "	";
		if(i == 0){
			cout << "                	";
		}
	}
}

void imprimeDefault(string arrL[], string arrT[], int arr1[][4]){
	etiquetas(arrL);
	cout << endl << endl;
	for(int i = 0; i <= 19; i++){
		cout << arrT[i] << "		";
		for(int j = 0; j <= 3; j++){
			cout << arr1[i][j] << "	";
		}
		cout << endl;
	}
	
}

int main(){
	int array1[20][4] = {{15, 17, 4, 13}, {11, 9, 2, 7}, {11, 9, 2, 7}, {11, 11, 8, 3}, {10, 8, 6, 2}, {9, 13, 10, 3}, {8, 5, 4, 1}, {8, 4, 4, 0}, {7, 7, 6, 1}, {7, 7, 6, 1}, {7, 8, 8, 0}, {7, 5, 5, 0}, {7, 6, 10, -4}, {5, 4, 6, -2}, {5, 3, 7, -4}, {4, 3, 7, -4}, {4, 2, 13, -11}, {3, 2, 4, -2}, {2, 6, 10, -4}, {1, 3, 10, -7}};
	string arrayTeams[20] = {"01. Barcelona	", "02. At. Madrid	", "03. Real Madrid	", "04. Villarreal	", "05. Athletic	", "06. Celta Vigo	", "07. Real Betis	", "08. RCD Mallorca", "09. Rayo Vallecano", "10. Alaves	", "11. Girona	", "12. RCD Espanyol", "13. Osasuna	", "14. Sevilla	", "15. Leganes	", "16. Real Sociedad", "17. Valladolid	", "18. Getafe	", "19. UD Las Palmas", "20. Valencia CF	"};
	string arrayLabels[5] = {"Equipo", "Pts", "GF", "GC", "DG"};
	int arrayGroupSorted[20] = {};
	int arrayPositions[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};	

	imprimeDefault(arrayLabels, arrayTeams, array1);
	int number = 0;
	for(int i = 0; i <= 19; i++){
		for(int j = 0; j <= 3; j++){
			if(j == number){
				arrayGroupSorted[i] = array1[i][j];
			}
		}
	}
	cout << endl << endl;
	ordenaBurbujaAscendente(arrayGroupSorted, 19);
	ordenaBurbujaDescendenteString(arrayTeams, 19);
	etiquetas(arrayLabels);
	cout << endl;
	for(int i = 0; i <= 19; i++){
		cout << arrayTeams[i] << "		";
		cout << arrayGroupSorted[i] << "	";
		for(int j = 1; j <= 3; j++){
			cout << array1[19 - i][j] << "	";
		}
		cout << endl;
	}
	return 0;
}
