// This is attempt 6 of animal safari code.
// It does not contain vectors or any functions that were not specified
// Animal count will no longer be an array
// Mod statement will be fixes

// Date: 20/04/2023

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Declaring object
    ifstream file1("Binoculars.txt");
    ifstream file2("Compass.txt");

    // Declaring variables for main game
    int const MAX_PLAYERS = 2;
    int const MAX_POSITIONS = 100;
    int num_Players = 0;
    int i = 0, b = 0, c = 0;
    int roll_Prompt = 0;
    int dice = 0;
    int position[2] = {0};
    string name[2] = {" "};
    srand(time(NULL)); // random number
    string winner = " ";
    int w = 0;

    // Declaring variables for binoculars cards
    string line = " ";
    string line_Store1[26] = {" "};
    // int i = 0;                        //cannot be declared twice, but will be used in Binoculars code as well
    int random_Binoculars = 0;
    int animal_Count[2] = {0};
    // srand(time(NULL));                   //random number

    // Declaring variables for compass cards
    string line2 = " ";
    string line_Store2[21] = {" "};
    // int i = 0;
    int random_Compass = 0;
    // srand(time(NULL));                   //random number

    // Game Introduction
    cout << "**********************************************" << endl;
    cout << " --------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << "|         Welcome To Animal Safari           |" << endl;
    cout << "|                                            |" << endl;
    cout << "|       Created by: Kdi Dornelly             |" << endl;
    cout << "|                   Annalyn Hassell          |" << endl;
    cout << "|                   Mindy Brandford          |" << endl;
    cout << "|                                            |" << endl;
    cout << " --------------------------------------------" << endl;
    cout << "**********************************************" << endl;

    cout << endl;

    // Telling players maximum number of players
    cout << "Only 2 players can play this game." << endl;
    cout << endl;
    // Prompt and accept names of players in for loop

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        cout << "Enter the name of player " << i + 1 << ": ";
        cin >> name[i];
        num_Players++;
    }

    // resetting variable i
    i = 0;

    // clearing the screen
    system("CLS");

    // Game Begins
    cout << "##############################################" << endl;
    cout << " --------------------------------------------" << endl;
    cout << "|                  GAME TIME                 |" << endl;
    cout << " --------------------------------------------" << endl;
    cout << "##############################################" << endl;
    cout << endl;
    cout << endl;

    // Dice roll and position update before main loop
    while (i < num_Players)
    {
        cout << name[i] << ", enter '0' to roll the dice: ";
        cin >> roll_Prompt;

        // random generation of dice number
        dice = (rand() % 6) + 1;
        position[i] += dice;

        cout << "You rolled a " << dice << ".  Move to position " << position[i] << " on game board." << endl;
        cout << endl;

        i++;
    }

    // resetting variable i
    i = 0;

    // clear screen
    // system("CLS");

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // position update
    while (i < num_Players)
    {

        cout << name[i] << " is at position " << position[i] << endl;
        cout << endl;
        i++;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    // resetting variable i
    i = 0;

    // while position... main loop
    while (position[i] < MAX_POSITIONS)
    {
        for (i = 0; i < num_Players; i++)
        {
            // Check if player has won
            for (int w = 0; w < num_Players; w++)
            {

                if (position[w] >= 99 && animal_Count[w] >= 5)
                {
                    winner = name[w];
                    cout << "Congratulations " << winner << "!     You have won!" << endl;
                }

                // Check if player has reached 100 without 5 animals
                else if (position[i] >= MAX_POSITIONS && animal_Count[i] < 5)
                {
                    cout << name[i] << " reached 100 without 5 animals :( \nGo back to 50." << endl;
                    position[i] -= 50;
                }

                w++;
            }
        }

        cout << name[i] << ", enter '0' to roll the dice: ";
        cin >> roll_Prompt;

        // random generation of dice number
        dice = (rand() % 6) + 1;
        position[i] += dice;

        cout << "You rolled a " << dice << ". Move to position " << position[i] << " on game board." << endl;
        cout << endl;

        // Binoculars Code begins here

        if ((position[i] == 8) || (position[i] == 13) || (position[i] == 31) || (position[i] == 47) || (position[i] == 52) || (position[i] == 67) || (position[i] == 72) || (position[i] == 87) || (position[i] == 93))
        {
            // Checking if file is opened and getting line

            if (file1.is_open())
            {
                while (getline(file1, line))
                {
                    // the line store variable will
                    line_Store1[b] += line;
                    b++;
                }

                random_Binoculars = (rand() % 26);

                cout << "    --> " << line_Store1[random_Binoculars] << endl;

                // Animal count
                if ((random_Binoculars % 2) == 0)
                {
                    animal_Count[i] += 1;
                }
                else
                {
                    animal_Count[i] += 2;
                }
                // Displaying animal count
                cout << "    --> Number of animals in backpack: " << animal_Count[i] << endl;
                cout << endl;
                cout << endl;

            } // end if

            // Error opening file
            else
            {
                cout << "Error opening file." << endl;
            }

        } // end if

        // for compass
        else if ((position[i] == 12) || (position[i] == 17) || (position[i] == 35) || (position[i] == 51) || (position[i] == 56) || (position[i] == 71) || (position[i] == 76) || (position[i] == 91) || (position[i] == 97))
        {
            // Check if file is open
            if (file2.is_open())
            {
                while (getline(file2, line2))
                {
                    line_Store2[c] += line2;
                    c++;
                }

                random_Compass = (rand() % 20);

                // cout<< "Random line number: " << random_Compass + 1 << endl;
                cout << "    --> " << line_Store2[random_Compass] << endl;
                cout << endl;
                cout << endl;

                // Coding instructions
                if (random_Compass == 1 - 1) // Move forward 3 spaces.
                {
                    position[i] += 3;
                }
                else if (random_Compass == 2 - 1) // Move back 2 spaces.
                {
                    position[i] -= 2;
                }
                else if (random_Compass == 3 - 1) // Give one animal away to the other player.
                {
                    if (i == 0 && animal_Count[i] >= 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i + 1] += 1;
                    }
                    else if (i == 1 && animal_Count[i] >= 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i - 1] += 1;
                    }
                }
                else if (random_Compass == 4 - 1) // Move forward 5 spaces.
                {
                    position[i] += 5;
                }
                else if (random_Compass == 5 - 1) // Steal one animal from the other player.
                {
                    if (i == 0 && animal_Count[i + 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i + 1] -= 1;
                    }
                    else if (i == 1 && animal_Count[i - 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i - 1] -= 1;
                    }
                }
                else if (random_Compass == 6 - 1) // Move back 1 space.
                {
                    position[i] -= 1;
                }
                else if (random_Compass == 7 - 1) // Give two animals away to the other player.
                {
                    if (i == 0 && animal_Count[i] >= 2)
                    {
                        animal_Count[i] -= 2;
                        animal_Count[i + 1] += 2;
                    }
                    else if (i == 0 && animal_Count[i] == 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i + 1] += 1;
                    }
                    else if (i == 1 && animal_Count[i] >= 2)
                    {
                        animal_Count[i] -= 2;
                        animal_Count[i - 1] += 2;
                    }
                    else if (i == 1 && animal_Count[i] == 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i - 1] += 1;
                    }
                }
                else if (random_Compass == 8 - 1) // Move forward 2 spaces.
                {
                    position[i] += 2;
                }
                else if (random_Compass == 9 - 1) // Move back 3 spaces.
                {
                    position[i] -= 3;
                }
                else if (random_Compass == 10 - 1) // Steal two animals from the other player.
                {
                    if (i == 0 && animal_Count[i + 1] >= 2)
                    {
                        animal_Count[i] += 2;
                        animal_Count[i + 1] -= 2;
                    }
                    else if (i == 0 && animal_Count[i + 1] == 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i + 1] -= 1;
                    }
                    else if (i == 1 && animal_Count[i - 1] >= 2)
                    {
                        animal_Count[i] += 2;
                        animal_Count[i - 1] -= 2;
                    }
                    else if (i == 1 && animal_Count[i - 1] == 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i - 1] -= 1;
                    }
                }
                else if (random_Compass == 11 - 1) // Move forward 4 spaces.
                {
                    position[i] += 4;
                }
                else if (random_Compass == 12 - 1) // Give one animal away to the other player.
                {
                    if (i == 0 && animal_Count[i] >= 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i + 1] += 1;
                    }
                    else if (i == 1 && animal_Count[i] >= 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i - 1] += 1;
                    }
                }
                else if (random_Compass == 13 - 1) // Move back 2 spaces.
                {
                    position[i] -= 2;
                }
                else if (random_Compass == 14 - 1) // Steal one animal from the other player.
                {
                    if (i == 0 && animal_Count[i + 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i + 1] -= 1;
                    }
                    else if (i == 1 && animal_Count[i - 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i - 1] -= 1;
                    }
                }
                else if (random_Compass == 15 - 1) // Move forward 3 spaces.
                {
                    position[i] += 3;
                }
                else if (random_Compass == 16 - 1) // Give three animals away to the other player.
                {
                    if (i == 0 && animal_Count[i] >= 3)
                    {
                        animal_Count[i] -= 3;
                        animal_Count[i + 1] += 3;
                    }
                    else if (i == 0 && animal_Count[i] == 2)
                    {
                        animal_Count[i] -= 2;
                        animal_Count[i + 1] += 2;
                    }
                    else if (i == 0 && animal_Count[i] == 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i + 1] += 1;
                    }
                    else if (i == 1 && animal_Count[i] >= 3)
                    {
                        animal_Count[i] -= 3;
                        animal_Count[i - 1] += 3;
                    }
                    else if (i == 1 && animal_Count[i] == 2)
                    {
                        animal_Count[i] -= 2;
                        animal_Count[i - 1] += 2;
                    }
                    else if (i == 1 && animal_Count[i] == 1)
                    {
                        animal_Count[i] -= 1;
                        animal_Count[i - 1] += 1;
                    }
                }
                else if (random_Compass == 17 - 1) // Move back 1 space.
                {
                    position[i] -= 1;
                }
                else if (random_Compass == 18 - 1) // Move forward 2 spaces.
                {
                    position[i] += 2;
                }
                else if (random_Compass == 19 - 1) // Steal one animal from the other player.
                {
                    if (i == 0 && animal_Count[i + 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i + 1] -= 1;
                    }
                    else if (i == 1 && animal_Count[i - 1] >= 1)
                    {
                        animal_Count[i] += 1;
                        animal_Count[i - 1] -= 1;
                    }
                }
                else if (random_Compass == 20 - 1) // Move back 4 spaces.
                {
                    position[i] -= 4;
                }

            } // end if

            // Error opening file
            else
            {
                cout << "Error opening file." << endl;
            }

        } // end if

    } // end for

    i = 0;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    while (i < num_Players)
    {
        cout << name[i] << " is at position " << position[i] << endl;
        cout << name[i] << " has " << animal_Count[i] << " animals" << endl;
        cout << endl;
        i++;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    i = 0;

    // end while

    // Ending game if there is a winner
    if (winner == name[i])
    {
        cout << "Better luck next time " << name[i + 1] << "!     You have lost!" << endl;
    }
    else
    {
        cout << "Better luck next time " << name[i] << "!     You have lost!" << endl;
    }

    // Closing files

    file1.close();

    file2.close();

    return 0;
}

