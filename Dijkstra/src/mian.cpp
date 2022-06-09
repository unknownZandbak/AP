#include <map>
#include <iostream>
#include <vector>

using std::map, std::string, std::vector, std::pair, std::make_pair, std::cout, std::endl;

template <typename T>
class Graph {
    map<T, vector<pair<T, int>>> g;
    
public:
    void add_edge(T node, T neighbour, int weight){
        // Voeg een verbinding tussen 2 nodus toe
        g[node].push_back(make_pair(neighbour, weight));
        g[neighbour].push_back(make_pair(node, weight));
    }
    
    void display_graph(){
        for(auto n : g) {
            T node = n.first;
            vector<pair<T, int>> neighbour = n.second;

            cout << "==================" << endl;
            cout << node << " Has neighbours:" << endl;

            for(auto nbr : neighbour) {
                T dest = nbr.first;
                int weight = nbr.second;

                cout << "Neighbour: " << dest << "\tWeight: " << weight << endl;
            }
            cout << endl;
        }
    }
};

int main(){
    Graph <string> g;
     
    g.add_edge("Delhi", "Jaipur", 250);
    g.add_edge("Delhi", "Shamli", 147);
    g.add_edge("Delhi", "Mumbai", 1100);
    g.add_edge("Shamli", "Lucknow", 377);
    g.add_edge("Shamli", "Baghpat", 50);
    g.add_edge("Jaipur", "Bikaner", 300);
    g.add_edge("Udaipur", "Jaipur", 600);
    g.add_edge("Uttarlai", "Jaipur", 500);
    g.add_edge("Jaipur", "Jodhpur", 150);
    g.add_edge("Mumbai", "Jaipur", 1000);
 
    g.display_graph();

    return 0;
}

