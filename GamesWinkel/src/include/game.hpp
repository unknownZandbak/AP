#include <iostream>

using std::string, std::ostream;

class Game
{
    private:
        string naam;
        int release_datum;
        double prijs;

    public:
        Game(string naam, int release_datum, double prijs);
        ~Game();

        string get_naam();
        int get_release_datum();
        double get_prijs();
};