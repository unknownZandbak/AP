#include <istream>
#include <vector>
#include "game.hpp"

using std::string, std::ostream, std::vector;

class Person
{
    private:
        string name;
        float budget;
        vector<Game> games_in_bezit;

    public:
        Person(string name, float budget);
        Person();
        ~Person();
        
        string buy(Game game);
        string sell(Game game, Person person);
        
        void addGame();
        void removeGame();
        void print_details();

        vector<Game> getGames();
        float getBudget();

        void setBudget();
        void setGames();
};