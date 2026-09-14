#pragma once
#include <iostream>


// int silly(int silly_counter)
// int anger(int anger_counter)
// int emotions(bool emotions_flag, int silly_counter, int anger_counter)

int silly(int silly_counter){
    switch (silly_counter) {
        case 0 : {
            std::cout << "Oopsie-doopsie, wrong number, huh? :)\n" "Could enter your guess again, please~: ";
            break;
        }
        case 1 : {
            std::cout << "Dude, are you serious . . ?\n" "Enter your guess and make sure it's between 1 and 100: ";
            break;
        }
        case 2 : {
            std::cout << ". . ." << std::endl;
            break;
        }
    }
}

int anger(int anger_counter){
    switch (anger_counter) {
        case 0 : {
            std::cout << "It's just a typo, rigth?\n" "Could enter your guess again: ";
            break;
        }
        case 1 : {
            std::cout << "Erm, it should be a number between 1 and 100 . . .\n" "Enter your guess again: ";
            break;
        }
        case 2 : {
            std::cout << "Are you even listening to me?\n" "Enter a number from 1 to 100: ";
            break;
        }
        case 3 : {
            std::cout << "I repeat last time, NUMBER BETWEEN 1 AND 100: ";
            break;
        }
        case 4 : {
            std::cout << ". . ." << std::endl;
            break;
        }
    }
}

int emotions(bool emotions_flag, int silly_counter, int anger_counter){
    if (emotions_flag == true) {
        silly(silly_counter);
    }
    else {
        anger(anger_counter);
    }
}