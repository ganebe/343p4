#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>
#include<iostream>
using namespace std;

class Customer {
public:
    // Constructor
    Customer(int customerId, const string& lastName, const string& firstName);

    // Get the customer's ID
    int getCustomerId() const;

    // Get the customer's last name.
    string getLastName() const;

    // Get the customer's first name.
    string getFirstName() const;

    // Adds a transaction to the customer's history.
    void addHistory(string data);

    // Displays the customer's transaction history.
    void displayHistory() const;

private:
    int customerId_; // Unique identifier for the customer.
    string lastName_; // Last name of the customer.
    string firstName_; // First name of the customer.
    vector<string> history_; // customer's transactions history
};
#endif
