#include <vector>
#include "stap.hpp"

using std::vector;

class Reis {
private:
    string src;
    string dest;
    int totalWeight;
    vector<Stap> stappen;

public:
    void compareTo(Reis reis);
};
