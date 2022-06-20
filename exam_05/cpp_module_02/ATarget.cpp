#include "ATarget.hpp"

ATarget::ATarget (std::string const type): _type(type) {}

ATarget::ATarget (ATarget const &copy) { *this = copy; }

ATarget &ATarget::operator=(ATarget const &right ) {
	if (&right != this)
		this->_type = right.getType();
	return (*this);
}

ATarget::~ATarget() {}

const std::string &ATarget::getType ( void ) const {
	return (this->_type);
}

void ATarget::getHitBySpell ( ASpell const &spell ) const {
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
