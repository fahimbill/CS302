//Fahim Billah

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

/*
Function checkBalance:Checks if equation is balanced.
*/
bool checkBalance(std::string input){

  std::stack<char> dataStack;
  char stackSpot;
  int stringLen = input.length();

  for(int i = 0; i < stringLen; i++){
    if (input[i]=='('||input[i]=='['||input[i]=='{'){ //Checks if theres an opening paren then pushes it
      dataStack.push(input[i]);
      continue;
    }

    else if (dataStack.empty()){ //safety check
		    return false;
    }

    //else if(input[i] == ' '){ //Skip whitespace
      //continue;

    switch (input[i]){

      case '}': //check if last element is }
            stackSpot = dataStack.top(); //start at top of the stack
            dataStack.pop(); //pop till
            //if (stackSpot =='{') //} is found
               //return true;
            if (stackSpot == '(' || stackSpot == '[')
                return false;
            break;

      case ']': //check if last element is ]
            stackSpot = dataStack.top(); //start at top of the stack
            dataStack.pop(); //pop till
            //if (stackSpot ==']') //] is found(ffd)
                //return true;
            if (stackSpot == '(' || stackSpot == '{')
                return false;
            break;

        case ')': //check if last element is )
            stackSpot = dataStack.top(); //start at top of the stack
            dataStack.pop(); //pop till
            //if (stackSpot =='(') //) is found
                //return true;
            if (stackSpot == '{' || stackSpot == '[')
                return false;
            break;
        }
      }

      return(dataStack.empty());
        //return false;

}

int main() {
  std::string input;
  std::string terminate = "END";

  std::cout << "This program checks for a balanced expression" << std::endl << "Enter 'END' to close the program" << std::endl;

  while(input != terminate){
    std::cout << "Enter Expression: ";
    std::cin >> input;

    if(checkBalance(input))
      std::cout << input << " " << "is balanced" << std::endl << std::endl;
    else
      std::cout << input << " " << "is not balanced" << std::endl << std::endl;

    std::transform(terminate.begin(), terminate.end(), terminate.begin(),::toupper); //Extra stuff makes it not case sensitive

  }

  return 0;
}
