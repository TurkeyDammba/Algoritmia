//Manuel Monforte Escobar


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int pares = 0;
	bool valido = false;
};
// función que resuelve el problema
tSol resolver(std::vector<int> const &v,int ini, int fin) {
	tSol sol;
	if (ini  == fin){
		if (v[ini] % 2 == 0){
			sol.pares = 1;
		}
		sol.valido = true;
	}
	else{
		int mitad = (ini + fin) / 2;
		tSol izq = resolver(v, ini, mitad);
		tSol derec = resolver(v, mitad+1, fin);

		if ((-2 <= izq.pares - derec.pares && izq.pares - derec.pares <= 2) && izq.valido && derec.valido){
			sol.valido = true;
		}
		sol.pares = izq.pares + derec.pares;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n = 0;
	std::cin >> n;
	std::vector<int>v(n);
	for (int i = 0; i < v.size(); i++){
		std::cin >> v[i];
	}
	tSol sol = resolver(v,0,v.size()-1);
	// escribir sol

	if (sol.valido){
		std::cout << "CAUCASICO" << "\n";
	}
	else{
		std::cout << "NO CAUCASICO" << "\n";

	}
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