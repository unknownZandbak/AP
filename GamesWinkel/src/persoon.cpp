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
                cout << "Buyer already owns game: ";
                goto transaction_failed;
            }
        }
        // haal het geld van het budget af en stop de game in zijn bezit
        budget = budget - game.CalculateCurrentPrice();
        addGame(game);

        goto transaction_succes;
    } 
    else {
        cout << "Buyer doesn't have enough money: ";
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

    // check of het koper genoeg geld heeft om de game te kopen
    if (game.getOriginalPrice() <= persoon.budget){
        bool owns_game = false;
        // check of de verkoper de game wel in bezit heeft
        for (Game x: this->games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                owns_game = true;
                break;
            }
        }
        // check of de koper de game al in bezit heeft
        for (Game x: persoon.games_in_bezit){
            if (x.getTitle() == game.getTitle()){
                cout << "Buyer already owns game: ";
                goto transaction_failed;
            }
        }
        
        if(not owns_game){
            cout << "Seller doesn't own game: ";
            goto transaction_failed;
            }

        budget = budget + game.CalculateCurrentPrice();
        persoon.budget = persoon.budget - game.CalculateCurrentPrice();
        
        this->removeGame(game);

        // persoon.games_in_bezit.push_back(game);
        persoon.addGame(game);
        goto transaction_succes;
        
    } 
    else {
        cout << "Buyer doesn't have enough money: ";
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
        cout << game.getTitle() << ";\nRelease date: " 
        << game.getReleaseDate() << ";\nOriginal price: €"
        << game.getOriginalPrice() << ";\nCurrent price: €"
        << game.CalculateCurrentPrice() << endl;
    }
    cout << endl;
}

void Person::addGame(Game game){
    this->games_in_bezit.push_back(game);
}

void Person::removeGame(Game game){
    int count = 0;
    for (Game x: games_in_bezit){
        if(x.getTitle() == game.getTitle()){
            games_in_bezit.erase(games_in_bezit.begin()+count);
            return;
        }
        count++;
    }
}

void Person::setBudget(float budget){
    this->budget = budget;
}
void Person::setGames(vector<Game> games){
    this->games_in_bezit = games;
}

void Person::setName(string name){
    this->name = name;
}