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
 private:
  vector<int> testNum;
  vector<int> gridCount[9][9];
}; // Puzzle class

#endif

