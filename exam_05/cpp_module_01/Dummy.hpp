#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class Dummy: public ATarget {

	private:
		std::string _type;
	
	public:
		Dummy ();
		Dummy( Dummy const &copy );
		Dummy &operator=(Dummy const &right);
		virtual ~Dummy();

		ATarget *clone() const;
};

#endif
