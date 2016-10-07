#include "stdafx.h"
#include "RandomPlayer.h"
#include <list>
#include <map>
#include <time.h>

RandomPlayer::RandomPlayer(gameField *gf, cellValue_t cv) : Player()
{
	srand(time(NULL));
	init(gf, cv);
}
RandomPlayer::RandomPlayer() : Player()
{
}
RandomPlayer::~RandomPlayer()
{
}

/* choses empty cell and marks it by its cellValue
*/
Coord RandomPlayer::doNextStep()
{
	list<Coord> l = list<Coord>();
	Coord coord = _gf->getCoord();
	for (int x = 0; x < coord.x; x++)
	{
		for (int y = 0; y < coord.y; y++)
		{
			cellValue_t cell = _gf->getValueFrom(x, y);
			if (cell == cv_none)
			{
				Coord c = { x, y };
				l.push_back(c);
			}
		}
	}

	Coord retval = { -1, -1 };
	if (l.size() > 0)
	{
		int r = rand() % l.size();
		list<Coord>::iterator iter = l.begin();
		while (r > 0) { r--; iter++; }
		retval = (*iter);
	}
	return retval;
}
