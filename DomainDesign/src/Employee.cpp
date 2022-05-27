#include "include/Employee.hpp"

Employee::Employee(const std::string name, bool forkLiftCertificate){
    this->name = name;
    this->forkLiftCertificate = forkLiftCertificate;
}

std::string Employee::getName(){
    return name;
}

bool Employee::getBusy(){
    return busy;
}

bool Employee::getForkLiftCertificate(){
    return forkLiftCertificate;
}

void Employee::setBusy(bool busy){
    this->busy = busy;
}

void Employee::setForkLiftCertificate(bool forkLiftCertificate){
    this->forkLiftCertificate = forkLiftCertificate;
}