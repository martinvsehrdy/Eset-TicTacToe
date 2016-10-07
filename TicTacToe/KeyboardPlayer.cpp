#include "stdafx.h"
#include "KeyboardPlayer.h"
#include <iostream>


KeyboardPlayer::KeyboardPlayer() : Player()
{
}
KeyboardPlayer::KeyboardPlayer(gameField *gf, cellValue_t cv) : Player()
{
	init(gf, cv);
}
KeyboardPlayer::~KeyboardPlayer()
{
}

Coord KeyboardPlayer::doNextStep()
{
	Coord retval = { -1, -1 };
	if (_gf != NULL)
	{
		Coord coord = _gf->getCoord();
		_gf->printField();
		cout << "XY = ";
		char buf[3];
		cin >> buf;
		for (int i = 0; i < 2; i++)
		{
			int x = buf[i] - 'A';
			if (0 <= x && x < coord.x)
			{
				retval.x = x;
			}
			int y = buf[i] - '1';
			if (0 <= y && y < coord.y)
			{
				retval.y = y;
			}
		}
	}
	return retval;
}
