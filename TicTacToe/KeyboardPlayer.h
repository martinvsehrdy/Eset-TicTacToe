#pragma once
#include "Player.h"
class KeyboardPlayer :
	public Player
{
public:
	KeyboardPlayer();
	KeyboardPlayer(gameField *gf, cellValue_t cv);
	~KeyboardPlayer();
	Coord doNextStep();
};

