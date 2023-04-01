#include "CPassLeader.h"

void CPassLeader::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
	const shared_ptr<CTable> enemyTable = enemy->GetTable();
	const int damage = GetCardPower();

    // If the enemy student card doesn't exist
    if (enemyTable->mTable.empty())
    {
        enemy->SetPrestige(enemy->GetPrestige() - damage);
        cout << GetCardName() << " attacks " << enemy->GetName() << ". ";
    }
    else // enemy student card exists
    {
	    const int randomIndex = player->Random(enemyTable->mTable.size());
        // Get random enemy card
	    const shared_ptr<CCard> randomEnemyCard = enemyTable->mTable[randomIndex];

	    const int newResilience = randomEnemyCard->GetCardResilience() - damage;
        randomEnemyCard->SetCardResilience(newResilience);

        cout << GetCardName() << " attacks " << randomEnemyCard->GetCardName() << ". ";

        if (newResilience <= 0)
        {
            cout << randomEnemyCard->GetCardName() << " is defeated." << endl;
            enemyTable->EraseCard(randomEnemyCard);
        }
        else
        {
            cout << randomEnemyCard->GetCardName() << "'s resilience is now " << newResilience << endl;
        }
    }

    cout << enemy->GetName() << "'s prestige is now " << enemy->GetPrestige() << endl;
}



void CPassLeader::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    const shared_ptr<CTable> table = player->GetTable();
    table->PlaceCardOnTop(shared_from_this());
    GetTotalPassLeadersOnTable(table);
    SetPowerIncrement(table);

    cout << player->GetName() << " plays " << GetCardName() << endl;
    cout << "There is now " << GetCardCount() << " Pass Leader card on the table, with power " << GetCardPower() << endl;

    player->DeleteCard(shared_from_this());
}


int CPassLeader::GetTotalPassLeadersOnTable(shared_ptr<CTable> table)
{
    // Calculate total pass leaders on table 
    mCardCount = 0;
    for (const auto& card : table->mTable)
    {
        if (dynamic_pointer_cast<CPassLeader>(card) != nullptr)
        {
            mCardCount++;
        }
    }
    return mCardCount;
}


void CPassLeader::SetPowerIncrement(shared_ptr<CTable> table)
{
    this->mPower = this->mCardCount * this->mPowerIncrement;
    for (const auto& card : table->mTable) {
        if (card->GetCardName() == this->GetCardName()) {
            card->SetCardPower(this->mPower);
        }
    }
}

CPassLeader::CPassLeader(istream& file) : CCard(file)
{
    file >> mResilience >> mPowerIncrement;
}

// Operator overloading 
istream& operator>>(istream& file, CPassLeader& card)
{

    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mPowerIncrement;
    card.mName += (" " + card.mSecondName);
    return file;
}


// Setters and getters
void CPassLeader::SetCardResilience(int resilience) { mResilience = resilience; }
void CPassLeader::SetCardPower(int power) { mPower = power; }
string CPassLeader::GetCardName() { return mName; }
int CPassLeader::GetCardPower() { return mPower; }
int CPassLeader::GetCardResilience() const { return mResilience; }
int CPassLeader::GetPowerIncrement() const { return mPowerIncrement; }
int CPassLeader::GetCardCount() const { return mCardCount; }

CPassLeader::~CPassLeader() = default;
