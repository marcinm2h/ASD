#include<stdio.h>

static int inputCharacters = 0;
static int candidatesNumber = 0;
static int communitiesNumber = 0;
static int headquatersNumberA = 0;
static int headquatersNumberB = 0;

class Community;
class Candidate;


class CommunityListElement
{
public:
    Community* community;
    CommunityListElement* nextElement;

    CommunityListElement(Community* community)
    {
        this->community = community;
        this->nextElement = NULL;
    }
    CommunityListElement(Community* community, CommunityListElement* nextElement)
    {
        this->community = community;
        this->nextElement = nextElement;
    }
};

class CommunityList
{
public:
    CommunityListElement* firstElement;
    int size;

    CommunityList()
    {
        firstElement = NULL;
        size = 0;
    }

    Community* get(int id)
    {
        CommunityListElement* tmp = firstElement;
        for (int i = 0; i < id; i++)
        {
            tmp = tmp->nextElement;
        }

        return tmp->community;
    }

    void add(Community* community)
    {
        if (this->firstElement == NULL)
        {
            this->firstElement = new CommunityListElement(community);
        }
        else
        {
            firstElement = new CommunityListElement(community, firstElement);
        }
        size++;
    }

    bool contains(Community* community)
    {
        CommunityListElement* tmp = firstElement;
        while(tmp)
        {
            if (community == tmp->community)
            {
                return true;
            }
            tmp = tmp->nextElement;
        }
        return false;
    }

    void empty()
    {
        firstElement = NULL;
        size = 0;
    }
};

class CandidateListElement
{
public:
    Candidate* candidate;
    CandidateListElement* nextElement;

    CandidateListElement(Candidate* candidate)
    {
        this->candidate = candidate;
        this->nextElement = NULL;
    }
    CandidateListElement(Candidate* candidate, CandidateListElement* nextElement)
    {
        this->candidate = candidate;
        this->nextElement = nextElement;
    }
};

class CandidateList
{
public:
    CandidateListElement* firstElement;
    int size;

    CandidateList()
    {
        firstElement = NULL;
        size = 0;
    }

    Candidate* get(int id)
    {
        CandidateListElement* tmp = firstElement;
        for (int i = 0; i < id; i++)
        {
            tmp = tmp->nextElement;
        }

        return tmp->candidate;
    }

    void add(Candidate* candidate)
    {
        if (this->firstElement == NULL)
        {
            this->firstElement = new CandidateListElement(candidate);
        }
        else
        {
            firstElement = new CandidateListElement(candidate, firstElement);
        }
        size++;
    }

    bool contains(Candidate* candidate)
    {
        CandidateListElement* tmp = firstElement;
        while(tmp)
        {
            if (candidate == tmp->candidate)
            {
                return true;
            }
            tmp = tmp->nextElement;
        }
        return false;
    }

    void empty()
    {
        firstElement = NULL;
        size = 0;
    }
};


class Candidate
{
public:
    int id;
    int costA = 0;
    int costB = 0;

    Candidate(int id)
    {
        this->costA = 0;
        this->costB = 0;
        this->id = id;
    }
};

class Community
{
public:
    int id;
    CommunityList* neighbors;
    Candidate* candidateAHeadquaters = NULL; //sztab w wariancie A
    Candidate* candidateBHeadquaters = NULL; //sztab w wariancie B

    Candidate* winnerA = NULL;
    Candidate* winnerB = NULL;
    CandidateList* comitteesA; //komitety w wariancie A
    CandidateList* comitteesB; //komitety w wariancie B

    bool hasHeadquaters = false;
    bool hasComittees = false;
    bool hasWinner = false;

    void addNeighbor(Community* neighbor) {
        this->neighbors->add(neighbor);
    }

    void setHeadquaters(Candidate* candidateA, Candidate* candidateB)
    {
        candidateA->costA++;
        candidateB->costB++;
        this->candidateAHeadquaters = candidateA;
        this->candidateBHeadquaters = candidateB;
        headquatersNumberA++;
        headquatersNumberB++;

        this->hasHeadquaters = true;
        this->hasComittees = false;
        this->winnerA = NULL;
        this->winnerA = NULL;
    }

    void setComittees(Candidate* candidateA, Candidate* candidateB)
    {
        this->comitteesA->add(candidateA);
        this->comitteesB->add(candidateB);
        this->hasComittees = true;
    }

    Community(int id)
    {
        this->id = id;
        comitteesA = new CandidateList();
        comitteesB = new CandidateList();
        neighbors = new CommunityList();
    }
};

int numDigits(int number)
{
    int digits = 0;
    if (number <= 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

void incrementInputCharacters(int var)
{
//    fprintf(stdout, "----> %d, %d <---\n\n", var, numDigits(var));
    inputCharacters += numDigits(var);
}

int main()
{

    fscanf(stdin, "%d", &communitiesNumber);
    incrementInputCharacters(communitiesNumber);

    Community* communities[communitiesNumber];

    for(int id = 0; id < (sizeof(communities)/sizeof(*communities)); id++)
    {
        communities[id] = new Community(id);
    }

    int community1;
    int community2;
    fscanf(stdin, "%d", &community1);
    fscanf(stdin, "%d", &community2);
    incrementInputCharacters(community1);
    incrementInputCharacters(community2);

    while(community1 != -1 && community2 != -1)
    {
        communities[community1]->addNeighbor(communities[community2]);
        communities[community2]->addNeighbor(communities[community1]);

        fscanf(stdin, "%d", &community1);
        fscanf(stdin, "%d", &community2);
        incrementInputCharacters(community1);
        incrementInputCharacters(community2);
    }

    fscanf(stdin, "%d", &candidatesNumber);
    incrementInputCharacters(candidatesNumber);

    Candidate* candidates[candidatesNumber];

    for(int id = 0; id < candidatesNumber; id++)
    {
        candidates[id] = new Candidate(id);
    }

    int candidateStartpointId;
    for(int id = 0; id < candidatesNumber; id++)
    {
        fscanf(stdin, "%d", &candidateStartpointId);
        incrementInputCharacters(candidateStartpointId);
        Candidate* candidate = candidates[id];
        communities[candidateStartpointId]->setHeadquaters(candidate, candidate);
    }

    CommunityList* communitiesWithElections = new CommunityList();
    while(headquatersNumberA != communitiesNumber && headquatersNumberB != communitiesNumber)
    {
        //krok 1
        communitiesWithElections->empty();
        for (int i = 0; i < (sizeof(communities)/sizeof(*communities)); i++)
        {
            Community* community = communities[i];
            if (community->hasHeadquaters)
            {
                Candidate* candidateA = community->candidateAHeadquaters;
                Candidate* candidateB = community->candidateBHeadquaters;
                for (int j = 0; j < community->neighbors->size; j++)
                {
                    Community* neighbor = community->neighbors->get(j);
                    if (!neighbor->hasHeadquaters)
                    {
                        communitiesWithElections->add(neighbor);
                        neighbor->setComittees(candidateA, candidateB);
                    }
                }
            }
        }

        //krok 2
        CommunityListElement* currentCommunityListElement = communitiesWithElections->firstElement;
        int numberOfElections = communitiesWithElections->size;
        for (int i = 0; i < numberOfElections; i++)
        {
            Community* currentCommunity = currentCommunityListElement->community;

            if (currentCommunity->hasComittees && !currentCommunity->hasHeadquaters)//społeczności z komitetami
            {
                int minAnumber = -1;
                int countANeighborsHqs = 0;
                Candidate* winnerA = NULL;

                CandidateListElement* currentCandidateListElement = currentCommunity->comitteesA->firstElement;
                int numOfCandidatesA = currentCommunity->comitteesA->size;

                for (int j = 0; j < numOfCandidatesA; j++)
                {
                    Candidate* candidateA = currentCandidateListElement->candidate;
                    countANeighborsHqs = 0;

                    CommunityListElement* currentCommunityListElement = currentCommunity->neighbors->firstElement;
                    int numOfNeighbors = currentCommunity->neighbors->size;

                    for (int k = 0; k < numOfNeighbors; k++)
                    {
                        Community* neighbor = currentCommunityListElement->community;
                        if ((neighbor->candidateAHeadquaters != NULL) && (neighbor->candidateAHeadquaters->id== candidateA->id)){
                            countANeighborsHqs++;
                        }
                        currentCommunityListElement = currentCommunityListElement->nextElement;
                    }
                    if ((minAnumber == -1) || countANeighborsHqs < minAnumber)
                    {
                        minAnumber = countANeighborsHqs;
                        winnerA = candidateA;
                    }
                    else if ((countANeighborsHqs == minAnumber) && (winnerA != NULL))
                    {
                        if (winnerA->id < candidateA->id)
                        {
                            winnerA = candidateA;
                        }
                    }
                    currentCandidateListElement = currentCandidateListElement->nextElement;
                }
                currentCommunity->winnerA = winnerA;
                currentCommunity->hasWinner = true;

                int maxBnumber = -1;
                int countBNeighborsHqs = 0;
                Candidate* winnerB = NULL;

                CandidateListElement* currentCandidateListElementB = currentCommunity->comitteesB->firstElement;
                int numOfCandidatesB = currentCommunity->comitteesB->size;

                for (int j = 0; j < numOfCandidatesB; j++)
                {
                    Candidate* candidateB = currentCandidateListElementB->candidate;
                    countBNeighborsHqs = 0;

                    CommunityListElement* currentNeighbotListElement = currentCommunity->neighbors->firstElement;
                    int numOfNeighbors = currentCommunity->neighbors->size;
                    for (int k = 0; k < numOfNeighbors; k++)
                    {
                        Community* neighbor = currentNeighbotListElement->community;
                        if ((neighbor->candidateBHeadquaters != NULL) && (neighbor->candidateBHeadquaters->id == candidateB->id)){
                            countBNeighborsHqs++;
                        }
                        currentNeighbotListElement = currentNeighbotListElement->nextElement;
                    }
                    if ((maxBnumber == -1) || countBNeighborsHqs > maxBnumber)
                    {
                        maxBnumber = countBNeighborsHqs;
                        winnerB = candidateB;
                    }
                    else if ((countBNeighborsHqs == maxBnumber) && (winnerB != NULL))
                    {
                        if (winnerB->id > candidateB->id)
                        {
                            winnerB = candidateB;
                        }
                    }
                    currentCandidateListElementB = currentCandidateListElementB->nextElement;
                }

                currentCommunity->winnerB = winnerB;
                currentCommunity->hasWinner = true;
            }

            currentCommunityListElement = currentCommunityListElement->nextElement;
        }

        //krok 3
        currentCommunityListElement = communitiesWithElections->firstElement;
        numberOfElections = communitiesWithElections->size;
        for(int i = 0; i < numberOfElections; i++)
        {
            Community* community = currentCommunityListElement->community;
            if (community->hasWinner && !community->hasHeadquaters)
            {
                community->setHeadquaters((community->winnerA), (community->winnerB));
            }
            currentCommunityListElement = currentCommunityListElement->nextElement;
        }
    }

    for(int i = 0; i < candidatesNumber; i++)
    {
        fprintf(stdout, "%d %d\n", candidates[i]->costA, candidates[i]->costB);
    }
    fprintf(stdout, "%d", inputCharacters);

    return 0;
}
