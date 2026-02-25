#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	std::string _first_name, _last_name, _nickname, _phone_number, _darkest_secret;

	
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		Contact();
		void print_contact();
	private:
		void print_var(std::string var);

};

#endif


