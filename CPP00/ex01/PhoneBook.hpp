#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		int add_contact();
		int search_contact();
	private:
		Contact arr[8];
		size_t _count, _ind;
		void arr_limit_check();	
};

#endif
