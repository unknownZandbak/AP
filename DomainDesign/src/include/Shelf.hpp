#include "Pallet.hpp"
#include <vector>

using std::vector;

class Shelf
{
private:
    int capacity;
    vector<Pallet> pallets;
public:
    Shelf();
    ~Shelf();

    int getCapacity();
    int getSlotStatus();
    vector<Pallet> getPallets();

    bool takeItems(int slot, int amount);

    bool removePallet(int slot);
    bool insertPallet(int slot, Pallet pallet);
};
