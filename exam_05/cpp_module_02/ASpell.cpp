#include "ASpell.hpp"

ASpell::ASpell ( std::string name, std::string effects ): _name(name), _effects(effects) {}

ASpell::ASpell ( ASpell const &copy ): _name(copy._name), _effects(copy._effects) {}

ASpell::~ASpell () {}

ASpell &ASpell::operator=(ASpell const &right) {
	if (&right != this)
	{
		this->_name = right._name;
		this->_effects = right._effects;
	}
	return (*this);
}

const std::string &ASpell::getName () const {
	return (this->_name);
}

const std::string &ASpell::getEffects () const {
	return (this->_effects);
}

void ASpell::launch ( ATarget const &target ) {
	target.getHitBySpell(*this);
}
