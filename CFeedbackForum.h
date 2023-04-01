#pragma once

// Standard C++ library header files being included
#include <iostream>
#include <sstream>
#include <vector>

// Custom header files being included
#include "CCard.h"

// Forward declaration of the CCard class to prevent errors
class CCard;

using namespace std;

// Definition of the CFeedbackForum class, which inherits from the CCard class
class CFeedbackForum : public CCard {
protected:
	// Member variables of the CFeedbackForum class
	int mResilience; // Resilience of the card
	int mBoost; // Boost of the card

public:
	// Constructor for the CFeedbackForum class which takes an input file stream
	CFeedbackForum(istream& file);
	// Friend function to read card information from an input file stream
	friend istream& operator>> (istream& file, CFeedbackForum& card);

	// Operations that can be performed by the card
	void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent) override; // PlayCard the card and call the attack function
	void AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent) override; // AttackEnemy the opponent player

	// Setter for member variables
	void SetCardResilience(int resilience) override; // Set the resilience of the card

	// Getters for member variables
	int GetBoost() const; // Get the boost of the card
	int GetCardResilience() const override; // Get the resilience of the card

	// Destructor for the CFeedbackForum class
	~CFeedbackForum() override;
};
