// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*Ecuacion de recurrencia
	T(n){ c0 si n = 1
		{ T(n/2) +c0 si n > 1

		Coste de la Solucion --> F(O(logn))
*/
// función que resuelve el problema
int resolver(std::vector<int> const &v, int ini, int fin) {
	int minimo = 0;
	if (ini + 1 == fin) { // vector de 1 elemento
		minimo = v[ini];
	}
	else if (ini + 2 == fin){ // vector de 2 elementos
		if (v[ini] < v[ini + 1]){
			minimo = v[ini];
		}
		else {
			minimo = v[ini + 1];
		}
	}
	else {
		int mitad = (ini + fin)/ 2;
		if (v[mitad] < v[mitad - 1]&& v[mitad] < v[mitad+1] ){
			minimo = v[mitad];
		}
		else if (v[mitad] > v[mitad - 1]){
			minimo = resolver(v, ini, mitad);
		}
		else {
			minimo = resolver(v, mitad, fin);
		}
	}
	return minimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam = 0;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<int>v(tam);
	for (int i = 0; i < tam; i++){
		std::cin >> v[i];
	}
	int sol = resolver(v,0,v.size());

	// escribir sol
	std::cout << sol << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
