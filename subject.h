#include <iostream>
#include "file.h"
using namespace std;

class subject
{
  public:
  subject()
  {
    this->subname = "Maths";
  }

  subject(string subname)
  {
    this->subname = subname;
  }

  void setsubname(string subname)
  {
    this->subname = subname;
  }

  string getsubname()
  {
    return this->subname;
  }

  void play(string fileName)
  {
    int score = 0;
    int i , j = 0 , line = 1;
    while(f.Fileread(fileName , line) != "End" )
    {
      for(i = 1; i <= 5; i++)
      {
        cout << f.Fileread(fileName , line) << endl;
        line++;
      }
      score = answer(fileName , line , score , j);
      line++;
      j++;
    }
    system("cls");
    cout << "End of Quiz\nThanks for Playing\nYour Score is " << score << " Out of 150\n" <<endl;
    result(score);
  };

  int answer(string fileName , int line , int score , int j)
  {
    cout << "Enter Answer: ";
    cin >> ans[j];
    if(f.Fileread(fileName , line) == ans[j] )
    {
      cout<<"Correct"<< endl << endl;
      score+=20;
      return score;
    }
    else 
    {
      cout<<"InCorrect"<< endl << endl;
      return score;
    }
  };

  void result(int score)
  {
    ofstream file("result.txt");
    file << "Name: ";
    file << "\nScore: " << score << "\nAnswer\n";
    for(int i = 0; i < 15; i++)
    {
      file << i+1 << ". " << this->ans[i] << "\n"; 
    }
    file.close();
    char choice;
    cout << "Do You want To Check Your Answers Y/N\n>> ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
      int line = 1;
      while(line <= 18)
      {
        cout << f.Fileread("result.txt" , line) << endl;
        line++;
      }
    }    
  };

  private:
  string subname;
  string ans[15];
  file f;
};