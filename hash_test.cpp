/* Author: Jennifer Zheng
*  Assignment: KPCB Engineering Fellows Application
*/

#include "hashtable.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	// Declare a hash table that associates a string key with an int value
	HashTable<int> h(31);
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	// Fill in the hash table
	h.set("hello", &a);
	h.set("world", &b);
	h.set("my", &c);
	h.set("name", &d);
	h.set("is", &e);
	h.set("the", &a);
	h.set("red", &b);
	h.set("fox", &c);
	h.set("jumped", &d);
	h.set("over", &e);
	bool success = h.set("the", &b); // Test to see if an already existing key is reset
	h.set("lazy", &b);
	h.set("dog", &c);

	cout << "Original hash table: " << endl;
	h.print_hashtable();

	// An already existing key should NOT be set again if its key is not NULL
	if (!success)
		cout << "'the' was not set again" << endl;

	// Testing the delete function
	int * p1 = h.del("hello");
	int * p2 = h.del("world");
	int * p3 = h.del("my");
	int * p4 = h.del("name");
	int * p5 = h.del("is");
	int * p6 = h.del("is");

	cout << endl << endl << "AFTER DELETE" << endl;
	h.print_hashtable();
	cout << "Deleted items in order: " << endl;
	cout << *p1 << *p2 << *p3 << *p4 << *p5 << endl;
	if (p6 == NULL)
		cout << "Deleting 'is' again returns NULL" << endl;

	bool reset = h.set("hello", &b);
	if (reset) {
		cout << "Previously deleted value has been successfully reset" << endl << endl << endl;
	}
	
	HashTable<string> h2(31);
	string a2 = "one";
	string b2 = "two";
	string c2 = "three";
	string d2 = "four";
	string e2 = "five";

	h2.set("kpcb", &a2);
	h2.set("fellows", &b2);
	h2.set("engineering", &c2);
	h2.set("design", &d2);
	h2.set("product", &e2);
	h2.set("the", &a2);
	h2.set("is", &b2);
	h2.set("silicon", &c2);
	h2.set("valley", &d2);
	h2.set("start", &e2);
	bool success2 = h2.set("the", &b2);
	h2.set("ups", &b2);
	h2.set("best", &c2);

	cout << "Original hash table: " << endl;
	h2.print_hashtable();

	// "the" should NOT be set again because it already exists
	if (!success2)
		cout << "'the' was not set again" << endl;

	string * q1 = h2.del("kpcb");
	string * q2 = h2.del("fellows");
	string * q3 = h2.del("engineering");
	string * q4 = h2.del("design");
	string * q5 = h2.del("is");
	string * q6 = h2.del("is");

	cout << endl << endl << "AFTER DELETE" << endl;
	h2.print_hashtable();
	cout << "Deleted items in order: " << endl;
	cout << *q1 << " " << *q2 << " " << *q3 << " " << *q4 << " " << *q5 << " " << endl;
	if (q6 == NULL)
		cout << "Deleting 'is' again returns NULL" << endl;

	bool reset2 = h2.set("kpcb", &b2);
	// Since the value was previously deleted, it is allowed to be reset
	if (reset2) {
		cout << "Previously deleted value has been successfully reset" << endl;
	}

	return 0;
}