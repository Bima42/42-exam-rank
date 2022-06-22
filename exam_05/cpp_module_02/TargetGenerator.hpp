#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>
class TargetGenerator;
#include "ATarget.hpp"

class TargetGenerator {

	private:
		std::vector<ATarget*> _target;

		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &right);

	public:
		TargetGenerator();
		virtual ~TargetGenerator();

		void learnTargetType (ATarget *type);
		void forgetTargetType (std::string const &type);
		ATarget *createTarget (std::string const &type);
};

#endif
