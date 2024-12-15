//
// Created by dorbi on 18/02/2024.
//

#ifndef EX3_PATH_H
#define EX3_PATH_H

class Path {
private:
    double level_of_path; /**< The level of the path. */
    int to; /**< The destination of the path. */
    double transition_level; /**< The transition level of the path. */

public:
    /**
     * @brief Constructor for the Path class.
     * @param level_of_path The Level of the path.
     * @param TO The destination of the path.
     */
    explicit Path(int Level_of_path=0, int To=0,double Transition_level=0):level_of_path(Level_of_path),to(To),transition_level(Transition_level){};


    /**
     * @brief Getter function to retrieve the destination of the path.
     * @return The destination of the path.
     */
    int getTo() const;

    /**
     Return level ttransition_level+(c/level_of_path);
     */

    double operator+(double c) const;

    /**
     * @brief Getter function to retrieve the transition level of the path.
     * @return The transition level of the path.
     */
    double getTransitionLevel() const;

    /**set transition level */
    void setTransitionLevel(double transitionLevel);

    Path& operator=(const Path &other);

    ~Path()=default;

};


#endif //EX3_PATH_H
/**Note to the reviewer:I didn't need to use all the big three because copying is the copying of primitive variables and the default is enough for me
 * but I used Not all of them*/
