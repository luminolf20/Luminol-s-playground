#pragma once
#include <iostream>

// int check_guess(int player_num, int pc_num)
// int check_input(int input)

bool check_guess(int player_num, int pc_num) {
    bool win = false;
    if(player_num > pc_num) {
        std::cout << "Nuh uh, my number is . . . lower. ▼" << std::endl;
        return false;
    }
    else if(player_num < pc_num) {
        std::cout << "Nope, my number is . . . GREATER. ▲" << std::endl;
        return false;
    }
    else if (player_num == pc_num){
        return true;
    }
}

bool check_input(int input){
    if(input >= 1 && input <= 100){
        return true;
    }
    else{
        return false;
    }
}