#include "CPlayer.h"  // Include the CPlayer header file
#include "CTable.h"  // Include the CTable header file

// Constructor for the CPlayer class, initializes player's name, prestige, deck, and table
CPlayer::CPlayer(string name, int prestige, CardVector deck)
{
    mName = name;  
    mPrestige = prestige;  
    mDeck = deck;  
    mHandSize = 0;  
    randomCard = 0;  
    Table = make_shared<CTable>();  // Create a new table object and store it in the Table member variable
}


void CPlayer::DrawCard() {
    if (mDeck.size() > mHandSize) {  // Check if there are cards left in the deck to draw
        if (mDeck[mHandSize]) {  // Check if the card at the index exists
            mHandSize++;  // Increase the player's hand size by 1
            if (mHandSize == 1) { cout << mName << " starts with " << mDeck[0]->GetCardName() << "\n" <<endl; }  // Display a message if this is the player's first card
            else { cout << mName << " draws " << mDeck[mHandSize - 1]->GetCardName() << endl; }  // Display a message indicating the card that was drawn
        }
    }
}


// Function that returns a random number between 0 and max
int CPlayer::Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

// Function that plays a random card from the player's hand
void CPlayer::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) {
    if (mHandSize > 0) {  // Check if the player has any cards in their hand
        randomCard = Random(mHandSize);  // Generate a random card index
        if (enemy->GetPrestige() >= 1) {  // Check if the enemy has any prestige left
            mDeck[randomCard]->PlayCard(player, enemy);  // Play the card at the random index
        }

        Table->DisplayTable();  // Display the contents of the table
        Table->TriggerCards(player, enemy);  // Activate any cards on the table
        cout << endl; 
    }
}

// Function that returns a shared pointer to the player object if their prestige is 0 or less, or nullptr otherwise
shared_ptr<CPlayer> CPlayer::GetSacked()
{
    if (mPrestige <= 0)  // Check if the player's prestige is 0 or less
    {
        return shared_from_this();  // Return a shared pointer to the player object
    }
    else {
        return nullptr;  // Return nullptr
    }
}



void CPlayer::DeleteCard(const CardPtr card) {

    // Look for memory address of card
	const auto it = find(mDeck.begin(), mDeck.begin() + mHandSize, card);
    if (it != mDeck.begin() + mHandSize) {
        mDeck.erase(it);
        mHandSize--; // Decrease the hand size by 1, since we removed a card from the hand
    }
}


// Setter function that sets the player's prestige
void CPlayer::SetPrestige(int prestige)
{
    mPrestige = prestige;  // Set the player's prestige to the specified value
}

// Getter function that returns the player's name
string CPlayer::GetName()
{
    return mName;  // Return the player's name
}

// Getter function that returns the player's prestige
int CPlayer::GetPrestige() const
{
    return mPrestige;  // Return the player's prestige
}

// Getter function that returns the player's deck
CPlayer::CardVector CPlayer::GetDeck()
{
    return mDeck;  // Return the player's deck
}

// Getter function that returns the player's hand
// The hand is a subset of the player's deck, consisting of the first mHandSize cards
CPlayer::CardVector CPlayer::GetHand() {
    return CardVector(mDeck.begin(), mDeck.begin() + mHandSize);  // Return a vector containing the first mHandSize cards in the player's deck
}

// Getter function that returns the index of a random card in the player's hand
int CPlayer::GetRandomCard()
{
    return randomCard;  // Return the index of a random card in the player's hand
}

// Getter function that returns a shared pointer to the player's table
shared_ptr<CTable> CPlayer::GetTable()
{
    return Table;  // Return a shared pointer to the player's table
}

