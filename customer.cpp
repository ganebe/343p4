#include "customer.h"

Customer::Customer(int customerId, const string &lastName, const string &firstName)
{
    customerId_ = customerId;
    lastName_ = lastName;
    firstName_ = firstName;
}

Customer::Customer(const Customer &rhs)
{

    customerId_ = rhs.customerId_;
    lastName_ = rhs.lastName_;
    firstName_ = rhs.firstName_;
    history_ = rhs.history_;
}

int Customer::getCustomerId() const
{
    return customerId_;
}

string Customer::getLastName() const
{
    return lastName_;
}

string Customer::getFirstName() const
{
    return firstName_;
}

void Customer::addHistory(string data)
{
    history_.push_back(data);


}

void Customer::displayHistory() const
{
    for(int i = 0; i < history_.size(); i++){
        cout << history_[i] << endl;
    }
}
