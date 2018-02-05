// Manuel Monforte Esocbar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*Ecuacion de Recurrencia y coste de la solucion -->Requisito de implementacion
T(n){ c0	 si	n = 0
	{ T(n/2)+ c1 si n >1

	n--> numero de elementos del segmento a analizar
Coste constante --> F(O(nlogn))
*/


struct tSolucion{
	bool encontrado = false;
	int tachado = -1;
};

// función que resuelve el problema
tSolucion resolver(std::vector<int> const &v, int cantado,int ini, int fin) {
	tSolucion sol;
	int mitad = (ini + fin) / 2;
	if (ini + 1 == fin || v[mitad] == mitad + cantado){
		sol.encontrado = (v[mitad] == mitad + cantado);
		sol.tachado = v[mitad];
	}
	else if(v[mitad] > mitad + cantado){
		sol = resolver(v, cantado, ini, mitad);
	}
	else if (v[mitad] < mitad + cantado){
		sol = resolver(v, cantado, mitad, fin);
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam = 0;
	int cantado = 0;
	std::cin >> tam;
	std::cin >> cantado;
	std::vector<int>v(tam);
	for (int i = 0; i < v.size(); i++){
		std::cin >> v[i];
	}

	tSolucion sol = resolver(v, cantado,0,v.size());

	// escribir sol
	if (sol.encontrado){
		std::cout << sol.tachado;;
	}
	else {
		std::cout << "NO";
	}
	std::cout << std::endl;
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
