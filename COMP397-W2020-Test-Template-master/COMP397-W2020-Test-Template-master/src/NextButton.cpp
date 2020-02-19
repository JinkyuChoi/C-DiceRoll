#include "NextButton.h"
#include "Config.h"

NextButton::NextButton()
// call super constructor
	:Button(
		"../Assets/textures/StartButton.png",
		"NextButton",
		START_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.8, Config::SCREEN_HEIGHT * 0.8)), m_isClicked(false)
{
}

NextButton::~NextButton()
{
}

bool NextButton::ButtonClick()
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