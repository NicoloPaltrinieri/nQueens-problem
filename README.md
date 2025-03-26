# nQueens-problem

This is my personal try to solve the nQueens problem in C.

The main function require in input an integer that stands for the lenght of the chessboard.

By going throught a recursive funtion the algorithm try every possibility: if a space is free it puts there a queen (1) and goes to eliminate every possible positions that could be killed by the queen just positioned (using 2). If the algoritm cannot place n queens it returns otherwise it print the solution.
