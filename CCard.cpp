#include "CCard.h"
#include "CPlayer.h"

// Constructor that reads data from a file stream and initializes the card's properties
CCard::CCard(istream& file)
{
    file >> mName >> mSecondName >> mPower;  // Read card name, second name, and power from file
    mName += (" " + mSecondName);  // Combine name and second name into a single string
}

// Function that is called when the card is played by a player
void CCard::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    cout << player->GetName() << " plays " << this->mName << endl;  // Display message indicating that the card has been played
    player->DeleteCard(shared_from_this());  // Remove the card from the player's hand
}

// Getter function that returns the name of the card
string CCard::GetCardName()
{
    return mName;
}

// Getter function that returns the power of the card
int CCard::GetCardPower()
{
    return mPower;
}

// Getter function that returns the resilience of the card
int CCard::GetCardResilience() const
{
    return 0;
}

// Overloaded input stream operator that reads card data from a file stream
istream& operator>> (istream& file, CCard& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower;  // Read card name, second name, and power from file
    card.mName += (" " + card.mSecondName);  // Combine name and second name into a single string
    return file;  // Return the input stream
}

// Function that is called when the card attacks an enemy
void CCard::AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
}

// Setter function that sets the resilience of the card
void CCard::SetCardResilience(int resilience)
{
}

// Setter function that sets the power of the card
void CCard::SetCardPower(int power)
{
    mPower = power;
}



// Destructor for the card class
CCard::~CCard()
= default;  // Use default implementation
