#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph: public ASpell {

	private:
		std::string _name;
		std::string _effects;

	
	public:
		Polymorph();
		Polymorph( Polymorph const &copy );
		Polymorph &operator=(Polymorph const &right);
		virtual ~Polymorph();

		ASpell *clone() const;
};

#endif
