#include "BrickWall.hpp"

BrickWall::BrickWall (): ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall (BrickWall const &copy): ATarget(copy) {}

BrickWall &BrickWall::operator=(BrickWall const &right ) {
	if (&right != this)
		this->_type = right.getType();
	return (*this);
}

BrickWall::~BrickWall() {}

ATarget *BrickWall::clone () const { return (new BrickWall()); }
