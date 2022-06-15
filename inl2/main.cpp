#include <iostream>

using namespace std;

void printEnding(int number_of_runners, int winner_number, int winner_time);
int convertToSeconds(int hours, int minutes, int seconds);
bool afterMidnight();

int main() {
    int startHours, startMinutes, startSeconds;
    int endHours, endMinutes, endSeconds;
    int startNumber;
    int bestStartNumber;
    int numberOfRunners = 0;

    cout << "Startnummer? ";
    cin >> startNumber;

    // main input loop
    while (startNumber > 0) {
        cout << "\nStarttid? ";
        cin >> startHours >> startMinutes >> startSeconds;
        number_of_runners++;
        
        // take next number
        cout << "\nStartnummer? ";
        cin >> startNumber;
    }
    printEnding(2, 12, 42);

    return 0;
}

void printEnding(int number_of_runners, int winner_number, int winner_time) {
    if (number_of_runners == 0) {
        cout << "Inga tävlande" << endl;
    } else {
        cout << "Vinnare är startnr: " << winner_number << endl;
        cout << winner_time << endl; // convert winnertime to normal format
        cout << "Antal tävlande: " << number_of_runners << endl;
    }
    cout << "Programmet avslutas" << endl;
}

int convertToSeconds(int hours, int minutes, int seconds) {
    return (hours * 60 * 60 + minutes * 60 + seconds);
}