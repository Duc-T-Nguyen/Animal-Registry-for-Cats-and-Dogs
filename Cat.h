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
        cout << "Cat number: " << individualCatNum << endl;
    };
};
int Cat::numberOfCats = 0;
#endif /* Cat_h */
