#include "StdAfx.h"
#include "gameField.h"
#include <ctime>


gameField::gameField(void)
{
	sizeX = 0;
	sizeY = 0;
	field = NULL;
	emptyCells = new map<int, bool>();
	srand(time(0));
}
gameField::~gameField(void)
{
	if(field != NULL)
	{
		delete[] field;
	}
	delete emptyCells;
}

int gameField::convertXYToIndex(int x, int y)
{
	int result = -1;
	if (0 <= x && x<sizeX && 0 <= y && y<sizeY)
	{
		result = x + y*sizeX;
	}
	return result;
}

void gameField::init(int x, int y)
{
	if (field != NULL)
	{
		delete[] field;
	}
	sizeX = x;
	sizeY = y;
	field = new cellValue_t[sizeX*sizeY];
	emptyCells->clear();
	for (int i = 0; i < sizeX*sizeY; i++)
	{
		field[i] = cv_none;
		emptyCells[i] = true;
	}
}
cellValue_t gameField::getValueFrom(int x, int y)
{
	cellValue_t res = cv_err;
	if (field != NULL && 0 <= x && x < sizeX && 0 <= y && y < sizeY)
	{
		int i = convertXYToIndex(x, y);
		res = field[i];
	}
	return res;
}

/* sets cell on coordinate x,y as value and return its value
 * Return
 *   cv_err - x,y is out of field
 *   cv_none - cell is not empty (cv_none)
 *   cv_X, cv_Y - successfully placed
 */
cellValue_t gameField::setCellAs(int x, int y, cellValue_t value)
{
	cellValue_t res = cv_err;
	if (field != NULL && 0 <= x && x < sizeX && 0 <= y && y < sizeY)
	{
		int i = convertXYToIndex(x, y);
		if (field[i] == cv_none)
		{
			res = field[i] = value;
			emptyCells->erase(i);
		}
		else
		{
			res = cv_none;
		}
	}
	return res;
}

/* choses empty cell and marks it by its cellValue
*/
void gameField::doNextStep(int &x, int &y)
{
	int r = rand();
	r %= emptyCells->count;
	map<int, bool>::iterator iter = emptyCells->begin();
	while (r > 0) { r--; iter++; }
	
	iter->first


}

cellValue_t gameField::whoHasWon()
{
	return cv_none;
}