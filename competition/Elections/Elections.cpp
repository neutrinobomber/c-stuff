#include "pch.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long double CalculateMinVotes(const vector<unsigned>& partyVotes)
{
	long double allVotes = 0;
	for (auto vote : partyVotes)
	{
		allVotes += vote;
	}

	return allVotes * 0.04;
}

unsigned CountPassedParties(const vector<unsigned>& partyVotes, long double minVotes)
{
	unsigned count = 0;

	for (auto currentVotes : partyVotes)
	{
		if (currentVotes >= minVotes)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	unsigned partiesCount = 0;
	while (cin >> partiesCount)
	{
		vector<unsigned> allPartyVotes;

		for (size_t i = 1; i <= partiesCount; i++)
		{
			unsigned currentPartyVotes = 0;
			cin >> currentPartyVotes;
			allPartyVotes.emplace_back(currentPartyVotes);

			
		}	

		long double minVotes = CalculateMinVotes(allPartyVotes);
		unsigned passedPartiesCount = CountPassedParties(allPartyVotes, minVotes);

		cout << passedPartiesCount << endl;
	}

	return 0;
}
