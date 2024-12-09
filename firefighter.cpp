#include "firefighter.h"

// Constructor
FireDepartment::FireDepartment(int districtID, int personnelCount)
    : districtID(districtID), personnelCount(personnelCount), availableFirefighters(personnelCount), availableVehicles(3) {}

// Dispatch resources
void FireDepartment::dispatchResources(int requiredFirefighters, int requiredVehicles) {
    if (availableFirefighters >= requiredFirefighters && availableVehicles >= requiredVehicles) {
        availableFirefighters -= requiredFirefighters;
        availableVehicles -= requiredVehicles;
        std::cout << "Fire Department in District " << districtID
                  << " dispatched " << requiredFirefighters << " firefighters and "
                  << requiredVehicles << " vehicles." << std::endl;
    } else {
        std::cout << "Not enough firefighters or vehicles available in District " << districtID << "!" << std::endl;
    }
}

// Return resources
void FireDepartment::returnResources(int firefighters, int vehicles) {
    availableFirefighters += firefighters;
    availableVehicles += vehicles;
    std::cout << "Fire Department in District " << districtID
              << " returned " << firefighters << " firefighters and "
              << vehicles << " vehicles." << std::endl;
}

// Display current status
void FireDepartment::displayStatus() const {
    std::cout << "Fire Department in District " << districtID
              << " has " << availableFirefighters << " firefighters and "
              << availableVehicles << " vehicles available." << std::endl;
}

// Calculate distance from a given district
int FireDepartment::distanceFrom(int districtNumber) const {
    return std::abs(districtID - districtNumber);
}
