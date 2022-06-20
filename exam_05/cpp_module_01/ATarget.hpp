#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>
#include <iostream>
class ATarget;
#include "ASpell.hpp"

class ATarget {

	private:
		std::string _type;
	
	public:
		ATarget (std::string const _type);
		ATarget( ATarget const &copy );
		ATarget &operator=(ATarget const &right);
		virtual ~ATarget();

		const std::string &getType() const;

		void getHitBySpell ( ASpell const &spell ) const;

		virtual ATarget *clone() const = 0;
};

#endif
