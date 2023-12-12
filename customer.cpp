#include "customer.h"

Customer::Customer(int customerId, const string &lastName, const string &firstName)
{
    customerId_ = customerId;
    lastName_ = lastName;
    firstName_ = firstName;
}

Customer::Customer(const Customer &rhs)
{
     *this = rhs;
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

//to-do add a character for the movie type
void Customer::addHistory(string data, bool is_return, string movieType)
{
    if(is_return == false){
        string his = movieType;
        his += " ";
        his += data;
        history_.push_back(his);
        status_.push_back("borrowed");
    }
    //if is_return is true, the status of the movie must be borrowed
    string temp = " ";
    if(is_return == true){
        int index = -1;
        for(int i = 0; i < history_.size(); i++){
            if(history_[i].compare(data) && index == -1 && status_[i] == "borrowed"){
                index = i;
                temp = history_[i];
            }
        }

        vector<string> historyHolder;
        vector<string> statusHolder;

        for(int i = 0; i < history_.size(); i++){
            if( i == index){

            }else{
                historyHolder.push_back(history_[i]);
                statusHolder.push_back(status_[i]);
            }

        }
        historyHolder.push_back(temp);
        statusHolder.push_back("retunred");
        history_.clear();
        status_.clear();
        for(int i = 0; i < historyHolder.size(); i++){
            history_.push_back(historyHolder[i]);
            status_.push_back(statusHolder[i]);
        }

    }



}

void Customer::displayHistory() const
{
    cout << "customer: " << customerId_ <<  " history: " << endl;
    for(int i = history_.size() - 1; i >= 0; i--){
        cout << history_[i] << "   " << status_[i] << endl;
    }
}

bool Customer::containsHistory(string history) const
{
    for(int i = 0; i < history_.size(); i++){
        cout << history << endl;
        cout << history_[i] << endl;
        if(history_[i].compare(history)){
            cout << status_[i] << endl;   
            if(status_[i] == "borrowed"){
                return true;
            }
        }

    }
    return false;
}

Customer &Customer::operator=(const Customer &rhs)
{

    customerId_ = rhs.customerId_;
    lastName_ = rhs.lastName_;
    firstName_ = rhs.firstName_;
    history_ = rhs.history_;
    return *this;
}
