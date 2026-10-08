#pragma once
#include <iostream>
#include <string>
#include "random_number.h"
#include "checks.h"
#include "emotions.h"
#include "is_digit.h"



void game() {
    // introducing and initialization
    std::cout << "▃ ▅ ▇ NUMBER GUESSING GAME (1-100) ▇ ▅ ▃\n" "========================================" << std::endl;
    std::cout << "Initialization. . .";
    bool win_flag = false; // winning situation
    bool crashout_flag = false; // PC's emotional crashout
    bool emotion_flag = false; // which emotion PC should use
    bool amogus_flag = false; // non-digit input
    int silly_counter = 0; // sillyness
    int anger_counter = 0; // anger
    int pc_number = random_int();
    std::cout << "complete!" << std::endl;
    std::cout << "The number was generated.\n" "========================================" << std::endl;
    std::cout << "Wath's your guess?\n" "Enter the number from 1 to 100: ";
    std::string players_input;
    std::cin >> players_input;
    
    // selcting PC's mood based on player choice or crashing the game
    if(is_digit(players_input))
    {
        int players_number = std::stoi(players_input);
        if (check_input(players_number))
        {
            emotion_flag = false;
        }
        else
        {
            emotion_flag = true;
        }
    }
    else
    {
        amogus_flag = true;
    };
    
    
    // start of the game cycle
    while(!win_flag && !crashout_flag && !amogus_flag) // game logic
    {
        if(is_digit(players_input)) // checking players input for letters in it
        {
            int players_number = std::stoi(players_input); // converting string into int if every character is digit

            if(check_input(players_number)) // proper input range
            {
                win_flag = check_guess(players_number, pc_number);
            } 
            else if(!check_input(players_number)) // wrong input range
            {
                emotions(emotion_flag, silly_counter, anger_counter); // writing PC's answers based on it's mood if input not in [1;100]
                if(emotion_flag)
                {
                    ++anger_counter; // sillyness
                }    
                else
                {
                    ++silly_counter; // anger
                }

                if(silly_counter == 3 || anger_counter == 5) // checking for an emotioanl crashout
                {
                    crashout_flag = true;
                }

                if(win_flag || crashout_flag) // game stopping situation for win or crashout
                {
                    break;
                }
            }
        }
        else  // game stopping situation for non-digit input
        {
            amogus_flag = true;
            break;
        }
        
        if(win_flag || crashout_flag) // game stopping situation for win or crashout
        {
            break;
        }

        std::cin >> players_input;
    }
    
    if(win_flag) // if player won
    {
        std::cout << "░▒▓ CONGRATULATIONS!!! ▓▒░\n" "You've guessed my number, " << pc_number << " ♥" << std::endl;
    }
    else if(crashout_flag) // if PC have an emotional crashout
    {
        std::cout << "Cr@$h0ut" << std::endl;
    }
    else // if input was non-digit
    {
        crash();
    }
}