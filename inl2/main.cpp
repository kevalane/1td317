#include <iostream>

using namespace std;

void printEnding(int number_of_runners, int winner_number, int winner_time);
int convertToSeconds(int hours, int minutes, int seconds);

int main() {
    int startHours, startMinutes, startSeconds;
    int endHours, endMinutes, endSeconds;
    int startNumber;
    int bestStartNumber;
    int bestDiff;
    int numberOfRunners = 0;

    cout << "Startnummer? ";
    cin >> startNumber;

    // main input loop
    while (startNumber > 0) {
        // Get start and end time
        cout << "Starttid? ";
        cin >> startHours >> startMinutes >> startSeconds;
        cout << "Måltid? ";
        cin >> endHours >> endMinutes >> endSeconds;

        int startTime = convertToSeconds(startHours, startMinutes, startSeconds);
        int endTime = convertToSeconds(endHours, endMinutes, endSeconds);

        if (endTime <= startTime) endTime += 24*60*60; // add 24 hours in seconds to endTime if past midnight
        int diff = endTime - startTime;
        if (diff < bestDiff) {
            bestDiff = diff;
            bestStartNumber = startNumber;
        }

        // increment and repeat
        numberOfRunners++;
        cout << "Startnummer? ";
        cin >> startNumber;
    }
    
    printEnding(numberOfRunners, bestStartNumber, bestDiff);
    return 0;
}

void printEnding(int number_of_runners, int winner_number, int winner_time) {
    // let's convert winnertime to hh-mm-ss
    int hours, seconds, minutes;
    seconds = winner_time;
    minutes = winner_time / 60;
    hours = winner_time / 3600;

    if (number_of_runners == 0) {
        cout << "Inga tävlande" << endl;
    } else {
        cout << "Vinnare är startnr: " << winner_number << endl;
        cout << "Tim: " << int(hours);
        cout << " Min: " << int(minutes % 60);
        cout << " Sek: " << int(seconds%60) << endl;
        cout << "Antal tävlande: " << number_of_runners << endl;
    }
    cout << "Programmet avslutas" << endl;
}

int convertToSeconds(int hours, int minutes, int seconds) {
    return (hours * 60 * 60 + minutes * 60 + seconds);
}