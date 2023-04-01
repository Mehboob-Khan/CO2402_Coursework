#include "CCardUtilities.h"
#include "CCard.h"
#include "CCourseAccreditation.h"
#include "CFeedbackForum.h"
#include "CIndustrialistPlacement.h"
#include "CStudent.h"
#include "CPassLeader.h"
#include "CPlagiaristHearing.h"


// Function that creates a new card based on the specified card type
shared_ptr<CCard> CreateNewCard(ECardType card, istream& file) {
    shared_ptr<CCard> cardptr = nullptr;  // Initialize card pointer to nullptr

    // Use a switch statement to determine the card type and create the appropriate card object
    switch (card) {
    case ECardType::Student:
        cardptr = make_shared<CStudent>(file);  // Create a new CStudent object and store it in the card pointer
        break;
    case ECardType::PlagiarismHearing:
        cardptr = make_shared<PlagiaristHearing>(file);  // Create a new PlagiaristHearing object and store it in the card pointer
        break;
    case ECardType::CourseAccreditation:
        cardptr = make_shared<CCourseAccreditation>(file);  // Create a new CCourseAccreditation object and store it in the card pointer
        break;
    case ECardType::FeedbackForum:
        cardptr = make_shared<CFeedbackForum>(file);  // Create a new CFeedbackForum object and store it in the card pointer
        break;
    case ECardType::SIndustrialPlacement:
        cardptr = make_shared<CIndustrialistPlacement>(file);  // Create a new CIndustrialistPlacement object and store it in the card pointer
        break;
    case ECardType::SPassLeader:
    	cardptr = make_shared<CPassLeader>(file);  // Create a new CPassLeader object and store it in the card pointer
        break;

    default:
        cardptr = make_shared<CCard>(file);  // Create a new CCard object and store it in the card pointer
        break;
    }

    return cardptr;  // Return the card pointer
}
