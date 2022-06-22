#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
class Warlock;
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include "ASpell.hpp"

class Warlock {

	private:
		std::string _name;
		std::string _title;

		SpellBook _book;

		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &right);

	public:
		Warlock(std::string name, std::string title);
		virtual ~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle (std::string const &title);

		void introduce () const;

		void learnSpell (ASpell *spell);
		void forgetSpell (std::string name);
		void launchSpell (std::string name, ATarget &target);
};

#endif
