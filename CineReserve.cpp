#include <iostream>
using namespace std;

struct Seat {
    int seatNumber;
    char rowLetter;
    char status;
    Seat* next;
    Seat* prev;
};

class Cinema {
public:
    Seat* head;
    Seat* current;
    char currentRowLetter;
    int currentSeatNumber;
    int i;

    Cinema() {
        head = NULL;
    }

    void createCinema() {
        currentRowLetter = 'A';
        i = 1;

        do {
            currentSeatNumber = 1;

            do {
                Seat* newSeat = new Seat;
                newSeat->next = newSeat->prev = NULL;
                newSeat->rowLetter = currentRowLetter;
                newSeat->seatNumber = currentSeatNumber;
                newSeat->status = 'n';

                if (head == NULL) {
                    head = newSeat;
                    newSeat->next = newSeat->prev = head;
                } else {
                    current = head;

                    while (current->next != head)
                        current = current->next;

                    current->next = newSeat;
                    newSeat->prev = current;
                    newSeat->next = head;
                    head->prev = newSeat;
                }
                currentSeatNumber++;
            } while (currentSeatNumber <= 9);
            currentRowLetter++;
            i++;
        } while (i <= 10);
    }

    void displayCinemaStatus() {
        int j;
        i = j = 1;
        current = head;

        cout << "\n\n";
        cout << "\t\t\t\t\t\t   SCREEN THIS SIDE\n\n";
        cout << "\t  ------------------------------------------------------";
        cout << "-----------------------------------------------\n\n\n";

        for (i = 1; i <= 10; i++) {
            cout << "\t\t";
            for (j = 1; j <= 9; j++) {
                if (current->status == 'n') {
                    cout << "  " << current->rowLetter << current->seatNumber;
                    cout << "      ";
                } else {
                    cout << "BOOKED    ";
                }
                current = current->next;
            }
            cout << "\n\n";
        }
        cout << "\n\t  ------------------------------------------------------";
        cout << "-----------------------------------------------\n";
    }

    void bookTickets() {
        int numberOfTickets, bookedTickets = 0;
        char row;
        int seat;

        cout << "\n\nNumber of tickets to book: ";
        cin >> numberOfTickets;

        for (i = 1; i <= numberOfTickets; i++) {
            cout << "Ticket " << i << ": " << endl;
            cout << "Enter row: ";
            cin >> row;
            cout << "Enter Seat: ";
            cin >> seat;

            if ((row >= 'A' && row <= 'J') && (seat >= 1 && seat <= 9)) {
                current = head;

                while (current->rowLetter != row)
                    current = current->next;

                while (current->seatNumber != seat)
                    current = current->next;

                if (current->rowLetter == row && current->seatNumber == seat) {
                    if (current->status == 'n') {
                        current->status = 'b';
                        bookedTickets++;
                    } else {
                        cout << "\nSeat " << row << seat << " is already booked!\n\n";
                    }
                }
            } else {
                cout << "\nEnter a valid seat number!!\n\n";
            }
        }
        cout << "\n" << bookedTickets << " TICKETS BOOKED SUCCESSFULLY !!!\n\n";
    }

    void cancelBooking() {
        cout << "\nEnter row and seat number to cancel booking: ";
        cin >> currentRowLetter >> currentSeatNumber;

        if ((currentRowLetter >= 'A' && currentRowLetter <= 'J') && (currentSeatNumber >= 1 && currentSeatNumber <= 9)) {
            current = head;

            while (current->rowLetter != currentRowLetter)
                current = current->next;

            while (current->seatNumber != currentSeatNumber)
                current = current->next;

            if (current->rowLetter == currentRowLetter && current->seatNumber == currentSeatNumber && current->status == 'b') {
                current->status = 'n';
                cout << "\nTicket booking of " << currentRowLetter << currentSeatNumber << " canceled successfully !\n\n";
            } else {
                cout << "\nUNBOOKED SEATS CANNOT BE CANCELLED !!!\n\n";
            }
        } else {
            cout << "\nEnter a valid seat number!!\n\n";
        }
    }
};

int main() {
    Cinema cinema;
    int choice;

    cinema.createCinema();
    cinema.displayCinemaStatus();

    do {
        cout << "\n";
        cout << "***** MENU *****" << endl;
        cout << "1. Book tickets" << endl;
        cout << "2. Show status" << endl;
        cout << "3. Cancel booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cinema.bookTickets();
                break;
            case 2:
                cinema.displayCinemaStatus();
                break;
            case 3:
                cinema.cancelBooking();
                break;
            case 4:
                cout << "\n\n\t\tTHANK YOU AND COME AGAIN !\n\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
