#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator {

	private:
		std::vector<ATarget*> target;

	public:
		TargetGenerator();
		virtual ~TargetGenerator();

		void learnTargetType (ATarget *target);
		void forgetTargetType (std::string const &type);
		ATarget *createTarget (std::string const &type); 
};

#endif
