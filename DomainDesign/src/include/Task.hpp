#include "pickitems.hpp"
#include "rearangeShelf.hpp"
#include "putitems.hpp"

enum TaskStatus {
    todo,
    finished,
    failed
};

class Task
{
private:
    int id;
    bool requiresFork;
    int requiredTaskForce;
    TaskStatus taskstatus;
public:
    // ? why do i not neet de contruter and destructer
    // Task(int id, bool requiresFork, int requiredTaskForce);
    // ~Task();

    int getId();
    bool getRequiredFork();
    int getRequiredTaskForce();

    void setId(int id);
    void setRequiredFork(bool requiredFork);
    void setRequiredTaskForce(int requiredTaskForce);

    // TODO fill argument to methods below
    virtual bool runTask(Employee& employee, vector<Shelf&>);
};

