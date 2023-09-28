/* file: proj5-BUAthlete.hpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include "proj5-NCAAAthlete.hpp"

#ifndef PROJECT_5_PROJ5_BUATHLETE_HPP
#define PROJECT_5_PROJ5_BUATHLETE_HPP

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

#include <sstream>

class BUAthlete : public NCAAAthlete {
    protected:
        int evaluation;
        Position bestFit;
    public:
    /**
 * setEvaluation
 *
 * stores the passed parameter in the evaluation data member
 *
 * Parameters:
 *      evaluation:  the number to store in the evaluation data member
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
        void setEvaluation(int);
    /**
* setPosition
*
* stores the passed parameter in the bestFit data member
*
* Parameters:
*      bestFIt:  the number to store in the bestFit data member
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void setPosition(Position);
    /**
     * getEvaluation
     *
     * getEvaluation returns a copy of the evaluation data memeber
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of the evaluation data member
     *      reference parameters: none
     *      stream: none
     */
        int getEvaluation();
    /**
* getPosition
*
* getPosition returns a copy of the bestFit data memeber
*
* Parameters: none
*
* Output:
*      return: a copy of the bestFit data member
*      reference parameters: none
*      stream: none
*/
        Position getPosition();
    /**
* toString
*
* converts an instance of a BUAthlete into a string representtion
*
* Parameters: none
*
* Output:
*      return: a string representation of the object
*      reference parameters: none
*      stream: none
*/
        string toString();
};

#endif //PROJECT_5_PROJ5_BUATHLETE_HPP
