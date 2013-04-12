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
        gridCount[i][j][0] = 0;
      }//if
    }//for(j)
  }//for(i)
  for(i = 0; i < 9; i++)
  {
    for(j = 0; j < 9; j++)
    {
        controlGrid[i][j] = gridCount[i][j];
    }//for(j)
  }//for(i)
  //while
  recursive(grid, 0, 0);
}//solve()

void Puzzle::recursive(char grid[][9], int row, int col)
{
  //int found = 0;
  //int i, j;
  char convert;
  if(col < 0)
  {
    row--;
    col = 0;
  }//if
  if(col > 8)
  {
    row++;
    col = 0;
  }//if
  if(row < 0 || row > 8)
  {
    return;
  }//if

  if(rowCheck(grid, row, col) || colCheck(grid, row, col)
    || boxCheck(grid, row, col))
  {
    //if(gridCount[row][col][0] == -1)
    //{
      //grid[row][col] = '*';
    //}//if
    //else
    //{
      grid[row][col] = '*';
    //}//else
  }//if
  //if(gridCount[row][col][0] == 0)
  //{
    //col--;
    //recursive(grid, row, col);
  //}//if
  col++;
  if(grid[row][col] == '*')
  {
    if(gridCount[row][col][0] == -1)
    {
      gridCount[row][col] = controlGrid[row][col];
      recursive(grid, 0, 0);
    }//if
    else
    {
    convert = static_cast<char>(static_cast<int>('0')
      + gridCount[row][col].at(gridCount[row][col].size() - 1));
    grid[row][col] = convert;
    gridCount[row][col].pop_back();
    if(gridCount[row][col].empty())
      gridCount[row][col].push_back(-1);
    }//else
  }//if
  recursive(grid, row, col);
  /*for(row = 0; row < 9; row++)
  {
    for(col = 0; col < 9; col++)
    {
      if(gridCount[row][col][0] != 0)
      {
        found = 1;
        break;
      }//if
    }//for(col)
    if(found)
      break;
  }//for(row)*/
}//recursive

bool Puzzle::rowCheck(char grid[][9], int row, int col)
{
  int i = row;
  int j = col;
  int k;
  if(col < 0)
  {
    row--;
    col = 0;
  }//if
  if(col > 8)
  {
    row++;
    col = 0;
  }//if
  if(row < 0 || row > 8)
  {
    return false;
  }//if

  if(gridCount[row][col][0] == 0)
    return false;

  for(k = 0; k < 9; k++)
  {
    if(k == j)
      continue;
    if(grid[i][k] == grid[i][j])
      return true;
  }//for(k)
  return false;
}//row()

bool Puzzle::colCheck(char grid[][9], int row, int col)
{
  int i = row;
  int j = col;
  int k;
  if(col < 0)
  {
    row--;
    col = 0;
  }//if
  if(col > 8)
  {
    row++;
    col = 0;
  }//if
  if(row < 0 || row > 8)
  {
    return false;
  }//if

  if(gridCount[row][col][0] == 0)
    return false;

  for(k = 0; k < 9; k++)
  {
    if(k == i)
      continue;
    if(grid[k][j] == grid[i][j])
      return true;
  }//for(k)
  return false;
}//col()

bool Puzzle::boxCheck(char grid[][9], int row, int col)
{
  int i = row;
  int j = col;
  int m, n;
  if(col < 0)
  {
    row--;
    col = 0;
  }//if
  if(col > 8)
  {
    row++;
    col = 0;
  }//if
  if(row < 0 || row > 8)
  {
    return false;
  }//if

  if(gridCount[row][col][0] == 0)
    return false;

  if(i < 3)
  {
    if(j < 3)
    {
      for(m = 0; m < 3; m++)
      {
        for(n = 0; n < 3; n++)
        {
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
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
          if(m == i && n == j)
            continue;
          if(grid[m][n] == grid[i][j])
          {
            return true;
          }//if
        }//for(n)
      }//for(m)
    }//else if(j >= 6 && j < 9)
  }//else if(i >= 6 && i < 9)
  return false;
}//box()
