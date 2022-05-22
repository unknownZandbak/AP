#include "iostream"

class Employee
{
private:
    const int id;
    const std::string name;
    bool busy;
    bool forkLiftCertificate;
public:
    Employee(int id, std::string name, bool forkLiftCertificate);
    ~Employee();

    int getId();
    std::string getName();
    bool getBusy();
    bool getForkLiftCertificate();

    void setBusy(bool busy);
    void setForkLiftCertificate(bool forkliftCertificate);
};