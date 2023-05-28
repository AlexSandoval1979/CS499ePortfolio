#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Define a struct to hold bid information
struct Bid {
    string name;
    string vehicleType;
    string vehicleColor;
    string vehicle;
    double amount;
    double highestBid = 0;
};

// Display the bid information
void displayBid(const Bid& bid) {
    cout << "Bid Information" << endl;
    cout << "----------------" << endl;
    cout << "Name: " << bid.name << endl;
    cout << "Type of Vehicle: " << bid.vehicleType << endl;
    cout << "Vehicle Color: " << bid.vehicleColor << endl;
    cout << "Make and Model: " << bid.vehicle << endl;
    cout << "Bid Amount: $" << bid.amount << endl;
}

// Display the highest bid information
void displayHighestBid(const Bid& bid) {
    cout << "Highest Bid Information" << endl;
    cout << "-----------------------" << endl;
    cout << "Highest Bid Amount: $" << bid.highestBid << endl;
    cout << "Name: " << bid.name << endl;
    cout << "Type of Vehicle: " << bid.vehicleType << endl;
    cout << "Vehicle Color: " << bid.vehicleColor << endl;
    cout << "Make and Model: " << bid.vehicle << endl;
}

// Prompt user for bid information and store in a Bid struct
Bid getBid(const Bid& currentBid) {
    Bid bid;

    cout << "Enter your name: ";
    getline(cin, bid.name);

    // Prompt user for vehicle type and ensure it is a valid option
    bool validVehicleType = false;
    while (!validVehicleType) {
        cout << "Enter type of vehicle (Car/Truck/Other): ";
        getline(cin, bid.vehicleType);

        // Convert input to lowercase for case-insensitivity
        transform(bid.vehicleType.begin(), bid.vehicleType.end(), bid.vehicleType.begin(), ::tolower);

        if (bid.vehicleType == "car" || bid.vehicleType == "truck" || bid.vehicleType == "other") {
            validVehicleType = true;
        } else {
            cout << "Invalid vehicle type. Please enter 'Car', 'Truck', or 'Other'." << endl;
        }
    }

    // Prompt user to enter a valid vehicle color
    cout << "Vehicle Color (Blue, Green, Red, Black, White, Silver, Gray, Gold): ";
    while (true) {
        getline(cin, bid.vehicleColor);
        if (bid.vehicleColor == "Blue" ||
            bid.vehicleColor == "Green" ||
            bid.vehicleColor == "Red" ||
            bid.vehicleColor == "Black" ||
            bid.vehicleColor == "White" ||
            bid.vehicleColor == "Silver" ||
            bid.vehicleColor == "Gray" ||
            bid.vehicleColor == "Gold") {
            break;  // valid color entered, exit loop
        }
        cout << "Invalid color. Please enter a valid color: ";
    }

    cout << "Make and model of vehicle: ";
    getline(cin, bid.vehicle);

    cout << "Bid Amount: $";
    string strAmount;
    getline(cin, strAmount);
    bid.amount = stod(strAmount);

    // Check if the new bid amount is higher than the previous highest bid
    if (bid.amount > currentBid.highestBid) {
        bid.highestBid = bid.amount;
    } else {
        bid.highestBid = currentBid.highestBid;
    }

    return bid;
}



/**
 * The one and only main() method
 */
int main() {

    // Declare instance of data structure to hold bid information
    Bid currentBid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  3. Display Highest Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();  // ignore newline character after cin

        // Complete the method calls then test the program
        switch (choice) {
            case 1:
                currentBid = getBid(currentBid);
                break;
            case 2:
                if (currentBid.amount > 0) {
                    displayBid(currentBid);
                } else {
                    cout << "No bid information to display. Please enter a bid." << endl;
                }
                break;
            case 3:
                                if (currentBid.highestBid > 0) {
                    displayHighestBid(currentBid);
                } else {
                    cout << "No highest bid information to display. Please enter a bid." << endl;
                }
                break;
            case 9:
                cout << "Exiting program...Thank you for using our bidding system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
 
