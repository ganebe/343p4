// ----------------------------------------------------customer.cpp-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This implementation file has various functions to keep track of a customer's first name, 
// last name, their id, a way to add to their transaction history and to display their transaction history. 
// 
// --------------------------------------------------------------------------------------------------------------------
// The the unique customer ID can only be an integer
// -------------------------------------------------------------------------------------------------------------------- 

#include "customer.h"

//---------------------------Customer constructor---------------------------
//Constructor for the Customer
//--------------------------------------------------------------- 

Customer::Customer(int customerId, const string &lastName, const string &firstName)
{
    customerId_ = customerId; //Initializing customer ID
    lastName_ = lastName; //Initializing customer last name
    firstName_ = firstName; //Initializing customer first name
}

//---------------------------Copy constructor---------------------------
//Copy constructor to copy customer
//--------------------------------------------------------------- 

Customer::Customer(const Customer &rhs)
{
     *this = rhs;
}

//---------------------------getCustomerId---------------------------
//Return customer's ID
//--------------------------------------------------------------- 

int Customer::getCustomerId() const
{
    return customerId_;
}

//---------------------------getLastName---------------------------
//Return customer's last name
//--------------------------------------------------------------- 

string Customer::getLastName() const
{
    return lastName_;
}

//---------------------------getFirstName---------------------------
//Return customer's first name
//--------------------------------------------------------------- 

string Customer::getFirstName() const
{
    return firstName_;
}

//---------------------------addHistory---------------------------
// Customer is able to add a transaction to their history
//--------------------------------------------------------------- 
void Customer::addHistory(string data, bool is_return, string movieType)
{
    if(is_return == false) // If return is false then it is borrowed for the history
    {
        string his = movieType;
        his += " ";
        his += data;
        history_.push_back(his); //Adding the transaction to history
        status_.push_back("borrowed"); //Setting the status as borrowed
    }
    //if is_return is true, the status of the movie must be borrowed
    string temp = " ";
    if(is_return == true) //If return is true 
    {
        int index = -1;
        for(int i = 0; i < history_.size(); i++) //Finding borrowed transaction in history
        {
            if(history_[i].compare(data) && index == -1 && status_[i] ==  "borrowed" )
            {
                index = i;
                temp = history_[i];
            }
        }

        vector<string> historyHolder;
        vector<string> statusHolder;

        for(int i = 0; i < history_.size(); i++) //Looping through history
        {
            if(i == index)
            {

            }
            else
            {
                historyHolder.push_back(history_[i]);
                statusHolder.push_back(status_[i]);
            }

        }
        historyHolder.push_back(temp); //Add the transaction to the customer
        statusHolder.push_back("retunred"); //Status is now returned
        history_.clear(); //Clear the current history
        status_.clear(); //Ckear the current status
        for(int i = 0; i < historyHolder.size(); i++)
        {
            history_.push_back(historyHolder[i]);
            status_.push_back(statusHolder[i]);
        }

    }



}

//---------------------------displayHistory---------------------------
// Customer is able to display their transaction history
//--------------------------------------------------------------- 
void Customer::displayHistory() const
{
    cout << "customer: " << customerId_ <<  " history: " << endl;
    for(int i = history_.size() - 1; i >= 0; i--) //Looping through the history and printing 
    {
        cout << history_[i] << "   " << status_[i] << endl;
    }
}

//---------------------------containsHistory---------------------------
// Checks to see if the history contains a specific transaction
//--------------------------------------------------------------- 

bool Customer::containsHistory(string history) const
{
    for(int i = 0; i < history_.size(); i++) //Looping through history
    {
        if(history_[i].compare(history)) 
        {
            if(status_[i] ==  "borrowed")
            {
                return true;
            }
        }

    }
    return false;
}

//---------------------------Assignment operator = ---------------------------
// Copies the customer data from rhs to current 
//--------------------------------------------------------------- 

Customer &Customer::operator=(const Customer &rhs)
{
    
    customerId_ = rhs.customerId_; //Copy data of customer data
    lastName_ = rhs.lastName_;     //Copy data of last name
    firstName_ = rhs.firstName_;   //Copy data of first name
    history_ = rhs.history_;       //Copy data of history
    return *this;
}
