#ifndef MEDICAL_H
#define MEDICAL_H

#include <iostream>
#include <cmath>

class Hospital {
public:
    int personnelCount;

    Hospital(int personnelCount = 20) : personnelCount(personnelCount) {}

    void display() const {
        std::cout << "Hospital with " << personnelCount << " EMTs." << std::endl;
    }

    // assume hospitals always send 1 EMT for a medical emergency
    int assignEMTs() const {
        return 1; // 1 EMT sent
    }

    int distanceFrom(int districtNumber) const {
        return std::abs(districtNumber - 0);
    }
};

#endif
