#include "police.h"

// Constructor
PoliceDepartment::PoliceDepartment(int districtID, int personnelCount)
    : districtID(districtID), personnelCount(personnelCount), availableOfficers(personnelCount), availableVehicles(5) {}

// Dispatch resources
void PoliceDepartment::dispatch(int requiredOfficers, int requiredVehicles) {
    if (availableOfficers >= requiredOfficers && availableVehicles >= requiredVehicles) {
        availableOfficers -= requiredOfficers;
        availableVehicles -= requiredVehicles;
        std::cout << "Police Department in District " << districtID
                  << " dispatched " << requiredOfficers << " officers and "
                  << requiredVehicles << " vehicles." << std::endl;
    } else {
        std::cout << "Not enough officers or vehicles available in District " << districtID << "!" << std::endl;
    }
}

// Display status
void PoliceDepartment::displayStatus() const {
    std::cout << "Police Department in District " << districtID
              << " has " << availableOfficers << " officers and "
              << availableVehicles << " vehicles available." << std::endl;
}

// Calculate distance
int PoliceDepartment::distanceFrom(int districtNumber) const {
    return std::abs(districtID - districtNumber);
}
