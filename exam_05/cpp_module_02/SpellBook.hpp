#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <iostream>
#include <vector>
class SpellBook;
#include "ASpell.hpp"

class SpellBook {

	private:
		std::vector<ASpell*> book;

		SpellBook( SpellBook const &copy );
		SpellBook &operator=(SpellBook const &right);
	
	public:
		SpellBook();
		SpellBook (std::string const name, std::string const title);
		virtual ~SpellBook();

		void learnSpell (ASpell *spell);
		void forgetSpell (std::string const &spell_name);
		ASpell *createSpell (std::string const &name); 
};

#endif
