// ----------------------------------------------------hash.h-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file contains a hash table that is able to store the customers by ID which are all unique
// It has functions such as adding an item and retrieving an item from the hash table
// 
// --------------------------------------------------------------------------------------------------------------------
// The hash table should not have any duplicates as the customer ID's are all unique
// -------------------------------------------------------------------------------------------------------------------- 
#ifndef HASH_H_
#define HASH_H_
#include <vector>
#include <list>
#include <functional>
#include <utility>
using namespace std;

const int TABLESIZE = 7;
template<typename KeyType, typename ValueType>
class Hash {
public:
//----------------------------hash constructor-----------------------
// Constructor for hash table
//---------------------------------------------------------------
    Hash()
    {
        data_.resize(TABLESIZE);
    }

//----------------------------addItem-----------------------
//Adds an item with the given key and value to the hash table. 
//---------------------------------------------------------------
    bool addItem(const KeyType& key, ValueType& value) 
    {
        int index = hashFunction(key);
        for (const auto& pair : data_[index])  // Iterate through the list at 'index' to find the item
        {
            if (pair.first == key) 
            {
                return false; // Copy found
            }
        }
        data_[index].push_front({key, value});
        return true;
    }

//----------------------------getItem-----------------------
//Retrieves the value associated with a given key.
//---------------------------------------------------------------

    bool getItem(const KeyType& key, ValueType& value)
    {
        int index = hashFunction(key);

       
        for (const auto& pair : data_[index]) // Iterate through the list at 'index' to find the item
        {
            if (pair.first == key) 
            {
                value = pair.second;
                return true; //Item found
            }
        }

        return false;
    }


private:
    // The hash table data(using open hashing)
    vector<list<pair<KeyType, ValueType>>> data_;

    // Hash function
    int hashFunction(const KeyType& key) const 
    {
        int keyvalue = key;
        int returnValue = keyvalue % TABLESIZE;
        return returnValue;
    }
};
#endif
