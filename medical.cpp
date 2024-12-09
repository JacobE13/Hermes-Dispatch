#include "medical.h"

// Constructor
Hospital::Hospital(int personnelCount) : personnelCount(personnelCount), availableEMTs(personnelCount) {}

// Dispatch EMTs based on severity
void Hospital::dispatch(int severity) {
    if (availableEMTs >= severity) {
        availableEMTs -= severity;
        std::cout << "Hospital dispatched " << severity << " EMT(s)." << std::endl;
    } else {
        std::cout << "Not enough EMTs available!" << std::endl;
    }
}

// Display hospital status
void Hospital::display() const {
    std::cout << "Hospital has " << availableEMTs << " EMT(s) available." << std::endl;
}
