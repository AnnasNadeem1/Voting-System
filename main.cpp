//Headers

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include<windows.h>
#include <ctime>

using namespace std;
void printLogo() {
    cout << "                                      ======================================" << endl;
    cout << "                                              Welcome to Election System     " << endl;
    cout << "                                      ======================================" << endl;
    cout<<"             _____  .__          ____ ___      .__                          .__  __          \n"
          "            /  _  \\ |__|______  |    |   \\____ |__|__  __ ___________  _____|__|/  |_ ___.__.\n"
          "           /  /_\\  \\|  \\_  __ \\ |    |   /    \\|  \\  \\/ // __ \\_  __ \\/  ___/  \\   __<   |  |\n"
          "          /    |    \\  ||  | \\/ |    |  /   |  \\  |\\   /\\  ___/|  | \\/\\___ \\|  ||  |  \\___  |\n"
          "          \\____|__  /__||__|    |______/|___|  /__| \\_/  \\___  >__|  /____  >__||__|  / ____|\n"
          "                  \\/                         \\/              \\/           \\/          \\/     "<<endl<<endl<<endl<<endl;
    cout << "\n\n\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
    cout << "\n\n\t\t\t\t\t\t--------------------"; Sleep(500);
    cout << "\n\n\t\t\t\t     QASIM TARIQ       "; Sleep(1000);
    cout << "\n\n\t\t\t\t     MUHAMMAD ANNAS             "; Sleep(2000);
    cout << "\n\n\t\t\t\t     MUHAMMAD SAAD       "; Sleep(2000);
    cout << endl;
    system("cls");
}
class Candidate {
public:
    string cnic;
    int assemblyNo;
    string name;
    string constituency;
    string party;
    string electoralSymbol;
    string localAddress;
    string gender;
    long long phoneNo;
    int votes; // New member to store votes

    Candidate() : assemblyNo(0), phoneNo(0), votes(0) {}

    void enterCandidateDetails(unordered_set<string>& registeredCnic) {
        cout<<"                                      Press XX at any time to return to main menu                "<<endl;
        cout<<"                -----------------------------------------------------------"<<endl;
        cout << "                                      Enter Candidate CNIC No (13 digits): ";

        while (true) {
            cin >> cnic;
            if (cnic == "XX" || cnic == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            bool valid = true;
            for (char c : cnic) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (cnic.length() != 13 || !valid) {
                cout << "                                      CNIC must be exactly 13 digits and contain only numbers. Please re-enter: ";
            } else if (registeredCnic.find(cnic) != registeredCnic.end()) {
                cout << "                                      This CNIC is already registered. Please enter a different CNIC: ";
            } else {
                registeredCnic.insert(cnic); // Add CNIC to set
                break;
            }
        }

        string assemblyInput;
        while (true) {
            cout << "                                      Enter Candidate Assembly No: ";
            cin >> assemblyInput;
            if (assemblyInput == "XX" || assemblyInput == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            stringstream ss(assemblyInput);
            if (ss >> assemblyNo && ss.eof()) {
                break; // Valid input, exit the loop
            } else {
                cout << "                                      Invalid input. Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        }
        cin.ignore();

        // Prompt for name
        do {
            cout << "                                      Enter Candidate Name: ";
            getline(cin, name);
            if (name.empty()) {
                cout << "                                      Name cannot be empty. Please re-enter." << endl;
            }
        } while (name.empty());

        // Prompt for constituency
        do {
            cout << "                                      Enter Candidate Constituency: ";
            getline(cin, constituency);
            if (constituency.empty()) {
                cout << "                                      Constituency cannot be empty. Please re-enter." << endl;
            }
        } while (constituency.empty());

        // Prompt for party
        do {
            cout << "                                      Enter Candidate Party: ";
            getline(cin, party);
            if (party.empty()) {
                cout << "                                      Party cannot be empty. Please re-enter." << endl;
            }
        } while (party.empty());

        // Prompt for electoral symbol
        do {
            cout << "                                      Enter Candidate Electoral Symbol: ";
            getline(cin, electoralSymbol);
            if (electoralSymbol.empty()) {
                cout << "                                      Electoral Symbol cannot be empty. Please re-enter." << endl;
            }
        } while (electoralSymbol.empty());

        // Prompt for local address
        do {
            cout << "                                      Enter Candidate Local Address: ";
            getline(cin, localAddress);
            if (localAddress.empty()) {
                cout << "                                      Local Address cannot be empty. Please re-enter." << endl;
            }
        } while (localAddress.empty());

        bool validGender = false;
        while (!validGender) {
            cout << "                                      Enter Candidate Gender (male/female or m/f): ";
            getline(cin, gender);
            if (gender.empty()) {
                cout << "                                      Gender cannot be empty. Please re-enter." << endl;
            } else {
                // Convert gender to lowercase manually
                transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
                if (gender == "male" || gender == "m" || gender == "female" || gender == "f") {
                    validGender = true;
                } else {
                    cout << "                                      Invalid input. Gender must be male, female, m, or f. Please re-enter." << endl;
                }
            }
        }

        string phoneInput;
        while (true) {
            cout << "                                      Enter Candidate Phone No: ";
            cin >> phoneInput;
            if (phoneInput == "XX" || phoneInput == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            stringstream ss(phoneInput);
            if (ss >> phoneNo && to_string(phoneNo).length() == 10 && ss.eof()) {
                break; // Valid input, exit the loop
            } else {
                cout << "                                      Invalid input. Please enter a valid 11-digit phone number: ";
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        }
        cin.ignore();
    }

    void displayCandidateDetails() {
        cout << "                   CNIC: " << cnic << endl << endl;
        cout << "                   Assembly No: " << assemblyNo << endl << endl;
        cout << "                   Name: " << name << endl << endl;
        cout << "                   Constituency: " << constituency << endl << endl;
        cout << "                   Party: " << party << endl << endl;
        cout << "                   Electoral Symbol: " << electoralSymbol << endl << endl;
        cout << "                   Local Address: " << localAddress << endl << endl;
        cout << "                   Gender: " << gender << endl << endl;
        cout << "                   Phone No: " << phoneNo << endl << endl;
        cout << "                   Votes: " << votes << endl << endl; // Display votes
    }

    string getName() const {
        return name;
    }
};

class Voter {
public:
    string voterCnic;
    string voterName;
    string voterFatherName;
    string voterAddress;
    long long voterPhoneNo;
    char voterGender;
    string voterEmail;

    Voter() : voterPhoneNo(0), voterGender('M') {}

    void enterVoterDetails(unordered_set<string>& registeredCnic) {

        cout<<"                                      Press XX at any time to return to main menu                "<<endl;
        cout<<"                -----------------------------------------------------------"<<endl;
        cout << "                                      Enter Voter CNIC No (13 digits): ";
        while (true) {
            cin >> voterCnic;
            if (voterCnic == "XX" || voterCnic == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            bool valid = true;
            for (char c : voterCnic) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (voterCnic.length() != 13 || !valid) {
                cout << "                                      CNIC must be exactly 13 digits and contain only numbers. Please re-enter: ";
            } else if (registeredCnic.find(voterCnic) != registeredCnic.end()) {
                cout << "                                      This CNIC is already registered. Please enter a different CNIC: ";
            } else {
                registeredCnic.insert(voterCnic); // Add CNIC to set
                break;
            }
        }

        cin.ignore(); // Clear input buffer

        // Prompt for name
        do {
            cout << "                                      Enter your Name: ";
            getline(cin, voterName);
            if (voterName.empty()) {
                cout << "                                      Name cannot be empty. Please re-enter." << endl;
            }
        } while (voterName.empty());

        // Prompt for father's name
        do {
            cout << "                                      Enter your Father's Name: ";
            getline(cin, voterFatherName);
            if (voterFatherName.empty()) {
                cout << "                                      Father's Name cannot be empty. Please re-enter." << endl;
            }
        } while (voterFatherName.empty());

        // Prompt for address
        do {
            cout << "                                      Enter your Address: ";
            getline(cin, voterAddress);
            if (voterAddress.empty()) {
                cout << "                                      Address cannot be empty. Please re-enter." << endl;
            }
        } while (voterAddress.empty());

        string phoneInput;
        while (true) {
            cout << "                                      Enter your Phone No: ";
            cin >> phoneInput;
            if (phoneInput == "XX" || phoneInput == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            stringstream ss(phoneInput);
            if (ss >> voterPhoneNo && to_string(voterPhoneNo).length() == 10 && ss.eof()) {
                break; // Valid input, exit the loop
            } else {
                cout << "                                      Invalid input. Please enter a valid 11-digit phone number: ";
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        }
        cin.ignore(); // Clear input buffer

        bool validGender = false;
        string inputGender;
        do {
            cout << "                                      Enter your Gender (male/female or m/f): ";
            cin >> inputGender;
            if (inputGender == "XX" || inputGender == "xx") {
                cout << "                                      Returning to the main menu..." << endl;
                return;
            }
            // Convert input gender to lowercase for case-insensitive comparison
            transform(inputGender.begin(), inputGender.end(), inputGender.begin(), ::tolower);
            if (inputGender == "male" || inputGender == "female" || inputGender == "m" || inputGender == "f") {
                validGender = true;
            } else {
                cout << "                                      Invalid input. Gender must be male, female, m, or f. Please re-enter." << endl;
                // Clear input buffer before re-entering the loop
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        } while (!validGender);
        cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer

        // Prompt for email
        do {
            cout << "                                      Enter your Email: ";
            getline(cin, voterEmail);
            if (voterEmail.empty()) {
                cout << "                                      Email cannot be empty. Please re-enter." << endl;
            }
        } while (voterEmail.empty());
    }


    void showVoterDetails() {
        cout << "                   CNIC NO: " << voterCnic << endl << endl;
        cout << "                   Name: " << voterName << endl << endl;
        cout << "                   Father Name: " << voterFatherName << endl << endl;
        cout << "                   Address: " << voterAddress << endl << endl;
        cout << "                   Phone No: " << voterPhoneNo << endl << endl;
        cout << "                   Gender: " << voterGender << endl << endl;
        cout << "                   Email: " << voterEmail << endl << endl;
    }

    int getVotedCandidateIndex(int numCandidates) {
        int choice;
        cout << "Choose a candidate to vote for (1-" << numCandidates << "): ";
        cin >> choice;
        cin.ignore();
        return choice - 1;
    }
};

class Voting {
private:
    unordered_set<string> registeredCnic; // Store registered CNICs

    unordered_set<string> votedCnic;

public:
    // Function to write candidate information to file
    void writeCandidateInfoToFile(Candidate* candidates, int numCandidates) {
        ofstream candidateFile("candidates.txt");
        if (!candidateFile) {
            cerr << "Error opening candidates file!" << endl;
            return;
        }

        for (int i = 0; i < numCandidates; ++i) {
            candidateFile << candidates[i].cnic << endl;
            candidateFile << candidates[i].assemblyNo << endl;
            candidateFile << candidates[i].name << endl;
            candidateFile << candidates[i].constituency << endl;
            candidateFile << candidates[i].party << endl;
            candidateFile << candidates[i].electoralSymbol << endl;
            candidateFile << candidates[i].localAddress << endl;
            candidateFile << candidates[i].gender << endl;
            candidateFile << candidates[i].phoneNo << endl;
            candidateFile << candidates[i].votes << endl; // Write votes
        }
        candidateFile.close();
    }

    // Function to write voter information to file
    void writeVoterInfoToFile(Voter* voters, int numVoters) {
        ofstream voterFile("voters.txt");
        if (!voterFile) {
            cerr << "Error opening voters file!" << endl;
            return;
        }

        for (int i = 0; i < numVoters; ++i) {
            voterFile << voters[i].voterCnic << endl;
            voterFile << voters[i].voterName << endl;
            voterFile << voters[i].voterFatherName << endl;
            voterFile << voters[i].voterAddress << endl;
            voterFile << voters[i].voterPhoneNo << endl;
            voterFile << voters[i].voterGender << endl;
            voterFile << voters[i].voterEmail << endl;
        }
        voterFile.close();
    }

    unordered_set<string>& getRegisteredCnic() {
        return registeredCnic;
    }

    void startVoting(Candidate* candidates, int numCandidates, Voter* voters, int numVoters) {
        // Get the current date and time
        time_t currentTime = time(0);
        string dateTime = ctime(&currentTime);

        cout << "Candidates:" << endl;
        for (int i = 0; i < numCandidates; ++i) {
            candidates[i].displayCandidateDetails();
            cout << "-----------------------------------------------------------" << endl;
        }

        string voterCnic;
        cout << "Enter your CNIC No (13 digits): ";
        cin >> voterCnic;

        if (votedCnic.find(voterCnic) != votedCnic.end()) {
            cout << "You have already cast your vote. Multiple votes are not allowed !" << endl;
            return;
        }

        bool voterFound = false;
        for (int i = 0; i < numVoters; ++i) {
            if (voters[i].voterCnic == voterCnic) {
                cout << "Voter found. Your details:" << endl;
                voters[i].showVoterDetails();
                voterFound = true;
                int candidateIndex = voters[i].getVotedCandidateIndex(numCandidates);
                if (candidateIndex >= 0 && candidateIndex < numCandidates) {
                    cout << "You voted for:" << endl;
                    candidates[candidateIndex].displayCandidateDetails();
                    cout << "-----------------------------------------------------------" << endl;

                    // Increment the vote count for the selected candidate
                    candidates[candidateIndex].votes++;
                    // Store the updated candidate information back to file
                    writeCandidateInfoToFile(candidates, numCandidates);

                    // Store the vote details in a separate file
                    ofstream voteFile("votes.txt", ios::app); // Open the file in append mode
                    if (!voteFile) {
                        cerr << "Error opening votes file!" << endl;
                    } else {
                        // Write vote details: CNIC, Name, and Date & Time
                        voteFile << "Voter CNIC: " << voters[i].voterCnic << endl;
                        voteFile << "Voter Name: " << voters[i].voterName << endl;
                        voteFile << "Date & Time Voted: " << dateTime << endl;
                        voteFile << "-----------------------------------------------------------" << endl;
                        voteFile.close();
                    }

                    votedCnic.insert(voterCnic);
                } else {
                    cout << "Invalid candidate choice!" << endl;
                }
                break;
            }
        }

        if (!voterFound) {
            cout << "Voter not found. Register as a voter first." << endl;
        }
    }
    void displayCandidates(Candidate* candidates, int numCandidates) {
        cout << "Candidates:" << endl;
        for (int i = 0; i < numCandidates; ++i) {
            candidates[i].displayCandidateDetails();
            cout << "-----------------------------------------------------------" << endl;
        }
    }
    void displayVoters(Voter* voters, int numVoters) {
        cout << "Voters:" << endl;
        for (int i = 0; i < numVoters; ++i) {
            voters[i].showVoterDetails();
            cout << "-----------------------------------------------------------" << endl;
        }
    }

    // Function to store the total votes awarded to each candidate in a separate file called "result"
    void storeResult(Candidate* candidates, int numCandidates) {
        ofstream resultFile("result.txt");
        if (!resultFile) {
            cerr << "                                      Error opening result file!" << endl;
            return;
        }

        for (int i = 0; i < numCandidates; ++i) {
            resultFile << candidates[i].name << ": " << candidates[i].votes << endl;
        }

        resultFile.close();
    }
};

int main() {

    long long choice;
    int numCandidates = 0, numVoters = 0;
    Candidate* candidateArray = nullptr;
    Voter* voterArray = nullptr;
    Voting election;
    printLogo();
    do {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Election Management System Menu:" << endl;
        cout << "1. Add Candidate" << endl;
        cout << "2. Add Voter" << endl;
        cout << "3. Start Voting" << endl;
        cout << "4. Display Candidates" << endl; // New option
        cout << "5. Display Voters" << endl; // New option
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<long long>::max(), '\n');
        }
        //cin.ignore();
        cout << "-----------------------------------------------------------" << endl;

        switch (choice) {
            case 1:
                cout << "Enter the number of candidates (should be more than 1): ";
                while (!(cin >> numCandidates) || numCandidates < 2) {
                    cout << "Invalid input. Please enter a valid integer greater than 1: ";
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                }
                cout << "-----------------------------------------------------------" << endl;
                candidateArray = new Candidate[numCandidates];
                for (int j = 0; j < numCandidates; j++) {
                    cout << "          Candidate No " << j + 1 << ", Enter your details:" << endl;
                    candidateArray[j].enterCandidateDetails(election.getRegisteredCnic());
                    cout << "-----------------------------------------------------------" << endl;
                    system("cls");
                }
                election.writeCandidateInfoToFile(candidateArray, numCandidates);
                break;


            case 2:
                cout << "Enter the number of voters: ";
                while (!(cin >> numVoters)) {
                    cout << "Invalid input. Please enter a valid integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                }
                cout << "-----------------------------------------------------------" << endl;
                voterArray = new Voter[numVoters];
                for (int j = 0; j < numVoters; j++) {
                    cout << "          Voter No " << j + 1 << ", Enter your details:" << endl;
                    voterArray[j].enterVoterDetails(election.getRegisteredCnic());
                    cout << "-----------------------------------------------------------" << endl;
                    system("cls");
                }
                election.writeVoterInfoToFile(voterArray, numVoters);
                break;

            case 3:
                if (numCandidates == 0 || numVoters == 0) {
                    cout << "Please add candidates and voters first!" << endl;
                } else {
                    election.startVoting(candidateArray, numCandidates, voterArray, numVoters);
                }
                break;

            case 4:
                if (numCandidates == 0) {
                    cout << "No candidates added yet!" << endl;
                } else {
                    election.displayCandidates(candidateArray, numCandidates);
                }
                break;

            case 5:
                if (numVoters == 0) {
                    cout << "No voters added yet!" << endl;
                } else {
                    election.displayVoters(voterArray, numVoters);
                }
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }
    } while (choice != 6);

    // Call the storeResult function before exiting
    election.storeResult(candidateArray, numCandidates);
    
    if (candidateArray) {
        delete[] candidateArray;
    }
    if (voterArray) {
        delete[] voterArray;
    }

    return 0;
}