//
//  Dog.h
//  HW6-CS1337-Duc-Nguyen
//
//  Created by Duc Nguyen on 4/29/23.
//

#ifndef Dog_h
#define Dog_h
#include "Animal.h"

class Dog:public Animal {
private:
    static int numberOfDogs;
public:
    int individualDogNum;
    Dog(){
        animalSound = "woof";
        numberOfDogs++;
        individualDogNum = numberOfDogs;
    };
    void introduceDog() {
        cout << "Hello, I'm " << animalName << " and am a " << animalType << endl;
        cout << "I am " << animalAge << " years old and weigh " << animalWeight << endl;
        cout << "I am a " << animalBreed << " " << animalType << " and have " << animalColor << " as my color" << endl;
        cout << "My health status is " << animalHealth << endl;
        cout << "Animal sound " << animalSound << endl;
        cout << "Dog number: " << individualDogNum << endl;
    };
};
int Dog::numberOfDogs = 0;
#endif /* Dog_h */
