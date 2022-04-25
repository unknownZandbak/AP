#include "include/persoon.hpp"

using std::cout, std::endl;

Persoon::Persoon(string naam, float balans)
{
    this->naam = naam;
    this->balans = balans;
}

Persoon::~Persoon()
{

}

string Persoon::koop(Game game)
{
    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.get_prijs() <= balans){
        // check of het de game al in bezit heeft
        for (Game x: games_in_bezit){
            if (x.get_naam() == game.get_naam()){
                return "Niet gelukt";
            }
        }
        // haal het geld van het balans af en stop de game in zijn bezit
        balans = balans - game.get_prijs();
        games_in_bezit.push_back(game);
        return "Gelukt";
    } 
    else {
        return "Niet Gelukt";
    }
}

string Persoon::verkoop(Game game, Persoon persoon)
{   
    // check of het persoon genoeg geld heeft om de game te kopen
    if (game.get_prijs() <= persoon.balans){
        // check of het de game al in bezit heeft
        for (Game x: persoon.games_in_bezit){
            if (x.get_naam() == game.get_naam()){
                return "Niet gelukt";
            }
        }
        // Ik mis hier nog wel dat de game van per soon wordt afgehaal den dat hij zijn geld krijgt maar dat kreeg ik niet werkent
        // haal het geld van het balans af en stop de game in zijn bezit
        balans = balans + game.get_prijs();
        persoon.balans = persoon.balans - game.get_prijs();
        
        persoon.games_in_bezit.push_back(game);

        return "Gelukt";
    } 
    else {
        return "Niet Gelukt";
    }
}

vector<Game> Persoon::get_games()
{
    return games_in_bezit;
}

void Persoon::print_details()
{
    cout << naam << " heeft een budget van € " << balans
    << " en bezit de volgende games:" << std::endl;

    for(Game game: get_games())
    {
        cout << game.get_naam() << "; " 
        << game.get_release_datum() << "; €"
        << game.get_prijs() << endl;
    }
    cout << endl;
}