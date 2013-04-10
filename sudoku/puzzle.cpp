//Authors Nathan Lin, Vijay Kumar
#include "puzzle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Puzzle::Puzzle(const char grid[][9])
{
  int i, j, k;
  int x, y, z;
  vector<int> temp;
  char insert;
  temp.clear();
  for(i = 0; i < 9; i++)
  {
    for(j = 0; j < 9; j++)
    {
      if(grid[i][j] == '*')
      {
        for(k = 0; k < 9; k++)
        {
          if(grid[i][k] != '*')
          {
            insert = grid[i][k];
            //cout << insert << " " << static_cast<int>(insert) - 48 << ", " ;
            temp.push_back(static_cast<int>(insert) - 48);
          }//if
        }//for(k)
        for(k = 0; k < 9; k++)
        {
          if(grid[k][j] != '*')
          {
            insert = grid[k][j];
            //cout << insert << " " << static_cast<int>(insert) - 48 << ", " ;
            temp.push_back(static_cast<int>(insert) - 48);
          }//if
        }//for(k)
        vector<int>::iterator it;
        for(x = 0; x < static_cast<int>(temp.size()); x++)
        {
          it = temp.begin();
          for(y = x + 1; y < static_cast<int>(temp.size()); y++)
          {
            if(temp.at(x) == temp.at(y))
            {
              for(z = 0; z < y; z++)
                it++;
              temp.erase(it);
            }//if
          }//for(y)
        }//for(x)
      }//if
      else
      {
        temp.push_back(0);
        gridCount[i][j]=temp;
      }//else
      //for(vector<int>::iterator b = temp.begin(); b != temp.end(); b++)
        //cout << *b << " ";
      gridCount[i][j]=temp;
      temp.clear();
    }//for(j)
  }//for(i)
  for(vector<int>::iterator b = gridCount[0][0].begin(); b != gridCount[0][0].end(); b++)
    cout<< *b << ' ';
}//Puzzle()

void Puzzle::solve(char grid[][9])
{
  
}//solve()
