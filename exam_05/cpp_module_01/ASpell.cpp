#include "ASpell.hpp"

ASpell::ASpell (std::string const name, std::string const effects): _name(name), _effects(effects) {}

ASpell::ASpell (ASpell const &copy) { *this = copy; }

ASpell &ASpell::operator=(ASpell const &right ) {
	if (&right != this)
	{
		this->_name = right.getName();
		this->_effects = right.getEffects();
	}
	return (*this);
}

ASpell::~ASpell() {}

const std::string &ASpell::getName ( void ) const {
	return (this->_name);
}

const std::string &ASpell::getEffects (void) const {
	return (this->_effects);
}

void ASpell::launch ( ATarget const &target ) {
	target.getHitBySpell(*this);
}
