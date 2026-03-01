# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie 
{
	std::string name;
	
	public:
		void announce( void );
		Zombie(std::string _name);
		~Zombie( void );
};

Zombie *newZombie( std::string name);
void	randomChump( std::string name);


#endif
