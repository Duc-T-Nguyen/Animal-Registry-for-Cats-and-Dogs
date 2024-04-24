//
//  main.cpp
//  HW6-CS1337-Duc-Nguyen
//
//  Created by Duc Nguyen on 4/19/23.
// ChangeLog:
// 4/19/2023:
// -started on the project and created Animal class
// 4/21/2023:
// -created Animal, Dog, Cat, and otherAnimal classes
// 4/24/2023:
// - created code to read and open the excel sheet
// -put code to open execel sheet into a function named readTheDataBase
// 4/25/2023:
// -created the .h file and transfered the class to it
// -had to include #include <string> cause .h doesn't immediately include strings
// 4/26/2023:
// -included .cpp file for animal class
// -created function in main to open the file
// 4/27/2023:
// -created variables numberOfCats and number of Dogs to track the number of dog/cats indivdually
// -created the destructor for the cats and dogs subclasses to delete at the end of program
// -worked on reading in the excel sheet(reworked how to read in the execel)
// -worked on the subclasses dog, cat, and other animal
// 4/28/2023:
// -worked on setting up the subclasses for dog and cat
// 4/29/2023:
// -created code to create dynamic constructors
// -worked on allocating
// -created  variable to give each dog and cat their own number as a dog and cat
// -

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

char get_S_or_N;
string GetInfo, animalType, animalName, animalBreed, animalColor, animalHealth, animalSound;
int animalAge = -1;
double animalWeight = -1;
double theWeight = -1;
int theAge = -1;
vector<string> hold(7);
vector<Animal> animalVec;
vector<Dog> dogVec;
vector<Cat> catVec;
fstream nameOfFile;

void processFunctions();
void checkIfUnknown();
bool welcomePersonToProgram();
void haveANiceDay();
void openTheDataBase();
void readInTheData();
void createNewAnimalDog();
void createNewAnimalCat();
void createNonCatOrDog();
void outputTheReport();

void processFunctions() {
    if (welcomePersonToProgram() == true) {
        openTheDataBase();
        readInTheData();
        outputTheReport();
        nameOfFile.close();
    }
    else {
        haveANiceDay();
    }
}

bool welcomePersonToProgram() {
    bool gotAnswer = false;
    cout << "Hello, welcome to the animal rescue program" << endl;
    do {
        cout << "Please press S to start the program or N to stop the program now." << endl;
        cin >> get_S_or_N;
        get_S_or_N = toupper(get_S_or_N);
        if (get_S_or_N == 'S') {
            gotAnswer = true;
        }
        if (get_S_or_N == 'N') {
            gotAnswer = true;
        }
    } while (gotAnswer == false);
    if (toupper(get_S_or_N) == 'S') {
        return true;
    }
    return false;
}

void openTheDataBase() {
    string nameOfTheDataBaseFile;
    cout << "Okay, first please give the name of the file that you want to be read" << endl;
    do {
        getline(cin, nameOfTheDataBaseFile);
        nameOfFile.open(nameOfTheDataBaseFile);
    } while (!nameOfFile.is_open());
    // cout << "working" << endl;
}

void createNewAnimalDog() {
    double theWeight = -1;
    int theAge = -1;
    theAge = stoi(hold[2]);
    theWeight = stoi(hold[3]);
    checkIfUnknown();
    Dog Dog;
    Dog.animalType = hold[0];
    Dog.animalName = hold[1];
    Dog.animalAge = theAge;
    Dog.animalWeight = theWeight;
    Dog.animalBreed = hold[4];
    Dog.animalColor = hold[5];
    Dog.animalHealth = hold[6];
    dogVec.push_back(Dog);
    animalVec.push_back(Dog);
}

void createNewAnimalCat() {
    theAge = stoi(hold[2]);
    theWeight = stoi(hold[3]);
    checkIfUnknown();
    Cat Cat;
    Cat.animalType = hold[0];
    Cat.animalName = hold[1];
    Cat.animalAge = theAge;
    Cat.animalWeight = theWeight;
    Cat.animalBreed = hold[4];
    Cat.animalColor = hold[5];
    Cat.animalHealth = hold[6];
    catVec.push_back(Cat);
    animalVec.push_back(Cat);
}

void checkIfUnknown(){
    if(hold[0].length() < 2){
        hold[0] = "Unknown";
    }
    if(hold[1].length() < 2){
        hold[1] = "Unknown";
    }
    if(hold[4].length() < 2){
        hold[4] = "Unknown";
    }
    if(hold[5].length() < 2){
        hold[5] = "Unknown";
    }
    if(hold[6].length() < 2){
        hold[6] = "Its alive";
    }
    if(theAge < 1){
        theAge = -1;
    }
    if(theWeight < 1){
        theWeight = -1;
    }
}

void createNonCatOrDog() {
    double theWeight = -1;
    int theAge = -1;
    theAge = stoi(hold[2]);
    theWeight = stoi(hold[3]);
    checkIfUnknown();
    Animal Animal;
    Animal.animalType = hold[0];
    Animal.animalName = hold[1];
    Animal.animalAge = theAge;
    Animal.animalWeight = theWeight;
    Animal.animalBreed = hold[4];
    Animal.animalColor = hold[5];
    Animal.animalHealth = hold[6];
    animalVec.push_back(Animal);
}

void readInTheData() {
    int countTheNumber = 0;
    while (nameOfFile.good()) {
        getline(nameOfFile, GetInfo, ',');
        hold[countTheNumber] = GetInfo;
        countTheNumber++;
        if (countTheNumber == 7) {
            if (hold[0] == "dog") {
                createNewAnimalDog();
            }
            else if (hold[0] == "cat") {
                createNewAnimalCat();
            }
            else if (hold[0] != "cat" && hold[0] == "dog" && hold[0] != "AnimalType") {
                createNonCatOrDog();
            }
            countTheNumber = 0;
        }
        countTheNumber = 0;
    }
}

void outputTheReport() {
    cout << "entered" << endl;
    cout << "Report #1: Animal Report" << endl;
    for (int i = 0; i < animalVec.size(); i++) {
        animalVec[i].introduceAnimal();
    }
    cout << "Report #2: Dog Report" << endl;
    for (int i = 0; i < dogVec.size(); i++) {
        dogVec[i].introduceDog();
    }
    cout << "Report #3: Cat Report" << endl;
    for (int i = 0; i < catVec.size(); i++) {
        catVec[i].introduceCat();
    }

}

void haveANiceDay() {
    cout << "Thank you for the input" << endl;
    cout << "Have a nice day." << endl;
}

int main(int argc, const char* argv[]) {
    processFunctions();
    return 0;
}
