//
// Created by dorbi on 18/02/2024.
//

#ifndef EX3_INTERSECTION_H
#define EX3_INTERSECTION_H
#include "Path.h"
#include "Linkedlist.h"

class Intersection {
private:
    Linkedlist<Path>* paths; /**< Pointer to a linked list of Path objects representing paths at the intersection. */
    int sizeofPaths; /**< The number of paths at the intersection. */

public:
    /**
     * @brief Constructor for the Intersection class.
     * Initializes the intersection with an empty linked list of paths and sets the size to 0.
     */
    explicit Intersection();

    /**
     * @brief Inserts a new path into the intersection.
     * @param path The path to insert.
     */
    void Insert(Path* path);

    // Assignment operator
    Intersection& operator=(const Intersection& other);

    /**
     * @brief Getter function to retrieve the linked list of paths at the intersection.
     * @return A pointer to the linked list of paths.
     */
    Linkedlist<Path>* getPaths() const ;


    /**
     * @brief Getter function to retrieve the number of paths at the intersection.
     * @return The number of paths at the intersection.
     */

    int getSizeofpaths() const ;

    /**
     * @brief Destructor for the Intersection class.
     * Deallocates memory used by the linked list of paths.
     */
    ~Intersection() ;
};

#endif //EX3_INTERSECTION_H

