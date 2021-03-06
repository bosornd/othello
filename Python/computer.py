from player import *
from board import *
from random import randint

class Computer(Player):
    def __init__(self, othello):
        super().__init__(othello)

    def onTurn(self):
        board = self.othello.board

        max = 0
        for y in range(board.height):
            for x in range(board.width):
                c = board.count[y][x]

                if c > max or (c == max and randint(0, 1) == 0):
                    max, tx, ty = c, x, y

        self.othello.putStone(tx, ty)
