#include "include/Shelf.hpp"

Shelf::Shelf(vector<Pallet> pallets){
    this->pallets = pallets;
}

vector<Pallet> Shelf::getPallets(){
    return pallets;
}

int Shelf::getCapacity(){
    return capacity;
}

int Shelf::getSlotStatus(){
    return capacity-pallets.size();
}

bool Shelf::takeItems(int slot, int amount){
    for (int j=0; j < amount; j++){
        if (pallets[slot].takeOne()) continue;
        return false;
    }
    return true;
}

bool Shelf::removePallet(int slot){
    if (getCapacity() != 0){
        pallets.erase(pallets.begin()+slot);
        return true;
    } else return false;
}

bool Shelf::insertPallet(int slot, Pallet pallet){
    if (getCapacity() != pallets.size()){
        pallets.insert(pallets.begin()+slot, pallet);
        return true;
    } else return false;
}