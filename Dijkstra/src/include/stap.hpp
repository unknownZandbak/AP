#include <iostream>

using std::string;

class Stap {
protected:
    string src;
    string dest;
    int weight;
};

class Vlucht: Stap{
public:
    void displayStap(){
        cout << "Vlugt: " << src << "-->" << dest << "\tCost: " << weight << endl;
    }
};

class Rit: Stap{
public:
    void displayStap(){
        cout << "Rit: " << src << "-->" << dest << "\tCost: " << weight << endl;
    }
};

class Treinrit: Stap{
public:
    void displayStap(){
        cout << "Treinrit: " << src << "-->" << dest << "\tCost: " << weight << endl;
    }
};