#!/usr/bin/python

#
# solution to Robot Turtles
# @author Godmar
#
import sys
from collections import deque

b = [list(raw_input()) for _ in range(8)]

start = (7, 0, 0, 1, \
    frozenset((i, j) for i in range(8) for j in range(8) if b[i][j] == 'I'))

def successors((r, c, dr, dc, ice)):
    """
    r, c - initial row, column
    dr, dc - initial direction
    ice - list of remaining ice castles
    """
    states = dict()
    states['R'] = (r, c, dc, -dr, ice)
    states['L'] = (r, c, -dc, dr, ice)
    if 0 <= r+dr < 8 and 0 <= c+dc < 8:
        if b[r+dr][c+dc] in ".DI" and (r+dr, c+dc) not in ice:
            states['F'] = (r+dr, c+dc, dr, dc, ice)

        if (r+dr, c+dc) in ice:
            states['X'] = (r, c, dr, dc, ice - {(r+dr, c+dc)})
        
    return states

def solve():
    prev = dict()
    bfs = deque()
    bfs.append(start)

    while len(bfs) > 0:
        state = bfs.popleft()
        r, c, dr, dc, ice = state
        if b[r][c] == 'D':
            path = []
            while state != start:
                move, state = prev[state]
                path.append(move)
            path.reverse()
            return "".join(path)

        for move, nstate in successors(state).iteritems():
            if nstate not in prev:
                prev[nstate] = (move, state)
                bfs.append(nstate)

    return "no solution"

print solve()