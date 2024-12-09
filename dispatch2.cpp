#include <iostream>
#include <vector>
#include <limits>
#include "firefighter.h"
#include "police.h"
#include "medical.h"

// Enum to represent emergency types
enum EmergencyType {
    FIRE = 1,
    MEDICAL = 2,
    POLICE = 3,
    MIXED = 4,
    INVALID = -1
};

// Struct to represent an active emergency
struct Emergency {
    int district;
    EmergencyType type;
    int severity;
};

class Map {
public:
    std::vector<FireDepartment> fireDepartments;
    std::vector<PoliceDepartment> policeDepartments;
    Hospital hospital;

    void initializeDepartments() {
        // fire departments -- 30 first responders in districts 1 and 5
        fireDepartments.emplace_back(1, 30);   
        fireDepartments.emplace_back(5, 30);

        // police departments -- 30 first responders in districts 2 and 6
        policeDepartments.emplace_back(2, 30);
        policeDepartments.emplace_back(6, 30);

        // Add Hospital
        hospital = Hospital(30);
    }

    void displayStatus() const {
        std::cout << "\nFire Departments Status:\n";
        for (const auto& fd : fireDepartments) {
            fd.displayStatus();
        }

        std::cout << "\nPolice Departments Status:\n";
        for (const auto& pd : policeDepartments) {
            pd.displayStatus();
        }

        std::cout << "\nHospital Status:\n";
        hospital.display();
    }
};

EmergencyType askForEmergencyType() {
    int emergencyChoice;
    std::cout << "What type of emergency is happening?\n";
    std::cout << "1. Fire\n2. Medical Emergency\n3. Police Emergency\n4. Mixed\n";
    std::cout << "Enter the number corresponding to the emergency: ";

    while (true) {
        std::cin >> emergencyChoice;
        if (std::cin.fail() || emergencyChoice < 1 || emergencyChoice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number between 1 and 4: ";
        } else {
            break;
        }
    }
    return static_cast<EmergencyType>(emergencyChoice);
}

int askForSeverity() {
    int severity;
    std::cout << "On a scale of 1 to 5, how severe is the emergency? (1 = Least severe, 5 = Most severe): ";
    while (true) {
        std::cin >> severity;
        if (std::cin.fail() || severity < 1 || severity > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid severity level! Please enter a number between 1 and 5: ";
        } else {
            break;
        }
    }
    return severity;
}

int askForDistrict() {
    int districtNumber;
    std::cout << "Enter the district number (1 to 10) where the emergency occurred: ";
    while (true) {
        std::cin >> districtNumber;
        if (std::cin.fail() || districtNumber < 1 || districtNumber > 10) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid district number! Please enter a number between 1 and 10: ";
        } else {
            break;
        }
    }
    return districtNumber;
}

void handleEmergency(Map& map, EmergencyType type, int severity, int district) {
    switch (type) {
        case FIRE: {
            FireDepartment* nearestFireDept = nullptr;
            int minDistance = std::numeric_limits<int>::max();
            for (auto& fireDept : map.fireDepartments) {
                int distance = fireDept.distanceFrom(district);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestFireDept = &fireDept;
                }
            }
            if (nearestFireDept) {
                nearestFireDept->dispatchResources(severity * 5, severity); // # of firefighters dispatched determined by severity*5
            }
            break;
        }
        case MEDICAL: {
            map.hospital.dispatch(severity);
            break;
        }
        case POLICE: {
            PoliceDepartment* nearestPoliceDept = nullptr;
            int minDistance = std::numeric_limits<int>::max();
            for (auto& policeDept : map.policeDepartments) {
                int distance = policeDept.distanceFrom(district);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestPoliceDept = &policeDept;
                }
            }
            if (nearestPoliceDept) {
                nearestPoliceDept->dispatch(severity * 2, severity); // # of police officers dispatched determined by severity*2
            }
            break;
        }
        case MIXED: {
            handleEmergency(map, FIRE, severity, district);
            handleEmergency(map, MEDICAL, severity, district);
            handleEmergency(map, POLICE, severity, district);
            break;
        }
        default:
            std::cout << "Invalid emergency type!" << std::endl;
    }
}

int main() {
    Map map;
    map.initializeDepartments();

    int numEmergencies;
    std::cout << "Enter the number of emergencies to handle: ";
    std::cin >> numEmergencies;

    for (int i = 0; i < numEmergencies; ++i) {
        EmergencyType type = askForEmergencyType();
        int severity = askForSeverity();
        int district = askForDistrict();
        handleEmergency(map, type, severity, district);
    }

    map.displayStatus();
    return 0;
}
