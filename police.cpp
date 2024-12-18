#include "police.h"

// constructor
PoliceDepartment::PoliceDepartment(int districtID, int personnelCount)
    : districtID(districtID), personnelCount(personnelCount), availableOfficers(personnelCount), availableVehicles(15) {}

// dispatch resources
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

// display status
void PoliceDepartment::displayStatus() const {
    std::cout << "Police Department in District " << districtID
              << " has " << availableOfficers << " officers and "
              << availableVehicles << " vehicles available." << std::endl;
}

// calculate distance b/w districts
int PoliceDepartment::distanceFrom(int districtNumber) const {
    return std::abs(districtID - districtNumber);
}
