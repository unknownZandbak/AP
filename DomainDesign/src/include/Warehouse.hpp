#include "Employee.hpp"
#include "Shelf.hpp"

class Warehouse
{
private:
    vector<Employee> employees;
    vector<Shelf> shelves;

public:
    Warehouse(vector<Employee> employees, vector<Shelf> shelves);

    vector<Employee> getEmployees();
    vector<Shelf> getShelves();

    void addEmployee(Employee employee);
    void setEmployees(vector<Employee> employees);
    void addShelf(Shelf shelf);
    void setShelves(vector<Shelf> shelves);

    bool rearangeShelf(Shelf& shelf);
    bool pickItems(string itemName, int itemCount);
};