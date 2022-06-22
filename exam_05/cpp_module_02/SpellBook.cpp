#include "SpellBook.hpp"

SpellBook::SpellBook () {}

SpellBook::~SpellBook () {}

void SpellBook::learnSpell (ASpell *spell) {
	if (spell) 
	{
		std::vector<ASpell*>::iterator ite = this->_book.end();
		for (std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->_book.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell (std::string const &name) {
	std::vector<ASpell*>::iterator ite = this->_book.end();
	for (std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it) {
		if ((*it)->getName() == name)
		{
			delete (*it);
			it = this->_book.erase(it);
		}
	}

}

ASpell *SpellBook::createSpell (std::string const &name) {
	std::vector<ASpell*>::iterator ite = this->_book.end();
	for (std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it) {
		if ((*it)->getName() == name) {
			return (*it);
		}
	}
	return (NULL);
}
