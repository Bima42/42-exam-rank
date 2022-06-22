#include "Warlock.hpp"

Warlock::Warlock ( std::string name, std::string title ): _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock () {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName () const {
	return (this->_name);
}

const std::string &Warlock::getTitle () const {
	return (this->_title);
}

void Warlock::setTitle (std::string const &title) {
	this->_title = title;
}

void Warlock::introduce () const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell (ASpell *spell) {
	if (spell) 
	{
		std::vector<ASpell*>::iterator ite = this->_spells.end();
		for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->_spells.push_back(spell->clone());
	}
}

void Warlock::forgetSpell (std::string name) {
	std::vector<ASpell*>::iterator ite = this->_spells.end();
	for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == name)
		{
			delete (*it);
			it = this->_spells.erase(it);
		}
	}

}

void Warlock::launchSpell (std::string name, ATarget &target) {
	std::vector<ASpell*>::iterator ite = this->_spells.end();
	for (std::vector<ASpell*>::iterator it = this->_spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == name)
		{
			(*it)->launch(target);
			return ;
		}
	}
}
