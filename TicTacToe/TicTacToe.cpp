// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gameField.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "KeyboardPlayer.h"
#include <iostream>

using namespace std;

int main()
{
	gameField gf = gameField(3, 3);
	const int playerNum = 2;
	Player *p[playerNum];
	cout << "There are many option of strategy for player, choose what you like" << endl;
	cout << " 1 - Human player - keyboard input" << endl;
	cout << " 2 - Computer player - random steps" << endl;
	for (int i = 0; i < playerNum; i++)
	{
		int u;
		cout << "Choose player " << (i+1) << ": ";
		cin >> u;
		switch (u)
		{
		case 1:
			p[i] = new KeyboardPlayer();
			break;
		case 2:
			p[i] = new RandomPlayer();
			break;
		default:
			break;
		}
	}
	p[0]->init(&gf, cv_X);
	p[1]->init(&gf, cv_O);

	Coord c;
	int playerIdx = 0;
	cellValue_t winner = cv_none;
	while (winner == cv_none && gf.numEmptyCells()>0)
	{
		c = p[playerIdx]->doNextStep();
		cout << "P" << playerIdx + 1 << ": X=" << c.x << " Y=" << c.y << endl;
		gf.setCellAs(c.x, c.y, p[playerIdx]->getCValue());
		playerIdx++;
		playerIdx %= playerNum;
		winner = gf.whoHasWon();
	}
	cout << "=============" << endl;
	gf.printField();
	if (winner == cv_X || winner == cv_O)
	{
		cout << "CONGRATS to player with " << cv_text[winner] << endl;
	} else
	{
		cout << "game is over by PAT" << endl;
	}

	cin.get();
	cin.get();
	delete p[0];
	delete p[1];
    return 0;
}

