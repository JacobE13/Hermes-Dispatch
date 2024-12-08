#include <iostream>
#include <vector>
#include <limits> 
#include "firefighter.h"
#include "police.h"
#include "medical.h"

// enum to represent different types of emergencies
enum EmergencyType {
    FIRE = 1,
    MEDICAL = 2,
    POLICE = 3,
    INVALID = -1
};

// class represents a district
class District {
public:
    int districtID;

    // constructor defines a district with its ID
    District(int id) : districtID(id) {}

    void display() const {
        std::cout << "District " << districtID << std::endl;
    }
};

class Map {
public:
    std::vector<District> districts;
    std::vector<FireDepartment> fireDepartments;
    std::vector<PoliceDepartment> policeDepartments;
    Hospital hospital;

    // Function to create districts
    void createDistricts() {
        for (int i = 1; i <= 10; ++i) {
            districts.push_back(District(i));
        }
    }

    // Function to add departments and hospital
    void addDepartments() {
        // Add Fire Departments (evenly distributed, not next to each other)
        fireDepartments.push_back(FireDepartment(1)); // Fire Department in District 1
        fireDepartments.push_back(FireDepartment(5)); // Fire Department in District 5

        // Add Police Departments (evenly distributed, not next to each other)
        policeDepartments.push_back(PoliceDepartment(2, 30)); // Police in District 2
        policeDepartments.push_back(PoliceDepartment(6, 30)); // Police in District 6

        // Add Hospital
        hospital = Hospital(); // Hospital with 20 EMTs
    }

    // Function to display the departments and hospital
    void displayDepartments() const {
        std::cout << "\nFire Departments:\n";
        for (const auto& fd : fireDepartments) {
            fd.display();
        }

        std::cout << "\nPolice Departments:\n";
        for (const auto& pd : policeDepartments) {
            pd.display();
        }

        std::cout << "\nHospital:\n";
        hospital.display();
    }
};


// Function to ask for the type of emergency
EmergencyType askForEmergencyType() {
    int emergencyChoice;
    std::cout << "What type of emergency is happening?\n";
    std::cout << "1. Fire\n2. Medical Emergency\n3. Police Emergency\n";
    std::cout << "Enter the number corresponding to the emergency: ";

    while (true) {
        std::cin >> emergencyChoice;

        // Input validation for emergency type
        if (std::cin.fail() || emergencyChoice < 1 || emergencyChoice > 3) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice! Please enter a number between 1 and 3: ";
        } else {
            break;
        }
    }

    return static_cast<EmergencyType>(emergencyChoice);
}

// Function to ask for the severity of the emergency (1 to 5)
int askForSeverity() {
    int severity;
    std::cout << "On a scale of 1 to 5, how severe is the emergency? (1 = Least severe, 5 = Most severe): ";
    
    while (true) {
        std::cin >> severity;

        // Input validation for severity level
        if (std::cin.fail() || severity < 1 || severity > 5) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid severity level! Please enter a number between 1 and 5: ";
        } else {
            break;
        }
    }

    return severity;
}

// Function to ask for the district number (1 to 10)
int askForDistrict() {
    int districtNumber;
    std::cout << "Enter the district number (1 to 10) where the emergency occurred: ";
    
    while (true) {
        std::cin >> districtNumber;

        // Input validation for district number
        if (std::cin.fail() || districtNumber < 1 || districtNumber > 10) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid district number! Please enter a number between 1 and 10: ";
        } else {
            break;
        }
    }

    return districtNumber;
}

// Function to assign personnel based on the emergency type, severity, and district
void assignPersonnel(Map& map, EmergencyType emergency, int severity, int districtNumber) {
    if (emergency == FIRE) {
        // Fire department dispatch
        FireDepartment* nearestFireDepartment = nullptr;
        int minDistance = std::numeric_limits<int>::max();

        // Find the nearest fire department
        for (auto& fireDept : map.fireDepartments) {
            int distance = fireDept.distanceFrom(districtNumber);
            if (distance < minDistance) {
                minDistance = distance;
                nearestFireDepartment = &fireDept;
            }
        }

        if (nearestFireDepartment) {
            nearestFireDepartment->dispatchFirefighters(severity);
            nearestFireDepartment->dispatchFireVehicles(severity);
        }
    } else if (emergency == POLICE) {
        // Police department dispatch
        PoliceDepartment* nearestPoliceDepartment = nullptr;
        int minDistance = std::numeric_limits<int>::max();

        // Find the nearest police department
        for (auto& policeDept : map.policeDepartments) {
            int distance = policeDept.distanceFrom(districtNumber);
            if (distance < minDistance) {
                minDistance = distance;
                nearestPoliceDepartment = &policeDept;
            }
        }

        if (nearestPoliceDepartment) {
            int officersDispatched = nearestPoliceDepartment->assignOfficers(severity);
            std::cout << "Police Department in District " << nearestPoliceDepartment->districtID
                      << " dispatched " << officersDispatched << " officers to District " << districtNumber << "." << std::endl;
            nearestPoliceDepartment->dispatchSquadCars(severity);  // Dispatch squad cars based on severity
        }
    } else if (emergency == MEDICAL) {
        // Hospital dispatch
        int emtsDispatched = map.hospital.assignEMTs();
        std::cout << "Hospital dispatched " << emtsDispatched << " EMT to District " << districtNumber << "." << std::endl;
    }
}

int main() {
    Map map;

    // Create the map and add departments
    map.createDistricts();
    map.addDepartments();

    // Display all departments and hospital
    map.displayDepartments();

    // Ask for the type of emergency, severity, and district number
    EmergencyType emergency = askForEmergencyType();
    int severity = askForSeverity();
    int districtNumber = askForDistrict();

    // Assign personnel based on the emergency type, severity, and district
    assignPersonnel(map, emergency, severity, districtNumber);

    return 0;
}
