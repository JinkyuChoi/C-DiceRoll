//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Five
//Referenced from Tom Tsiliopoulos


#include "Five.h"
#include "Game.h"

Five::Five()
{
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"five", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("five");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::DICE);
}

Five::~Five()
{
}

void Five::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("five", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Five::update()
{
}

void Five::clean()
{
}
