// Section 9
// Switch Statement

/* 
    Ask the user what grade they expect on an exam and 
    tell them what they need to score to get it.
*/

#include <iostream>

using namespace std;

int main() {
    
    char letter_grade {};

    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A':
            cout << "You need a score of 90 or above. Study hard!" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80–89 for a B. Keep it up!" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70–79 for an average grade. Stay consistent!" << endl;
            break;
        case 'd':
        case 'D':
            cout << "You need 60–69. Try to aim higher next time!" << endl;
            break;
        case 'f':
        case 'F': {
            char confirm {};
            cout << "Are you sure (Y/N)? ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
                cout << "Alright, maybe more studying next time!" << endl;
            else if (confirm == 'n' || confirm == 'N')
                cout << "Good choice! Now go study!" << endl;
            else
                cout << "Invalid choice. Please enter Y or N." << endl;
            break;
        }
        default:
            cout << "Sorry, that's not a valid grade." << endl;
    }

    cout << endl;
}