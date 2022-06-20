#include "Warlock.hpp"

Warlock::Warlock (std::string const name, std::string const title): _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << this->_name << ": My job here is done." << std::endl; }

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
