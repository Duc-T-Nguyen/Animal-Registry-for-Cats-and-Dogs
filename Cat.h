//
//  Cat.h
//  HW6-CS1337-Duc-Nguyen
//
//  Created by Duc Nguyen on 4/29/23.
//

#ifndef Cat_h
#define Cat_h
#include "Animal.h"

class Cat:public Animal {
private:
    static int numberOfCats;
public:
    int individualCatNum;
    Cat(){
        animalSound = "meow";
        numberOfCats++;
        individualCatNum = numberOfCats;
    };
    void introduceCat() {
        cout << "Hello, I'm " << animalName << " and am a " << animalType << endl;
        cout << "I am " << animalAge << " years old and weigh " << animalWeight << endl;
        cout << "I am a " << animalBreed << " " << animalType << " and have " << animalColor << " as my color" << endl;
        cout << "My health status is " << animalHealth << endl;
        cout << "Animal sound " << animalSound << endl;
        cout << "Cat number: " << individualCatNum << endl;
    };
};
int Cat::numberOfCats = 0;
#endif /* Cat_h */
