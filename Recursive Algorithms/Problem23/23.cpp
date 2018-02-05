// Manuel Monforte Esocbar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*Ecuacion de Recurrencia y coste de la solucion -->Requisito de implementacion
T(n){ c0	 si	n = 0
{ T(n/2)+ c1 si n >1
Coste constante --> F(O(logn))
*/



// función que resuelve el problema
char resolver(std::vector<char> const &v, int ini,int fin) {
	char sol;
	if (ini+2==fin){//caso base de dos elementos
		sol= v[ini] + 1;
	}
	else {
		int mitad = (ini+fin)/2;
		if(v[mitad]-v[0]==mitad){
			sol = resolver(v,mitad,fin);
		}
		else {
			sol = resolver(v,ini,mitad+1);
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char sol = ' ';
	char ini = 0;
	char fin = 0;
	std::cin >> ini;
	std::cin >> fin;
	int tam = fin - ini;
	std::vector<char>v(tam);
	for (int i = 0; i < tam; i++){
		std::cin >> v[i];
	}
	//si falta la primera letra o la ultima no aplicamos recursividad
	if (v[0] != ini){
		sol = ini;
	}
	else  if (v[v.size() - 1] != fin){
		sol = fin;
	}
	else {
		sol = resolver(v, ini,fin);
	}
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
