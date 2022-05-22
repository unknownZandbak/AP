#include <iostream>
#include "IContainer.hpp"

class Pallet
{
private:
    const int id;
    int itemCount;
    std::string itemName;
    int itemCapacity;
public:
    Pallet(int id, std::string itemName, int itemCapacity, int itemCount);
    ~Pallet();

    int getId();
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();

    void reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};