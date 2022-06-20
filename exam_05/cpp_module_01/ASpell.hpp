#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>
#include <iostream>
class ASpell;
#include "ATarget.hpp"

class ASpell {

	private:
		std::string _name;
		std::string _effects;

		ASpell();
	
	public:
		ASpell (std::string const name, std::string const effects);
		ASpell( ASpell const &copy );
		ASpell &operator=(ASpell const &right);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;

		void launch ( ATarget const &target );

		virtual ASpell *clone() const = 0;
};

#endif
