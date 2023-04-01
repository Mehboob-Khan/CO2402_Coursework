#pragma once
#include <iostream>
#include <vector>
#include <memory>


class CCard; // Forward declaration for CCard

using namespace std;

class CTable;

class CPlayer : public enable_shared_from_this<CPlayer> { // Inherit from enable_shared_from_this<CPlayer>
protected:
    using CardPtr = shared_ptr<CCard>; // Declare CardPtr as an alias for shared_ptr<CCard>
    using CardVector = vector<shared_ptr<CCard>>;

    string mName;
    int mPrestige;
    int randomCard;
    CardVector mDeck;
    int mHandSize;
    shared_ptr<CTable> Table;
    CardVector mHand;

public:
    CPlayer(string name, int prestige, CardVector deck);
    void DrawCard();
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy);
    void DeleteCard(CardPtr card);
    void SetPrestige(int prestige);
    shared_ptr<CPlayer> GetSacked();


    static int Random(int max);
    string GetName();
    int GetPrestige() const;
    CardVector GetDeck();
    CardVector GetHand();
    shared_ptr<CTable> GetTable();
    int GetRandomCard();
};
