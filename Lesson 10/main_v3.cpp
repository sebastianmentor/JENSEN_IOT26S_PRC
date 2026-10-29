#include <iostream>
#include <string>

#define MAX_NUMBER_OF_PLAYERS 10

typedef struct 
{
    std::string name;
    int score;
    int rounds;
}Player;

void print_player(Player& player){
    std::cout << "\nName   : " << player.name   << "\n";
    std::cout << "Score  : " << player.score  << "\n";
    std::cout << "Rounds : " << player.rounds << "\n";
}

void creat_player(Player& player){
    std::cout << "Enter name: ";
    std::cin >> player.name;

    player.score = 0;
    player.rounds = 0;
}
void change_player(std::string& old_name){
    std::cout << "Enter new name: ";
    std::string new_name;
    std::cin >> new_name;
    old_name = new_name;
}

void change_player(int& old_score){
    int score_to_add;
    std::cout << "Enter score to add: ";
    std::cin >> score_to_add;
    if(score_to_add < 0){
        std::cout << "Cant add negative score\n";
        return;
    }
    old_score += score_to_add;
}

void change_player(Player& player){   
    while (true)
    {
        std::cout << "1. Change name\n";
        std::cout << "2. Increase score\n";
        std::cout << "3. Increase one round\n";
        std::cout << "0. Go back\n";

        std::cout << "Enter choice: ";
        int user_choice;
        std::cin >> user_choice;
        if(user_choice == 1){
            // std::cout << "Enter new name: ";
            // std::string new_name;
            // std::cin >> new_name;
            // player.name = new_name;
            change_player(player.name);

        }
        else if(user_choice == 2){
            change_player(player.score);

        }
        else if(user_choice == 3){
            player.rounds ++;
        }
        else if(user_choice == 0){
            break;
        }
        else{
            std::cout << "Invalid choice!\n";
        }

    }
    
}

void print_menu(){
    std::cout << "1. Creat player\n";
    std::cout << "2. Print all player\n";
    std::cout << "3. Change player\n";
    std::cout << "0. Exit\n";
}

int main() {Player players[MAX_NUMBER_OF_PLAYERS];
    
    int total_players = 0;
    bool run_program = true;
    std::string player_name;
    bool player_found = false;

    while (run_program)
    {   
        print_menu();
        int user_input;
        std::cout << "Enter choice: ";
        std::cin >> user_input;

        switch (user_input)
        {
        case 0:
            run_program = false;
            break;               
        case 1:
            if(total_players < MAX_NUMBER_OF_PLAYERS)
            {
                creat_player(players[total_players]);
                total_players ++;
            }
            break;
        case 2:
            for(int i = 0; i < total_players; i++)
            {
                print_player(players[i]);
            }
            break;
        case 3:
            
            std::cout << "Enter players name: ";
            std::cin >> player_name;
            player_found = false;

            for(int i = 0; i < total_players; i++){
                if(players[i].name == player_name){
                    change_player(players[i]);
                    player_found = true;
                }
            }

            if(!player_found){
                std::cout << "No player with name " << player_name << " found\n";
            }

            break;                    
         
        default:
            std::cout << "Invalid choice! Try again!\n";
            break;
        }
    }
    

    return 0;
}