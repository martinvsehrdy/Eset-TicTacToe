#pragma once
#include <list>
#include <map>

using namespace std;

enum cellValue_t
{
	cv_none = 0,	// empty cell
	cv_X = 1,		// cell with X
	cv_O = 2,		// cell with O
	cv_err = 3		// undefined cell
};
const char cv_text[] = {' ', 'X', 'O', 'e'};
struct Coord
{
	int x;
	int y;
};

class gameField
{
public:
	/* Sets game field empty, ie. no cells
	 * 
	 */
	gameField(void);
	gameField(int x, int y);

	~gameField(void);

	/* Allocates/reallocates field of given size
	 * sets all cells to cv_none
	 */
	void init(int sizeX, int sizeY);

	cellValue_t getValueFrom(int x, int y);

	/* sets cell on coordinate x,y as value and return its value
	 * in case of x,y is out of field returns cv_err
	 */
	cellValue_t setCellAs(int x, int y, cellValue_t value);

	Coord getCoord();
	/* returns sign of winner
	 *   cv_none - game is still going on
	 *   cv_X - player with X won
	 *   cv_Y - player with Y won
	 */
	cellValue_t whoHasWon();

	/* returns number of empty cells */
	int numEmptyCells();

	void printField();

private:
	int sizeX;	// vertical number of cells
	int sizeY;	// horizontal number of cells
	cellValue_t **field;	// cell[x][y]

	int numCellsWith(cellValue_t val);
};

