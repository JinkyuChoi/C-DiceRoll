#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pRollButton->draw();

	m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25, Config::SCREEN_HEIGHT * 0.3));
	m_pBlank->draw();

	m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.3));
	m_pBlank->draw();

	m_pFirstDiceLabel->draw();
	m_pSecondDiceLabel->draw();
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pRollButton = new RollButton();

	m_pBlank = new Blank();

	SDL_Color black = { 0,0,0,255 };
	m_pFirstDiceLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.25, Config::SCREEN_HEIGHT * 0.55), true, true);
	m_pSecondDiceLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.55), true, true);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

