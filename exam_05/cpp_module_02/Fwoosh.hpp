#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh: public ASpell {

	private:
		std::string _name;
		std::string _effects;

	
	public:
		Fwoosh();
		Fwoosh( Fwoosh const &copy );
		Fwoosh &operator=(Fwoosh const &right);
		virtual ~Fwoosh();

		ASpell *clone() const;
};

#endif
