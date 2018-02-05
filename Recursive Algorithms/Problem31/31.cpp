//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

//Coste de la solucion-->f(O(n))
struct tSol{
	int j = -1;
	int partidos = 0;
	int ronda = 0;
};
// función que resuelve el problema
tSol resolver(std::vector<int> const &v,int ini, int fin,int ronda) {
	tSol sol;
	if (ini + 1 == fin){
		if (v[ini] == 0 && v[fin] == 0){//ninguno presentado
			sol.j = 0;
		}
		else if (v[ini]== 1 &&v[fin] == 1){//ambos presentados
			sol.j = 1;
			sol.partidos++;
		}
		else{//alguno no se presenta
			sol.j = 1;
		}
		sol.ronda++;
	}
	else {
		int mitad = (ini + fin) / 2;
		tSol izq = resolver(v, ini, mitad,ronda);
		tSol derec = resolver(v, mitad + 1, fin,ronda);
		sol.ronda = derec.ronda+1;
		sol.partidos = izq.partidos + derec.partidos;
		if (sol.ronda <= ronda){
			if (derec.j == 0 && izq.j == 0){//ninguno presentado
				sol.j = 0;
			}
			else if (derec.j == 1 && izq.j == 1){//ambos presentados
				sol.j = 1;
				sol.partidos++;
			}
			else{//alguno no se presenta
				sol.j = 1;
			}
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
	int ronda = 0;
	std::cin >> ronda;
	std::string aux = "";
	std::vector<int>v(tam);//vector de enteros que guarda 0 si es NP y 1 si hay jug
	for (int i = 0; i < tam; i++){
		std::cin >>aux;
		if (aux == "NP"){
			v[i] = 0;
		}
		else{
			v[i] = 1;
		}
	}
	tSol sol = resolver(v,0,v.size()-1,ronda);

	// escribir sol
	std::cout << sol.partidos << std::endl;

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
