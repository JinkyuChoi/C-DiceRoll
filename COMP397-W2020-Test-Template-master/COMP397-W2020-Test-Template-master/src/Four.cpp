//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Four
//Referenced from Tom Tsiliopoulos


#include "Four.h"
#include "Game.h"

Four::Four()
{
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"four", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("four");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::DICE);
}

Four::~Four()
{
}

void Four::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("four", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Four::update()
{
}

void Four::clean()
{
}
