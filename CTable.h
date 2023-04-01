#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "CCard.h"
#include "CPlayer.h"

using namespace std;

class CPlayer;

class CTable {
private:
    using CardVector = vector<CardPtr>;

public:
    CTable();
    void PlaceCardOnTop(CardPtr card);
    void EraseCard(CardPtr card);
    void TriggerCards(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy) const;
    void DisplayTable() const;

    CardVector mTable;

    ~CTable();
};
