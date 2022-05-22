class rearangeShelf
{
private:
    int shelfID;

public:
    rearangeShelf(int shelfID);
    ~rearangeShelf();

    int getShelfID();
    bool runTask(Employee& employee);
};
