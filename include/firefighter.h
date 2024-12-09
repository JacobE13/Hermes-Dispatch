#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#include <iostream>
#include <cmath>

class FireDepartment {
public:
    int districtID;
    int personnelCount;
    int availableFirefighters; // Tracks available firefighters
    int availableVehicles;     // Tracks available vehicles

    FireDepartment(int districtID, int personnelCount = 30);

    void dispatchResources(int requiredFirefighters, int requiredVehicles);
    void returnResources(int firefighters, int vehicles);
    void displayStatus() const;

    int distanceFrom(int districtNumber) const;
};

#endif
