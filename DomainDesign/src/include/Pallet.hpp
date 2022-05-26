#include <iostream>
#include "IContainer.hpp"

class Pallet
{
private:
    int itemCount = 0;
    std::string itemName = "PH";
    int itemCapacity = 0;

public:
    Pallet();
    Pallet(std::string itemName, int itemCapacity, int itemCount);
    ~Pallet();

    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();

    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};