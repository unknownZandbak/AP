#include "include/game.hpp"

Game::Game(string title, int releaseDate, double originalPrice)
{
    this->title = title;
    this->releaseDate = releaseDate;
    this->originalPrice = originalPrice;
}

Game::~Game()
{
    
}

float Game::CalculateCurrentPrice()
{   
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);

    int timeDiff = (tm_local->tm_year + 1900)-releaseDate;
    float price = originalPrice;

    while (timeDiff > 0)
    {   
        timeDiff -= 1;
        price = price * .7;
    }
    return price;
}

string Game::getTitle()
{
    return title;
}

int Game::getReleaseDate()
{
    return releaseDate;
}

double Game::getOriginalPrice()
{
    return originalPrice ;
}

void Game::setTitle(string title)
{
    this->title = title;
}

void Game::setReleaseDate(int releaseDate)
{
    this->releaseDate = releaseDate;
}

void Game::setOriginalPrice(float originalPrice)
{
    this->originalPrice = originalPrice;
}