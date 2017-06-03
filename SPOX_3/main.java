package pl.edu.pjatk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;


public class Main {
    public static void main(String[] args) {
        String inputline = null;
        long readChars = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = null;

        CommunityGraph graph = null;
        long inputProcess = 0;
        long numOfCandidates = 0;
        int candidateId = 0;

        try {
            while ((str = br.readLine()) != null) {
                inputline = str.trim();

                if (inputProcess == 0) {
                    long verticesNumber = Long.parseLong(inputline);
                    graph = new CommunityGraph(verticesNumber);
                    readChars+= inputline.length();
                    inputProcess++;

                } else if (inputProcess == 1) {
                    String [] inputArr = inputline.split(" ");
                    int id1 = Integer.parseInt(inputArr[0]);
                    int id2 = Integer.parseInt(inputArr[1]);
                    readChars+= inputArr.length;

                    if (id1 != -1 && id2 != -1) {
                        graph.addNeighbour(id1, id2);
                    } else {
                        readChars+= 2;
                        inputProcess++;
                    }

                } else if (inputProcess == 2) {
                    numOfCandidates = Integer.parseInt(inputline);
                    readChars+= inputline.length();
                    inputProcess++;
                } else if (inputProcess == 3) {
                    readChars+= inputline.length();
                    Candidate candidate = new Candidate(candidateId);
                    int candidateStartpoint = Integer.parseInt(inputline);
                    CommunityVertex community = graph.getCommunity(candidateStartpoint);
                    community.setHeadquaters(candidate, candidate);

                    numOfCandidates--;
                    if (numOfCandidates == 0) {
                        break;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        graph.election();
        StringBuilder sb = new StringBuilder();
        for (Candidate candidate : Candidates.candidates) {
            sb. append(candidate.costA + " " + candidate.costB + "\n");
        }
        System.out.print(sb.toString() + readChars);

    }
}

class CommunityGraph {
    private LinkedList<CommunityVertex> communities; //in order - id == position

    CommunityGraph(long verticesNumber) {
        this.communities = new LinkedList<CommunityVertex>();
        for (int communityId = 0; communityId < verticesNumber; communityId++) {
            addCommunity(communityId);
        }
    }

    CommunityVertex getCommunity(int communityId) {
        return this.communities.get(communityId);
    }

    void election() {
        long communitiesSize = communities.size();
        long headquatersNumberA = Communities.headquatersNumberA;
        long headquatersNumberB = Communities.headquatersNumberB;

        while(headquatersNumberA != communitiesSize && headquatersNumberB != communitiesSize) {
            for (CommunityVertex community : communities) {
                //krok I
                if (community.hasHeadquaters()) {
                    Candidate candidateA = community.candidateAHeadquaters;
                    Candidate candidateB = community.candidateBHeadquaters;

                    //kandydat wariant A i B odwiedza sąsiedznie społeczności
                    for (CommunityVertex neighbor : community.neighbors) {
                        if (!neighbor.hasHeadquaters()) {
                            neighbor.setCommittees(candidateA, candidateB);
                        }
                    }
                }
            }

            //krok II
            for (CommunityVertex community : communities) {
                if (community.hasComitees() && !community.hasHeadquaters()) { //społeczności z komitetami
                    long minANumber = -1;
                    long countANeighborsHqs = 0;
                    Candidate winnerA = null;

                    for(Candidate candidateA : community.committeesA) {
                        countANeighborsHqs = 0;
                        for (CommunityVertex neighbor : community.neighbors) {
                            if ((neighbor.candidateAHeadquaters != null) && (neighbor.candidateAHeadquaters.id == candidateA.id)) {
                                countANeighborsHqs++;
                            }
                        }
                        if ((minANumber == -1) || countANeighborsHqs < minANumber) {
                            minANumber = countANeighborsHqs;
                            winnerA = candidateA;
                        } else if ((countANeighborsHqs == minANumber) && (winnerA != null)) {
                            if (winnerA.id < candidateA.id) {
                                winnerA = candidateA;
                            }

                        }
                    }
                    community.setWinnerA(winnerA);

                    long maxBNumber = -1;
                    long countBNeighborsHqs = 0;
                    Candidate winnerB = null;

                    for(Candidate candidateB : community.committeesB) {
                        countBNeighborsHqs = 0;
                        for (CommunityVertex neighbor : community.neighbors) {
                            if ((neighbor.candidateBHeadquaters != null) && (neighbor.candidateBHeadquaters.id == candidateB.id)) {
                                countBNeighborsHqs++;
                            }
                        }
                        if ((maxBNumber == -1) || countBNeighborsHqs > maxBNumber) {
                            maxBNumber = countBNeighborsHqs;
                            winnerB = candidateB;
                        } else if ((countBNeighborsHqs == maxBNumber) && (winnerB != null)) {
                            if (winnerB.id > candidateB.id) {
                                winnerB = candidateB;
                            }

                        }
                    }
                    community.setWinnerB(winnerB);
                }
            }
            //krok III
            for (CommunityVertex community : communities) {
                if (community.hasWinner()) {
                    community.setHeadquaters(community.winnerA, community.winnerB);
                }
            }

            communitiesSize = communities.size();
            headquatersNumberA = Communities.headquatersNumberA;
            headquatersNumberB = Communities.headquatersNumberB;
        }
    }

    private void addCommunity(int communityId) {
        CommunityVertex communityVertex = new CommunityVertex(communityId);
        this.communities.add(communityId, communityVertex);
    }

    void addNeighbour(int communityId1, int communityId2) {
        CommunityVertex communityVertex1 = this.communities.get(communityId1);
        CommunityVertex communityVertex2 = this.communities.get(communityId2);
        communityVertex1.addNeighbor(communityVertex2);
        communityVertex2.addNeighbor(communityVertex1);
    }
}

class Communities {
    public static long headquatersNumberA = 0;
    public static long headquatersNumberB = 0;
}

class CommunityVertex {
    private int id;
    HashSet<CommunityVertex> neighbors; //not in order

    private boolean hasHeadquaters = false; //HQ == sztab
    private boolean hasComitees = false; //komitety

    Candidate candidateAHeadquaters; //sztab w wariancie A
    Candidate candidateBHeadquaters; //sztab w wariancie B

    Candidate winnerA;
    Candidate winnerB;
    LinkedList<Candidate> committeesA; //komitety w wariancie A
    LinkedList<Candidate> committeesB; //komitety w wariancie B

    CommunityVertex(int id) {
        this.committeesA = new LinkedList<Candidate>();
        this.committeesB = new LinkedList<Candidate>();
        this.neighbors = new HashSet<CommunityVertex>();
        this.id = id;
    }

    void addNeighbor(CommunityVertex communityVertex) {
        this.neighbors.add(communityVertex);
    }

    void setHeadquaters(Candidate candidateA, Candidate candidateB) {
        this.candidateAHeadquaters = candidateA;
        this.candidateBHeadquaters = candidateB;
        this.hasHeadquaters = true;
        this.hasComitees = false;
        this.winnerA = null;
        this.winnerA = null;
        candidateA.costA++;
        candidateB.costB++;
        Communities.headquatersNumberA++;
        Communities.headquatersNumberB++;
    }

    void setCommittees(Candidate candidateA, Candidate candidateB) {
        this.committeesA.add(candidateA);
        this.committeesB.add(candidateB);
        this.hasComitees = true;
    }

    void setWinnerA(Candidate winnerA) {
        this.winnerA = winnerA;
    }

    void setWinnerB(Candidate winnerB) {
        this.winnerB = winnerB;
    }

    boolean hasHeadquaters () {
        return this.hasHeadquaters;
    }

    boolean hasComitees () {
        return this.hasComitees;
    }
    boolean hasWinner() {
        return winnerA != null && winnerB != null;
    }
}

class Candidates {
    static LinkedList<Candidate> candidates = new LinkedList<Candidate>();
}

class Candidate {
    int id;
    long costA = 0; //liczba sztabów przy wariancie A
    long costB = 0; //liczba sztabó przy wariancie B

    Candidate(int id) {
        this.id = id;
        Candidates.candidates.add(this);
    }
}