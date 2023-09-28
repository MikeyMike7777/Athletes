/* file: proj5-BUAthleteList.cpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include "proj5-BUAthleteList.hpp"

BUAthleteList::BUAthleteList(){
    this->size = 0;
    this->capacity = 2;
    this->list = new BUAthlete[this->capacity];
}

BUAthleteList::~BUAthleteList(){
    delete [] this->list;
}

BUAthleteList::BUAthleteList(const BUAthleteList& obj){
    if(this != &obj){
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->list = new BUAthlete[obj.capacity];
        for(int i = 0; i < obj.size; i++){
            this->list[i] = obj.list[i];
        }
    }
}

BUAthleteList& BUAthleteList::operator=(const BUAthleteList& obj){
    if(this != &obj){
        delete [] this->list;

        this->size = obj.size;
        this->capacity = obj.capacity;

        this->list = new BUAthlete[obj.capacity];
        for(int i = 0; i < obj.size; i++){
            this->list[i] = obj.list[i];
        }
    }
    return *this;
}

void BUAthleteList::resizeArray(){
    this->capacity += 2;
    BUAthlete* temp = new BUAthlete[this->capacity];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->list[i];
    }
    delete [] this->list;
    this->list = temp;
}

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school){
    if (this->size == this->capacity) {
        this->resizeArray();
    }
    this->list[this->size].setID(ID);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(LOI);
    this->list[this->size].setSchool(school);
    this->size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval){
    this->list[index].setPosition(pos);
    this->list[index].setEvaluation(eval);
}

int BUAthleteList::findById(int id){
    int i = 0, mid, pos = 0;

    this->sortByID();

    while (i <= this->size){
        mid = i + (this->size-1) / 2;

        //if x is bigger, ignore left half
        if(this->list[mid].getID() < id){
            i = mid + 1;
        }
        //if x is smaller, ignore right half
        else if(this->list[mid].getID() > id){
            i = mid - 1;
        }
        else {
            pos = mid;
        }
    }
    return pos;
}

void BUAthleteList::sortByID(){
    int i = 0, j, midpoint, pivot;
    bool done = false;

    i = 0;
    j = this->size-1;
    //set middle element as pivot
    midpoint = (this->size-1) / 2;
    pivot = this->list[midpoint].getID();

    while(!done){
        // use quicksort algorithm to divide and conquer with use of pivot
        while(this->list[i].getID() < pivot) {
            i++;
        }
        while(this->list[j].getID() > pivot){
            j--;
        }
        if(i >= j){
            done = true;
        }
            //swap
        else {
            BUAthlete *temp = new BUAthlete[this->capacity];

            temp[i] = this->list[i];
            this->list[i] = this->list[j];
            this->list[j] = temp[i];
            delete [] temp;
            i++;
            j--;
        }
    }


}

void BUAthleteList::sortByPosition(){
    int i, j;
    for (i = 0; i < this->size-1; i++)

        // Last i elements are already in place
        for (j = 0; j < this->size-i-1; j++) {
            if (this->list[j].getPosition() > this->list[j + 1].getPosition());
            swap(this->list[j], this->list[j + 1]);
        }
}

void BUAthleteList::sortByEvaluation(){
    int i = 0, j, midpoint, pivot;
    bool done = false;

    i = 0;
    j = this->size-1;
    //set middle element as pivot
    midpoint = (this->size-1) / 2;
    pivot = this->list[midpoint].getEvaluation();

    while(!done){
        // use quicksort algorithm to divide and conquer with use of pivot
        while(list[i].getEvaluation() > pivot) {
            i++;
        }
        while(list[j].getEvaluation() < pivot){
            j--;
        }
        if(i >= j){
            done = true;
        }
            //swap
        else {
            BUAthlete *temp = new BUAthlete[this->capacity];
            temp[i] = this->list[i];
            this->list[i] = this->list[j];
            this->list[j] = temp[i];
            delete [] temp;
            i++;
            j--;
        }
    }
}

BUAthlete& BUAthleteList::operator[] (int ndx){
    return this->list[ndx];
}

string BUAthleteList::toString(){
    ostringstream out;
    int i = 0;

    while (i < this->size) {
        out << "[ " << i << " ]" << endl;
        out << this->list[i].BUAthlete::toString();
        i++;
    }
    return out.str();
}