#include "CTable.h"

CTable::CTable() = default;

// Function to place a given card on the top of the table
void CTable::PlaceCardOnTop(CardPtr card)
{
    // Create a temporary vector to hold the new order of cards
    CardVector temp;

    // Place the new card at the beginning of the temporary vector
    temp.push_back(card);

    // Print a debug message indicating the card is being added
    cout << "Adding card: " << card->GetCardName() << " to table." << endl;

    // Add the cards already on the table to the temporary vector
    for (const auto& element : mTable)
    {
        temp.push_back(element);
    }

    // Replace the original table with the new order of cards
    mTable = temp;
}

// Function to erase a specific card from the table
void CTable::EraseCard(shared_ptr<CCard> card)
{
    // Search for the given card in the table
    const auto it = find(mTable.begin(), mTable.end(), card);

    // If the card is found
    if (it != mTable.end())
    {
        // Print a debug message indicating the card is being removed
        cout << "Removing card: " << card->GetCardName() << " from table." << endl;

        // Remove the card from the table
        mTable.erase(it);
    }
    // If the card is not found
    else
    {
        // Print a debug message indicating the card was not found
        cout << "Card not found: " << card->GetCardName() << " in table." << endl;
    }
}

// Function trigger each card's attack based on enemy's prestige
void CTable::TriggerCards(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) const
{
    for (const auto& i : mTable)
    {
        // If enemy's prestige is 1 or more, trigger the card's attack. Otherwise, do nothing.
        (enemy->GetPrestige() >= 1) ? i->AttackEnemy(player, enemy) : (void)0;
    }
}

// Function to display the list of cards currently on the table
void CTable::DisplayTable() const
{
    cout << "Cards on table: ";

    // Loop through each card on the table
    for (int i = 0; i < mTable.size(); ++i)
    {
        const auto& card = mTable[i];

        // Print the card's name and its resilience
        cout << card->GetCardName() << " (" << card->GetCardResilience() << ")";

        // Add a comma separator if it's not the last card
        if (i < mTable.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}



CTable::~CTable() = default;

