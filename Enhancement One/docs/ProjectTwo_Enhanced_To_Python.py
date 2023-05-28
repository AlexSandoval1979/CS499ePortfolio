import sys


def check_user_permission_access():
    # Prompt the user for their username
    username = ""
    password = "123"
    print("Enter your username: ")
    username = input()

    # Prompt the user for their password
    print("Enter your password: ")
    password = input()

    # Check if the password is correct
    if password == "123":
        return 1


def display_info(num1, num2, num3, num4, num5):
    # Print the header for the client information
    print("Client's Name    " + "  Service Selected (1 = Brokerage, 2 = Retirement)")

    # Print the information for each client
    print("1. {}       selected option {}".format("Bob Jones", num1))
    print("2. {}     selected option {}".format("Sarah Davis", num2))
    print("3. {}    selected option {}".format("Amy Friendly", num3))
    print("4. {}    selected option {}".format("Johnny Smith", num4))
    print("5. {}    selected option {}\n".format("Carol Spears", num5))


def change_customer_choice(num1, num2, num3, num4, num5):
    changechoice = 0
    newservice = 0

    # Prompt the user to enter the client number to change
    print("Enter the number of the client that you wish to change")
    while True:
        try:
            changechoice = int(input())
            break
        except ValueError:
            # Prompt the user to enter a valid number for changechoice
            changechoice = input("Please enter a valid number for changechoice: ")

    # Prompt the user to enter the new service choice for the client
    print("Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)")
    while True:
        try:
            newservice = int(input())
            break
        except ValueError:
            # Prompt the user to enter a valid number for newservice
            newservice = input("Please enter a valid number for newservice: ")

    # Update the service choice based on the selected client
    if changechoice == 1:
        num1 = newservice
    elif changechoice == 2:
        num2 = newservice
    elif changechoice == 3:
        num3 = newservice
    elif changechoice == 4:
        num4 = newservice
    elif changechoice == 5:
        num5 = newservice

    # Return the updated service choices
    return num1, num2, num3, num4, num5


def main():
    # Initialize variables
    answer = 0
    choice = 0
    num1 = 1
    num2 = 2
    num3 = 1
    num4 = 1
    num5 = 2
    attempts = 0
    max_attempts = 3

    # Display welcome message
    print("Assembled by: Alex Sandoval\nHello! Welcome to our Investment Company")

    # Handle user authentication
    while answer != 1:
        answer = check_user_permission_access()
        if answer != 1:
            attempts += 1
            if attempts == max_attempts:
                print("You have been locked out. Please try again later.")
                sys.exit()
            else:
                print("Unsuccessful login. Attempts left: {}".format(max_attempts - attempts))

    # Main menu loop
    while choice != 4:
        # Display menu options
        print("Please select from the following menu options:\n1. Display Client Info\n2. Change Customer Choice\n3. Exit Program")
        choice = int(input())

        if choice == 1:
            # Display client information
            display_info(num1, num2, num3, num4, num5)
        elif choice == 2:
            # Change customer choice
            num1, num2, num3, num4, num5 = change_customer_choice(num1, num2, num3, num4, num5)
        elif choice == 3:
            # Exit the program
            sys.exit()

if __name__ == "__main__":
    main()
