#include "Task.hpp"
#include "Employee.hpp"
#include "Shelf.hpp"
#include <vector>

using std::vector;

class Warehouse
{
public:
    Warehouse();
    ~Warehouse();

    TaskStatus getTotalTaskStatus();
    TaskStatus performOneTask();
    TaskStatus performeAllTasks();

    vector<Employee> getEmployees();
    vector<Task> getTasks();
    vector<Shelf> getShelves();

    void addEmployee(Employee employee);
    void setEmployees(vector<Employee> employees);
    void addTask(Task task);
    void setTasks(vector<Task> tasks);
    void addShelf(Shelf shelf);
    void setShelves(vector<Shelf> shelves);
};
