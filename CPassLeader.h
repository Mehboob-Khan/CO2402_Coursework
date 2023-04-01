#pragma once
#include <iostream>
#include <memory>
#include "CCard.h"
#include "CTable.h"

using namespace std;

class CPassLeader : public CCard
{
private:
    int mResilience{};
    int mPowerIncrement{};
    int mCardCount{};
public:
    CPassLeader(istream& file);
    friend istream& operator>>(istream& file, CPassLeader& passLeader);
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void AttackEnemy(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void SetCardResilience(int resilience) override;
    void SetPowerIncrement(shared_ptr<CTable> table);
    void SetCardPower(int power) override;

    string GetCardName() override;
    int GetCardPower() override;
    int GetCardResilience() const override;
    int GetPowerIncrement() const;
    int GetCardCount() const;
    ~CPassLeader() override;
    int GetTotalPassLeadersOnTable(shared_ptr<CTable> table);
};
