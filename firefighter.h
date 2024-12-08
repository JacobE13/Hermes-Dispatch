#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#include <iostream>
#include <cmath>

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

    // dispatches fire vehicles based on severity
    void dispatchFireVehicles(int severity) const {
        std::cout << "Fire Department in District " << districtID << " dispatches: ";
        switch (severity) {
            case 1: std::cout << "1 Water Truck." << std::endl; break;
            case 2: std::cout << "2 Water Trucks." << std::endl; break;
            case 3: std::cout << "1 Ladder Truck, 1 Water Truck." << std::endl; break;
            case 4: std::cout << "2 Ladder Trucks, 1 Water Truck." << std::endl; break;
            case 5: std::cout << "2 Ladder Trucks, 2 Water Trucks, 1 Rescue Truck." << std::endl; break;
            default: std::cout << "Invalid severity level!" << std::endl;
        }
    }

    // dispatches firefighters based on severity
    int dispatchFirefighters(int severity) const {
        switch (severity) {
            case 1: return 5;   // minor fire requires fewer firefighters
            case 2: return 10;  // slightly larger fire requires more firefighters
            case 3: return 15;  // moderate fire requires more firefighters
            case 4: return 20;  // serious fire requires even more firefighters
            case 5: return personnelCount;  // major fire requires all firefighters
            default: return 0;  // invalid severity level
        }
    }

    // function calculates distance from a district
    int distanceFrom(int districtNumber) const {
        return std::abs(districtID - districtNumber);
    }
};

#endif
