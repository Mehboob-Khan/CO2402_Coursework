#include "CPlagiaristHearing.h"
#include <string>
#include "CPlayer.h"

void PlagiaristHearing::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) {


    const shared_ptr<CTable> enemyTable = enemy->GetTable();
    const int enemyTableSize = enemyTable->mTable.size();

    // Generate a random number to decide which card (or the enemy directly) will be attacked
    const int randomIndex = player->Random(enemyTableSize + 1);

    // If the random number corresponds to a card on the enemy's table:
    if (randomIndex < enemyTableSize) {

        //Determine the damage based on the resilience of the targeted enemy card and the power of the PlagiaristHearing card
        const auto enemyCard = enemyTable->mTable[randomIndex];
        const int damage = enemyCard->GetCardResilience() - this->GetCardPower();

        damage <= 0 ? enemyTable->EraseCard(enemyCard) : enemyCard->SetCardResilience(damage);

        // Print the result of the attack on the enemy card
        cout << this->GetCardName() << " attacks " << enemyCard->GetCardName() << ". ";
        cout << (damage <= 0 ? " is defeated." : "'s resilience is now " + to_string(enemyCard->GetCardResilience())) << endl;
    }
    // If the random number doesn't correspond to any card on the enemy's table:
    else {

        // The PlagiaisrtHearing card attacks the enemy player directly, reducing the enemy's prestige
        const int damage = enemy->GetPrestige() - this->GetCardPower();
        enemy->SetPrestige(damage);

        // Print the result of the direct attack on the enemy player
        cout << this->GetCardName() << " attacks " << enemy->GetName() << ". ";
        cout << enemy->GetName() << "'s prestige is now " << enemy->GetPrestige() << endl;
    }
}

void PlagiaristHearing::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) {

    // Announce the playing of this card
    cout << player->GetName() << " plays " << this->GetCardName() << endl;

    // Launch an attack on the enemy
    AttackEnemy(player, enemy);

    // Remove this card from the player's set
    player->DeleteCard(shared_from_this());
}


// Constructor that initializes from a file
PlagiaristHearing::PlagiaristHearing(istream& file) : CCard(file) {}

PlagiaristHearing::~PlagiaristHearing() = default;
