#include <vector>
#include <iostream>
#include "IContainer.hpp"

using std::vector, std::string;

class Pallet
{
private:
    int itemCount;
    string itemName;
    int itemCapacity;

public:
    Pallet(string itemName, int itemCapacity, int itemCount);

    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();

    bool reallocateEmptyPallet(string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};