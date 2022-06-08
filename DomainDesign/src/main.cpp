#include <iostream>
#include "include/Warehouse.hpp"

using std::cout, std::endl;

Warehouse initWarehouse(){
    // Creating different kind pallets
    Pallet p1 = Pallet("TV", 10, 10);
    Pallet p2 = Pallet("Toilets", 20, 16);
    Pallet p3 = Pallet("Sofa", 5, 3);
    Pallet p4 = Pallet("PC", 30, 24);

    // Creating the shelves to put the pallets in/on
    Shelf s1 = Shelf(vector<Pallet>{p1, p3});
    Shelf s2 = Shelf(vector<Pallet>{p3, p2});
    Shelf s3 = Shelf(vector<Pallet>{p4});
    Shelf s4 = Shelf(vector<Pallet>{p1, p4, p2});
    vector<Shelf> shelves = {s1, s2, s3, s4};

    // Creating some s̶l̶a̶v̶e̶s̶ employees to work for us
    Employee e1 = Employee("jan", true);
    Employee e2 = Employee("Dirk", false);
    vector<Employee> employees = {e1, e2};

    Warehouse w1 = Warehouse(employees, shelves);
}

int main()
{
    

    return 0;
}
