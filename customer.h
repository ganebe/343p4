// ----------------------------------------------------customer.h-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file has various functions to keep track of a customer's first name, last name, their id, a way to 
// add to their transaction history and to display their transaction history. 
// 
// --------------------------------------------------------------------------------------------------------------------
// The the unique customer ID can only be an integer
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>
#include<iostream>
using namespace std;

class Customer 
{
public:
    // Constructor
    Customer(int customerId, const string& lastName, const string& firstName);
    Customer(const Customer& rhs);
    
    // Get the customer's ID
    int getCustomerId() const;

    // Get the customer's last name.
    string getLastName() const;

    // Get the customer's first name.
    string getFirstName() const;

    // Adds a transaction to the customer's history.
    void addHistory(string data, bool is_return, string movieType);

    // Displays the customer's transaction history.
    void displayHistory() const;
    bool containsHistory(string history) const;
    Customer& operator =(const Customer& rhs);
private:
    int customerId_; // Unique identifier for the customer.
    string lastName_; // Last name of the customer.
    string firstName_; // First name of the customer.
    vector<string> history_; // customer's transactions history
    vector<string> status_;
};
#endif
