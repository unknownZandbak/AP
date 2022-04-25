#include "include/game.hpp"

Game::Game(string naam, int release_datum, double prijs)
{
    this->naam = naam;
    this->release_datum = release_datum;
    this->prijs = prijs;
}

Game::~Game()
{
    
}

string Game::get_naam()
{
    return naam;
}

int Game::get_release_datum()
{
    return release_datum;
}

double Game::get_prijs()
{
    return prijs;
}