class pickitems
{
private:
    std::string itemName;
    int itemCount;
    
public:
    pickitems(std::string itemName, int itemCount);
    ~pickitems();

    std::string getItemName();
    int getItemCount();
    bool runTask(Employee& employee);
};
