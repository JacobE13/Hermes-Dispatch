#include "medical.h"

// constructor
Hospital::Hospital(int personnelCount) : personnelCount(personnelCount), availableEMTs(personnelCount) {}

// dispatch EMTs 
void Hospital::dispatch(int severity) {
    if (availableEMTs >= severity) {
        availableEMTs -= severity;
        std::cout << "Hospital dispatched " << severity << " EMT(s)." << std::endl;
    } else {
        std::cout << "Not enough EMTs available!" << std::endl;
    }
}

// display hospital status
void Hospital::display() const {
    std::cout << "Hospital has " << availableEMTs << " EMT(s) available." << std::endl;
}
