#include <iostream>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <stdexcept>

template <typename T>
class unidirected_edge {
private:
    T a; 
    T b; 
public:
    unidirected_edge(T nodo1, T nodo2) {
        if (nodo1 < nodo2) {
            a= nodo1;
            b = nodo2;
        } else {
            a = nodo2;
            b = nodo1;
        }
    }
    T from() const { 
		return a; 
		}
    T to() const { 
		return b; 
		}
    bool operator<(const unidirected_edge& other) const {
        if (a != other.a) {
            return a < other.a;
        }
		else {
			return b < other.b;
		}
	}
    bool operator==(const unidirected_edge& other) const {
        return (a == other.a && b == other.b);
    }
};
template<typename T> 
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& vertice) {
        os << "(" << vertice.from() << ", " << vertice.to() << ")" << "\n";
        return os;
}
template <typename T>
class unidirected_graph {
private:
    std::set<T> nodi;                                  
    std::map<T, std::set<T>> lista_adiacenza;            
    std::vector<unidirected_edge<T>> archi;       
    std::map<unidirected_edge<T>, int> archi_indicizzati;  

public:
    unidirected_graph() : nodi(), lista_adiacenza(), archi(), archi_indicizzati() {}
	unidirected_graph(const unidirected_graph<T>& other) : 
        nodi(other.nodi), 
        lista_adiacenza(other.lista_adiacenza), 
        archi(other.archi), 
        archi_indicizzati(other.archi_indicizzati) {}
	std::set<T> neighbours(T nodo) const {
		for (const auto& [nodo_attuale, set_adiacenti] : lista_adiacenza) {
			if (nodo_attuale == nodo) { 
            return set_adiacenti;   
        }
    }
    return std::set<T>(); 
}
	std::vector<unidirected_edge<T>> all_edges() const {
        return archi;
    }
	std::set<T> all_nodes() const {
        return nodi; 
    }
	int edge_number(const unidirected_edge<T>& edge) const {
    for (const auto& [arco_corrente, indice] : archi_indicizzati) {
        if (arco_corrente == edge) { 
            return indice;           
        }
    }
	return -1; 
}
	unidirected_edge<T> edge_at(size_t index) const {
        if (index >= archi.size()) {
            throw std::out_of_range("Indice arco non valido");
        }
        return archi[index];
    }
unidirected_graph<T> operator-(const unidirected_graph<T>& other) const {
        unidirected_graph<T> risultato;
		for (const auto& edge_corrente : archi) {
			bool trovato_in_other = false;
			for (const auto& [arco_other, indice_other] : other.archi_indicizzati) {
                if (arco_other == edge_corrente) {
                    trovato_in_other = true;
                    break;
                }
            }
			if (!trovato_in_other) {
                T u = edge_corrente.from();
                T v = edge_corrente.to();

                risultato.nodi.insert(u);
                risultato.nodi.insert(v);
                risultato.lista_adiacenza[u].insert(v);
                risultato.lista_adiacenza[v].insert(u);
				bool gia_nel_risultato = false;
                for (const auto& [arco_res, indice_res] : risultato.archi_indicizzati) {
                    if (arco_res == edge_corrente) {
                        gia_nel_risultato = true;
                        break;
                    }
                }

                if (!gia_nel_risultato) {
					risultato.archi_indicizzati[edge_corrente] = risultato.archi.size();
                    risultato.archi.push_back(edge_corrente);
                }
            }
        }
        return risultato;
    }

    void add_edge(T n1, T n2) {
        unidirected_edge<T> edge(n1, n2);bool gia_presente = false;
        for (const auto& [arco_esistente, indice_esistente] : archi_indicizzati) {
            if (arco_esistente == edge) {
                gia_presente = true;
                break;
            }
        }
		if (!gia_presente) {
            nodi.insert(n1);
            nodi.insert(n2);
            lista_adiacenza[n1].insert(n2);
            lista_adiacenza[n2].insert(n1);archi_indicizzati[edge] = archi.size();
            archi.push_back(edge);
        }
    }
};

