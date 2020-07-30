#!/usr/bin/python3

import sys


def solve(row, column):
    solver = [[]]
    for q in range(row):
        solver = place_queen(q, column, solver)
    return solver


def place_queen(q, column, prev_solver):
    solver_queen = []
    for array in prev_solver:
        for x in range(column):
            if is_safe(q, x, array):
                solver_queen.append(array + [x])
    return solver_queen


def is_safe(q, x, array):
    if x in array:
        return (False)
    else:
        return all(abs(array[column] - x) != q - column
                   for column in range(q))


def init():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit():
        the_queen = int(sys.argv[1])
    else:
        print("N must be a number")
        sys.exit(1)
    if the_queen < 4:
        print("N must be at least 4")
        sys.exit(1)
    return(the_queen)


def n_queens():

    the_queen = init()
    solver = solve(the_queen, the_queen)
    for array in solver:
        clean = []
        for q, x in enumerate(array):
            clean.append([q, x])
        print(clean)


if __name__ == '__main__':
    n_queens()
