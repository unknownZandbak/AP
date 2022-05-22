class putitems
{
private:
    std::string itemName;
    int itemCount;

public:
    putitems(std::string itemName, int itemCount);
    ~putitems();

    std::string getItemName();
    int getItemName();
    bool runTask(Employee& employee);
};
