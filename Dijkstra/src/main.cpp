#include <map>
#include <vector>
#include "include/reis.hpp"

using std::map, std::vector, std::pair, std::make_pair, std::cout, std::endl;

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
    // Find the shortest path form 2 nodes in a graph 
    Reis findShortestPath(T src, T dest){
        cout << "Finding shortest route from:\n" << src << "to" << dest << endl;
    }
};

int main(){
    // init a graph for using the algorithm with
    Graph <string> g;
     
    g.add_edge("S", "A", 7);
    g.add_edge("S", "B", 2);
    g.add_edge("S", "C", 3);
    g.add_edge("A", "D", 4);
    g.add_edge("A", "B", 3);
    g.add_edge("B", "D", 4);
    g.add_edge("B", "H", 1);
    g.add_edge("C", "L", 2);
    g.add_edge("D", "F", 5);
    g.add_edge("F", "H", 3);
    g.add_edge("H", "G", 2);
    g.add_edge("G", "E", 2);
    g.add_edge("E", "K", 5);
    g.add_edge("K", "I", 4);
    g.add_edge("K", "J", 4);
    g.add_edge("I", "J", 6);
    g.add_edge("I", "L", 4);
    g.add_edge("J", "L", 4);

    // give a overview of all the edges per node
    g.display_graph();

    Reis rSE = g.findShortestPath("S", "E");

    return 0;
}

