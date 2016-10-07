#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer();
	RandomPlayer(gameField *gf, cellValue_t cv);
	~RandomPlayer();
	Coord doNextStep();
};

