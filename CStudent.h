#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "CCard.h"

using namespace std;

class CStudent : public CCard {
protected:
    int mResilience{};

public:
    CStudent(istream& file);
    friend istream& operator>> (istream& file, CStudent& card);


    void SetCardResilience(int resilience) override;
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void AttackEnemy(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> Enemy) override;

    int GetCardResilience() const override;
    string GetCardName() override;
};
