// CCourseAccreditation.h
#pragma once
#include "CCard.h"
#include "CPlayer.h"

class CCard;

using namespace std;

class CCourseAccreditation : public CCard
{
public:
    CCourseAccreditation(istream& file);
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) override;
    void AttackEnemy(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> Enemy) override;
    ~CCourseAccreditation() override;
};