#pragma once
#include <iostream>

// int check_guess(int player_num, int pc_num)
// int check_input(int input)

int check_guess(int player_num, int pc_num) {
    bool win = false;
    if(player_num > pc_num) {
        std::cout << "Nuh uh, my number is lower. ▼" << std::endl;
        win = false;
        return win;
    }
    else if(player_num < pc_num) {
        std::cout << "Nope, my number is GREATER. ▲" << std::endl;
        win = false;
        return win;
    }
    else if (player_num == pc_num){
        win = true;
        return win;
    }
}

int check_input(int input){
    if(input >= 1 && input <= 100){
        return true;
    }
    else{
        return false;
    }
}