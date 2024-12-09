#ifndef POLICE_H
#define POLICE_H

#include <iostream>
#include <cmath>

class PoliceDepartment {
public:
    int districtID;
    int personnelCount;
    int availableOfficers;
    int availableVehicles;

    PoliceDepartment(int districtID, int personnelCount = 30);

    void dispatch(int requiredOfficers, int requiredVehicles);
    void displayStatus() const;
    int distanceFrom(int districtNumber) const;
};

#endif
