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
    // Constructor
    Hash(){
        data_.resize(TABLESIZE);
    }

     // Adds an item with the given key and value to the hash table. Updates the value if the key already exists.
    bool addItem(const KeyType& key, ValueType& value) {
        int index = hashFunction(key);
       // Iterate through the list at 'index' to find the item
        for (const auto& pair : data_[index]) {
            if (pair.first == key) {
                return false; // Copy found
            }
        }
        data_[index].push_front({key, value});
        return true;
    }

     // Applies a given function to each item in the hash table.
    void forEachItem(const function<void(const pair<KeyType, ValueType>&)>& func) const {
        
    }

    // Retrieves the value associated with a given key.
    bool getItem(const KeyType& key, ValueType& value){
        int index = hashFunction(key);

       // Iterate through the list at 'index' to find the item
        for (const auto& pair : data_[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true; // Item found
            }
        }

        return false;
    }

    // Removes the item with the specified key from the hash table.
    bool removeItem(const KeyType& key) {
        return false;
    }

    void clear(){

    }

    void empty(){
        
    }

private:
    // The hash table data(using open hashing)
    vector<list<pair<KeyType, ValueType>>> data_;

    // Hash function
    int hashFunction(const KeyType& key) const {
        int keyvalue = key;
        int returnValue = keyvalue % TABLESIZE;
        return returnValue;
    }
};
#endif
