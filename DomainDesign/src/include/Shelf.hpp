#include "Pallet.hpp"
#include "IContainer.hpp"

class Shelf
{
private:
    const int id;
    Pallet pallets[4];
    bool slotStatus[4];
public:
    Shelf(int id);
    ~Shelf();

    int getId();
    bool * getSlotStatus();
    Pallet * getpallets();

    Pallet removePallet(int slot);
    bool insertPallet(int slot, Pallet pallet);
};
