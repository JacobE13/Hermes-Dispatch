#include "firefighter.h"

// cnstructor
FireDepartment::FireDepartment(int districtID, int personnelCount)
    : districtID(districtID), personnelCount(personnelCount), availableFirefighters(personnelCount), availableVehicles(4) {}

// dispatch resources
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

// return resources
void FireDepartment::returnResources(int firefighters, int vehicles) {
    availableFirefighters += firefighters;
    availableVehicles += vehicles;
    std::cout << "Fire Department in District " << districtID
              << " returned " << firefighters << " firefighters and "
              << vehicles << " vehicles." << std::endl;
}

// display current status
void FireDepartment::displayStatus() const {
    std::cout << "Fire Department in District " << districtID
              << " has " << availableFirefighters << " firefighters and "
              << availableVehicles << " vehicles available." << std::endl;
}

// calculate distance from given district
int FireDepartment::distanceFrom(int districtNumber) const {
    return std::abs(districtID - districtNumber);
}
