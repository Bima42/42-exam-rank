#include "Fireball.hpp"

Fireball::Fireball (): ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball (Fireball const &copy): ASpell(copy) {}

Fireball &Fireball::operator=(Fireball const &right ) {
	if (&right != this)
	{
		this->_name = right.getName();
		this->_effects = right.getEffects();
	}
	return (*this);
}

Fireball::~Fireball() {}

ASpell *Fireball::clone() const { return (new Fireball()); }
