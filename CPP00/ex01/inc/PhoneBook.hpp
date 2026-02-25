#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		int add_contact();
		//int search_contact()
	private:
		int _count;
		Contact arr[8];
		//void print_contacts();
};

#endif