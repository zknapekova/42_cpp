# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie 
{
	std::string name;
	
	public:
		void announce( void );
		void set_name( std::string name ) ;
		Zombie(std::string _name = "");
		~Zombie( void );
};

Zombie	*zombieHorde(int N, std::string name);

#endif
