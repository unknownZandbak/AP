#include "include/persoon.hpp"

using std::cout, std::endl;

Person::Person(string name, float budget)
{
    this->name = name;
    this->budget = budget;
}

Person::~Person()
{

}

void Person::buy(Game game)
{
    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.getOriginalPrice() <= budget){
        // check of het de game al in bezit heeft
        for (Game x: games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                cout << "Transactie Niet Gelukt" << endl;
                return;
            }
        }
        // haal het geld van het budget af en stop de game in zijn bezit
        budget = budget - game.CalculateCurrentPrice();
        games_in_bezit.push_back(game);

        cout << "Transactie Gelukt" << endl;
        return;
    } 
    else {
        cout << "Transactie Niet Gelukt" << endl;
        return;
    }
}

void Person::sell(Game game, Person persoon)
{   
    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.getOriginalPrice() <= persoon.budget){
        // check of het de game al in bezit heeft
        for (Game x: persoon.games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                cout << "Transactie Niet Gelukt" << endl;
                return;
            }
        }
        // TODO Zorg ervoor dat de game bij de verkoper uit zijn lijst van games gaat
        budget = budget + game.CalculateCurrentPrice();
        persoon.budget = persoon.budget - game.CalculateCurrentPrice();
        
        persoon.games_in_bezit.push_back(game);

        cout << "Transactie Niet Gelukt" << endl;
        return;
    } 
    else {
        cout << "Transactie Niet Gelukt" << endl;
        return;

    }
}

vector<Game> Person::getGames()
{
    return games_in_bezit;
}

void Person::print_details()
{
    cout << name << " heeft een budget van € " << budget
    << " en bezit de volgende games:" << std::endl;

    for(Game game: getGames())
    {
        cout << "-----" << endl;
        cout << game.getTitle() << ";\nRlease date: " 
        << game.getReleaseDate() << ";\nOriginal price: €"
        << game.getOriginalPrice() << ";\nCurrent price: €"
        << game.CalculateCurrentPrice() << endl;
    }
    cout << endl;
}