#pragma once

#include <string>
#include <vector>
#include <memory>
#include "CCard.h"

using namespace std;

class CCard;

class CCardDeckLoader {
protected:
    string mFileName;
    int mSeedNumber{};
    using CardsDeck = vector<shared_ptr<CCard>>;
    CardsDeck mDeck;

public:
    CCardDeckLoader(string fileName);

    // Operations
    void LoadCardDeck();
    void LoadSeedNumber();

    // Returns
    vector<shared_ptr<CCard>> GetCards() const;
    int GetSeedNumber() const;

    ~CCardDeckLoader();
};
