#pragma once
#include <iostream>
#include "random_number.h"
#include "checks.h"
#include "emotions.h"



int game() {
    // introducing and initialization
    std::cout << "NUMBER GUESSING GAME (1-100)" << std::endl;
    std::cout << "Initialization. . .";
    bool win_flag = false;
    bool crashout_flag = false;
    bool emotion_flag = false;
    int count = 0;
    int silly_counter = 0;
    int anger_counter = 0;
    int pc_number = random_int();
    std::cout << "complete!" << std::endl;
    std::cout << "The number was generated.\n" "======================" << std::endl;
    std::cout << "Wath's your guess?\n" "Enter the number from 1 to 100: ";
    int players_number;
    std::cin >> players_number;
    
            // selcting PC's mood based on player choice
    if(count == 0) {
        ++count;
        if (check_input(players_number)) {
            emotion_flag = false;
        }
        else {
            emotion_flag = true;
        }
    }

    // checking for valid input
    while(true) {
        // game logic
        if(check_input(players_number)) {
            win_flag = check_guess(players_number, pc_number);
        }
        else {
            emotions(emotion_flag, silly_counter, anger_counter);
            if(emotion_flag == true) {
                ++silly_counter;
            }
            else {
                ++anger_counter;
            }

        }
        if((silly_counter == 3) || (anger_counter == 5)) {
            crashout_flag = true;
        }

        if((win_flag == true) || (crashout_flag == true)) {
            break;
        }

        std::cin >> players_number;
    }
    if(win_flag == true){
        std::cout << "░▒▓ CONGRATULATIONS!!! ▓▒░\n" "You've guessed my number, " << pc_number << " ♥" << std::endl;
    }
    else{
        std::cout << "Cr@$h0ut" << std::endl;
    }
}