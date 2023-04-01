// Include guards
#pragma once

// Import required libraries
#include <iostream>
#include <memory>

#include "CPlayer.h"

// Definition of CCard class, inheriting from enable_shared_from_this
class CCard : public enable_shared_from_this<CCard> {
protected:
    // Class member variables
    string mName;
    string mSecondName;
    int mPower;
    int randomCard{};

public:
    // Constructor that initializes CCard object from an input stream
    CCard(istream& file);

    // Overloaded input stream operator to read CCard objects from input streams
    friend istream& operator>>(istream& file, CCard& card);

    // Virtual methods to be overridden in derived classes
    virtual void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy);
    virtual void AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy);

    // Setter methods for setting card resilience and power
    virtual void SetCardResilience(int resilience);
    virtual void SetCardPower(int power);

    // Getter methods for card name, power, and resilience
    virtual string GetCardName();
    virtual int GetCardPower();
    virtual int GetCardResilience() const;

    // Virtual destructor
    virtual ~CCard();
    
};

// Define a type alias for a shared_ptr to a CCard object
using CardPtr = shared_ptr<CCard>;
