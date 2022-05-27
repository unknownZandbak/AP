#include "include/Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount){
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

std::string Pallet::getItemName(){
    return itemName;
}

int Pallet::getItemCount(){
    return itemCount;
}

int Pallet::getRemainingSpace(){
    return itemCapacity-itemCount; 
}

bool Pallet::reallocateEmptyPallet(std::string itenName, int itemCapacity){
    if (getItemCount() == 0){
        this->itemName = itenName;
       this->itemCapacity = itemCapacity;
       return true;
    } else return false;
}

bool Pallet::takeOne(){
    if (getItemCount() == 0){
        itemCount -= 1;
        return true;
    } else return false;
}

bool Pallet::putOne(){
    if (getItemCount() != getRemainingSpace()){
        itemCount += 1;
        return true;
    } else return false;
}