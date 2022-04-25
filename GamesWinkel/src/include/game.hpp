#include <iostream>

using std::string, std::ostream;

class Game
{
    private:
        string Title;
        int ReleaseDate;
        double OriginalPrice;

    public:
        Game(string Title, int ReleaseDate, double OriginalPrice);
        ~Game();

        float CalculateCurrentPrice();

        string getTitle();
        int getReleaseDate();
        double getOriginalPrice();

        void setTitle();
        void setReleaseDate();
        void setOriginalPrice();
};