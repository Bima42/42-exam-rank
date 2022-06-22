#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include <string>
class ASpell;
#include "ATarget.hpp"

class ASpell {

	protected:
		std::string _name;
		std::string _effects;

		ASpell();

	public:
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const &copy);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &right);

		const std::string &getName() const;
		const std::string &getEffects() const;

		virtual ASpell *clone () const = 0;

		void launch (ATarget const &target);
};

#endif
