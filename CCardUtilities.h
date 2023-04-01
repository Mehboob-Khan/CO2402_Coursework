#pragma once

#include <memory>
#include "CCard.h"

using namespace std;

class CCard;

enum class ECardType : int {
	Student = 1,
	PlagiarismHearing = 2,
	CourseAccreditation = 3,
	FeedbackForum = 4,
	SIndustrialPlacement = 5,
	SPassLeader = 6,
	MResearchFunding = 7,
	MMitigatingCircumstances = 8,
	SEasyTarget = 9,
	SSerialOffender = 10,
	SGraduateStudent = 11
};

shared_ptr<CCard> CreateNewCard(ECardType card, istream& file);
