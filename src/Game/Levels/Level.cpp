#include "Level.h"
#include "Level0.h"
#include "Level1.h"
#include <iostream>

std::unique_ptr<Level> Level::getLevel(unsigned int level)
{
	switch (level) {
	case 1:
		return std::make_unique<Level0>();
	case 0:
		return std::make_unique<Level1>();

	default:
		std::cerr << "Level " << level << " not found" << std::endl;
		return std::make_unique<Level0>();
	}
}
