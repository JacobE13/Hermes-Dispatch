#include <iostream>
#include <vector>
#include <limits> // To handle input validation
#include <cmath>  // For absolute value calculation

// Enum to represent different types of emergencies
enum EmergencyType {
    FIRE = 1,
    MEDICAL = 2,
    POLICE = 3,
    INVALID = -1
};

class District {
public:
    int districtID;

    // Constructor to define a district with its ID
    District(int id) : districtID(id) {}

    void display() const {
        std::cout << "District " << districtID << std::endl;
    }
};

class FireDepartment {
public:
    int personnelCount;
    int districtID;

    FireDepartment(int districtID, int personnelCount = 30)
        : districtID(districtID), personnelCount(personnelCount) {}

    void display() const {
        std::cout << "Fire Department in District " << districtID
                  << " with " << personnelCount << " firefighters." << std::endl;
    }

    // Function to dispatch fire personnel
    int dispatchFirefighters() const {
        return personnelCount;  // Fire department always sends 30 firefighters
    }

    // Function to calculate distance from a district
    int distanceFrom(int districtNumber) const {
        return std::abs(districtID - districtNumber);  // Absolute difference
    }
};

class PoliceDepartment {
public:
    int personnelCount;
    int districtID;

    PoliceDepartment(int districtID, int personnelCount = 30)
        : districtID(districtID), personnelCount(personnelCount) {}

    void display() const {
        std::cout << "Police Department in District " << districtID
                  << " with " << personnelCount << " police officers." << std::endl;
    }

    // Function to assign officers based on severity
    int assignOfficers(int severity) const {
        int officersNeeded = 0;

        switch (severity) {
            case 1: officersNeeded = 2; break;
            case 2: officersNeeded = 4; break;
            case 3: officersNeeded = 8; break;
            case 4: officersNeeded = 16; break;
            case 5: officersNeeded = personnelCount; break;
            default: std::cout << "Invalid severity level." << std::endl;
        }

        return officersNeeded;
    }

    // Function to calculate distance from a district
    int distanceFrom(int districtNumber) const {
        return std::abs(districtID - districtNumber);  // Absolute difference
    }
};

class Hospital {
public:
    int personnelCount;

    Hospital(int personnelCount = 20) : personnelCount(personnelCount) {}

    void display() const {
        std::cout << "Hospital with " << personnelCount << " EMTs." << std::endl;
    }

    // For simplicity, we'll assume hospitals always send 1 EMT for a medical emergency.
    int assignEMTs() const {
        return 2; // Simplified assumption that 1 EMT is sent for a medical emergency
    }

    // Function to calculate distance from a district
    int distanceFrom(int districtNumber) const {
        return std::abs(districtNumber - 0);  // Hospital is at a fixed location (let's say at District 0)
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
            std::cout << "Invalid severity! Please enter a number between 1 and 5: ";
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

// Function to find the closest department (fire, police, or hospital) based on district
template<typename T>
T* findClosestDepartment(const std::vector<T>& departments, int districtNumber) {
    int minDistance = std::numeric_limits<int>::max();
    T* closestDept = nullptr;

    for (const auto& dept : departments) {
        int distance = dept.distanceFrom(districtNumber);
        if (distance < minDistance) {
            minDistance = distance;
            closestDept = const_cast<T*>(&dept); // Get a non-const pointer to the department
        }
    }

    return closestDept;
}

// Function to assign and display the number of personnel based on the emergency type and severity
void assignPersonnel(Map& map, EmergencyType emergency, int severity, int districtNumber) {
    int personnelDispatched = 0;
    std::string departmentType = "";

    if (emergency == POLICE) {
        // Find the closest police department to the emergency district
        PoliceDepartment* closestPD = findClosestDepartment(map.policeDepartments, districtNumber);
        if (closestPD) {
            personnelDispatched = closestPD->assignOfficers(severity);
            departmentType = "Police Department";
        }
    } else if (emergency == FIRE) {
        // Find the closest fire department to the emergency district
        FireDepartment* closestFD = findClosestDepartment(map.fireDepartments, districtNumber);
        if (closestFD) {
            personnelDispatched = closestFD->dispatchFirefighters();
            departmentType = "Fire Department";
        }
    } else if (emergency == MEDICAL) {
        // Find the hospital (we assume hospital is at district 0 for simplicity)
        personnelDispatched = map.hospital.assignEMTs();
        departmentType = "Hospital";
    }

    // Output the dispatch information
    std::cout << departmentType << " dispatched " << personnelDispatched
              << " personnel to District " << districtNumber << "." << std::endl;
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
