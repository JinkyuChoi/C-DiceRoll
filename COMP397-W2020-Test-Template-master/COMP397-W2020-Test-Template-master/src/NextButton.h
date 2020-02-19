#pragma once
#ifndef __NEXT_BUTTON__
#define __NEXT_BUTTON__

#include "Button.h"

class NextButton : public Button
{
public:
	NextButton();
	~NextButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__NEXT_BUTTON__) */