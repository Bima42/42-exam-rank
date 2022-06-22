#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator () {}

TargetGenerator::~TargetGenerator () {}

void TargetGenerator::learnTargetType (ATarget *type) {
	if (type) 
	{
		std::vector<ATarget*>::iterator ite = this->_target.end();
		for (std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it) {
			if ((*it)->getType() == type->getType())
				return ;
		}
		this->_target.push_back(type->clone());
	}
}

void TargetGenerator::forgetTargetType (std::string const &type) {
	std::vector<ATarget*>::iterator ite = this->_target.end();
	for (std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it) {
		if ((*it)->getType() == type)
		{
			delete (*it);
			it = this->_target.erase(it);
		}
	}

}

ATarget *TargetGenerator::createTarget (std::string const &type) {
	std::vector<ATarget*>::iterator ite = this->_target.end();
	for (std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it) {
		if ((*it)->getType() == type) {
			return (*it);
		}
	}
	return (NULL);
}
