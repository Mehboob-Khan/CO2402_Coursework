// CGame.h
#pragma once

#include <vector>
#include <memory>
#include "CPlayer.h"

class CGame
{
public:
    CGame();
    ~CGame();

    void AddPlayer(const shared_ptr<CPlayer>& player);
    //void Initialize(int seed,int initialPrestige);
    void Play();

private:
    void PlayRound();
    void DisplaySackedPlayers() const;
    void DisplayWinner() const;

    vector<shared_ptr<CPlayer>> mActivePlayers;
    vector<shared_ptr<CPlayer>> mDefeatedPlayers;
    int mMaxRounds;
    int mCurrentRound;
};