//Jinkyu Choi 301024988
//2020-02-18
//Level1Scene where you roll the dice
//Referenced from Tom Tsiliopoulos


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
	m_pNextButton->draw();

	m_pFirstDieLabel->draw();
	m_pSecondDieLabel->draw();

	switch (m_pFirstDieValue)
	{
	case 1:
		m_pOne->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pOne->draw();
		break;
	case 2:
		m_pTwo->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pTwo->draw();
		break;
	case 3:
		m_pThree->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pThree->draw();
		break;
	case 4:
		m_pFour->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pFour->draw();
		break;
	case 5:
		m_pFive->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pFive->draw();
		break;
	case 6:
		m_pSix->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pSix->draw();
		break;
	default:
		m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.3));
		m_pBlank->draw();
		break;
	}

	switch (m_pSecondDieValue)
	{
	case 1:
		m_pOne->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pOne->draw();
		break;
	case 2:
		m_pTwo->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pTwo->draw();
		break;
	case 3:
		m_pThree->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pThree->draw();
		break;
	case 4:
		m_pFour->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pFour->draw();
		break;
	case 5:
		m_pFive->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pFive->draw();
		break;
	case 6:
		m_pSix->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pSix->draw();
		break;
	default:
		m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.3));
		m_pBlank->draw();
		break;
	}
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	if(m_pRollButton->ButtonClick())
	{
		RollFirstDie();
		RollSecondDie();
		m_pRollButton->setMouseButtonClicked(false);
	}

	m_pNextButton->setMousePosition(m_mousePosition);
	if (m_pNextButton->ButtonClick())
	{
		TheGame::Instance()->changeSceneState(SceneState::LEVEL2_SCENE);
		m_pNextButton->setMouseButtonClicked(false);
	}
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
				m_pRollButton->setMouseButtonClicked(true);
				m_pNextButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				m_pNextButton->setMouseButtonClicked(false);
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
	m_pNextButton = new NextButton();

	m_pOne = new One();
	m_pTwo = new Two();
	m_pThree = new Three();
	m_pFour = new Four();
	m_pFive = new Five();
	m_pSix = new Six();



	
	m_pBlank = new Blank();

	SDL_Color black = { 0,0,0,255 };
	m_pFirstDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.55), true, true);
	m_pSecondDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.55), true, true);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::RollFirstDie()
{
	int firstDie = Util::RandomRange(1, 6);
	m_pFirstDieLabel->setText(std::to_string(firstDie));
	m_pFirstDieValue = firstDie;
}

void Level1Scene::RollSecondDie()
{
	int secondDie = Util::RandomRange(1, 6);
	m_pSecondDieLabel->setText(std::to_string(secondDie));
	m_pSecondDieValue = secondDie;
}

