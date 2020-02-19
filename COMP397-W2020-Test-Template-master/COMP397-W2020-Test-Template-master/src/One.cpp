//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for One
//Referenced from Tom Tsiliopoulos


#include "One.h"
#include "Game.h"

One::One()
{
	TheTextureManager::Instance()->load("../Assets/textures/1.png",
		"one", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("one");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::DICE);
}

One::~One()
{
}

void One::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("one", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void One::update()
{
}

void One::clean()
{
}
