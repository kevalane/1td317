#include <iostream>

using namespace std;

void print_ending(int number_of_runners, int winner_number, int winner_time);
int convertToSeconds(int hours, int minutes, int seconds);
bool afterMidnight();

int main() {
    int start_hours, start_minutes, start_seconds;
    int end_hours, end_minutes, end_seconds;
    int start_number;
    int best_start_number;
    int number_of_runners = 0;

    cout << "Startnummer? ";
    cin >> start_number;

    // main input loop
    // while (start_number > 0) {
        cout << "\nStarttid? ";
        cin >> start_hours >> start_minutes >> start_seconds;
        number_of_runners++;
        
        // take next number
        cout << "\nStartnummer? ";
        cin >> start_number;
    // }
    cout << "\n" << convertToSeconds(start_hours, start_minutes, start_seconds) << endl;
    print_ending(2, 12, 42);

    return 0;
}

void print_ending(int number_of_runners, int winner_number, int winner_time) {
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