#include "iostream"

class Employee
{
private:
    std::string name;
    bool busy;
    bool forkLiftCertificate;
public:
    Employee(std::string name, bool forkLiftCertificate);
    ~Employee();

    std::string getName();
    bool getBusy();
    bool getForkLiftCertificate();

    void setBusy(bool busy);
    void setForkLiftCertificate(bool forkliftCertificate);
};