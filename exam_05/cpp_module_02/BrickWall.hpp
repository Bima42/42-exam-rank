#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall: public ATarget {

	private:
		std::string _type;
	
	public:
		BrickWall ();
		BrickWall( BrickWall const &copy );
		BrickWall &operator=(BrickWall const &right);
		virtual ~BrickWall();

		ATarget *clone() const;
};

#endif
