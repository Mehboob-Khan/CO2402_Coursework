#include "CFeedbackForum.h"
#include "CPlayer.h"
#include "CTable.h"

// Constructor that initializes the card properties by calling the base class constructor and reading in the boost value from the file
CFeedbackForum::CFeedbackForum(istream& file) : CCard(file)
{
    file >> mBoost;
}

// Overloaded stream extraction operator that reads in the card properties from the file
istream& operator>>(istream& file, CFeedbackForum& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mBoost;
    card.mName += (" " + card.mSecondName);
    return file;
}

// Function that attacks the enemy's card or prestige
void CFeedbackForum::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    const shared_ptr<CTable> playerTable = player->GetTable();

    const shared_ptr<CTable> opponentTable = opponent->GetTable();

    // Get the number of cards on the player's table
    const int playerCount = playerTable->mTable.size() + 1; // +1 for the player

    // Get the number of cards on the opponent's table
    const int opponentCount = opponentTable->mTable.size() + 1; // +1 for the opponent

    // total number of potential targets
    const int sum = playerCount + opponentCount;

    // Generates a random number to pick a target
    int random = player->Random(sum);

    // Determine the target (player or card)
    const bool isPlayerTarget = random < playerCount;

    // Assigning playerTarget to random
    random = isPlayerTarget ? random : random - playerCount;

    shared_ptr<CCard> card = nullptr;
    const shared_ptr<CPlayer> target = isPlayerTarget ? player : opponent;
    const shared_ptr<CTable> targetTable = isPlayerTarget ? playerTable : opponentTable;

    // If the random number is less than the number of cards on the target's table,
    // then the target is a card. Otherwise, the target is the opponent.
    if (random < targetTable->mTable.size()) {
        card = targetTable->mTable[random];
    }

    // Get the target value
    const int targetValue = card ? card->GetCardResilience() : target->GetPrestige();

    // Calculate the updated value
    const int updatedValue = isPlayerTarget ? targetValue + this->GetBoost() : targetValue - this->GetBoost();

    // If the target is a card, set its resilience to the updated value.
    // Otherwise, set the opponent's prestige to the updated value.
    if (card) {
        card->SetCardResilience(updatedValue);
    }
    else {
        target->SetPrestige(updatedValue);
    }


    // Output

    cout << this->GetCardName() << " ";
    cout << (isPlayerTarget ? "boosts " : "attacks ");
    cout << (card ? card->GetCardName() : target->GetName()) << ". ";

    if (!isPlayerTarget && card && card->GetCardResilience() <= 0)
    {
        cout << card->GetCardName() << " is defeated" << endl;
        targetTable->EraseCard(card); // Removes the defeated card.
    }
    else
    {
        cout << (card ? card->GetCardName() : target->GetName());
        cout << (card ? "'s resilience" : "'s prestige");
        cout << " is now " << updatedValue << endl;
    }
}


// Function that is called when the card is played by a player
void CFeedbackForum::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card from the hand
    cout << player->GetName() << " plays " << this->mName << endl;

    // Attack the enemy
    AttackEnemy(player, opponent);

    // Delete the card from the hand
    player->DeleteCard(shared_from_this());
}


// Function that is called when the card is played by a player
void CFeedbackForum::SetCardResilience(int resilience)
{
    mResilience = resilience;
}

int CFeedbackForum::GetBoost() const
{
    return mBoost;
}


int CFeedbackForum::GetCardResilience() const
{
    return mResilience;
}

CFeedbackForum::~CFeedbackForum()
= default;
