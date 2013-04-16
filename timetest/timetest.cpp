//Authors Nathan Lin, Vijay Kumar
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "CPUTimer.h"
#include "CursorList.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include "QueueAr.h"
//#include "QueueLL.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
//#include "vector.h"

void RunList(string filename);
void RunCursorList(string filename);
void RunStackAr(string filename);
void RunStackLi(string filename);
void RunQueueAr(string filename);
void RunSkipList(string filename);

using namespace std;

int getChoice();

int main(void)
{
  string filename;
  int choice;
  CPUTimer ct;

  cout << "Filename >> ";
  cin >> filename;
  cout << endl;


  cout << "      ADT Menu\n";
  cout << "0. Quit\n";
  cout << "1. LinkedList\n";
  cout << "2. CursorList\n";
  cout << "3. StackAr\n";
  cout << "4. StackLi\n";
  cout << "5. QueueAr\n";
  cout << "6. SkipList\n";
  cout << "Your choice >> ";

  do
  {
    choice = getChoice();
    ct.reset();
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    } //switch

    cout << "CPU time: " << ct.cur_CPUTime() << endl;

  } while(choice > 0); //do_while

  return 0;
} //main

int getChoice()
{
  int choice;
  cin >> choice;
  return choice;
} //getChoice


void RunList(string filename)
{
  ifstream input;
  input.open(filename.c_str());
  string temp, number, number2; //temp string to discard first line
  int number3;
  getline(input,temp);
  List<int> listObject;
  ListItr<int> it = listObject.first();

  while(getline(input, number, ' '))
  {
    if(number[0] == 'i')
    {
      number2 = number.substr(1,number.length());
      istringstream(number2) >> number3;
      listObject.insert(number3, it);
      //it.current = it.current->next;
      //insert ADT
    }
    else
    {
      number2 = number.substr(1,number.length());
      listObject.remove(number3);

    }
      //delete from ADT
  }
  input.close();
}//end RunList


void RunCursorList(string filename)
{
  ifstream my_file;
  my_file.open(filename);
  input.close();
}//end RunCursorList
void RunStackAr(string filename)
{
  ifstream my_file;
  my_file.open(filename);
  input.close();
}//end RunStackAr

void RunStackLi(string filename)
{
  ifstream my_file;
  my_file.open(filename);
  input.close();
}//end RunStackLi

void RunQueueAr(string filename)
{
  ifstream my_file;
  my_file.open(filename);
  input.close();
}//end RunQueueAr

void RunSkipList(string filename)
{
  ifstream my_file;
  my_file.open(filename);
  input.close();
}//end RunSkipList

