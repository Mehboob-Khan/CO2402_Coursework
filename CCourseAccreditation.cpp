#include "CCourseAccreditation.h"
#include <string>
#include "CTable.h"

// Constructor that initializes the card properties by calling the base class constructor
CCourseAccreditation::CCourseAccreditation(istream& file) : CCard(file)
{
}

// Function that attacks the enemy's cohort and the professor
void CCourseAccreditation::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    // if (!enemy) return;  // Check if enemy pointer is null, and return if it is

    const shared_ptr<CTable> enemyTable = enemy->GetTable();  // Get the enemy's table

    // if (!enemyTable) return;  // Check if enemyTable pointer is null, and return if it is


    // Attacking the entire enemy cohort
    for (const auto& card : enemyTable->mTable)
    {
        if (!card) continue;  // Check if card pointer is null, and skip to next iteration if it is

        const int damage = card->GetCardResilience() - this->GetCardPower();  // Calculate the damage to the card
        card->SetCardResilience(damage);  // Reduce the card's resilience by the damage amount

        // Determine if the card is defeated or if its resilience has changed
        string resultMsg = (damage <= 0) ? " is defeated. " : "'s resilience is " + to_string(card->GetCardResilience());

        cout << this->GetCardName() << " attacks " << card->GetCardName() << ". ";
        cout << card->GetCardName() << resultMsg << endl;

        if (damage <= 0) enemyTable->EraseCard(card);  // Remove the card from the table if its resilience is <= 0
    }

    // Attacks the professor
    const int professorDamage = enemy->GetPrestige() - this->GetCardPower();  // Calculate the damage to the professor
    enemy->SetPrestige(professorDamage);  // Reduce the professor's prestige by the damage amount

    cout << this->GetCardName() << " attacks " << enemy->GetName() << ". ";
    cout << enemy->GetName() << "'s resilience is " << enemy->GetPrestige() << endl;
}

// Function that is called when the card is played by a player
void CCourseAccreditation::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetCardName() << endl;

    // Activating the AttackEnemy function
    AttackEnemy(player, enemy);

    // Removes the card from the table
    player->DeleteCard(shared_from_this());
}

// Destructor for the card class
CCourseAccreditation::~CCourseAccreditation() = default;