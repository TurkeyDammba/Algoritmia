// Manuel Monforte Escobar
// E37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*Ecuacion de recurrencia --> Requisito de Implementacion
	T(n){ c0 si n = 1
		{ T(n/2)+c0 si n > 1

*/


// función que resuelve el problema
int resolver(std::vector<int> const &v, int ini, int fin) {
	int sol = 0;
	if (ini + 1 == fin){//caso base de 1 elemento
		return ini;
	}
	else {//vector n >1 elementos
		int mitad = (ini + fin) / 2;
		if (mitad % 2 == 0){
			if (v[mitad] == v[mitad - 1]){
				return resolver(v, ini, mitad);
			}
			else {
				return resolver(v, mitad, fin);
			}
		}
		else {
			if (v[mitad] == v[mitad - 1]){
				return resolver(v, mitad, fin);
			}
			else {
				return resolver(v, ini, mitad);
			}
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam = 0;
	std::cin >> tam;
	std::vector<int>v(tam);
	for (int i = 0; i < tam; i++){
		std::cin >> v[i];
	}

	int sol = resolver(v,0,v.size());
	// escribir sol
	std::cout << sol << std::endl;

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
