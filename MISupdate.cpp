#include <iostream>
#include <vector>
#include <string>

// Define a Patient class to store patient information
class Patient {
public:
    std::string name;
    int age;
    std::string diagnosis;

    // Constructor
    Patient(const std::string& n, int a, const std::string& d)
        : name(n), age(a), diagnosis(d) {}
};

// Function to add a new patient record
void AddPatient(std::vector<Patient>& patients) {
    std::string name, diagnosis;
    int age;

    std::cout << "Enter patient name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter patient age: ";
    std::cin >> age;

    std::cout << "Enter patient diagnosis: ";
    std::cin.ignore();
    std::getline(std::cin, diagnosis);

    patients.push_back(Patient(name, age, diagnosis));
    std::cout << "Patient added successfully." << std::endl;
}

// Function to display all patient records
void DisplayPatients(const std::vector<Patient>& patients) {
    std::cout << "Patient Records:" << std::endl;
    for (const Patient& patient : patients) {
        std::cout << "Name: " << patient.name << std::endl;
        std::cout << "Age: " << patient.age << std::endl;
        std::cout << "Diagnosis: " << patient.diagnosis << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

// Function to search for a patient by name
void SearchPatient(const std::vector<Patient>& patients) {
    std::string searchName;
    std::cout << "Enter patient name to search: ";
    std::cin.ignore();
    std::getline(std::cin, searchName);

    bool found = false;
    for (const Patient& patient : patients) {
        if (patient.name == searchName) {
            std::cout << "Patient found:" << std::endl;
            std::cout << "Name: " << patient.name << std::endl;
            std::cout << "Age: " << patient.age << std::endl;
            std::cout << "Diagnosis: " << patient.diagnosis << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Patient not found." << std::endl;
    }
}

int main() {
    std::vector<Patient> patients;

    while (true) {
        std::cout << "Medical Information System" << std::endl;
        std::cout << "1. Add Patient" << std::endl;
        std::cout << "2. Display Patients" << std::endl;
        std::cout << "3. Search Patient" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                AddPatient(patients);
                break;
            case 2:
                DisplayPatients(patients);
                break;
            case 3:
                SearchPatient(patients);
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
