# Sudoku-Game

I am learning C++. Therefore this is a project for learning practice. I probably did a lot of mistakes. 
Therefore if you detect any mistakes or if you have any ideas to improve the code, please commit.

About the code, it has couple of tasks;

- Creating our Sudoku grid;
-- Create a random array that includes integers 1-9. (e.g {2,7,5,9,8,3,1,4,6}
-- Creating a 2 dimension flag arrays (flagRow,flagColumn,flagBox) to avoid repetition of numbers. 
-- In a nested for loops for each row and column, place the numbers from the arrays according to rules with the help of flag arrays.
-- I used global 2 dimension arrays for grids. But it could be initialized as local variable and passed through functions ith a pointer.

- Masking our grid to create a grid-to-Solve
-- To hide the numbers, I have used a masking pattern which contains 0s and 1s. I multiply the elements of the grid with 0s and 1s.
-- The number of 1s and the placements of 1s is important. If the places of two 0s in a box (like place of 4 and 6 in a numpad)
are as the same in other boxes from up to down, the numbers could not be found no mattter what. But this problem could also be solved 
with adding new methods while creating our grid to make it more random(There is a problem of repetition of 3 consecutive numbers(like there is always 2-7-5)).
