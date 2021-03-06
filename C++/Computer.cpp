#include "Computer.h"

Computer::Computer(OthelloPtr othello) : Player(othello)
{
}

// simple greedy player
bool Computer::onTurn()
{
	const Board& board = othello->getBoard();

	int max = 0, tx, ty;
	for (int y = 0; y < board.height; ++y)
		for (int x = 0; x < board.width; ++x) {
			int c = board.getCount(x, y);
			if (c > max || ((c == max) && rand() % 2)) {
				max = c;
				tx = x; ty = y;
			}
		}

	othello->putStone(tx, ty);

	return Player::onTurn();
}
