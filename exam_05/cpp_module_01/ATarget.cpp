#include "ATarget.hpp"

ATarget::ATarget ( std::string type ): _type(type) {}

ATarget::ATarget ( ATarget const &copy ): _type(copy._type) {}

ATarget::~ATarget () {}

ATarget &ATarget::operator=(ATarget const &right) {
	if (&right != this)
		this->_type = right._type;
	return (*this);
}

const std::string &ATarget::getType () const {
	return (this->_type);
}

void ATarget::getHitBySpell( ASpell const &spell ) const {
	std::cout << this->_type << "has been " << spell.getEffects() << "!" << std::endl;
}
