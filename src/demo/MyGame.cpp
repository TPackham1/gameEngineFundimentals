#include "MyGame.h"


//Enemy *enemy;

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(5), gameWon(false), box(5, 5, 30, 30), enemy(Point2(400, 300), 2)
{
	TTF_Font * font = ResourceManager::loadFont("C:/Users/toppa/Documents/Uni/year2/CI517/Project/xcube/res/fonts/arial.ttf", 72);
	gfx->useFont(font);
	gfx->setVerticalSync(true);

    for (int i = 0; i < numKeys; i++) {
        std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
        k->isAlive = true;
        k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
        gameKeys.push_back(k);
    }
	//std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(Point2(400, 300), 2);
	//enemy = &Enemy(Point2(400, 300), 2);
}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	int speed = 3;

	if (eventSystem->isPressed(Key::W)) {
		velocity.y = -speed;
	}

	if (eventSystem->isPressed(Key::S)) {
		velocity.y = speed;
	}

	if (eventSystem->isPressed(Key::A)) {
		velocity.x = -speed;
	}

	if (eventSystem->isPressed(Key::D)) {
		velocity.x = speed;
	}
}

void MyGame::update() {
	box.x += velocity.x;
	box.y += velocity.y;

	for (auto key : gameKeys) {
		if (key->isAlive && box.contains(key->pos)) {
			score += 200;
			key->isAlive = false;
			numKeys--;
		}
	}

	velocity.x = 0;
    velocity.y = 0;

	if (numKeys == 0) {
		gameWon = true;
	}
	playerPosition.x = box.x;
	playerPosition.y = box.y;
	
	//enemy->Update(playerPosition);
	
	
	// 
	/*mySystem->Update(playerPosition);*/ // XCube doesn't like this?? why? if the enemy class is set up in the MyEngine System it has fit!
	//
}

void MyGame::render() {
	gfx->setDrawColor(SDL_COLOR_RED);
	gfx->drawRect(box);

	gfx->setDrawColor(SDL_COLOR_YELLOW);
	for (auto key : gameKeys)
        if (key->isAlive)
		    gfx->drawCircle(key->pos, 5);
	

	//rendering enemy

		/*gfx->setDrawColor(SDL_COLOR_GREEN);
		gfx->drawCircle(enemy->pos, 2);*/
	
}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_AQUA);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);

	if (gameWon) {
		gfx->drawText("YOU WON", 250, 500);
	}
	
}


Enemy::Enemy(Point2 startPos, int enemySpeed)
	{
		debug("Enemy init");
		pos = startPos; speed = enemySpeed;

	}



void Enemy::Update(const Point2& playerPos) 
	{
		// Calculate direction towards the player
		float dx = playerPos.x - pos.x;
		float dy = playerPos.y - pos.y;
		float distance = sqrt(dx * dx + dy * dy);

		// Normalize direction vector
		if (distance != 0) {
			dx /= distance;
			dy /= distance;
		}
		//debug("Moving towards the player");
		// Move towards the player
	/*	pos.x += dx * speed;
		pos.y += dy * speed;
	*/


	}



