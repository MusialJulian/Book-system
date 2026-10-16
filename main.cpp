
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Book {
private:
    string title, author, ISBN, dateAdd;
    bool availability;

public:
    void setBookDetails(string t, string a, string isbn,
                        bool available, string date) {
        title = t;
        author = a;
        ISBN = isbn;
        availability = available;
        dateAdd = date;
    }

    string getISBN() const {
        return ISBN;
    }

    bool isAvailable() const {
        return availability;
    }

    void displayBookDetails() const {
        cout << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nISBN: " << ISBN
             << "\nAvailability: "
             << (availability ? "Available" : "Borrowed")
             << "\nDate Added: " << dateAdd << "\n";
    }

    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        availability = true;
    }

    static void sortBookData(Book books[], int size) {
        sort(books, books + size,
             [](const Book& a, const Book& b) {
                 return a.getISBN() < b.getISBN();
             });
    }
};

int main() {
    Book books[5];

    books[0].setBookDetails("The Hobbit", "J.R.R. Tolkien",
        "9780007525492", true, "2026-01-10");
    books[1].setBookDetails("1984", "George Orwell",
        "9780451524935", true, "2026-01-12");
    books[2].setBookDetails("Dune", "Frank Herbert",
        "9780441172719", true, "2026-01-15");
    books[3].setBookDetails("Dracula", "Bram Stoker",
        "9780486411095", false, "2026-01-18");
    books[4].setBookDetails("Frankenstein", "Mary Shelley",
        "9780486282114", true, "2026-01-20");

    Book::sortBookData(books, 5);

    string isbn;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> isbn;

        if (isbn == "0") {
            cout << "Program terminated.\n";
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == isbn) {
                found = true;

                if (books[i].borrowBook()) {
                    cout << "Book borrowed successfully!\n";
                } else {
                    cout << "Error: Book is unavailable.\n";
                }

                books[i].displayBookDetails();
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found.\n";
        }
    }

    return 0;
}
