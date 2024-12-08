#ifndef POLICE_H
#define POLICE_H

#include <iostream>
#include <cmath>

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

    // function to assign officers based on severity
    int assignOfficers(int severity) const {
        switch (severity) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 8;
            case 4: return 16;
            case 5: return personnelCount;
            default: std::cout << "Invalid severity level." << std::endl; return 0;
        }
    }

    // function to dispatch squad cars based on severity
    void dispatchSquadCars(int severity) const {
        std::cout << "Police Department in District " << districtID << " dispatches: ";
        switch (severity) {
            case 1: std::cout << "1 Squad Car." << std::endl; break;
            case 2: std::cout << "2 Squad Cars." << std::endl; break;
            case 3: std::cout << "4 Squad Cars." << std::endl; break;
            case 4: std::cout << "8 Squad Cars." << std::endl; break;
            case 5: std::cout << "All available squad cars (" << personnelCount << " squad cars)." << std::endl; break;
            default: std::cout << "Invalid severity level!" << std::endl;
        }
    }

    int distanceFrom(int districtNumber) const {
        return std::abs(districtID - districtNumber);
    }
};

#endif
