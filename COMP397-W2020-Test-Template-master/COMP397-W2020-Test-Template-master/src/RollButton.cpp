#include "RollButton.h"

#include "Config.h"

RollButton::RollButton()
// call super constructor
	:Button(
		"../Assets/textures/rollButton.png",
		"rollButton",
		START_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.8)), m_isClicked(false)
{
}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
