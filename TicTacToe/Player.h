#pragma once
#include "gameField.h"

class Player
{
protected:
	gameField *_gf;
	cellValue_t _cv;
public:
	void init(gameField* gf, cellValue_t cv)
	{
		_gf = gf;
		_cv = cv;
	}
	cellValue_t getCValue()
	{
		return _cv;
	}
	virtual Coord doNextStep() = 0;
};
