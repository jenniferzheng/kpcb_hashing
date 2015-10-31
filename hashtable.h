/* Author: Jennifer Zheng
*  Assignment: KPCB Engineering Fellows Application
*  This 
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

template <class T>
class HashTable {
public:
	// struct for every item in linked list
	struct Item {
		T* _val; // a pointer to an arbitrary data object
		std::string _key; // stores the key string
		Item* _next; // Item pointer to the next item in linked list; 
					 // NULL if its the last or only Item in list		
	};

	HashTable(int size);
	~HashTable();
	bool set(std::string key, T* val);
	T* get(std::string key);
	float load();
	T* del(std::string key);
	void print_hashtable();

private:
	int hash_function(std::string str); // hashing function

	Item** hashtable; // array of singly linked lists
	int cap; // total capacity
	int _size; // counter for size
};

// Constructor
template<class T>
HashTable<T>::HashTable(int size) {
	hashtable = new Item*[size];
	cap = size;
	_size = 0;

	for (int i = 0; i < cap; i++) {
		hashtable[i] = NULL;
	}
}

template<class T>
HashTable<T>::~HashTable() {
	// fill in here
	// go through every item in the linked list and then delete[]
	for (int i = 0; i < cap; i++) {
		Item* a = hashtable[i];
		while (a != NULL) {
			Item* temp = a->_next;
			delete a;
			a = temp;
		}
	}

	delete[] hashtable; 
}

// Function to calculate hash value
template<class T>
int HashTable<T>::hash_function(std::string val) {
	int hash = 0;
	for (unsigned int i = 0; i < val.size(); i++) {
		int ascii = val[i];
		hash += ascii;
	}		
	return hash % cap;
}

// Stores the given key/value pair in the hash map
// Returns a bool value indicating success/failure of operation
template<class T>
bool HashTable<T>::set(std::string key, T* val)  {
	int hash = hash_function(key);
	// if the linked list has not been initialized at that position yet
	if (hashtable[hash] == NULL) {
		Item* a = new Item;
		a->_next = NULL;
		a->_key = key;
		a->_val = val;
		hashtable[hash] = a;
		_size++;
	} else { // if you need to update the linked list with new Item*
		Item* a = hashtable[hash];
		Item* b = new Item; 
		while (a != NULL) {
			// if the key already exists in linked list, do not set again
			// unless the associated value to the key is NULL
			if (a->_key == key) {
				delete b;
				if (a->_val != NULL)
					return false;
				else {
					a->_val = val;
					return true;
				}
			} else if (a->_next == NULL) { // else, add new Item to end of list
				b->_next = NULL;
				b->_key = key;
				b->_val = val;
				a->_next = b;
				_size++;
				break;
			}
			a = a->_next;
		}
	}
	return true;
}

// Return the value associated with the given key
// Or null if no value is set
template<class T>
T* HashTable<T>::get(std::string key) {
	int hash = hash_function(key); // calcuate hash

	Item* a = hashtable[hash];

	// find the key within the linked list
	while (a != NULL) {
		if (a->_key == key) {
			return a->_val;
		}
		a = a->_next;
	}
	// if you do not find it by the end of the list, return NULL
	return NULL;
}

// Delete the value associated with the given key
// Returns the value on success or null if the key has no value
template<class T>
T* HashTable<T>::del(std::string key) {
	int hash = hash_function(key);

	Item* a = hashtable[hash];

	while (a != NULL) {
		if (a->_key == key) {
			if (a->_val == NULL) {
				return NULL;
			} else {
				T* temp = a->_val;
				a->_val = NULL;
				return temp;
			}
			break;
		}
		a = a->_next;
	}

	return NULL;
}

// Return a float value representing the load factor of the data structure
// (items in hash map) / (size of hash map)
template<class T>
float HashTable<T>::load() {
	float load_f = (double) _size / cap;
	return load_f;
}

// Printing out the Hash Table in current state
template<class T>
void HashTable<T>::print_hashtable() {
	for (int i = 0; i < cap; i++) {
		// if the linked list is empty
		if (hashtable[i] == NULL) {
			std::cout << (i + 1) << ". Empty" << std::endl;
		} else { // else print out individual Items in order
			Item* a = hashtable[i];
			std::cout << (i + 1) << ". ";
			while (a != NULL) {
				std::cout << a->_key << ", ";
				if (a->_val == NULL)
					std::cout << "NULL" << " ---> ";
				else
					std::cout << *(a->_val) << " ---> ";
				a = a->_next;
			}
			std::cout << std::endl;
		}
	}
	// prints out capacity, size, and load factor
	std::cout << "Total capacity = " << cap << ", Size = " << _size << std::endl;
	std::cout << "Load factor = " << load() << std::endl;
}

#endif