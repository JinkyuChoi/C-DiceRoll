//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Two
//Referenced from Tom Tsiliopoulos


#include "Two.h"
#include "Game.h"

Two::Two()
{
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"two", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("two");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::DICE);
}

Two::~Two()
{
}

void Two::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("two", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Two::update()
{
}

void Two::clean()
{
}
