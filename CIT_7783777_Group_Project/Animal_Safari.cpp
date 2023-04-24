#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <time.h>  // for time()
#include <fstream>
#include <ctype.h> // for toupper()

using namespace std;

int main()
{

    // Declaring variables for game
    string pNames[2];
    int num_Players = 0;
    int x = 0;
    int counting = 0;
    int i = 0;
    int player_Positions[2] = {0};
    string winner2[2] = {" ", " "};

    // Declaring variables for binoculars

    ifstream file("Binoculars.txt");
    string line;
    int animal_Count[2] = {0};
    int random_Line = 0;
    string line_store[26] = {" "};

    // Declaring variables for compass

    ifstream file2("Compass.txt");
    string line2;
    int random_Line2 = 0;
    string line_store2[21] = {""};

    // Displaying Screen

    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "                                   Welcome To Animal Safari                                         " << endl;
    cout << "                                 Play Safe And Win your Friends                                     " << endl;
    cout << "                     Game Creator: Shervin Elibox Designed By: Shervin Elibox                       " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << endl;
    cout << endl;

    // Prompt the User to Enter the Number of players Playing the Game

    cout << "NOTICE: Only two players can play at a time." << endl;
    cout << endl;
    cout << "Enter Number Of Players: ";
    cin >> num_Players;
    cout << endl;

    if (num_Players != 2)
    {

        // Sending an error message if a user exceeds the maxium anount of players
        cerr << "Only Two Players Can Play This Game At A Time" << endl;
        return 1;
    }

    // Declaring Player Answer
    string player_Answer[num_Players];

    while (x < num_Players)
    {
        cout << "Enter Player " << counting + 1 << " Name: ";
        cin >> pNames[x];
        cout << endl;

        // accumulator
        counting++;
        x++;
    }

    // clearing Screen
    system("CLS");

    srand(time(NULL));

    while (player_Positions[i] < 99)
    {

        for (i = 0; i < num_Players; i++)
        {

            for (int w = 0; w < num_Players; w++) // Wining Conditions
            {
                if (player_Positions[w] > 99 && animal_Count[w] < 5)
                {
                    // Resetting Players Positions IF Conditions are not Meet
                    cout << pNames[w] << " You have Made it to the 100th Position Without Collecting 5 Cards" << endl;
                    cout << endl;
                    cout << pNames[w] << " You Must Now Go Back 50 Spaces" << endl;

                    player_Positions[w] -= 50;
                }
                else if (player_Positions[w] >= 100 && animal_Count[w] >= 5)
                {
                    // Clearing Screen
                    system("CLS");

                    winner2[w] = pNames[w];

                    // Winner Message
                    cout << "###############################################################################" << endl;
                    cout << " ------------------------------------------------------------------------------" << endl;
                    cout << "|                                CONGRATULATIONS!!!                            |" << endl;
                    cout << " ------------------------------------------------------------------------------" << endl;
                    cout << "###############################################################################" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "Congratulations: " << winner2[w] << " You have won the Game" << endl;
                    cout << endl;

                    // Displaying the Animals the user Collected
                    cout << "You have collected: " << animal_Count[w] << " Animal cards" << endl;

                    string winner_name;
                    int animal_index = i;

                    if (w == 0)
                    {
                        // Displaying the name of the player who won
                        winner_name = winner2[w];
                        // Displaying the name of the player who lost
                        cout << endl;
                        cout << endl;
                        cout << "Better luck next time " << pNames[1] << ", you have lost." << endl;
                        cout << "You have collected: " << animal_Count[animal_index] << " Animal cards" << endl;
                    }
                    else
                    {
                        // Displaying the name of the player who won
                        winner_name = winner2[w];
                        cout << endl;
                        cout << endl;
                        cout << "Better luck next time " << pNames[0] << ", you have lost." << endl;
                        cout << "You have collected: " << animal_Count[animal_index] << " Animal cards" << endl;
                    }

                    cout << endl;
                    cout << endl;
                    cout << endl;

                    // GAME OVER Message
                    cout << "###############################################################################" << endl;
                    cout << " ------------------------------------------------------------------------------" << endl;
                    cout << "|                                   GAME OVER                                 |" << endl;
                    cout << " ------------------------------------------------------------------------------" << endl;
                    cout << "###############################################################################" << endl;
                    cout << endl;
                    cout << endl;

                    return 0;
                }
            }

            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << endl;
            cout << "Player Name:" << pNames[i] << " :Enter Go to Roll: ";
            cin >> player_Answer[i];
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << endl;

            // Convert player's answer to uppercase
            for (string::size_type k = 0; k < player_Answer[i].length(); k++)
            {
                player_Answer[i][k] = toupper(player_Answer[i][k]);
            }

            if (player_Answer[i] == "GO")
            {
                int roll = rand() % 6 + 1;
                player_Positions[i] += roll;

                if (player_Positions[i] >= 100) // setting player position if they pass 100
                {

                    player_Positions[i] = 100;
                }

                cout << pNames[i] << " rolled a " << roll << " and moved to position " << player_Positions[i] << endl;
                cout << endl;

                // Binoculars
                if (player_Positions[i] == 8 || player_Positions[i] == 13 || player_Positions[i] == 31 ||
                    player_Positions[i] == 47 || player_Positions[i] == 52 || player_Positions[i] == 67 ||
                    player_Positions[i] == 72 || player_Positions[i] == 87 || player_Positions[i] == 93)
                {
                    int j = 0;            // initialize separate index variable
                    int animal_index = i; // separate index variable for animal_Count

                    if (!file.is_open())
                    {
                        cerr << "Unable to open file" << endl;
                        return 1;
                    }
                    else
                    {
                        if (file.is_open())
                        {

                            while (getline(file, line))
                            {
                                line_store[j] += line;
                                j++; // used separate index variable
                            }

                            random_Line = rand() % 25;

                            cout << line_store[random_Line] << endl;

                            // Animal count
                            if ((random_Line % 2) == 0)
                            {
                                animal_Count[animal_index] += 1;
                            }
                            else
                            {
                                animal_Count[animal_index] += 2;
                            }
                        }

                        cout << endl;
                        // Displaying animal count
                        cout << "Number of animals in Your backpack is: " << animal_Count[animal_index] << endl;
                        cout << endl;
                    }
                }
                // Compass Cards
                else if (player_Positions[i] == 12 || player_Positions[i] == 17 || player_Positions[i] == 35 || player_Positions[i] == 51 || player_Positions[i] == 56 || player_Positions[i] == 71 || player_Positions[i] == 76 || player_Positions[i] == 91 || player_Positions[i] == 97)
                {
                    // Checking If Compass.txt Was Opened

                    if (!file2.is_open())
                    {

                        cerr << "Unable to Open file" << endl;
                        return 1;
                    }

                    int c = 0;
                    while (getline(file2, line2))
                    {

                        line_store2[c] += line2;
                        c++; // use separate index variable
                    }

                    random_Line2 = (rand() % 20);

                    cout << "---> " << line_store2[random_Line2] << endl;
                    cout << endl;
                    cout << endl;

                    // Nested IF STATEMENT FOR EACH COMPASS CONDITION

                    if (random_Line2 == 1 - 1) // Move forward 3 spaces.
                    {

                        player_Positions[i] += 3;
                    }
                    else if (random_Line2 == 2 - 1) // Move back 2 spaces.
                    {

                        player_Positions[i] -= 2;
                    }
                    else if (random_Line2 == 3 - 1) // Give one animal away to the other player.
                    {

                        if (i == 0 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] -= 1;
                            animal_Count[i + 1] += 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i + 1] << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] -= 1;
                            animal_Count[i - 1] += 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i - 1] << endl;
                        }
                    }

                    else if (random_Line2 == 4 - 1) // Move up 5 spaces
                    {

                        player_Positions[i] += 5;
                    }

                    else if (random_Line2 == 5 - 1) // Steal one animal from the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] += 1;
                            animal_Count[i + 1] -= 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i + 1] << " has no animals to steal " << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] += 1;
                            animal_Count[i - 1] -= 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i - 1] << " has no animals to steal " << endl;
                        }
                        else
                        {
                            cout << "Player " << i + 1 << " has no animals to give." << endl;
                        }
                    }

                    else if (random_Line2 == 6 - 1) // Move back 1 space.
                    {

                        player_Positions[i] -= 1;
                    }
                    else if (random_Line2 == 7 - 1) // Give two animals away to the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 2)
                        {

                            animal_Count[i] -= 2;
                            animal_Count[i + 1] += 2;
                        }
                        else if (i == 0 && animal_Count[i] == 1)
                        {
                            cout << pNames[i] << " has only 1 animals to give to " << pNames[i + 1] << endl;
                            animal_Count[i] -= 1;
                            animal_Count[i + 1] += 1;
                        }
                        else if (i == 0 && animal_Count[0] == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i + 1] << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 2)
                        {

                            animal_Count[i] -= 2;
                            animal_Count[i - 1] += 2;
                        }
                        else if (i == 1 && animal_Count[i] == 1)
                        {

                            cout << pNames[i] << " has only 1 animals to give to " << pNames[i - 1] << endl;
                            animal_Count[i] -= 1;
                            animal_Count[i - 1] += 1;
                        }
                        else if (i == 1 && animal_Count == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i - 1] << endl;
                        }
                    }
                    else if (random_Line2 == 8 - 1) // Move forward 2 spaces.
                    {

                        player_Positions[i] += 2;
                    }
                    else if (random_Line2 == 9 - 1) // Move back 3 spaces.
                    {

                        player_Positions[i] -= 3;
                    }
                    else if (random_Line2 == 10 - 1) // Steal two animals from the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 2)
                        {

                            animal_Count[i] += 2;
                            animal_Count[i + 1] -= 2;
                        }
                        else if (i == 0 && animal_Count[i] == 1)
                        {
                            cout << pNames[i + 1] << " has only one animal to steal" << endl;

                            animal_Count[i] += 1;
                            animal_Count[i + 1] -= 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i + 1] << " has no animal to steal" << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 2)
                        {

                            animal_Count[i] += 2;
                            animal_Count[i - 1] -= 2;
                        }
                        else if (i == 1 && animal_Count[i] == 1)
                        {
                            cout << pNames[i - 1] << " has only one animal to steal" << endl;

                            animal_Count[i] += 1;
                            animal_Count[i - 1] -= 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i - 1] << " has no animals to steal " << endl;
                        }
                        else
                        {

                            cout << "Player " << i + 1 << " has no animals to give." << endl;
                        }
                    }
                    else if (random_Line2 == 11 - 1) // Move forward 4 spaces.
                    {

                        player_Positions[i] += 4;
                    }
                    else if (random_Line2 == 12 - 1) // Give one animal away to the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] -= 1;
                            animal_Count[i + 1] += 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i + 1] << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 1)
                        {
                            animal_Count[i] -= 1;
                            animal_Count[i - 1] += 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i] << " has no animals to give to " << pNames[i - 1] << endl;
                        }
                    }
                    else if (random_Line2 == 13 - 1) // Move back 2 spaces.
                    {

                        player_Positions[i] -= 2;
                    }
                    else if (random_Line2 == 14 - 1) // Steal one animal from the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 1)
                        {

                            animal_Count[i] += 1;
                            animal_Count[i + 1] -= 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i + 1] << " has no animals to steal" << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 1)
                        {
                            animal_Count[i] += 1;
                            animal_Count[i - 1] -= 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i - 1] << " has no animals to steal" << endl;
                        }
                    }
                    else if (random_Line2 == 15 - 1) // Move 3 spaces forward
                    {

                        player_Positions[i] += 3;
                    }
                    else if (random_Line2 == 16 - 1) // Give three animals away to the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 3)
                        {
                            animal_Count[i] -= 3;
                            animal_Count[i + 1] += 3;
                        }
                        else if (i == 0 && animal_Count[i] == 2)
                        {
                            cout << pNames[i] << "  has only 2 animals to give to   " << pNames[i + 1] << endl;
                            animal_Count[i] -= 2;
                            animal_Count[i + 1] += 2;
                        }
                        else if (i == 0 && animal_Count[i] == 1)
                        {
                            cout << pNames[i] << "  has only 1 animals to give to  " << pNames[i + 1] << endl;
                            animal_Count[i] -= 1;
                            animal_Count[i + 1] += 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i + 1] << " has no animal to give " << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 3)
                        {
                            cout << pNames[i] << "  has only 2 animals to give to   " << pNames[i - 1] << endl;
                            animal_Count[i] -= 3;
                            animal_Count[i - 1] += 3;
                        }
                        else if (i == 1 && animal_Count[i] == 2)
                        {
                            cout << pNames[i] << "  has only 2 animals to give to   " << pNames[i - 1] << endl;
                            animal_Count[i] -= 2;
                            animal_Count[i - 1] += 2;
                        }
                        else if (i == 1 && animal_Count[i] == 1)
                        {
                            cout << pNames[i] << "  has only 2 animals to give to   " << pNames[i - 1] << endl;
                            animal_Count[i] -= 1;
                            animal_Count[i - 1] += 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i] << " has no animals to give " << pNames[i - 1] << endl;
                        }
                    }
                    else if (random_Line2 == 17 - 1) // Move back 1 space backwards.
                    {

                        player_Positions[i] -= 1;
                    }
                    else if (random_Line2 == 18 - 1) // Move forward 2 spaces.
                    {
                        player_Positions[i] += 2;
                    }
                    else if (random_Line2 == 19 - 1) // Steal one animal from the other player.
                    {
                        if (i == 0 && animal_Count[i] >= 1)
                        {
                            animal_Count[i] += 1;
                            animal_Count[i + 1] -= 1;
                        }
                        else if (i == 0 && animal_Count[i] == 0)
                        {

                            cout << pNames[i + 1] << " has no animals to steal" << endl;
                        }
                        else if (i == 1 && animal_Count[i] >= 1)
                        {
                            animal_Count[i] += 1;
                            animal_Count[i - 1] -= 1;
                        }
                        else if (i == 1 && animal_Count[i] == 0)
                        {

                            cout << pNames[i - 1] << " has no animals to steal" << endl;
                        }
                    }
                    else if (random_Line2 == 20 - 1) // Move back 4 spaces.
                    {
                        player_Positions[i] -= 4;
                    }
                }
            }
        }

        // Player positions  and animal count after rolling the dice.
        for (i = 0; i < num_Players; i++)
        {
            int animal_index = i;
            cout << "Player Name: " << pNames[i] << " Your New Position is: " << player_Positions[i] << endl;
            cout << "Animal Count: " << animal_Count[animal_index] << endl;
        }
    }

    // Closing files
    file.close();
    file2.close();

    return 0;
}
