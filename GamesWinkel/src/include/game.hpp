#include <iostream>

using std::string, std::ostream;

class Game
{
    private:
        string title;
        int releaseDate;
        double originalPrice;

    public:
        Game(string title, int releaseDate, double originalPrice);
        ~Game();

        float CalculateCurrentPrice();

        string getTitle();
        int getReleaseDate();
        double getOriginalPrice();

        void setTitle(string title);
        void setReleaseDate(int releaseDate);
        void setOriginalPrice(float originalPrice);
};