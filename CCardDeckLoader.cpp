#include "CCardDeckLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "CCardUtilities.h"

CCardDeckLoader::CCardDeckLoader(string fileName) : mFileName(fileName) {
    LoadCardDeck();
    LoadSeedNumber();
}

// This function is used to create a new card based on the type of card
void CCardDeckLoader::LoadCardDeck() {
    ifstream file(mFileName);
    // If the file isn't opening, then it will print out the error message
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }
    // This will read the file line by line
    string line;
    // This will read the line and convert it into a stream
    while (getline(file, line)) {
        stringstream lineStream(line);
        int type;
        lineStream >> type;
        // If the line stream isn't empty, then it will push back the card into the deck
        if (lineStream) {
            mDeck.push_back(CreateNewCard(static_cast<ECardType>(type), lineStream));
        }
    }
    // This will close the file
    file.close();
}
 // This function is used to load the seed number
void CCardDeckLoader::LoadSeedNumber() {
    ifstream file(mFileName);

    if (!file.is_open()) {
        cout << mFileName << " file isn't opening!" << endl;
        return;
    }
    // This will read the file line by line
    string line;
    while (getline(file, line)) {
        stringstream lineStream(line);
        int parsedSeed;
        lineStream >> parsedSeed;
        // If the line stream is empty, then it will set the seed number to the parsed seed
        if (lineStream.eof()) {
            mSeedNumber = parsedSeed;
            break;
        }
    }

    file.close();
}

vector<shared_ptr<CCard>> CCardDeckLoader::GetCards() const {
    return mDeck;
}

int CCardDeckLoader::GetSeedNumber() const {
    return mSeedNumber;
}

CCardDeckLoader::~CCardDeckLoader() = default;
