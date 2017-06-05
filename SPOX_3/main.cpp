#include<stdio.h>

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

    T* get(int id)
    {
        ListElement<T>* tmp = firstElement;
        for (int i = 0; i < id; i++)
        {
            tmp = tmp->nextElement;
        }

        return tmp->data;
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

    bool contains(T* data)
    {
        ListElement<T>* tmp = firstElement;
        while(tmp)
        {
            if (data == tmp->data)
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
    int costA;
    int costB;
    int hqTmpCounter;
    int currentCommunityId;

    void incrementHqTmpCounter(int communityId)
    {
        if (!this->currentCommunityId == communityId)
        {
            this->currentCommunityId = communityId;
            this->hqTmpCounter = 0;   
        }
        this->hqTmpCounter++;
    }

    Candidate(int id)
    {
        this->costA = 0;
        this->costB = 0;
        this->hqTmpCounter = 0;
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
        if (!this->neighbors->contains(neighbor))
        {
            this->neighbors->add(neighbor);
        }
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
        this->hasComittees = false;
    }

    void setComittees(Candidate* candidateA, Candidate* candidateB)
    {
        this->comittees[0]->add(candidateA);
        this->comittees[1]->add(candidateB);
        this->hasComittees = true;
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

    List<Community>* communitiesWithElections = new List<Community>;
    while((headquatersNumberA != communitiesNumber) && (headquatersNumberB != communitiesNumber))
    {
        communitiesWithElections->empty();
        //krok 1
        //kandydaci odwiedzają miasta sąsiednie i zakładają komitety
        for (int i = 0; i < communitiesNumber; i++)
        {
            Community* community = communities[i];
            if (community->hasHeadquaters)
            {
                Candidate* candidateA = community->headquaters[0];
                Candidate* candidateB = community->headquaters[1];
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

        //krok2
        //prawybory
        ListElement<Community>* currentCommunityListElement = communitiesWithElections->firstElement;
        while(currentCommunityListElement)
        {
            //prawybory w currentCommunityListElement
            Community* currentCommunity = currentCommunityListElement->data;
            Candidate* currentWinners[2];

            List<Community>* neighbors = currentCommunity->neighbors;
            ListElement<Community>* neighborListElement = neighbors->firstElement;
            int currentMin = -1;
            int currentMax = -1;
            int currentMinId = 0;
            int currentMaxId = 0;
            //iteracja po sąsiadach miasta w którym są prawybory
            while(neighborListElement)
            {
                Community* neighbor = neighborListElement->data;

                if (neighbor->hasHeadquaters)
                {
                    neighbor->headquaters[0]->incrementHqTmpCounter(currentCommunity->id);
                    neighbor->headquaters[1]->incrementHqTmpCounter(currentCommunity->id);
                }

                if (
                    (currentMin == -1) ||
                    (neighbor->headquaters[0]->hqTmpCounter < currentMin) ||
                    ((neighbor->headquaters[0]->hqTmpCounter == currentMin) && (neighbor->headquaters[0]->id > currentMinId))
                )
                {
                    currentMin = neighbor->headquaters[0]->hqTmpCounter;
                    currentMinId = neighbor->headquaters[0]->id;
                    currentWinners[0] = neighbor->headquaters[0];
                }

                if (
                    (currentMax == -1) ||
                    (neighbor->headquaters[1]->hqTmpCounter > currentMax) ||
                    ((neighbor->headquaters[1]->hqTmpCounter == currentMax) && (neighbor->headquaters[1]->id < currentMaxId))
                    )
                {
                    currentMax = neighbor->headquaters[1]->hqTmpCounter;
                    currentMaxId = neighbor->headquaters[1]->id;
                    currentWinners[1] = neighbor->headquaters[1];
                }


                neighborListElement = neighborListElement->nextElement;
            }

            currentCommunity->setWinners(currentWinners[0], currentWinners[1]);

            currentCommunityListElement = currentCommunityListElement->nextElement;
        }



        //krok3
        //zwycięzcy wyborów zakładają sztaby
        for (int i = 0; i < communitiesNumber; i++)
        {
            Community* community = communities[i];
            if (community->hasWinner() && !community->hasHeadquaters)
            {
                community->setHeadquaters((community->winners[0]), (community->winners[1]));
            }
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
