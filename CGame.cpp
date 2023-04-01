// CGame.cpp
#include "CGame.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

// Constructor that initializes the game
CGame::CGame() : mMaxRounds(30), mCurrentRound(0) {}

// Destructor for the game
CGame::~CGame() = default;


void CGame::AddPlayer(const shared_ptr<CPlayer>& player) {
    // Players are added to the mActivePlayers vector
    mActivePlayers.push_back(player);
}


// Function that initializes the game with the specified parameters
//void CGame::Initialize(int seed,int initialPrestige)
//{
//    srand(seed);  // Seed the random number generator
//    // mMaxRounds = maxRounds;  // Set the maximum number of rounds
//
//    // for loop initializes the prestige for each players
//    for (const auto player : mActivePlayers)
//    {
//        player->SetPrestige(initialPrestige);
//    }
//}

// Function that starts the game
void CGame::Play()
{
    cout << "Welcome to U-Can't. Let the winnowing begin... \n" << endl;

    while (mCurrentRound <= mMaxRounds && mActivePlayers.size() > 1) {
        PlayRound();
    }

    DisplayWinner();  // Display the winner of the game
}

// Function that plays a round of the game
void CGame::PlayRound()
{
    if (mCurrentRound == 0)  // On the first round...
    {
        // Drawing the cards for all players at the start of the game
        for (const auto player : mActivePlayers)
        {
            player->DrawCard();  // Draw a card for each player
        }
    }
    else  // On subsequent rounds...
    {
        cout << "ROUND " << mCurrentRound << endl;
        cout << "=========" << endl << endl;

        for (int i = 0; i < mActivePlayers.size(); ++i)// It goes through each player
        {
            shared_ptr<CPlayer> prof = mActivePlayers[i]; // 

            // Drawing the cards for the current player
            prof->DrawCard();

            // Plays the card for the current player against the opponent.
            int currentPlayer = i;  // Already have index from the loop
            int nextIndex = (currentPlayer + 1) % mActivePlayers.size();  // Get the index of the next player
            const shared_ptr<CPlayer> enemy = mActivePlayers[nextIndex];  // Get the next player as the enemy

            prof->PlayCard(prof, enemy);  // Play a card for the current player against the enemy


        	// Check if opponent is sacked and update player vector accordingly
            shared_ptr<CPlayer> sackedPlayer = enemy->GetSacked();  // Check if the enemy player is sacked
            if (sackedPlayer != nullptr)
            {
                mDefeatedPlayers.push_back(sackedPlayer);  // Add the sacked player to the defeated player vector
                cout << endl << sackedPlayer->GetName() << " has no prestige and is sacked!" << endl << endl;
                mActivePlayers.erase(find(mActivePlayers.begin(), mActivePlayers.end(), sackedPlayer));  // Remove the sacked player from the active player vector

            }

            // Check if there is only one player left and end the game if so
            if (mActivePlayers.size() == 1)
            {
                break;
            }
        }


    }

    mCurrentRound++; // Goes to the next round
}


// Function that displays the prestige of all defeated players
void CGame::DisplaySackedPlayers() const
{
    for (const auto prof : mDefeatedPlayers)
    {
        cout << prof->GetName() << "'s prestige is " << prof->GetPrestige() << endl;  // Display the player's name and prestige
    }
}

// Function that displays the winner of the game
void CGame::DisplayWinner() const
{
    cout << "Game Over" << endl;
    cout << "=========" << endl;
    const shared_ptr<CPlayer> player = mActivePlayers[0];  // Get the winning player
    cout << player->GetName() << "'s prestige is " << player->GetPrestige() << endl;  // Display the winning player's name and prestige

    DisplaySackedPlayers();  // Display the prestige of all defeated players

    cout << endl;
    cout << player->GetName() << " wins! " << endl;  // Display the name of the winning player
}

