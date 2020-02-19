#include "Level2Scene.h"
#include "Game.h"

Level2Scene::Level2Scene()
{
	start();
}

Level2Scene::~Level2Scene()
{
}

void Level2Scene::draw()
{
	m_pRollButton->draw();

	m_pFirstDieLabel->draw();
	m_pSecondDieLabel->draw();
	m_pThirdDieLabel->draw();
	m_pFourthDieLabel->draw();

	m_pAddResultLabel->draw();

	switch (m_pFirstDieValue)
	{
	case 1:
		m_pOne->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pOne->draw();
		break;
	case 2:
		m_pTwo->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pTwo->draw();
		break;
	case 3:
		m_pThree->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pThree->draw();
		break;
	case 4:
		m_pFour->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pFour->draw();
		break;
	case 5:
		m_pFive->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pFive->draw();
		break;
	case 6:
		m_pSix->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pSix->draw();
		break;
	default:
		m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.3));
		m_pBlank->draw();
		break;
	}

	switch (m_pSecondDieValue)
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


	switch (m_pThirdDieValue)
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

	switch (m_pFourthDieValue)
	{
	case 1:
		m_pOne->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pOne->draw();
		break;
	case 2:
		m_pTwo->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pTwo->draw();
		break;
	case 3:
		m_pThree->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pThree->draw();
		break;
	case 4:
		m_pFour->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pFour->draw();
		break;
	case 5:
		m_pFive->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pFive->draw();
		break;
	case 6:
		m_pSix->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pSix->draw();
		break;
	default:
		m_pBlank->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.3));
		m_pBlank->draw();
		break;
	}
}

void Level2Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	if (m_pRollButton->ButtonClick())
	{
		RollFirstDie();
		RollSecondDie();
		RollThirdDie();
		RollFourthDie();
		AddWithoutLowest();
		m_pRollButton->setMouseButtonClicked(false);
	}
}

void Level2Scene::clean()
{
}

void Level2Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
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
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
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

void Level2Scene::start()
{
	m_pRollButton = new RollButton();
	

	m_pOne = new One();
	m_pTwo = new Two();
	m_pThree = new Three();
	m_pFour = new Four();
	m_pFive = new Five();
	m_pSix = new Six();




	m_pBlank = new Blank();

	SDL_Color black = { 0,0,0,255 };
	m_pFirstDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.20, Config::SCREEN_HEIGHT * 0.55), true, true);
	m_pSecondDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.40, Config::SCREEN_HEIGHT * 0.55), true, true);
	m_pThirdDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.60, Config::SCREEN_HEIGHT * 0.55), true, true);
	m_pFourthDieLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.80, Config::SCREEN_HEIGHT * 0.55), true, true);

	m_pAddResultLabel = new Label("Blank", "Consolas", 20,
		black, glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.60), true, true);
}

glm::vec2 Level2Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level2Scene::RollFirstDie()
{
	int firstDie = Util::RandomRange(1, 6);
	m_pFirstDieLabel->setText(std::to_string(firstDie));
	m_pFirstDieValue = firstDie;
}

void Level2Scene::RollSecondDie()
{
	int secondDie = Util::RandomRange(1, 6);
	m_pSecondDieLabel->setText(std::to_string(secondDie));
	m_pSecondDieValue = secondDie;
}

void Level2Scene::RollThirdDie()
{
	int thirdDie = Util::RandomRange(1, 6);
	m_pThirdDieLabel->setText(std::to_string(thirdDie));
	m_pThirdDieValue = thirdDie;
}

void Level2Scene::RollFourthDie()
{
	int fourthDie = Util::RandomRange(1, 6);
	m_pFourthDieLabel->setText(std::to_string(fourthDie));
	m_pFourthDieValue = fourthDie;
}

void Level2Scene::AddWithoutLowest()
{
	if(m_pFirstDieValue <= m_pSecondDieValue && m_pFirstDieValue <= m_pThirdDieValue && m_pFirstDieValue <= m_pFourthDieValue)
	{
		m_pAddResult = m_pSecondDieValue + m_pThirdDieValue + m_pFourthDieValue;
		m_pAddResultLabel->setText(std::to_string(m_pAddResult));
	}
	else if (m_pSecondDieValue <= m_pFirstDieValue && m_pSecondDieValue <= m_pThirdDieValue && m_pSecondDieValue <= m_pFourthDieValue)
	{
		m_pAddResult = m_pFirstDieValue + m_pThirdDieValue + m_pFourthDieValue;
		m_pAddResultLabel->setText(std::to_string(m_pAddResult));
	}
	else if (m_pThirdDieValue <= m_pFirstDieValue && m_pThirdDieValue <= m_pSecondDieValue && m_pThirdDieValue <= m_pFourthDieValue)
	{
		m_pAddResult = m_pFirstDieValue + m_pSecondDieValue + m_pFourthDieValue;
		m_pAddResultLabel->setText(std::to_string(m_pAddResult));
	}
	else if (m_pFourthDieValue <= m_pFirstDieValue && m_pFourthDieValue <= m_pSecondDieValue && m_pFourthDieValue <= m_pThirdDieValue)
	{
		m_pAddResult = m_pFirstDieValue + m_pSecondDieValue + m_pThirdDieValue;
		m_pAddResultLabel->setText(std::to_string(m_pAddResult));
	}
	else
	{
		m_pAddResult = 0;
		m_pAddResultLabel->setText(std::to_string(m_pAddResult));
	}
}
