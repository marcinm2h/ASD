#include <stdio.h>

class Community;
class Candidate;

static int inputCharacters = 0;
static int candidatesNumber = 0;
static int communitiesNumber = 0;

static int headquatersNumberA = 0;
static int headquatersNumberB = 0;


template <class T>
class ListElement
{
public:
    T* data;
    ListElement* nextElement;

    ListElement(T* data)
    {
        this->data = data;
        this->nextElement = NULL;
    }
    ListElement(T* data, ListElement* nextElement)
    {
        this->data = data;
        this->nextElement = nextElement;
    }
};


template <class T>
class List
{
public:
    ListElement<T>* firstElement;
    int size;

    List()
    {
        firstElement = NULL;
        size = 0;
    }

    void add(T* data)
    {
        if (this->firstElement == NULL)
        {
            this->firstElement = new ListElement<T>(data);
        }
        else
        {
            firstElement = new ListElement<T>(data, firstElement);
        }
        size++;
    }

};

class Candidate
{
public:
    int id;
    int costA;
    int costB;
    int hqTmpCounterA;
    int hqTmpCounterB;
    int currentCommunityIdA = 0;
    int currentCommunityIdB = 0;

    void incrementHqTmpCounterA(int communityId)
    {
        if (currentCommunityIdA != communityId)
        {
            currentCommunityIdA = communityId;
            this->hqTmpCounterA = 0;
        }
        this->hqTmpCounterA++;
    }

    void incrementHqTmpCounterB(int communityId)
    {
        if (currentCommunityIdB != communityId)
        {
            currentCommunityIdB = communityId;
            this->hqTmpCounterB = 0;
        }
        this->hqTmpCounterB++;
    }

    Candidate(int id)
    {
        this->costA = 0;
        this->costB = 0;
        this->hqTmpCounterA = 0;
        this->hqTmpCounterB = 0;
        this->id = id;
    }
};

class Community
{
public:
    int id;
    List<Community>* neighbors; //miasta sąsiedzkie
    Candidate* headquaters[2]; //[sztab w wariancie A, sztab w wariancie B]
    List<Candidate>* comittees[2]; //[komitety w wariancie A, komitety w wariancie B]
    Candidate* winners[2]; //[zwycięzca prawyborów w wariancie A, zwycięzca prawyborów w wariancie B]

    bool hasHeadquaters;
    bool hasComittees;

    void addNeighbor(Community* neighbor) {
        this->neighbors->add(neighbor);
    }

    void setHeadquaters(Candidate* candidateA, Candidate* candidateB)
    {
        candidateA->costA++;
        candidateB->costB++;

        this->headquaters[0] = candidateA;
        this->headquaters[1] = candidateB;

        headquatersNumberA++;
        headquatersNumberB++;

        this->hasHeadquaters = true;
    }

    void setComittees(Candidate* candidateA, Candidate* candidateB)
    {
        this->comittees[0]->add(candidateA);
        this->comittees[1]->add(candidateB);
        this->hasComittees = true;
    }

    void setComitteeA(Candidate* candidateA)
    {
        this->comittees[0]->add(candidateA);
    }

    void setComitteeB(Candidate* candidateB)
    {
        this->comittees[1]->add(candidateB);
    }

    void setWinners(Candidate* winnerA, Candidate* winnerB)
    {
        this->winners[0] = winnerA;
        this->winners[1] = winnerB;
    }

    bool hasWinner()
    {
        return (this->winners[0] != NULL) || (this-> winners[1] != NULL);
    }

    Community(int id)
    {
        this->id = id;
        this->comittees[0] = new List<Candidate>();
        this->comittees[1] = new List<Candidate>();
        this->neighbors = new List<Community>();
    }
};

inline int numDigits(int number)
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
    inputCharacters += numDigits(var);
}

int main()
{

    //wczytanie miast
    fscanf(stdin, "%d", &communitiesNumber);
    incrementInputCharacters(communitiesNumber);

    Community* communities[communitiesNumber];
    for(int i = 0; i < communitiesNumber; i++)
    {
        communities[i] = new Community(i);
    }

    //wczytanie sąsiedztw
    int community1;
    int community2;
    fscanf(stdin, "%d", &community1);
    fscanf(stdin, "%d", &community2);
    incrementInputCharacters(community1);
    incrementInputCharacters(community2);

    while((community1 != -1) && (community2 != -1))
    {
        communities[community1]->addNeighbor(communities[community2]);
        communities[community2]->addNeighbor(communities[community1]);

        fscanf(stdin, "%d", &community1);
        fscanf(stdin, "%d", &community2);
        incrementInputCharacters(community1);
        incrementInputCharacters(community2);
    }

    //wczytanie kandydatów
    fscanf(stdin, "%d", &candidatesNumber);
    incrementInputCharacters(candidatesNumber);

    Candidate* candidates[candidatesNumber];
    for(int id = 0; id < candidatesNumber; id++)
    {
        candidates[id] = new Candidate(id);
    }


    //wczytanie sztabów
    int candidateStartpointId;
    for(int id = 0; id < candidatesNumber; id++)
    {
        fscanf(stdin, "%d", &candidateStartpointId);
        incrementInputCharacters(candidateStartpointId);

        Candidate* candidate = candidates[id];
        communities[candidateStartpointId]->setHeadquaters(candidate, candidate);
    }

    List<Community>* communitiesWithElections;
    while((headquatersNumberA != communitiesNumber) && (headquatersNumberB != communitiesNumber))
    {
        communitiesWithElections = new List<Community>;

        //krok 1
        //kandydaci odwiedzają miasta sąsiednie i zakładają komitety
        Community* community;
        List<Community>* neighbors;
        ListElement<Community>* neighborListElement;
        Community* neighbor;
        for(int i = 0; i < communitiesNumber; i++)
        {
            community = communities[i];
            if(community->hasHeadquaters)
            {
                neighbors = community->neighbors;
                neighborListElement = neighbors->firstElement;

                while(neighborListElement)
                {
                    neighbor = neighborListElement->data;
                    if(!neighbor->hasHeadquaters)
                    {
                        neighbor->setComitteeA(community->headquaters[0]);
                        neighbor->setComitteeB(community->headquaters[1]);
                        if(!(neighbor->hasComittees))
                        {
                            neighbor->setComittees(community->headquaters[0], community->headquaters[1]);
                            communitiesWithElections->add(neighbor);
                        }
                    }
                    neighborListElement = neighborListElement->nextElement;
                }
            }
        }

        //krok2
        //prawybory
        ListElement<Community>* currentCommunityListElement = communitiesWithElections->firstElement;
        Community* currentCommunity;
        while(currentCommunityListElement)
        {
            //prawybory w currentCommunityListElement
            currentCommunity = currentCommunityListElement->data;

            neighbors = currentCommunity->neighbors;
            neighborListElement = neighbors->firstElement;
            //iteracja po sąsiadach miasta w którym są prawybory

            while(neighborListElement)
            {
                neighbor = neighborListElement->data;

                if(neighbor->hasHeadquaters)
                {
                    neighbor->headquaters[0]->incrementHqTmpCounterA(currentCommunity->id);
                    neighbor->headquaters[1]->incrementHqTmpCounterB(currentCommunity->id);
                }

                neighborListElement = neighborListElement->nextElement;
            }

            //ustalenie zwycięzców
            Candidate* currentWinners[2] = { NULL, NULL };

            ListElement<Candidate>* comitteesAListElement = currentCommunity->comittees[0]->firstElement;
            Candidate* candidateA;
            while(comitteesAListElement)
            {
                candidateA = comitteesAListElement->data;
                if (
                        (currentWinners[0] == NULL) ||
                        (candidateA->hqTmpCounterA < currentWinners[0]->hqTmpCounterA) ||
                        ((candidateA->hqTmpCounterA == currentWinners[0]->hqTmpCounterA) && (candidateA->id > currentWinners[0]->id))
                        )
                {
                    currentWinners[0] = candidateA;
                }

                comitteesAListElement = comitteesAListElement->nextElement;
            }
            //B
            ListElement<Candidate>* comitteesBListElement = currentCommunity->comittees[1]->firstElement;
            Candidate* candidateB;
            while(comitteesBListElement)
            {
                candidateB = comitteesBListElement->data;
                if (
                        (currentWinners[1] == NULL) ||
                        (candidateB->hqTmpCounterB > currentWinners[1]->hqTmpCounterB) ||
                        ((candidateB->hqTmpCounterB == currentWinners[1]->hqTmpCounterB) && (candidateB->id < currentWinners[1]->id))
                        )
                {
                    currentWinners[1] = candidateB;
                }

                comitteesBListElement = comitteesBListElement->nextElement;
            }

            currentCommunity->setWinners(currentWinners[0], currentWinners[1]);

            currentCommunityListElement = currentCommunityListElement->nextElement;
        }

        //krok3
        //zwycięzcy wyborów zakładają sztaby
        currentCommunityListElement = communitiesWithElections->firstElement;
        while(currentCommunityListElement)
        {
            community = currentCommunityListElement->data;
            if (community->hasWinner() && !community->hasHeadquaters)
            {
                community->setHeadquaters((community->winners[0]), (community->winners[1]));
            }
            currentCommunityListElement = currentCommunityListElement->nextElement;
        }
    }


    //Odpowiedź
    for(int i = 0; i < candidatesNumber; i++)
    {
        fprintf(stdout, "%d %d\n", candidates[i]->costA, candidates[i]->costB);
    }
    fprintf(stdout, "%d", inputCharacters);

    return 0;
}
