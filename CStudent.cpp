#include "CStudent.h"
#include "CPlayer.h"
#include "CTable.h"

void CStudent::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    const shared_ptr<CTable> enemyTable = enemy->GetTable();  // Get a shared pointer to the enemy player's table

    if (enemyTable->mTable.empty())  // If the enemy player's table is empty
    {
        const int attackDamage = this->GetCardPower();  // Get the card's power
        enemy->SetPrestige(enemy->GetPrestige() - attackDamage);  // Reduce the enemy player's prestige by the card's power

        // Display a message indicating the attack and the updated prestige value
        cout << this->GetCardName() << " attacks " << enemy->GetName() << ". ";
        cout << enemy->GetName() << "'s prestige is now " << enemy->GetPrestige() << endl;
    }
    else  // If the enemy player's table is not empty
    {
        const int randomIndex = player->Random(enemyTable->mTable.size());  // Choose a random index in the enemy player's table
        const auto randomEnemyCard = enemyTable->mTable[randomIndex];  // Get a shared pointer to the card at the random index

        const int attackDamage = this->GetCardPower();  // Get the card's power
        const int newResilience = randomEnemyCard->GetCardResilience() - attackDamage;  // Calculate the new resilience of the enemy card
        randomEnemyCard->SetCardResilience(newResilience);  // Set the new resilience of the enemy card

        if (newResilience <= 0)  // If the enemy card's resilience is now zero or negative
        {
            // Display a message indicating the attack, the defeated card, and remove the card from the enemy player's table
            cout << this->GetCardName() << " attacks " << randomEnemyCard->GetCardName() << ". ";
            cout << randomEnemyCard->GetCardName() << " is defeated." << endl;
            enemyTable->EraseCard(randomEnemyCard);
        }
        else  // If the enemy card's resilience is still positive
        {
            // Display a message indicating the attack and the updated resilience value of the enemy card
            cout << this->GetCardName() << " attacks " << randomEnemyCard->GetCardName() << ". ";
            cout << randomEnemyCard->GetCardName() << "'s resilience is now " << newResilience << endl;
        }
    }
}

// Function that plays the card
void CStudent::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    cout << player->GetName() << " plays " << this->GetCardName() << endl;
    const shared_ptr<CTable> table = player->GetTable();
    table->PlaceCardOnTop(shared_from_this());
    player->DeleteCard(shared_from_this());
}


// Setter function that sets the resilience of the card
void CStudent::SetCardResilience(int resilience)
{
    mResilience = resilience;  // Set the card's resilience to the specified value
}

// Constructor that reads data from a file stream and initializes the card's properties
CStudent::CStudent(istream& file) : CCard(file)
{
    file >> mResilience;  // Read the card's resilience from the file
}


int CStudent::GetCardResilience() const
{
    return mResilience;
}

string CStudent::GetCardName()
{
    return mName;
}

istream& operator>>(istream& file, CStudent& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience;
    card.mName += (" " + card.mSecondName);
    return file;
}
