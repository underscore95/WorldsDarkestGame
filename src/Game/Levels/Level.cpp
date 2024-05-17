#include "Level.h"
#include <iostream>

#include "Level0.h"
#include "Level1.h"
#include "Level2.h"

std::unique_ptr<Level> Level::getLevel(unsigned int level)
{
	switch (level) {
	case 0:
		return std::make_unique<Level0>();
	case 1:
		return std::make_unique<Level1>();
	case 2:
		return std::make_unique<Level2>();

	default:
		std::cerr << "Level " << level << " not found" << std::endl;
		return std::make_unique<Level0>();
	}
}
