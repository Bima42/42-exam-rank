#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
class SpellBook;
#include "ASpell.hpp"

class SpellBook {

	private:
		std::vector<ASpell*> _book;

		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &right);

	public:
		SpellBook();
		virtual ~SpellBook();

		void learnSpell (ASpell *spell);
		void forgetSpell (std::string const &name);
		ASpell *createSpell (std::string const &name);
};

#endif
