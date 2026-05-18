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
        cout << "Dog number: " << individualDogNum << endl;
    };
};
int Dog::numberOfDogs = 0;
#endif /* Dog_h */
