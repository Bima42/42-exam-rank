#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator () {}

TargetGenerator::~TargetGenerator() { 
	std::vector<ATarget*>::iterator ite = this->target.end();
	for (std::vector<ATarget*>::iterator it = this->target.begin(); it != ite; it++) {
		delete *it;
	}
	this->target.clear();
}

void TargetGenerator::learnTargetType (ATarget *target) {
	if (target) {
		std::vector<ATarget*>::iterator ite = this->target.end();
		for (std::vector<ATarget*>::iterator it = this->target.begin(); it != ite; ++it) {
			if ((*it)->getType() == target->getType())
				return ;
		}
		this->target.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType (std::string const &type) {
	std::vector<ATarget*>::iterator ite = this->target.end();
	for (std::vector<ATarget*>::iterator it = this->target.begin(); it != ite; ++it) {
		if ((*it)->getType() == type)
		{
			delete *it ;
			it = this->target.erase(it);
		}
	}
}

ATarget *TargetGenerator::createTarget (std::string const &type) {
	std::vector<ATarget*>::iterator ite = this->target.end();;
	for (std::vector<ATarget*>::iterator it = this->target.begin(); it != ite; ++it) {
		if ((*it)->getType() == type)
			return (*it);
	}
	return (NULL);
}
