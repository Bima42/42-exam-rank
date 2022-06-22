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
	this->_book.learnSpell(spell);
}

void Warlock::forgetSpell (std::string name) {
	this->_book.forgetSpell(name);
}

void Warlock::launchSpell (std::string name, ATarget &target) {
	ATarget const *test = 0;
	if (test == &target)
		return ;
	ASpell *tmp = _book.createSpell(name);
	if (tmp)
		tmp->launch(target);
}
