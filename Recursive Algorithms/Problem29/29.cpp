//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct tElemento{
	int canicas = 0;
	std::string nombre;
};


/*Ecuacione de recurrencia --> Requisito de Implementacion
T(n){ c0 si n= 1
	{ c1 +2T(n/2) si n >1

Coste de la solucion --> F(O(n))
*/

// función que resuelve el problema
tElemento resolver(std::vector<tElemento>const &lista, int ini, int fin) {//Introducimos filas por vector -->Requisito de implementacion
	tElemento sol;
	if (ini + 1 == fin){
		sol.canicas = lista[ini].canicas;
		sol.nombre = lista[ini].nombre;
	}
	else {
		int mitad = (ini + fin + 1) / 2;
		tElemento izq = resolver(lista, ini, mitad);
		tElemento derec = resolver(lista, mitad, fin);
		if (izq.canicas >= derec.canicas){
			sol.nombre = izq.nombre;
			sol.canicas = izq.canicas + (derec.canicas / 2);
		}
		else{
			sol.nombre = derec.nombre;
			sol.canicas = derec.canicas + (izq.canicas / 2);
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	

	tElemento sol;
	int tam;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<tElemento>lista(tam);
	for (int j = 0; j<tam; j++){
		std::cin >> lista[j].nombre;
		std::cin >> lista[j].canicas;
	}
		sol = resolver(lista, 0, lista.size());
	// escribir sol
		std::cout << sol.nombre << " " << sol.canicas << std::endl;
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
