// Name: Mehboob Arif Khan Kousar
// Student ID: 20940379 / CE

#include <memory>
#include <cstdlib>
#include <crtdbg.h>
#include "CCardDeckLoader.h"
#include "CGame.h"
#include "CPlayer.h"

// Define memory allocation mapping
#define CRTDBG_MAP_ALLOC

using namespace std;

int main()
{
    {
        // Load card decks from files
        const auto profPlagiaristFile = make_shared<CCardDeckLoader>("plagiarist.txt");
        const auto profPifflePaperFile = make_shared<CCardDeckLoader>("piffle-paper.txt");
        const auto seedNumberFile = make_shared<CCardDeckLoader>("seed.txt");
        const auto profPointlessFile = make_shared<CCardDeckLoader>("pointless.txt");
        const auto profPerditionFile = make_shared<CCardDeckLoader>("perdition.txt");

        // Create professor players
        int prestige = 30;
        const auto profPlagiarist = make_shared<CPlayer>("Plagiarist", prestige, profPlagiaristFile->GetCards());
        const auto profPifflePaper = make_shared<CPlayer>("Piffle-paper", prestige, profPifflePaperFile->GetCards());
        const auto profPointless = make_shared<CPlayer>("Pointless", prestige, profPointlessFile->GetCards());
        const auto profPerdition = make_shared<CPlayer>("Perdition", prestige, profPerditionFile->GetCards());

        // Initialize random seed
        srand(seedNumberFile->GetSeedNumber());

        // Set up game parameters
        // const int maxRounds = 30;
        CGame game;
        game.AddPlayer(profPlagiarist);
        game.AddPlayer(profPifflePaper);
        game.AddPlayer(profPointless);
        game.AddPlayer(profPerdition);


        // Initialize and play game
        // game.Initialize(seedNumberFile->GetSeedNumber(), prestige);
        game.Play();

    }

    // Check for memory leaks
    _CrtDumpMemoryLeaks();
}
