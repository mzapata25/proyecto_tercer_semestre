#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#define EQUIPOS "equipos.csv"

using namespace std;

class BST;

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
		void reemplazarCampo(const string&, Team[]);
		
		friend class BST;
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
        string pos, nom, pun, golF, golC;
        // Extraer todos los valores de esa fila
		getline(stream, pos, delimitador);
		arr[i].posicion = stoi(pos);
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





void Team::reemplazarCampo(const string& archivo, Team arr[]) {
    int variable = 0;
	string nombreEquipo;
	cout << endl << "Introduce el nombre del equipo a modificar, EXACTAMENTE como se lee en la tabla, includios mayusculas y espacios." << endl;
	cin.ignore();
	getline(cin, nombreEquipo, '\n');
	ifstream entrada(archivo);

    string archivoTemporal = "temp.csv"; 
    ofstream salida(archivoTemporal);

    string linea;
    char delimitador = ',';
    bool encontrado = false;
	
	cout << endl << "Para modificar nombre de equipo, introduce 1." << endl;
	cout << "Para modificar puntos de equipo, introduce 2." << endl;
	cout << "Para modificar goles a favor de equipo, introduce 3." << endl;
	cout << "Para modificar goles en contra de equipo, introduce 4." << endl;
	cin >> variable;
    if (getline(entrada, linea)) {
		salida << linea << endl;
    }

    while (getline(entrada, linea)) {
        stringstream stream(linea);
        string posicion, nombre, puntos, golesFavor, golesContra;
		getline(stream, posicion, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, puntos, delimitador);
        getline(stream, golesFavor, delimitador);
        getline(stream, golesContra, delimitador);

        if (nombre == nombreEquipo) {
			encontrado = true;
			if(variable==1){
				string nuevoNombre;
				cout << endl <<"Introduce nuevo nombre:" << endl;
				cin.ignore();
				getline(cin, nuevoNombre, '\n');
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

        salida << posicion << delimitador << nombre << delimitador << puntos << delimitador << golesFavor << delimitador << golesContra << endl;
    }

    entrada.close();
    salida.close();

    
    if (encontrado) {
		if (remove(archivo.c_str()) != 0 || rename(archivoTemporal.c_str(), archivo.c_str()) != 0) {
            
        } else {
            
        }
	}
    else {
       
        remove(archivoTemporal.c_str()); 
    }
}

class TreeNode {
	private:	
		Team data;
		TreeNode* left;
		TreeNode* right;

		TreeNode(Team team) : data(team), left(nullptr), right(nullptr) {}
		
		friend class BST;
		
};

class BST {
    TreeNode* root;

    void inOrder(TreeNode* node, vector<Team>& sortedTeams) {
		if (node == nullptr) return;
        inOrder(node->left, sortedTeams);
        sortedTeams.push_back(node->data);
        inOrder(node->right, sortedTeams);
    }

   TreeNode* insert(TreeNode* node, Team team, int key, int attribute) {
        if (node == nullptr) return new TreeNode(team);
        if(attribute==1){
			if (key < node->data.puntos){
				node->left = insert(node->left, team, key,attribute);
			}
			else{
				node->right = insert(node->right, team, key,attribute);
			}

		}
		else if(attribute==2){
			if (key < node->data.golesFavor){ 
				node->left = insert(node->left, team, key,attribute);
			}
			else{
				node->right = insert(node->right, team, key,attribute);
			}

		}
		else if(attribute==3){
			if (key < node->data.golesContra){ 
				node->left = insert(node->left, team, key,attribute);
			}
			else{
				node->right = insert(node->right, team, key,attribute);
			}
		}
		else if(attribute==4){
			if (key < node->data.difGoles){
				node->left = insert(node->left, team, key,attribute);
			}
			else{
				node->right = insert(node->right, team, key,attribute);
			}

		}
		return node;
   }
   
   void inOrderTraversal(TreeNode* root, int& positionCounter, int attribute, int way) {
    if (root != nullptr) {
		inOrderTraversal(root->right, positionCounter, attribute, way);
		if(positionCounter==18){
			cout << endl << "		--- Zona de descenso ---";
		}
        if(attribute==1){
			root->data.posicion = positionCounter++;
		}
        root->data.printData(); 
        inOrderTraversal(root->left, positionCounter, attribute, way);
		}
	}



public:
    BST() : root(nullptr) {}

    void insert(Team team, int attribute) {
		if(attribute==1){
			root = insert(root, team, team.puntos, 1);
		}
		else if(attribute==2){
			root = insert(root, team, team.golesFavor, 2);
		}
		else if(attribute==3){
			root = insert(root, team, team.golesContra, 3);
		}
		else if(attribute==4){
			root = insert(root, team, team.difGoles, 4);
		}
    }

    vector<Team> getSortedTeams(int attribute, int way) {
        vector<Team> sortedTeams;
		int positionCounter = 1; 
		inOrderTraversal(root, positionCounter, attribute, way);
        return sortedTeams;
    }

};


int main() {
	int element = 0;
	int command;
	int modifier = 1;
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
		t01.asignaDatos(arregloEquipos);
		t01.etiquetas(arrayLabels);
		BST bst;
		for (int i = 0; i < 20; i++) {
			bst.insert(arregloEquipos[i],1);
		}
		vector<Team> sortedTeams = bst.getSortedTeams(1, 1);
		cout << endl;
		while(modifier!=0){
			cout << endl << endl << "Para cerrar el programa, introduce 0" << endl;
			cout << "Para ordenar por puntuacion, introduce 1" << endl;
			cout << "Para ordenar por goles a favor, introduce 2" << endl;
			cout << "Para ordenar por goles en contra, introduce 3" << endl;
			cout << "Para ordenar por diferencia de goles, introduce 4." << endl;
			cout << "Para modificar registros, introduce 5." << endl;
			cin>>command;
			if(command==0){
				break;
			}
			else if(command==5){
				t01.reemplazarCampo(EQUIPOS, arregloEquipos);
			}
			else{
				t01.asignaDatos(arregloEquipos);
				cout << endl << endl;
				BST bst2;
				t01.etiquetas(arrayLabels);
				for (int i = 0; i < 20; i++) {
					bst2.insert(arregloEquipos[i],command);
				}
				vector<Team> sortedTeams2 = bst2.getSortedTeams(command, 1);
			}
		}
    return 0;
}
