#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <list>


using namespace std;
class file
{
  public:
  file()
  {}

  string Fileread(string filename , int lineno)
  {
    string temp;
    int i = 1;
    ifstream obj(filename);
    while(getline(obj , temp))
    {
      if(i == lineno)
      {
        return temp ;
      }
      i++;
    }
  }


  string Compfileread(string filename)
  {
    ifstream file(filename);
    string file_contents {istreambuf_iterator<char>(file) , istreambuf_iterator<char>() };
    return file_contents;
  };

  string wordfileread(string filename , string word)
  {
    ifstream file;
    file.open (filename);
    string input;
    while (file >> input)
    {
      if(input == word)
      {
        cout << "Found" endl;
      } 
    }
  }

  string vector(string filename)
  {
    ifstream file;
    file.open (filename);
    string word;
    while (file >> word)
    {
      vector<string> text{word};
      string input;
      while(getline(file , input))
      {
        vector<string> text1{input};  
        list<vector<string>> rec{text,text1};
        for(list<vector<string>>::const_iterator i = rec.begin(); i != rec.end(); ++i)
        {
            for(vector<string>::const_iterator j = i->begin(); j != i->end(); ++j)
                cout << *j << " ";
            cout <<	endl;
        }
      }
    }
    //vector<vector<vector<string>>> line{rec}; 
    //for(vector<vector<vector<string>>>::const_iterator i = rec.begin(); i != rec.end(); ++i)
    //{

    /*string word;
    while (file >> word)
    {
      vector<string> text{word};
      //vector<vector<vector<string>>> line{rec}; 
      //for(vector<vector<vector<string>>>::const_iterator i = rec.begin(); i != rec.end(); ++i)
      //{
      for(vector<vector<string>>::const_iterator i = rec.begin(); i != rec.end(); ++i)
      {
          for(vector<string>::const_iterator j = i->begin(); j != i->end(); ++j)
          cout << *j << " ";
      }
    }*/

    /*ifstream file(filename);
    string file_contents {istreambuf_iterator<char>(file) , istreambuf_iterator<char>() };
    return file_contents;*/
  }


  
  private:

};