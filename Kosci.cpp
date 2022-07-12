#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int players_number();

void write_table(int players[4][13], int player_number);

void write_dice(int dice[5]);

void dice_throw(int dice[5]);

void  rethrow(int dice[5], int rethrow_number);

void rethrow_round(int dice[5]);

void save_result(int players[4][13], int player_number, int dice[5], int row);

void choose_row(int players[4][13], int player_number, int dice[5]);

void save_result(int players[4][13], int player_number, int dice[5], int row);

void round(int players[4][13], int player_number);

void count_result(int players[4][13], int number_of_players);

int main()
{
    int number_of_players;
    int players[4][13]; 

   
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            players[i][j] = NULL;
        }
    }

    
    number_of_players = players_number();

    int turns_number = 1;

    while (turns_number <= 13)
    {
        cout << endl << "TURA NUMER  " << turns_number << endl << endl;
        for (int i = 0; i < number_of_players; i++)
        {
            cout << "kolej gracza " << i+1 << " w turze nr "<< turns_number<< endl << endl;
            round(players, i);
            
        }
        turns_number++;
    }

    count_result(players, number_of_players);
}


int players_number()
{
    int number_of_players;
    cout << "Podaj liczbe graczy (od 2 do 4) : ";
    cin >> number_of_players;

    
    if (number_of_players == 2 || number_of_players == 3 || number_of_players == 4)
    {
        cout << endl << "Liczba graczy : " << number_of_players << endl;
        return number_of_players;
    }
    else
    {
        cout << "Nieprawidlowa liczba graczy!" << endl;
        players_number();
    }    
}


void write_table(int players[4][13], int player_number)
{
    cout << "1. Jedynki:      " << players[player_number][0] << endl;
    cout << "2. Dwojki:       " << players[player_number][1] << endl;
    cout << "3. Trojki:       " << players[player_number][2] << endl;
    cout << "4. Czworki:      " << players[player_number][3] << endl;
    cout << "5. Piatki:       " << players[player_number][4] << endl;
    cout << "6. Szostki:      " << players[player_number][5] << endl;
    cout << "7. 3 jednakowe:  " << players[player_number][6] << endl;
    cout << "8. 4 jednakowe:  " << players[player_number][7] << endl;
    cout << "9. Full:         " << players[player_number][8] << endl;
    cout << "10. Maly street: " << players[player_number][9] << endl;
    cout << "11. Duzy street: " << players[player_number][10] << endl;
    cout << "12. General:     " << players[player_number][11] << endl;
    cout << "13. Szansa:      " << players[player_number][12] << endl << endl;
}


void write_dice(int dice[5])
{
    cout << "  ---  " << "  ---  " <<"  ---  " <<"  ---  " <<"  ---  " << endl;
    cout << " | " << dice[0] << " |  | " << dice[1] << " |  | " << dice[2] << " |  | " << dice[3] << " |  | " << dice[4] << " |" << endl;
    cout << "  ---  " << "  ---  " << "  ---  " << "  ---  " << "  ---  " << endl;
}


void dice_throw(int dice[5])
{
    srand(time(NULL)); 
    for (int i = 0; i < 5 ; i++)
    {
        dice[i] = (rand() % 6) + 1;    
    }
}


void  rethrow(int dice[5], int rethrow_number)
{
    dice[rethrow_number] = (rand() % 6) + 1;
}


void rethrow_round(int dice[5])
{
    int rethrow_number; 
    cout << "Ile kosci przerzucic: ";
    cin >> rethrow_number;
    vector <int> rethrowed; 
    int vector_size = 0;    
    
    if (rethrow_number > 4)
    {
        cout << "Podano nieprawidlowa liczbe kosci do przerzucenia!" << endl;
        rethrow_round(dice);
    }
    else
    {
        while (vector_size < rethrow_number)
        {
            bool is_new = true; 
            int choosen_number; 
            cout << "Numer kosci do przerzucenia (pamietaj ze kosci sa numerowane od 0): ";
            cin >> choosen_number;

            for (int i = 0; i < rethrowed.size(); i++)
            {
                
                if (choosen_number == rethrowed[i])
                {
                    is_new = false;
                    cout << "Ta kosc juz zostala przerzucona. Wybierz inna kosc." << endl;
                }
            }
            if (is_new == true)
            {
                
                rethrow(dice, choosen_number);
                rethrowed.push_back(choosen_number);
                vector_size++;
            }
            
        }
    }
    cout << endl << "Kosci po przerzuceniu: " << endl;
    write_dice(dice);
}


void choose_row(int players[4][13], int player_number, int dice[5])
{
    int row; 
    cout << endl << "Gdzie wpisac wynik? (Podaj numer pola w tabelce): ";
    cin >> row;


   
    if (players[player_number][row - 1] == NULL)
    {
        save_result(players, player_number, dice, row);
    }
    else
    {
        cout << "Wybrane pole jest juz zajete!" << endl;
        choose_row(players, player_number, dice);
    }
}


void save_result(int players[4][13], int player_number, int dice[5], int row)
{
    int result = 0; 
     
    if (row == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 1) result = result + 1;
        }
    }
   
    else if (row == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 2) result = result + 2;
        }
    }
    
    else if (row == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 3) result = result + 3;
        }
    }
    
    else if (row == 4)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 4) result = result + 4;
        }
    }
    
    else if (row == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 5) result = result + 5;
        }
    }
    
    else if (row == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 6) result = result + 6;
        }
    }

    else if (row == 7)
    {
        bool is_3 = false; 

        for (int i = 1; i <= 6; i++)
        {
            int schow_number = 0;  
            for (int j = 0; j < 5; j++)
            {
                if (i == dice[j])
                {
                    schow_number++;
                }
            }
           
            if (schow_number == 3) is_3 = true;
        }
        if (is_3 == true)
        {
            for (int i = 0; i < 5; i++) result = result + dice[i];
        }
        else
        {
           result = 0;
        }
    }
   
    else if (row == 8)
    {
        bool is_4 = false; 
        for (int i = 1; i <= 6; i++)
        {
            int schow_number = 0;  
            for (int j = 0; j < 5; j++)
            {
                if (i == dice[j])
                {
                    schow_number++;
                }
            }
            if (schow_number == 4) is_4 = true;
        }

        if (is_4 == true)
        {
            for (int i = 0; i < 5; i++) result = result + dice[i];
        }
        else
        {
            result = 0;
        }
    }
    else if (row == 9)
    {
        bool is_2 = false; 
        bool is_3 = false; 

        for (int i = 1; i <= 6; i++)
        {
            int schow_number = 0;  
            for (int j = 0; j < 5; j++)
            {
                if (i == dice[j])
                {
                    schow_number++;
                }
            }
            if (schow_number == 2) is_2 = true;
            else if (schow_number == 3) is_3 = true;
        }

        if (is_2 == true && is_3 == true)
        {
            result = 24;
        }
        else
        {
             result = 0;
        }
    }
    else if (row == 10)
    {
        bool is_1 = false; 
        bool is_2 = false; 
        bool is_3 = false; 
        bool is_4 = false;
        bool is_5 = false; 
        bool is_6 = false; 

        bool is_ok = false; 

        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 1) is_1 = true;
            else if (dice[i] == 2) is_2 = true;
            else if (dice[i] == 3) is_3 = true;
            else if (dice[i] == 4) is_4 = true;
            else if (dice[i] == 5) is_5 = true;
            else if (dice[i] == 6) is_6 = true;
        }

        if (is_1 == true && is_2 == true && is_3 == true && is_4 == true) is_ok = true;
        else if (is_2 == true && is_3 == true && is_4 == true && is_5 == true) is_ok = true;
        else if (is_3 == true && is_4 == true && is_5 == true && is_6 == true) is_ok == true;

        if (is_ok == true)
        {
            result = 30;
        }
        else
        {
             result = 0;
        }
    }
    else if (row == 11)
    {
        bool is_1 = false; 
        bool is_2 = false; 
        bool is_3 = false; 
        bool is_4 = false; 
        bool is_5 = false; 
        bool is_6 = false; 

        bool is_ok = false; 

        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == 1) is_1 = true;
            else if (dice[i] == 2) is_2 = true;
            else if (dice[i] == 3) is_3 = true;
            else if (dice[i] == 4) is_4 = true;
            else if (dice[i] == 5) is_5 = true;
            else if (dice[i] == 6) is_6 = true;
        }

        if (is_1 == true && is_2 == true && is_3 == true && is_4 == true && is_5 == true) is_ok = true;
        else if (is_2 == true && is_3 == true && is_4 == true && is_5 == true && is_6 == true) is_ok = true;

        if (is_ok == true)
        {
            result = 40;
        }
        else
        {
        result = 0;
        }
    }
    else if (row == 12)
    {
        bool is_5 = false;

        for (int i = 1; i <= 6; i++)
        {
            int schow_number = 0; 
            for (int j = 0; j < 5; j++)
            {
                if (i == dice[j])
                {
                    schow_number++;
                }
            }
            if (schow_number == 5) is_5 = true;
        }

        if (is_5 == true)
        {
            result = 50;
        }
        else
        {
        result = 0;
        }
    }
    else if (row == 13)
    {
        for (int i = 0; i < 5; i++)
        {
            result = result + dice[i];
        }
    }

    players[player_number][row - 1] = result; 

    cout << "Wpisano do " << row << ": " << result << "pkt" << endl << endl << endl;
}


void round(int players[4][13], int player_number)
{
    int dice[5]; 
    write_table(players, player_number);

    cout << "Kosci gracza " << player_number + 1 << ":" << endl;
    dice_throw(dice);
    write_dice(dice);
    rethrow_round(dice);
    rethrow_round(dice);
    choose_row(players, player_number, dice);
}


void count_result(int players[4][13], int number_of_players)
{
    int players_result[4];
    for (int i = 0; i < number_of_players; i++)
    {
        int result = 0; 
        int up_result = 0; 
        for (int j = 0; j < 13; j++)
        {
            result = result + players[i][j];
        }
        
        for (int j = 0; j < 6; j++)
        {
            int up_result = 0;
            up_result = up_result + players[i][j];
        }
        if (up_result >= 63) result = result + 35;
        players_result[i] = result;

        cout << "Wynik gracza " << i + 1 << ": " << players_result[i] << endl;
    }

    
    int max_result = 0; 
    int winner; 
    for (int i = 0; i < number_of_players; i++)
    {
        if (players_result[i] > max_result)
        {
            max_result = players_result[i];
            winner = i;
        }
    }
    cout << "WYGRAL GRACZ NUMER " << winner + 1 << endl;
}
