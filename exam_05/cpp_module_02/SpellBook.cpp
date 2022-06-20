#include "SpellBook.hpp"

SpellBook::SpellBook () {}

SpellBook::~SpellBook() { 
	std::vector<ASpell*>::iterator ite = this->book.end();
	for (std::vector<ASpell*>::iterator it = this->book.begin(); it != ite; it++) {
		delete *it;
	}
	this->book.clear();
}

void SpellBook::learnSpell (ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ite = this->book.end();
		for (std::vector<ASpell*>::iterator it = this->book.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->book.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell (std::string const &spell_name) {
	std::vector<ASpell*>::iterator ite = this->book.end();
	for (std::vector<ASpell*>::iterator it = this->book.begin(); it != ite; ++it) {
		if ((*it)->getName() == spell_name)
		{
			delete *it ;
			it = this->book.erase(it);
		}
	}
}

ASpell *SpellBook::createSpell (std::string const &name) {
	std::vector<ASpell*>::iterator ite = this->book.end();
	for (std::vector<ASpell*>::iterator it = this->book.begin(); it != ite; ++it) {
		if ((*it)->getName() == name)
			return (*it);
	}
	return (NULL);
}
