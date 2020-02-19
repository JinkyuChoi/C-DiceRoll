#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Blank.h"
#include "Five.h"
#include "Four.h"
#include "Label.h"
#include "One.h"
#include "RollButton.h"
#include "Scene.h"
#include "Six.h"
#include "Three.h"
#include "Two.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	RollButton* m_pRollButton;

	One* m_pOne;
	Two* m_pTwo;
	Three* m_pThree;
	Four* m_pFour;
	Five* m_pFive;
	Six* m_pSix;

	Blank* m_pBlank;

	Label* m_pFirstDiceLabel;
	Label* m_pSecondDiceLabel;



	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
