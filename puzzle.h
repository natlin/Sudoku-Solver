#ifndef PUZZLE_H
  #define PUZZLE_H

#include <set>
#include <vector>

using namespace std;

class Puzzle
{
 public:
  Puzzle(const char grid[][9]);
  void getCount(int i, int j);
  void solve(char grid[][9]);
  //void recursive(char grid[][9], int row, int col);
  bool recSolve(char grid[][9], int row, int col);
  bool rowCheck(char grid[][9], int row, int col);
  bool colCheck(char grid[][9], int row, int col);
  bool boxCheck(char grid[][9], int row, int col);
 private:
  vector<int> controlGrid[9][9];
  vector<int> gridCount[9][9];
  vector<pair<int, int> > count;
  //int row;
  //int col;
}; // Puzzle class

#endif

