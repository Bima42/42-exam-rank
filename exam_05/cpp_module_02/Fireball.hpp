#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball: public ASpell {

	private:
		std::string _name;
		std::string _effects;

	
	public:
		Fireball();
		Fireball( Fireball const &copy );
		Fireball &operator=(Fireball const &right);
		virtual ~Fireball();

		ASpell *clone() const;
};

#endif
