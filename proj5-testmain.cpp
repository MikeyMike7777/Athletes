/* file: proj5-main.cpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include <iostream>
#include "proj5-BUAthleteList.hpp"

int main() {
    BUAthleteList list;

    list.addNCAAAthlete(12,"hello", "yes", "BU");
    list.setBUInfo(0, WR, 11);

    list.addNCAAAthlete(14,"hillo", "no", "Bama");
    list.setBUInfo(1, RB, 14);

    list.sortByEvaluation();

    cout << list.toString();

    list.sortByID();

    cout << list.toString();
    return 0;
}