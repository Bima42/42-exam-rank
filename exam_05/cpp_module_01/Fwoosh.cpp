#include "Fwoosh.hpp"

Fwoosh::Fwoosh (): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh (Fwoosh const &copy): ASpell(copy) {}

Fwoosh &Fwoosh::operator=(Fwoosh const &right ) {
	if (&right != this)
	{
		this->_name = right.getName();
		this->_effects = right.getEffects();
	}
	return (*this);
}

Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const { return (new Fwoosh()); }
