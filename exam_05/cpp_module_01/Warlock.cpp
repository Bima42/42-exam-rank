#include "Warlock.hpp"

Warlock::Warlock (std::string const &name, std::string const &title): _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { 
	std::cout << this->_name << ": My job here is done!" << std::endl; 
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; it++) {
		delete *it;
	}
	this->spells.clear();
}

const std::string &Warlock::getName ( void ) const {
	return (this->_name);
}

const std::string &Warlock::getTitle (void) const {
	return (this->_title);
}

void Warlock::setTitle(std::string const title) {
	this->_title = title;
}

void Warlock::introduce () const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell (ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ite = this->spells.end();
		for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->spells.push_back(spell->clone());
	}
}

void Warlock::forgetSpell (std::string spell_name) {
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spell_name)
		{
			delete *it ;
			it = this->spells.erase(it);
		}
	}
}

void Warlock::launchSpell (std::string spell_name, ATarget &target) {
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spell_name)
		{
			(*it)->launch(target);
			return ;
		}
	}
}
