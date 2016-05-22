#pragma once
#include <list>
#include <functional>

using namespace std;

enum cellValue_t
{
	cv_none,	// empty cell
	cv_X,		// cell with X
	cv_O,		// cell with O
	cv_err		// undefined cell
};

ref class gameField
{
public:
	/* Sets game field empty, ie. no cells
	 * 
	 */
	gameField(void);

	~gameField(void);

	/* Allocates/reallocates field of given size
	 * sets all cells to cv_none
	 */
	void init(int sizeX, int sizeY);

	cellValue_t getValueFrom(int, x, int y);

	/* sets cell on coordinate x,y as value and return its value
	 * in case of x,y is out of field returns cv_err
	 */
	cellValue_t setCellAs(int x, int y, cellValue_t value);

	/* choses empty cell and marks it by its cellValue
	 */
	void doNextStep(int &x, int &y);

	/* returns sign of winner
	 *   cv_none - game is still going on
	 *   cv_X - player with X won
	 *   cv_Y - player with Y won
	 */
	cellValue_t whoHasWon();

private:
	int sizeX;	// vertical number of cells
	int sizeY;	// horizontal number of cells
	cellValue_t *field;	// cell[x,y] coresponds with field[x+y*sizeX]
	hash<int> emptyCells;

	/* convert coordinate X,Y to index of field, index = x+y*sizeX
	 */
	int convertXYToIndex(int x, int y);
};

