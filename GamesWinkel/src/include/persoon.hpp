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

        vector<Game> getGames();
        string getName();
        float getBudget();
        
        void buy(Game game);
        void sell(Game game, Person person);
        
        void print_details();
        void addGame(Game game);
        void removeGame(Game game);

        void setBudget(float budget);
        void setGames(vector<Game> games);
        void setName(string name);
};