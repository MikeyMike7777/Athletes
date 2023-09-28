/* file: proj5-BUAthleteList.hpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include "proj5-BUAthlete.hpp"

#ifndef PROJECT_5_PROJ5_BUATHLETELIST_HPP
#define PROJECT_5_PROJ5_BUATHLETELIST_HPP

class BUAthleteList : public BUAthlete {
    private:
        BUAthlete *list;
        int capacity;
        int size;
        void resizeArray();
    public:
    //Default Constructor
        BUAthleteList();
    //Destructor
        ~BUAthleteList();
        //Copy Constructor
        BUAthleteList(const BUAthleteList&);
        //Operator =
        BUAthleteList& operator=(const BUAthleteList&);

    /**
* addNCAAAthlete
*
* addNCAAAthlete adds a NCAAAthlete to the list of BUAthletes
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void addNCAAAthlete(int, string, string, string);
    /**
* setBUInfo
*
* setBUInfo sets the extra information for a BUAthlete
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void setBUInfo(int, Position, int);
    /**
* findById
*
* findById finds an ID's index in the list and returns it using Binary Search
*
* Output:
*      return: int
*      reference parameters: none
*      stream: none
*/
        int findById(int);
    /**
* sortByID
*
* sortByID sorts list by quicksort by ID
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void sortByID();
    /**
* sortByPosition
*
* sortByPosition sorts list by bubblesort by Position
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void sortByPosition();
    /**
* sortByEvaluation
*
* sortByEvaluation sorts list by quicksort by Evaluation
*
* Output:
*      return: none
*      reference parameters: none
*      stream: none
*/
        void sortByEvaluation();
        //overloaded []
        BUAthlete& operator[] (int);
    /**
* toString
*
* converts an instance of a NCAAAthlete into a string representtion
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

#endif //PROJECT_5_PROJ5_BUATHLETELIST_HPP
