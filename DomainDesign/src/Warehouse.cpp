#include "include/Warehouse.hpp"
#include <unordered_map>
#include <tuple>

using std::cout, std::endl, std::unordered_map, std::pair,
        std::tuple, std::make_tuple, std::get;

Warehouse::Warehouse(vector<Employee> employees,vector<Shelf> shelves){
    this->employees = employees;
    this->shelves = shelves;
}

vector<Employee> Warehouse::getEmployees(){
    return employees;
}

vector<Shelf> Warehouse::getShelves(){
    return shelves;
}

void Warehouse::addEmployee(Employee employee){
    employees.push_back(employee);
}

void Warehouse::setEmployees(vector<Employee> employees){
    this->employees = employees;
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

void Warehouse::setShelves(vector<Shelf> shelves){
    this->shelves = shelves;
}

bool Warehouse::rearangeShelf(Shelf& shelf){
    return true;
}

bool Warehouse::pickItems(string itemName, int itemCount){
    // using a hashmap to store location and,
    // the amount of the found item on that location
    int currentAmount;
    unordered_map<int, tuple<int, int>> mp; 
    cout << "\nCheck if there are enough items in th warehouse." << endl;
    for (int i=0; i < shelves.size(); i++){
        vector<Pallet> pallets = shelves[i].getPallets();
        for (int y=0; y < pallets.size(); y++) {
            if (itemName == pallets[y].getItemName()){
                // if we ofund a pallet with the right items,
                // we save the shelf location and the amount
                mp.insert(pair<int, tuple<int, int>>(i, make_tuple(y, pallets[y].getItemCount())));
                currentAmount += pallets[y].getItemCount();
            }
        }
    }

    if (currentAmount >= itemCount){
        int collected = 0;
        cout << "\nEnough items in the warehouse have been found." << endl;
        cout << "Taking Items" << endl;
        for (auto pair: mp){
            int gatherAmount = itemCount-collected;
            if (gatherAmount > get<1>(pair.second)){
                gatherAmount = get<1>(pair.second);
            }
            shelves[pair.first].takeItems(get<0>(pair.second), gatherAmount);
        }
        return true;
    }
    return false;
}