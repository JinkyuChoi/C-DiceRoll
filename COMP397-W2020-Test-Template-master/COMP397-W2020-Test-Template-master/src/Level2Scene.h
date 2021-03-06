//Jinkyu Choi 301024988
//2020-02-18
//Level2Scene where you roll the dice
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __LEVEL_2_SCENE__
#define __LEVEL_2_SCENE__

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

class Level2Scene : public Scene
{
public:
	Level2Scene();
	~Level2Scene();

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

	Label* m_pFirstDieLabel;
	Label* m_pSecondDieLabel;
	Label* m_pThirdDieLabel;
	Label* m_pFourthDieLabel;

	Label* m_pAddResultLabel;

	// methods
	void RollFirstDie();
	void RollSecondDie();
	void RollThirdDie();
	void RollFourthDie();

	void AddWithoutLowest();

	//properties
	int m_pFirstDieValue;
	int m_pSecondDieValue;
	int m_pThirdDieValue;
	int m_pFourthDieValue;

	int m_pAddResult;

	// private data member
	glm::vec2 m_mousePosition;


};

#endif /* defined (__LEVEL_1_SCENE__) */