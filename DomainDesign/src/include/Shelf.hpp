#include "Pallet.hpp"

class Shelf
{
private:
    const int capacity = 4;
    vector<Pallet> pallets;

public:
    Shelf(vector<Pallet> pallets);

    int getCapacity();
    int getSlotStatus();
    vector<Pallet> getPallets();

    bool takeItems(int slot, int amount);

    bool removePallet(int slot);
    bool insertPallet(int slot, Pallet pallet);
};
