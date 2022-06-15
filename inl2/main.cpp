#include <iostream>

using namespace std;

void printEnding(int number_of_runners, int winner_number, int winner_time);
int convertToSeconds(int hours, int minutes, int seconds);

/**
 * @brief Program to decide a marathon-runner winner given start and endtimes for all participants.
 * 
 * @return int 0 upon termination;
 */
int main() {
    int startHours, startMinutes, startSeconds;
    int endHours, endMinutes, endSeconds;
    int startNumber;
    int bestStartNumber;
    int bestDiff;
    int numberOfRunners = 0;

    cout << "Startnummer? ";
    cin >> startNumber;

    while (startNumber > 0) {
        // Get start and end time
        cout << "Starttid? ";
        cin >> startHours >> startMinutes >> startSeconds;
        cout << "Måltid? ";
        cin >> endHours >> endMinutes >> endSeconds;

        // convert times to seconds with help function
        int startTime = convertToSeconds(startHours, startMinutes, startSeconds);
        int endTime = convertToSeconds(endHours, endMinutes, endSeconds);

        if (endTime <= startTime) endTime += 24*60*60; // add 24 hours in seconds to endTime if past midnight
        
        // calc diff and update best if necessary
        int diff = endTime - startTime;
        if (diff < bestDiff) {
            bestDiff = diff;
            bestStartNumber = startNumber;
        }

        // increment and repeat
        numberOfRunners++;
        cout << "Startnummer? ";
        cin >> startNumber;
    } // end while (startNumber > 0)
    
    printEnding(numberOfRunners, bestStartNumber, bestDiff);
    return 0;
}

/**
 * @brief Prints ending in accordance with specified instructions.
 * Two cases, if 0 competitors or not
 * @param number_of_runners how many people were competing
 * @param winner_number the startNumber of the winner
 * @param winner_time the time between startTime and endTime in seconds for the winner
 */
void printEnding(int number_of_runners, int winner_number, int winner_time) {
    // convert winnertime to hh-mm-ss
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

/**
 * @brief Converts hours, minutes and seconds to only seconds
 * 
 * @param hours number of hours to convert, e.g. 14
 * @param minutes number of minutes to convert, e.g. 52
 * @param seconds number of seconds to convert, e.g. 32
 * @return int number of seconds from hours, minutes & seconds. Our e.g. would return 14*3600 + 52*60 + 32
 */
int convertToSeconds(int hours, int minutes, int seconds) {
    return (hours * 60 * 60 + minutes * 60 + seconds);
}