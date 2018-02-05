//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


struct tSol{
	int valorIzq=-1;
	int valorD = -1;
	int contador = 0;
};
// función que resuelve el problema
tSol resolver(std::vector<int>const &v,int ini, int fin) {
	tSol sol;
	if (ini  == fin){
		sol.contador = 1;
		sol.valorIzq = v[ini];
		sol.valorD = v[ini];

	}
	else{
		int mitad = (ini + fin) / 2;
		tSol izq = resolver(v, ini, mitad);
		tSol derec = resolver(v, mitad+1, fin);

		if (izq.valorD != derec.valorIzq &&izq.valorD != derec.valorD &&
			izq.valorIzq != derec.valorIzq && izq.valorIzq != derec.valorD){
			sol.contador = izq.contador + derec.contador;
			sol.valorIzq = izq.valorIzq;
			sol.valorD = derec.valorD;
		}
		else{
			sol.contador = izq.contador + derec.contador - 1;
			sol.valorIzq = izq.valorIzq;
			sol.valorD = derec.valorD;
		}

	}
	return sol;
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
	for (int i = 0; i < v.size(); i++){
		std::cin >> v[i];
	}

	tSol sol = resolver(v,0,v.size()-1);

	// escribir sol
	std::cout << sol.contador << std::endl;

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
