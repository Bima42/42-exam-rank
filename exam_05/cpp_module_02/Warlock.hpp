#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
class Warlock;
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "ATarget.hpp"

class Warlock {

	private:
		std::string _name;
		std::string _title;
		SpellBook	book;

		Warlock();
		Warlock( Warlock const &copy );
		Warlock &operator=(Warlock const &right);
	
	public:
		Warlock (std::string const &name, std::string const &title);
		virtual ~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(std::string const title);

		void introduce() const;

		void learnSpell (ASpell *spell);
		void forgetSpell (std::string spell_name);
		void launchSpell (std::string spell_name, ATarget &target);
};

#endif
