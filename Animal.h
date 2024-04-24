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
public:
    string animalType = "Unknown";
    string animalName = "Unknown";
    int animalAge = -1;
    double animalWeight = -1;
    string animalBreed = "Unknown";
    string animalColor = "Unknown";
    string animalHealth = "Its alive";
    string animalSound = "softly breathing";
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
};
int Animal::totalNumberAnimal = 0;
#endif /* Animal_h */
