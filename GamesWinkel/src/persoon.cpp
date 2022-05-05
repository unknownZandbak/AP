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
    cout << name << " koopt: " << game.getTitle() << endl;

    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.getOriginalPrice() <= budget){
        // check of het de game al in bezit heeft
        for (Game x: games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                goto transaction_failed;
            }
        }
        // haal het geld van het budget af en stop de game in zijn bezit
        budget = budget - game.CalculateCurrentPrice();
        games_in_bezit.push_back(game);

        goto transaction_succes;
    } 
    else {
        goto transaction_failed;
    }

    transaction_succes: 
        cout << "Transaction Succes" << endl;
        goto done;
    transaction_failed: 
        cout << "Transaction Failed" << endl;
    done:
    cout << "-----------" << endl;
    
}

void Person::sell(Game game, Person persoon)
{   
    cout << name << " verkoopt " << game.getTitle() << " aan: " << persoon.name << endl;

    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.getOriginalPrice() <= persoon.budget){
        // check of het de game al in bezit heeft
        for (Game x: persoon.games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                goto transaction_failed;
            }
        }
        // TODO Zorg ervoor dat de game bij de verkoper uit zijn lijst van games gaat
        budget = budget + game.CalculateCurrentPrice();
        persoon.budget = persoon.budget - game.CalculateCurrentPrice();
        
        // this->games_in_bezit.
        persoon.games_in_bezit.push_back(game);
        goto transaction_succes;
    } 
    else {
        goto transaction_failed;
    }
    
    transaction_succes: 
        cout << "Transaction Succes" << endl;
        goto done;
    transaction_failed: 
        cout << "Transaction Failed" << endl;
    done:
    cout << "-----------" << endl;
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