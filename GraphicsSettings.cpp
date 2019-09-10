#include "stdafx.h"
#include "GraphicsSettings.h"

// Constructors and Destructors
GraphicsSettings::GraphicsSettings()
	:fullscreen(NULL), verticalSync(NULL), frameRateLimit(NULL)
{

}

GraphicsSettings::~GraphicsSettings()
{

}

// Functions
void GraphicsSettings::loadFromFile(const std::string path)
{
	std::ifstream ifs(path);

	if (ifs.is_open())
	{
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->frameRateLimit;
		ifs >> this->verticalSync;
		ifs >> this->contextSettings.antialiasingLevel;
	}

	ifs.close();
}
