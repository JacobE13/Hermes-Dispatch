#ifndef MEDICAL_H
#define MEDICAL_H

#include <iostream>

class Hospital {
public:
    int personnelCount;
    int availableEMTs;

    Hospital(int personnelCount = 20);

    void dispatch(int severity);
    void display() const;
};

#endif
