#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer(OthelloPtr othello);

	bool onTurn();
};

