#pragma once
#include <iostream>

#include "CCard.h"
#include "CPlayer.h"

class CCard;

using namespace std;

class CIndustrialistPlacement : public CCard {
private:
    int mResilience;
    int mBoost;

public:
    CIndustrialistPlacement(istream& file);
    friend istream& operator>>(istream& file, CIndustrialistPlacement& card);
    ~CIndustrialistPlacement() override;

    void SetCardResilience(int resilience) override;
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    int GetCardResilience() const override;

};
