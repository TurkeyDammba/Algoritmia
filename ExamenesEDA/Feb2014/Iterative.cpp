//Manuel Monforte Escobar


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const &v,int m) {
	int i = 0;
	int p = 0;
	int sumaParcial = 0;
	while (i < m){
		sumaParcial = sumaParcial + v[i];
		i++;
	}
	int suma = sumaParcial;
	i = 0;
	while (i<v.size() - m){
	sumaParcial = sumaParcial - v[i] + v[i + m];
		if (sumaParcial>suma){
		suma = sumaParcial;
		p = i + 1;
		}
		i++;
	}
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n = 0;
	int m = 0;
	std::cin >> n;
	std::cin >> m;
	std::vector<int>v(n);
	for (int i = 0; i < v.size(); i++){
		std::cin >> v[i];
	}
	int sol = resolver(v,m);
	// escribir sol


	std::cout << sol << "\n";
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