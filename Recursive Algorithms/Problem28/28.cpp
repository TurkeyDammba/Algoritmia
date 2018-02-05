//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSolucion{
	bool adecuado = true;
	int suma = 0;
	int minimo = 0;
	int max = 0;
};

/*Ecuacion de Recurrencia --> Requisito de implementacion
	T(n){ c0 si n = 1
		{ 2T(n/2)+n si c0 > 1

	Coste de la solucion --> F(O(n))
*/


// función que resuelve el problema
tSolucion  resolver(std::vector<int> const &v, int ini, int fin) {
	tSolucion sol;
	if (ini + 1 == fin){//Vector de un elemento
		sol.adecuado = true;
		sol.suma = v[ini];
		sol.minimo = v[ini];
		sol.max = v[ini];

	}
	else {//Vector de mas de un elemento
		int mitad = (ini + fin) / 2;
		tSolucion izq = resolver(v, ini, mitad);
		tSolucion derec = resolver(v, mitad, fin);
		sol.suma = izq.suma + derec.suma;
		double media = sol.suma / (fin - ini);
		if (izq.minimo < derec.minimo){
			sol.minimo = izq.minimo;
		}else {
			sol.minimo = derec.minimo;
		}

		if (izq.max < derec.max){
			sol.max = derec.max;
		}else {
			sol.max = izq.max;
		}

		sol.adecuado = izq.adecuado && derec.adecuado && (sol.max <= media + (media / 2)) && (sol.minimo >= media - (media / 2));

	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elementos = 0;
	std::cin >> elementos;
	if (!std::cin)
		return false;
	std::vector<int>lista(elementos);
	for (int i = 0; i < lista.size(); i++){
		std::cin >> lista[i];
	}
	tSolucion sol = resolver(lista,0,lista.size());

	// escribir sol
	if (sol.adecuado){
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
