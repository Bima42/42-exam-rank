#include "Dummy.hpp"

Dummy::Dummy (): ATarget("Target Practise Dummy") {}

Dummy::Dummy (Dummy const &copy): ATarget(copy) {}

Dummy &Dummy::operator=(Dummy const &right ) {
	if (&right != this)
		this->_type = right.getType();
	return (*this);
}

Dummy::~Dummy() {}

ATarget *Dummy::clone () const { return (new Dummy()); }
