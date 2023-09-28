/* file: proj5-main.cpp
 *
 * author: Michael Mathews
* course: CSI 1440
* assignment: project 5
* due date: 10/18/2021
*/

#include <fstream>
#include <iostream>
#include "proj5-BUAthleteList.hpp"

int main() {
    BUAthleteList list;
    ifstream inputFile;
    stringstream ss;

    string name, loi, school, ssString, ssInt;
    int id, eval, index, size = 0, max = 0, i = 0;
    Position pos = OL;
    bool done = false;

    inputFile.open("proj5-NCAAAthlete.csv");

    if (!inputFile) {
        return 1;
    }

    inputFile >> id;
    inputFile.ignore(1);
    while(inputFile) {
        getline(inputFile, name, ',');

        getline(inputFile, loi, ',');

        getline(inputFile, school);

        list.addNCAAAthlete(id, name, loi, school);
        size++;

        inputFile >> id;
        inputFile.ignore(1);
    }

    list.sortByID();

    inputFile.close();

    // read and find additional buathlete required information
    inputFile.open("proj5-BUAthlete.csv");

    if (!inputFile) {
        return 1;
    }

    inputFile >> id;
    inputFile.ignore(1);

    getline(inputFile, name,',');
    while(inputFile) {

        index = list.findById(id);

        //check all positions
        if (name == "OL") {
            pos = OL;
        } else if (name == "QB") {
            pos = QB;
        } else if (name == "WR") {
            pos = WR;
        } else if (name == "TE") {
            pos = TE;
        } else if (name == "DL") {
            pos = DL;
        } else if (name == "DE") {
            pos = DE;
        } else if (name == "LB") {
            pos = LB;
        } else if (name == "CB") {
            pos = CB;
        } else if (name == "S") {
            pos = S;
        } else if (name == "K") {
            pos = K;
        }

        inputFile >> eval;
        inputFile.ignore(1);

        if (index != -1) {
            list.setBUInfo(index, pos, eval);
        }
        inputFile >> id;
        inputFile.ignore(1);
    }

    inputFile.close();

    list.sortByEvaluation();
    list.sortByPosition();

    for (int i = 0; i < size; i++) {
        cout << list[i].toString();
    }

    //print top two for each position
    /*
    while (!done) {
        name = list[i].getPosition();
        if (name == "OL" and max < 2) {
            cout << list[i].toString();
            max++;
        } else if (name == "QB" and max < 4) {
            cout << list[i].toString();
            max++;
        } else if (name == "WR" and max < 6) {
            cout << list[i].toString();
            max++;
        } else if (name == "TE" and max < 8) {
            cout << list[i].toString();
            max++;
        } else if (name == "DL" and max < 10) {
            cout << list[i].toString();
            max++;
        } else if (name == "DE" and max < 12) {
            cout << list[i].toString();
            max++;
        } else if (name == "LB" and max < 14) {
            cout << list[i].toString();
            max++;
        } else if (name == "CB" and max < 16) {
            cout << list[i].toString();
            max++;
        } else if (name == "S" and max < 18) {
            cout << list[i].toString();
            max++;
        } else if (name == "K" and max < 20) {
            cout << list[i].toString();
            max++;
            if (max == 19) {
                done = true;
            }
        }
    }
*/

    return 0;
}
