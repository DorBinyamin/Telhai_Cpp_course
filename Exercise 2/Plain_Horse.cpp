//
// Created by dorbi on 03/03/2024.
//
#include "Plain_Horse.h"
/**
 * Getter function to retrieve the location of the horse.
 * @return The location of the horse.
 */
int Plain_Horse::getLocation() const {
    return location;
}

/**
 * Setter function to update the location of the horse.
 * @param local The new location to set for the horse.
 */
void Plain_Horse::setLocation(const int local) {
    this->location = local;
}

/**
 * Getter function to retrieve the name of the horse.
 * @return The name of the horse.
 */

string Plain_Horse::getName() const {
    return name;
}

/** operator = */

Plain_Horse& Plain_Horse::operator=(const Plain_Horse& other) {
    if (this != &other) {
        name = other.name;
        location = other.location;
    }
    return *this;
}
