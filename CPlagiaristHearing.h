#pragma once
#include <iostream>
#include <vector>
#include "CCard.h"
#include "CPlayer.h"
#include "CTable.h"

class CCard;

using namespace std;

class PlagiaristHearing : public CCard {
public:
    PlagiaristHearing(istream& file);
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void AttackEnemy(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> Enemy) override;
    ~PlagiaristHearing() override;

};

