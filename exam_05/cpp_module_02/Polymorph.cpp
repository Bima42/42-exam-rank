#include "Polymorph.hpp"

Polymorph::Polymorph (): ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph (Polymorph const &copy): ASpell(copy) {}

Polymorph &Polymorph::operator=(Polymorph const &right ) {
	if (&right != this)
	{
		this->_name = right.getName();
		this->_effects = right.getEffects();
	}
	return (*this);
}

Polymorph::~Polymorph() {}

ASpell *Polymorph::clone() const { return (new Polymorph()); }
