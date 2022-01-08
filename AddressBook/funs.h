#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#define LEN 1000
#define UINT unsigned int
using namespace std;

struct AddressBook {
	string name;
	UINT sex;
	UINT age;
	UINT teleponeNumber;
	string address;
};



void addContacts(UINT *addc,AddressBook oneAdd);
void showContacts(UINT addc);
void deleteContacts(string name,UINT *addc);
void findContacts(string name);
void modifyContacts(string name);
void clearContacts(UINT *addc);
void testAdd(UINT* addc);
