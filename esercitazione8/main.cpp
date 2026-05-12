#include <iostream>
#include "Grafi.hpp"

int main() {
    unidirected_graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(2, 3); 
    g.add_edge(1, 3);
	g.add_edge(4, 5); 
	g.add_edge(6, 3);
    std::cout << "Nodi presenti nel grafo: " << "\n";
    for (const auto& nodo : g.all_nodes()) {
        std::cout << "[" << nodo << "] ";
    }
    std::cout << "\n" << std::endl;
    std::cout << "Elenco degli archi: " << "\n";
    for (const auto& arco : g.all_edges()) {
        std::cout << "Arco da " << arco.from() << " a " << arco.to() << "\n";
    }
	for (const auto& nodo : g.all_nodes()) {
    std::cout << "Nodo " << nodo << " e' collegato a: ";
    auto vicini = g.neighbours(nodo);
    for (const auto& v : vicini) {
        std::cout << v << " "; 
    }
    std::cout << std::endl; 
	}
	unidirected_graph<int> g2;
	g2.add_edge(1,2);
	g2.add_edge(3,4);
	unidirected_graph<int> differenza =  g-g2;
	std::cout << "Risultato Differenza: " << "\n";
for (const auto& arco : differenza.all_edges()) {
    std::cout << "Archi superstite: " << arco.from() << " - " << arco.to() << std::endl;
	}
}
