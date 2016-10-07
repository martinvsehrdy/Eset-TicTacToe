#include "StdAfx.h"
#include "gameField.h"
#include <iostream>
#include <ctime>
#include <algorithm>

template<class T>
void delete2DimArray(T *arr, int sX, int sY)
{
	if (arr != NULL)
	{
		for (int x = 0; x < sX; x++)
		{
			if (arr[x] != NULL)
			{
				delete[] arr[x];
			}
		}
		delete[] arr;
		arr = NULL;
	}
}

gameField::gameField(void)
{
	init(0, 0);
	srand(time(0));
}

gameField::gameField(int x, int y)
{
	init(x, y);
	srand(time(0));
}

gameField::~gameField(void)
{
	delete2DimArray(field, sizeX, sizeY);
}

void gameField::init(int x, int y)
{
	delete2DimArray(field, sizeX, sizeY);
	sizeX = x;
	sizeY = y;
	if (sizeX > 0 && sizeY > 0)
	{
		field = new cellValue_t*[sizeX];
		for (int x = 0; x < sizeX; x++)
		{
			field[x] = new cellValue_t[sizeY];
			for (int y = 0; y < sizeY; y++)
			{
				field[x][y] = cv_none;
			}
		}
	}
}
cellValue_t gameField::getValueFrom(int x, int y)
{
	cellValue_t res = cv_err;
	if (field != NULL && 0 <= x && x < sizeX && 0 <= y && y < sizeY)
	{
		res = field[x][y];
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
		if (field[x][y] == cv_none)
		{
			res = field[x][y] = value;
		}
		else
		{
			res = cv_none;
		}
	}
	return res;
}

Coord gameField::getCoord()
{
	Coord retval = { sizeX, sizeY };
	return retval;
}

cellValue_t gameField::whoHasWon()
{
	// check in row
	for (int y = 0; y < sizeY; y++)
	{
		bool v = true;
		for (int x = 1; x < sizeX; x++)
		{
			if (field[x][y] != field[0][y])
			{
				v = false;
				break;
			}
		}
		if (v)
		{
			return field[0][y];
		}
	}
	// check in column
	for (int x = 1; x < sizeX; x++)
	{
		bool v = true;
		for (int y = 0; y < sizeY; y++)
		{
			if (field[x][y] != field[x][0])
			{
				v = false;
				break;
			}
		}
		if (v)
		{
			return field[x][0];
		}
	}
	// check in diagonaly
	int minSize = min(sizeX, sizeY);
	bool v = true;
	for (int i = 1; i < minSize; i++)
	{
		if (field[i][i] != field[0][0])
		{
			v = false;
			break;
		}
	}
	if (v)
	{
		return field[0][0];
	}
	v = true;
	for (int i = 1; i < minSize; i++)
	{
		if (field[i][minSize - i - 1] != field[0][minSize - 1])
		{
			v = false;
			break;
		}
	}
	if (v)
	{
		return field[0][minSize - 1];
	}
	return cv_none;
}

int gameField::numCellsWith(cellValue_t val)
{
	int num = 0;
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (field[x][y] == val)
			{
				num++;
			}
		}
	}
	return num;
}

int gameField::numEmptyCells()
{
	return numCellsWith(cv_none);
}

void gameField::printField()
{
	// vykreslit celou herni plochu a zeptat se na souradnice
	cout << "____";
	for (int x = 0; x < sizeX; x++) cout << (char)('A' + x) << "_";
	cout << endl;

	for (int y = 0; y < sizeY; y++)
	{
		cout << (char)(y + '1') << " | ";
		for (int x = 0; x < sizeX; x++)
		{
			cellValue_t cell = getValueFrom(x, y);
			cout << (char)cv_text[cell] << " ";
		}
		cout << "|" << endl;
	}
}
