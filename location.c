#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LEN 50
#define MAX_INDUSTRY_LEN 30
#define MAX_PHONE_LEN 15
#define MAX_LOCATION_LEN 50

// Arrays for company information
char names[MAX_COMPANIES][MAX_NAME_LEN];
char industries[MAX_COMPANIES][MAX_INDUSTRY_LEN];
char phoneNumbers[MAX_COMPANIES][MAX_PHONE_LEN];
char locations[MAX_COMPANIES][MAX_LOCATION_LEN];

int numCompanies = 10;

// Function to convert a string to lowercase
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to search companies by industry
void searchByIndustry(char* industry) {
    int found = 0;
    char industryLower[MAX_INDUSTRY_LEN];
    strcpy(industryLower, industry);
    toLowerCase(industryLower);

    printf("\nCompanies in '%s' industry:\n", industry);
    
    for (int i = 0; i < numCompanies; i++) {
        char companyIndustryLower[MAX_INDUSTRY_LEN];
        strcpy(companyIndustryLower, industries[i]);
        toLowerCase(companyIndustryLower);

        if (strstr(companyIndustryLower, industryLower)) {
            printf("Name: %s\n", names[i]);
            printf("Phone: %s\n", phoneNumbers[i]);
            printf("Location: %s\n\n", locations[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No companies found in this industry.\n");
    }
}

// Function to add a new company
void addNewCompany() {
    if (numCompanies >= MAX_COMPANIES) {
        printf("Directory is full. Cannot add more companies.\n");
        return;
    }

    printf("Enter company name: ");
    scanf(" %[^\n]", names[numCompanies]);

    printf("Enter industry: ");
    scanf(" %[^\n]", industries[numCompanies]);

    printf("Enter phone number: ");
    scanf(" %[^\n]", phoneNumbers[numCompanies]);

    printf("Enter location: ");
    scanf(" %[^\n]", locations[numCompanies]);

    numCompanies++;
    printf("New company added successfully!\n");
}

// Display the main menu
void displayMenu() {
    printf("\n=== Company Directory ===\n");
    printf("1. Search by Industry\n");
    printf("2. Add New Company\n");
    printf("3. View All Companies\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to display available industries from the directory
void displayIndustries() {
    printf("\nAvailable industries in the directory:\n");
    printf("1) Software\n");
    printf("2) Healthcare\n");
    printf("3) Education\n");
    printf("4) Finance\n");
    printf("5) Construction\n");
}

// Main function
int main() {
    // Sample data for the directory
    strcpy(names[0], "Infosys");
    strcpy(industries[0], "Software");
    strcpy(phoneNumbers[0], "+91 8028520261");
    strcpy(locations[0], "Bengaluru");

    strcpy(names[1], "Tata Consultancy Services");
    strcpy(industries[1], "Software");
    strcpy(phoneNumbers[1], "+91 9833775853");
    strcpy(locations[1], "Mumbai");

    strcpy(names[2], "Apollo Hospitals");
    strcpy(industries[2], "Healthcare");
    strcpy(phoneNumbers[2], "+91 8042425000");
    strcpy(locations[2], "Chennai");

    strcpy(names[3], "Max Healthcare");
    strcpy(industries[3], "Healthcare");
    strcpy(phoneNumbers[3], "+91 9268880303");
    strcpy(locations[3], "New Delhi");

    strcpy(names[4], "Byju's");
    strcpy(industries[4], "Education");
    strcpy(phoneNumbers[4], "+91 9880031619");
    strcpy(locations[4], "Bengaluru");

    strcpy(names[5], "Unacademy");
    strcpy(industries[5], "Education");
    strcpy(phoneNumbers[5], "+91 8585858585");
    strcpy(locations[5], "Bengaluru");

    strcpy(names[6], "Bajaj Finance Limited");
    strcpy(industries[6], "Finance");
    strcpy(phoneNumbers[6], "18003094001");
    strcpy(locations[6], "Pune");

    strcpy(names[7], "Aditya Birla Finance Limited");
    strcpy(industries[7], "Finance");
    strcpy(phoneNumbers[7], "+91 9513402341");
    strcpy(locations[7], "Mumbai");

    strcpy(names[8], "Reliance Infrastructure");
    strcpy(industries[8], "Construction");
    strcpy(phoneNumbers[8], "+91 7947123363");
    strcpy(locations[8], "Navi Mumbai");

    strcpy(names[9], "Hindustan Construction");
    strcpy(industries[9], "Construction");
    strcpy(phoneNumbers[9], "+91 2225751000");
    strcpy(locations[9], "Mumbai");

    // Main loop for the menu
    while (1) {
        displayMenu();

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Show available industries
            displayIndustries();

            // Ask the user to select an industry
            int selectedIndustry;
            printf("Enter the number corresponding to the industry: ");
            scanf("%d", &selectedIndustry);

            // Validate input
            if (selectedIndustry < 1 || selectedIndustry > 5) {
                printf("Invalid choice. Please try again.\n");
                continue;
            }

            // Map the selected industry number to the industry name
            char selectedIndustryName[MAX_INDUSTRY_LEN];
            switch (selectedIndustry) {
                case 1:
                    strcpy(selectedIndustryName, "Software");
                    break;
                case 2:
                    strcpy(selectedIndustryName, "Healthcare");
                    break;
                case 3:
                    strcpy(selectedIndustryName, "Education");
                    break;
                case 4:
                    strcpy(selectedIndustryName, "Finance");
                    break;
                case 5:
                    strcpy(selectedIndustryName, "Construction");
                    break;
                default:
                    break;
            }

            // Perform the search with the selected industry
            searchByIndustry(selectedIndustryName);
        } 
        else if (choice == 2) {
            addNewCompany();
        }
        else if (choice == 3) {
            printf("\nAll Companies:\n");
            for (int i = 0; i < numCompanies; i++) {
                printf("Name: %s | Industry: %s | Phone: %s | Location: %s\n", names[i], industries[i], phoneNumbers[i], locations[i]);
            }
        } 
        else if (choice == 4) {
            printf("Exiting the directory...\n");
            break;
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
