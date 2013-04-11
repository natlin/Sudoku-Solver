//Authors Nathan Lin, Vijay Kumar
#include "puzzle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Puzzle::Puzzle(const char grid[][9])
{
  int i, j, k;
  //int x, y, z;
  int m, n;
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
        if(i < 3)
        {
          if(j < 3)
          {
            for(m = 0; m < 3; m++)
            {
              for(n = 0; n < 3; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//if(j < 3)
          else if(j >= 3 && j < 6)
          {
            for(m = 0; m < 3; m++)
            {
              for(n = 3; n < 6; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 3 && j < 6)
          else if(j >= 6 && j < 9)
          {
            for(m = 0; m < 3; m++)
            {
              for(n = 6; n < 9; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 6 && j < 9)
        }//if(i < 3)
        else if(i >= 3 && i < 6)
        {
          if(j < 3)
          {
            for(m = 3; m < 6; m++)
            {
              for(n = 0; n < 3; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//if(j < 3)
          else if(j >= 3 && j < 6)
          {
            for(m = 3; m < 6; m++)
            {
              for(n = 3; n < 6; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 3 && j < 6)
          else if(j >= 6 && j < 9)
          {
            for(m = 3; m < 6; m++)
            {
              for(n = 6; n < 9; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 6 && j < 9)
        }//else if(i >= 3 && i < 6)
        else if(i >= 6 && i < 9)
        {
          if(j < 3)
          {
            for(m = 6; m < 9; m++)
            {
              for(n = 0; n < 3; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//if(j < 3)
          else if(j >= 3 && j < 6)
          {
            for(m = 6; m < 9; m++)
            {
              for(n = 3; n < 6; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 3 && j < 6)
          else if(j >= 6 && j < 9)
          {
            for(m = 6; m < 9; m++)
            {
              for(n = 6; n < 9; n++)
              {
                if(grid[m][n] != '*')
                {
                  insert = grid[m][n];
                  temp.push_back(static_cast<int>(insert) - 48);
                }//if
              }//for(n)
            }//for(m)
          }//else if(j >= 6 && j < 9)
        }//else if(i >= 6 && i < 9)
        set<int> setTemp;
        copy(temp.begin(), temp.end(), inserter(setTemp, setTemp.end()));
        temp.clear();
        copy(setTemp.begin(), setTemp.end(), back_inserter(temp));
        /*vector<int>::iterator it;
        for(x = 0; x < static_cast<int>(temp.size()); x++)
        {
          it = temp.begin();
          for(y = x + 1; y < static_cast<int>(temp.size()); y++)
          {
            if(temp.at(x) == temp.at(y))
            {
              for(z = 0; z < y; z++)
                it++;
              cout << *it << ", ";
              temp.erase(it);
            }//if
          }//for(y)
        }//for(x)*/
      }//if
      else
      {
        temp.push_back(0);
        //gridCount[i][j] = temp;
      }//else
      //for(vector<int>::iterator b = temp.begin(); b != temp.end(); b++)
        //cout << *b << " ";
      gridCount[i][j] = temp;
      getCount(i, j);
      temp.clear();
    }//for(j)
  }//for(i)
  /*for(vector<int>::iterator b = gridCount[0][1].begin();
    b != gridCount[0][1].end(); b++)
    cout<< *b << ' ';
  cout << gridCount[0][1].size()<< endl;*/
}//Puzzle()

void Puzzle::getCount(int i, int j)
{
  int m, n;
  int found;
  vector<int> temp;
  if(gridCount[i][j][0] == 0)
    return;
  for(m = 1; m < 10; m++)
  {
    found = 0;
    for(n = 0; n < static_cast<int>(gridCount[i][j].size()); n++)
      if(m == gridCount[i][j].at(n))
      {
        found = 1;
        break;
      }//if
    if(found == 0)
      temp.push_back(m);
  }//for(m)
  gridCount[i][j].clear();
  gridCount[i][j] = temp;
}//getCount()

void Puzzle::solve(char grid[][9])
{
  int i, j;
  char convert;
  for(i = 0; i < 9; i++)
  {
    for(j = 0; j < 9; j++)
    {
      if(gridCount[i][j][0] == 0)
        continue;
      if(static_cast<int>(gridCount[i][j].size()) == 1)
      {
        convert = static_cast<char>(static_cast<int>('0') + gridCount[i][j][0]);
        //cout << "char: " << test << ", ";
        grid[i][j] = convert;
      }//if
    }//for(j)
  }//for(i)
}//solve()
