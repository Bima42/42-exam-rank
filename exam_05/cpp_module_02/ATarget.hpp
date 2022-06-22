#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
class ATarget;
#include "ASpell.hpp"

class ATarget {

	protected:
		std::string _type;

		ATarget();

	public:
		ATarget(std::string type);
		ATarget(ATarget const &copy);
		virtual ~ATarget();

		ATarget &operator=(ATarget const &right);

		const std::string &getType() const;

		void getHitBySpell(ASpell const &spell) const;

		virtual ATarget *clone () const = 0;
};

#endif
