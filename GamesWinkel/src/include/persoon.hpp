#include <istream>
#include <vector>
#include "game.hpp"

using std::string, std::ostream, std::vector;

class Persoon
{
    private:
        string naam;
        float balans;
        vector<Game> games_in_bezit;

    public:
        Persoon(string naam, float balans);
        Persoon();
        ~Persoon();
        
        string koop(Game game);
        string verkoop(Game game, Persoon persoon);
        vector<Game> get_games();

        void print_details();
};