//Manuel Monforte Escobar


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tColores{
	int azules = 0;
	int rojos = 0;
	int verdes = 0;
};

bool esValida(std::vector<int>const &sol, int k, tColores iniciales, tColores usadas){
	bool valido = true;
	if (usadas.azules > iniciales.azules || usadas.rojos > iniciales.rojos ||
		usadas.verdes > iniciales.verdes){
		valido = false;
	}
	if (sol[k] == sol[k - 1] && sol[k] == 2){// se repite color verde
		valido = false;
	}
	if (usadas.verdes > usadas.azules){// usa mas verdes que azules
		valido = false;
	}
	return valido;
}


// función que resuelve el problema
void resolver(std::vector<int>&sol, int k, tColores iniciales, tColores usadas,bool &pintado) {
	for (int i = 0; i < 3; i++){
		sol[k] = i;
		if (i == 0){
			usadas.azules++;
		}
		else if(i==1){
			usadas.rojos++;
		}
		else {
			usadas.verdes++;
		}
		if (esValida(sol,k,iniciales,usadas)){
			if (k == sol.size() - 1){
				if (usadas.rojos > usadas.verdes + usadas.azules){
					for (int i = 0; i < sol.size(); i++){
						switch (sol[i]){
						case 0: {std::cout << "azul "; }
							break;
						case 1: {std::cout << "rojo "; }
							break;
						case 2: {std::cout << "verde "; }
							break;
						}
					}
					pintado = true;
					std::cout << std::endl;
				}
			}
			else{
				resolver(sol, k + 1, iniciales, usadas, pintado);
			}
		}
		if (i == 0){
			usadas.azules--;
		}
		else if (i == 1){
			usadas.rojos--;
		}
		else {
			usadas.verdes--;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int h = 0;
	std::cin >> h;
	std::vector<int>sol(h,-1);
	tColores iniciales;
	std::cin >> iniciales.azules;
	std::cin >> iniciales.rojos;
	std::cin >> iniciales.verdes;
	bool pintado = false;
	tColores usadas;
	if (iniciales.rojos <= 0){
		std::cout << "SIN SOLUCION\n" <<  std::endl;
	}
	else{
		sol[0] = 1;
		usadas.rojos++;
		resolver(sol, 1, iniciales, usadas, pintado);
		std::cout << std::endl;

		if (!pintado){
			std::cout << "SIN SOLUCION\n" << std::endl;
		}
	}
	// escribir sol

	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}