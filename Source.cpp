#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
    //Map to store item frequency
    map<string, int> itemFrequency;
    //Load input file name
    const string inputFile = "CS210_Project_Three_Input_File.txt";
    //Create the output file
    const string outputFile = "frequency.dat";

public:
    //Constructor to read input file
    ItemTracker() {
        ReadInputFile();
    }
    // Function to populate itemFrequency map
    void ReadInputFile() {
        //open input file
        ifstream file(inputFile);
        string item;

        //update item frequencies after reading input file
        while (file >> item) {
            itemFrequency[item]++;
        }

        // Close the file
        file.close();
    }

    //Function to save item frequency
    void SaveFrequencyToFile() {
        ofstream file(outputFile);

        //Print frequencies to file
        for (const auto& entry : itemFrequency) {
            file << entry.first << " " << entry.second << endl;
        }
        // close file
        file.close();
    }

    //Function to print frequencies of all items 
    void PrintFrequency() {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    // Print histogram function
    void PrintHistogram() {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " ";
            // Print * for item frequency
            for (int i = 0; i < entry.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // User input Menu
    void Run() {
        int choice;
        while (true) {
            cout << "Menu:\n";
            cout << "1. Print Frequency of a specific item\n";
            cout << "2. Print frequency of all purchased items\n";
            cout << "3. Print histogram of all purchased items\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string item;
                cout << "Enter the item: (Case Sensitive) ";
                cin >> item;
                cout << "Frequency of " << item << ": " << itemFrequency[item] << endl;
                break;
            }
            case 2: {
                PrintFrequency();
                break;
            }
            case 3: {
                PrintHistogram();
                break;
            }
            case 4: {
                SaveFrequencyToFile();
                cout << "Data saved to " << outputFile << ". Exiting...\n";
                return;
            }
            default: {
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
            }
        }
    }
};

int main() {
    ItemTracker tracker;
    //run User input menu
    tracker.Run(); 
    return 0;
}
