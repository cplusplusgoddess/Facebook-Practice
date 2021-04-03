// Author:	Amber Rogowicz
// Date:	April 3, 2021
// Facebook practice exercise for string and character manipulation
// Input:	character string of non delimiter separated digit(s) entered by user
// Output:  generated string of what is seen in the given input, perpetually run for 100 times
// Look and say takes a string and returns a string with what is "seen" in the
// input string given by the user (initially)
// e.g.
// 1
// 11
// 21
// 1211
// 111221
// 312211
// 13112221
// 1113213211 ... and so on. 
// The main driver has a hard coded number for perpetual generation of subsequent strings
// the shortest input string yielding the shortest output string will be "22"
// Assumptions:
// 1.  anything other than a digit in a non-spaced string entry will be considered an error. 
// 2. Any space after digits in the string are considered EOL or end of input string
#include <locale>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string * look_and_say( const char* inStr )
{
	string in(inStr);
	string *ret = new string(""); // create heap space to return to caller
    ret->reserve(in.size() * 2);
	if(in.empty() )
		return ret;
	char first_seen = in[0];
	char curr_char;
	int  count = 1;
	for ( int i = 1; i <= in.size(); i++)
	{
	  if(!isdigit(first_seen) )
	  { 
		*ret= "invalid entry at character " ;
    	ret->push_back(first_seen);
		return ret;
	  }
	  if( (curr_char = in[i]) == first_seen )
	  {
          count++;
		  continue;
	  
	  } else {
		ret->append(to_string(count));
    	ret->push_back(first_seen);
		//ret += to_string(count) + first_seen;
		count =1;
		first_seen = curr_char;
	  }
    }
	// ret->append(to_string(count));
    // ret->push_back(first_seen);
	return ret;
}


int main(int argc, char** argv)
{

string inStr;
cout << "enter an input string of digits\n" << endl;
cin >> inStr ;
string *retStr ;
for( int i = 0; i < 100; i++)
{
  retStr = look_and_say( inStr.c_str() );
  cout << *retStr << endl;
  inStr = *retStr;
  delete(retStr);

}



}
