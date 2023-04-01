#include "CIndustrialistPlacement.h"

#include "CPlayer.h"
#include "CTable.h"

void CIndustrialistPlacement::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
	const shared_ptr<CTable> enemyTable = enemy->GetTable();

    if (enemyTable->mTable.empty()) // if the enemy student card doesn't exist
    {
	    const int damage = this->GetCardPower();
        enemy->SetPrestige(enemy->GetPrestige() - damage);

        cout << this->GetCardName() << " attacks " << enemy->GetName() << ". ";
        cout << enemy->GetName() << "'s prestige is now " << enemy->GetPrestige() << endl;
    }
    else // enemy student card exists
    {
	    const int randomIndex = player->Random(enemyTable->mTable.size());
	    const shared_ptr<CCard> randomEnemyCard = enemyTable->mTable[randomIndex];


	    const int damage = this->GetCardPower();
	    const int newResilience = randomEnemyCard->GetCardResilience() - damage;
        randomEnemyCard->SetCardResilience(newResilience);

        if (newResilience <= 0)
        {
            cout << this->GetCardName() << " attacks " << randomEnemyCard->GetCardName() << ". ";
            cout << randomEnemyCard->GetCardName() << " is defeated." << endl;

            enemyTable->EraseCard(randomEnemyCard);
        }
        else
        {
            cout << this->GetCardName() << " attacks " << randomEnemyCard->GetCardName() << ". ";
            cout << randomEnemyCard->GetCardName() << "'s resilience is now " << newResilience << endl;
        }
    }

    //Boosting the resilience
    this->mResilience += mBoost;
    cout << this->mName << " boosts its resilience " << ". ";
    cout << this->mName << "'s resilience is now " << this->mResilience << endl;
}

void CIndustrialistPlacement::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetCardName() << endl;

    // Plays the card to the table
    const shared_ptr<CTable> table = player->GetTable();
    table->PlaceCardOnTop(shared_from_this());

    // Deletes the card from the table
    player->DeleteCard(shared_from_this());
}



int CIndustrialistPlacement::GetCardResilience() const
{
    return mResilience;
}

CIndustrialistPlacement::CIndustrialistPlacement(istream& file) : CCard(file)
{
    file >> mResilience >> mBoost;
}

istream& operator>>(istream& file, CIndustrialistPlacement& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mBoost;
    card.mName += (" " + card.mSecondName);
    return file;
}


CIndustrialistPlacement::~CIndustrialistPlacement()
= default;

void CIndustrialistPlacement::SetCardResilience(int resilience)
{
    mResilience = resilience;
}
