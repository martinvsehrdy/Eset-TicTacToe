#include "StdAfx.h"
#include "gameField.h"


gameField::gameField(void)
{
	sizeX = 0;
	sizeY = 0;
	field = NULL;
	emptyCells = hash<int>();
}
gameField::~gameField(void)
{
	if(field != NULL)
	{
		delete field[];
	}
}

int gameField::convertXYToIndex(int x, int y)
{
	int result = -1;
	if(0<=x && x<sizeX && 0<=y && y<sizeY)
	{
		result = x+y*sizeX;
	}
	return result;
}

void gamefield::
