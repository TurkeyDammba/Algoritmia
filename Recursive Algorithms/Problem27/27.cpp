// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*Ecuacion de recurrencia -->Requisito de implementacion
	T(n){ c0 si n =1
		{ 2T(n/2) si n > 1

	Coste de la solucion --> F(O(nlogn))

*/



// función que resuelve el problema
int resolver(std::vector<int> &v, int ini, int fin){

	if (ini + 1 >= fin){//caso base de 0,1 elemento
		return 0;
	}
	else {
		int mitad = (ini + fin) / 2;
		int izq = resolver(v, ini, mitad);
		int derec = resolver(v, mitad, fin);
		int inversiones = 0;
		int i = ini;
		int j = mitad;
		while (i < mitad && j <fin){//calculamos numero de inversiones
			if (v[i] > v[j]){
				inversiones = inversiones + (mitad - i);
				j++;
			}
			else {
				i++;
			}
		}
		int tam = fin - ini;
		std::vector<int>aux(tam);
		std::merge(v.begin() + ini, v.begin() + mitad, v.begin() + mitad, v.begin() + fin, aux.begin());
		for (int i = 0; i < aux.size(); i++){//copiamos en el vector original
			v[ini] = aux[i];
			ini++;
		}
		return inversiones + izq + derec;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<int>v(tam);
	for (int i = 0; i < tam; i++){
		std::cin >> v[i];
	}

	int sol = resolver(v, 0, v.size());
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
