// Author: Sean Davis

#include "CPUTimer.h"
#include "puzzle.h"
#include <iostream>
#include <fstream>

using namespace std;

void readGrid(const char *filename, char grid[][9])
{
  ifstream inf(filename);
  int row, col;

  for(row = 0; row < 9; row++)
  {
    for(col = 0; col < 9; col++)
      inf >> grid[row][col];

    inf.ignore(1); // eat \n
  } // for row
  inf.close();
} // readGrid()

void writeGrid(const char grid[][9])
{
  for(int row = 0; row < 9; row++)
  {
    for(int col = 0; col < 9; col++)
      cout << grid[row][col];

    cout << endl;
  } // for row

} // writeGrid()

int main(int argc, char **argv)
{
  CPUTimer ct;
  ct.reset();
  char grid[9][9];
  readGrid(argv[1], grid);
  Puzzle puzzle(grid);
  puzzle.solve(grid);
  writeGrid(grid);
  cout << "CPU time: " << ct.cur_CPUTime() << endl;
  return 0;
} // main()
