//==============================================================================================
// Name         : Project_One_and_Two.cpp
// Author       : Alex Sandoval\n
// Version      : 
// Copyright    : 
// Description  : Project Two - Revision of Project One code.
//==============================================================================================

#include <iostream>
#include <limits>
using namespace std;

int CheckUserPermissionAccess() 
   {	
	// Initialize username
	std::string username = "";  

	// Initialize password
	std::string password = "123";                 
	
	// Displays message to enter username.
	std::cout << "Enter your username: \n";

	// Username input	
    std::cin >> username;                         
    
	// Displays message to enter password.
	std::cout << "Enter your password: \n"; 

	// Password input
	std::cin >> password;                         
  
    // Password
	if (password == "123")                        
  {           
        // Returns correct password input
		return 1;                                 
	}
	
}

// Pass by reference for num# values
void DisplayInfo(int& num1, int& num2, int& num3, int& num4, int& num5)                              
{     
    // Display info with name of clients.                       
	std::cout << "Client's Name    " << "  Service Selected (1 = Brokerage, 2 = Retirement)" << endl;  
	std::cout << "1. " << "Bob Jones" << "    selected option " << num1 << "\n";                       
	std::cout << "2. " << "Sarah Davis" << "  selected option " << num2 << "\n";                       
	std::cout << "3. " << "Amy Friendly" << " selected option " << num3 << "\n";                       
	std::cout << "4. " << "Johnny Smith" << " selected option " << num4 << "\n";                       
	std::cout << "5. " << "Carol Spears" << " selected option " << num5 << "\n" << "\n";               

	return;
}

// Pass by reference for num# values
void ChangeCustomerChoice(int& num1, int& num2, int& num3, int& num4, int& num5)                       
  {                  
  // Initialize changechoice
  int changechoice = 0;                        
	
  // Initialize newservice
  int newservice = 0;                          

  // Displays message for the user to choose client and pick on option from the menu list.
	std::cout << "Enter the number of the client that you wish to change\n";                          
	
  // Input for changechoice
  std::cin >> changechoice;                    
	
    // Displays message for the user to enter the client chosen new service.
	std::cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";    
	
	// Input for newservice
	std::cin >> newservice;                      
	
	while(1) 
      {
	    if (cin.fail())                                             // cin.fail detects whether the value entered is a number defined in the variable 'changechoice'.
	    {
	        cin.clear();                                            // cin.clear clears the error flag on cin so that future I/O operations will work correctly.
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // cin.ignore skips to the next newline and will ignore anything that is a non-number.
	        cin >> changechoice;                                    // Input from user for changechoice.                       
	    }
	    if (!cin.fail())
	    break;
	}
	
	while(1) {
	    if (cin.fail())                                              // cin.fail detects whether the value entered is a number defined in the variable 'newservice'.
	    {
	        cin.clear();                                             // cin.clear clears the error flag on cin so that future I/O operations will work correctly.
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');     // cin.ignore skips to the next newline and will ignore anything that is a non-number.
	        cin >> newservice;                                       // Input from user for newservice.
	    }
	    if (!cin.fail())
	    break;
	}
	
	
  // The following num# options are the current choices for the customer.
	if (changechoice == 1) {                                           
		num1 = newservice;
	}
	else if (changechoice == 2) {
		num2 = newservice;
	}
	else if (changechoice == 3) {
		num3 = newservice;
	}
	else if (changechoice == 4) {
		num4 = newservice;
	}
	else if (changechoice == 5) {
		num5 = newservice;
	}
	return;
}


int main() 
{

    // Initialize variables 
	int answer = 0;                             
	int choice = 0;
	int num1 = 1;
	int num2 = 2;
	int num3 = 1; 
	int num4 = 1; 
	int num5 = 2;
	int attempts = 0;
    const int maxAttempts = 3;
	
  // Displays welcome message.
  std::cout << "Assembled by: Alex Sandoval\n" << "Hello! Welcome to our Investment Company\n";   

	while (answer != 1) {
	    
	  /* This part of the code checks to see if the password is correct and if not, 
       then a message of unsuccessful login is diplayed with the amount of attempts
       left. If the user has too many unsuccessful attempts then the message of 
       you have been locked out, please try again later is displayed.
      */
		answer = CheckUserPermissionAccess();    
		if (answer == 1){
		std::cout << "\nSuccessful Login!\n \n";
			break;
		}
		else if (attempts <= 2)  {
			std::cout << "Unsuccessful Login: " << maxAttempts - attempts - 1 << " more attempt(s).\n";
		}
		else {
		    std::cout << "\nYou have been locked out of this account for too many incorrect login attempts.\n";
		    std::cout << "Please try again at a later time.\n \n";
		    
		}
		attempts++;
		
	}

    // Displays options and choice chosen.
	while (choice != 3) {                                                           
		std::cout << "What would you like to do?\n";
		std::cout << "DISPLAY the client list (enter 1)\n";
		std::cout << "CHANGE a client's choice (enter 2)\n";
		std::cout << "Exit the program.. (enter 3)\n";
		std::cin >> choice;
		std::cout << "You chose " << choice << "\n";
        
		// Displays choice 1.
		if (choice == 1) {                                                            
			DisplayInfo(num1, num2, num3, num4, num5);
		}
		
		// Displays choice 2.
		else if (choice == 2) {                                                      
			ChangeCustomerChoice(num1, num2, num3, num4, num5);
		}
		
		// Displays choice 3.
		else if (choice == 3) {                                                      
			return 1;
		}
		
		// If user does not chose the correct choice options, then is prompted to try again.
		else if (choice != 1 || choice != 2 || choice !=3) {
		    std::cout << "**** Please select a number from the list. ****\n \n";     
		}
	}
}

