# kpcb_hashing
Hashing program for KPCB application (optional challenge question)

Author: Jennifer Zheng
Assignment: KPCB Engineering Fellows Applications - Challenge Question
Date: October 30, 2015
Language: C++

My submission for the challenge question includes two programs:
	hashtable.h = templated class for a hash table
	hash_test.cpp = test file for the program

How to compile:
	g++ -g hash_test.cpp -o hash_test

How to run:
	./hash_test

Notes:
	1.The delete function in the hash table class is named del instead because delete is a keyword in C++

	2. For the set function, it returns true (successfully set) if the key does not already exist in table OR if it does already exist, but the associated value is NULL (i.e. it was previously deleted). Otherwise, it returns false and does NOT reset the key.

	3. Since C++ does not include a built in hashing function for strings, my hash function implementation includes ASCII conversions and modulo arithmetic. This strategy was found in the lecture slides of my Data Structures and Object Oriented Design course (taught by Mark Redekopp). The hash table would be preferably initialized with a prime size. 

	4. My general implementation for a hash table includes a 2D array, which is essentially a fized-sized array of singly-linked lists. A struct called Item is defined to serve as every individual node in a linked list. An outline of what each Item stores is included in the comments of hashtable.h

	5. My hash table is also templated to allow the user to associate the string keys to any data type to their liking. In my test file, I tested two types of hash tables, one that associates to ints and another that associates to strings. 
		To initialize your own hash table: 
			HashTable<type> name(int size);

	6. Also wrote a helper function that prints out the hash table, for testing purposes. 

Thank you for considering my application!
