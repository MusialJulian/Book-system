
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

void displayArray(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
}

int main() {
    // 1. Correctly initialized Book instances
    Book book1, book2, book3;

    book1.setBookDetails("The Hobbit", "J.R.R. Tolkien",
        "9780007525492", true, "2026-01-10");

    book2.setBookDetails("1984", "George Orwell",
        "9780451524935", true, "2026-01-12");

    book3.setBookDetails("Dune", "Frank Herbert",
        "9780441172719", false, "2026-01-15");

    cout << "=== CORRECT BOOK INFORMATION ===\n";
    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();

    // 2. Incorrectly initialized Book instances
    Book bad1, bad2, bad3;

    bad1.setBookDetails("", "J.R.R. Tolkien",
        "", true, "2026-01-10");

    bad2.setBookDetails("Harry Potter", "",
        "-12345", false, "2026-13-40");

    bad3.setBookDetails("The Great Gatsby",
        "F. Scott Fitzgerald",
        "9780743273565", true, "");

    cout << "\n=== INCORRECT BOOK INFORMATION ===\n";
    bad1.displayBookDetails();
    bad2.displayBookDetails();
    bad3.displayBookDetails();

    // 3. Three arrays with different initial orders

    // Ascending ISBN order
    Book ascending[3] = {book1, book3, book2};

    // Descending ISBN order
    Book descending[3] = {book2, book3, book1};

    // Mixed ISBN order
    Book mixed[3] = {book3, book1, book2};

    cout << "\n=== ASCENDING ARRAY BEFORE SORTING ===\n";
    displayArray(ascending, 3);

    cout << "\n=== DESCENDING ARRAY BEFORE SORTING ===\n";
    displayArray(descending, 3);

    cout << "\n=== MIXED ARRAY BEFORE SORTING ===\n";
    displayArray(mixed, 3);

    // 4. Sort all three arrays by ISBN
    Book::sortBookData(ascending, 3);
    Book::sortBookData(descending, 3);
    Book::sortBookData(mixed, 3);

    cout << "\n=== ASCENDING ARRAY AFTER SORTING ===\n";
    displayArray(ascending, 3);

    cout << "\n=== DESCENDING ARRAY AFTER SORTING ===\n";
    displayArray(descending, 3);

    cout << "\n=== MIXED ARRAY AFTER SORTING ===\n";
    displayArray(mixed, 3);

    return 0;
}

