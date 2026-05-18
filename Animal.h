//
//  Animal.h
//  HW6-CS1337-Duc-Nguyen
//
//  Created by Duc Nguyen on 4/30/23.
//

#ifndef Animal_h
#define Animal_h
#include <iostream>
#include <string>
using namespace std;
class Animal {
private:
    string animalType = "Unknown";
    string animalName = "Unknown";
    int animalAge = -1;
    double animalWeight = -1;
    string animalBreed = "Unknown";
    string animalColor = "Unknown";
    string animalHealth = "Its alive";
    string animalSound = "softly breathing";
public:
    static int totalNumberAnimal;
    int individualAnimalNum;
    Animal(){
        animalSound = "*softly breathing*";
        totalNumberAnimal++;
        individualAnimalNum = totalNumberAnimal;
    };
    void introduceAnimal() {
        cout << "Hello, I'm " << animalName << " and am a " << animalType << endl;
        cout << "I am " << animalAge << " years old and weigh " << animalWeight << endl;
        cout << "I am a " << animalBreed << " " << animalType << " and have " << animalColor << " as my color" << endl;
        cout << "My health status is " << animalHealth << endl;
        cout << "Animal sound " << animalSound << endl;
        cout << "Animal number: " << individualAnimalNum << endl;
    };
    void setType(string t) {animalType = t;}
    void setName(string n) {animalName = n;}
    void setAge(int a) {animalAge = a;}
    void setWeight(double w) {animalWeight = w;}
    void setBreed(string b) {animalBreed = b;}
    void setColor(string c) {animalColor = c;}
    void setHealth(string h) {animalHealth = h;}
};
int Animal::totalNumberAnimal = 0;
#endif /* Animal_h */
