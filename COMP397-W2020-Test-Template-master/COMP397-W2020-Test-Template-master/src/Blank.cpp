//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Blank
//Referenced from Tom Tsiliopoulos


#include "Blank.h"
#include "Game.h"


Blank::Blank()
{
	TheTextureManager::Instance()->load("../Assets/textures/blank.png",
		"blank", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("blank");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::DICE);
}

Blank::~Blank()
{
}

void Blank::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("blank", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Blank::update()
{
}

void Blank::clean()
{
}
