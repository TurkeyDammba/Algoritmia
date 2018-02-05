// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>


/*Ecuacion de recurrencia -->Requisito de implementacion, consideramos los niveles del movil
T(n){ c0 si n=1
{ 2T(n-1) si n > 1

Coste Solucion --> 2^n
*/
struct tSolucion{
	bool balanceado = true;
	int peso = 0;
};
// función que resuelve el problema
tSolucion resolver() {
	int p1;
	int p2;
	int d1;
	int d2;
	tSolucion sol;
	std::cin >> p1;
	std::cin >> d1;
	std::cin >> p2;
	std::cin >> d2;
	if (p1 != 0 && p2 != 0){
		sol.balanceado = (p1*d1 == p2*d2);
		sol.peso = p1 + p2;
	}
	else {

		if (p1 == 0 && p2 == 0){
			tSolucion solIzq = resolver();
			tSolucion solDerec = resolver();

			sol.peso = solIzq.peso + solDerec.peso;
			sol.balanceado = solIzq.balanceado && solDerec.balanceado && solIzq.peso*d1 == solDerec.peso*d2;
		}

		else if (p1 == 0){
			tSolucion solIzq = resolver();
			sol.peso = solIzq.peso + p2;
			sol.balanceado = solIzq.balanceado && (solIzq.peso *d1 == p2*d2);
		}

		else if (p2 == 0){
			tSolucion solDerec = resolver();
			sol.peso = solDerec.peso + p1;
			sol.balanceado = solDerec.balanceado && (solDerec.peso * d2 == p1*d1);
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	tSolucion sol = resolver();
	// escribir sol
	if (sol.balanceado){
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}

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
