#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

const int MAX_BUSINESSES = 100;  // Maximum number of businesses
const int MAX_NAME_LENGTH = 100;  // Maximum length of each business name

char* stores[MAX_BUSINESSES]; 
int storeCount = 0;

void displayBusinesses() {
    cout << "\n\nYour businesses are: \n";
    for (int i = 0; i < storeCount; ++i) {
        cout << stores[i] << endl;
    }
}

int main() {
    char yesno = 'y';
    char str[MAX_NAME_LENGTH];

    cout << "\t\tHELLO, welcome to the Business Sorting Program!\n\n";

    while (toupper(yesno) == 'Y') {
        cout << "\nPlease enter the name of a business: ";
        cin.getline(str, MAX_NAME_LENGTH);

        // Validate input
        if (strlen(str) > 0) {
            // Allocate memory for the new business name
            stores[storeCount] = new char[strlen(str) + 1];
            strcpy(stores[storeCount], str);
            storeCount++;

            // Sort the businesses
            sort(stores, stores + storeCount, [](const char* a, const char* b) {
                return strcmp(a, b) < 0;
                });

            displayBusinesses();
        }
        else {
            cout << "Business name cannot be empty. Please try again.\n";
        }

        cout << "\nDo you want to add another business? (Y/N)\n";
        cin >> yesno;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Clean up allocated memory
    for (int i = 0; i < storeCount; ++i) {
        delete[] stores[i];
    }

    cout << "\nThank you! Have a great day.";
    return 0;
}
