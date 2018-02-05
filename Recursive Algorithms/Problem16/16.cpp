//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int suma;
	bool ok;
}tSolucion;


/*Complejidad de la solucion recursiva //ecuaciones de recurrencia// entendemos por n el tamano del vector (fin-ini)
T(n){ c0 si n= 1
{ c1 +2T(n/2) si n >1

Coste de la solucion
T(n) = c1 + 2T(n/2) = c1 + 2(c1+2T(n/4)) = c1+2c1+2^2T(n/2^2) = c1+4c1+8c1+8T(n/8)= ... = c0
+c1+2c1...+2^(k-1)c1 +
2^kT(n/2^k) = Coste f(O(n))
*/

// función que resuelve el problema
tSolucion resolver(std::vector<int>const &lista, int ini, int fin) {//Introducimos filas por vector -->Requisito de implementacion
	tSolucion result1;
	result1.ok = true;
	result1.suma = 0;

	tSolucion result2;
	result2.ok = true;
	result2.suma = 0;

	tSolucion result;
	result.ok = true;
	result.suma = 0;


	int suma = 0;
	if (ini + 1 == fin){
		result.suma = lista[ini];
		result.ok = true;
		return result;
	}
	else {
		int mitad = (ini + fin + 1) / 2;
		result1 = resolver(lista, ini, mitad);
		result2 = resolver(lista, mitad, fin);
		result.ok = result1.ok && result2.ok && (result1.suma < result2.suma);
		result.suma = result1.suma + result2.suma;
		return result;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	bool vale = true;
	int filas = 0;
	int columnas = 0;
	std::cin >> filas;
	tSolucion sol;
	sol.ok = true;
	sol.suma = 0;
	if (!std::cin)
		return false;
	std::cin >> columnas;
	std::vector<int>lista(columnas);
	for (int i = 0; i < filas; i++){
		for (int j = 0; j<columnas; j++){
			std::cin >> lista[j];
		}
		sol = resolver(lista, 0, lista.size());
		if (!sol.ok){
			vale = false;
		}
	}
	// escribir sol
	if (vale){
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}
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
