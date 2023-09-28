/* file: proj5-BUAthlete.cpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include "proj5-BUAthlete.hpp"

void  BUAthlete::setEvaluation(int eval){
    this->evaluation = eval;
}
void  BUAthlete::setPosition(Position pos){
    this->bestFit = pos;
}
int BUAthlete::getEvaluation(){
    return this->evaluation;
}
Position BUAthlete::getPosition(){
    return this->bestFit;
}
string BUAthlete::toString(){
    ostringstream out;

    out << NCAAAthlete::toString();
    out << "Evaluation: " << this->evaluation << endl;
    out << "Position: " << this->bestFit << endl;

    return out.str();
}

