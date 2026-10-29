#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title_;
    std::string author_;
    bool borrowed_;

public:
    // Konstruktor
    Book(const std::string& title, const std::string& author)
        : title_(title), author_(author), borrowed_(false) {}

    // Läsmetoder: const betyder att de inte ändrar objektet
    const std::string& title() const {
        return title_;
    }

    const std::string& author() const {
        return author_;
    }

    bool isBorrowed() const {
        return borrowed_;
    }

    // Ändringsmetoder
    bool borrow() {
        if (borrowed_) {
            return false; // Boken är redan utlånad
        }

        borrowed_ = true;
        return true;
    }

    bool returnBook() {
        if (!borrowed_) {
            return false; // Boken var inte utlånad
        }

        borrowed_ = false;
        return true;
    }

    void print() const {
        std::cout << '"' << title_ << "\" av " << author_
                  << " — " << (borrowed_ ? "utlånad" : "tillgänglig")
                  << '\n';
    }
};

class Library {
private:
    std::string name_;
    std::vector<Book> books_;

public:
    explicit Library(const std::string& name)
        : name_(name) {}

    void addBook(const Book& book) {
        books_.push_back(book);
    }

    Book* findBook(const std::string& title) {
        for (Book& book : books_) {
            if (book.title() == title) {
                return &book;
            }
        }

        return nullptr; // Hittades inte
    }

    bool borrowBook(const std::string& title) {
        Book* book = findBook(title);

        if (book == nullptr) {
            std::cout << "Boken finns inte i biblioteket.\n";
            return false;
        }

        if (!book->borrow()) {
            std::cout << "Boken är redan utlånad.\n";
            return false;
        }

        std::cout << "Du lånade: " << book->title() << '\n';
        return true;
    }

    bool returnBook(const std::string& title) {
        Book* book = findBook(title);

        if (book == nullptr) {
            std::cout << "Boken finns inte i biblioteket.\n";
            return false;
        }

        if (!book->returnBook()) {
            std::cout << "Boken var inte utlånad.\n";
            return false;
        }

        std::cout << "Du lämnade tillbaka: " << book->title() << '\n';
        return true;
    }

    void printBooks() const {
        std::cout << "\nBöcker på " << name_ << ":\n";

        for (const Book& book : books_) {
            book.print();
        }
    }
};

int main() {
    Library library("Stadsbiblioteket");

    library.addBook(Book("Mio, min Mio", "Astrid Lindgren"));
    library.addBook(Book("Utvandrarna", "Vilhelm Moberg"));

    library.printBooks();

    library.borrowBook("Mio, min Mio");
    library.borrowBook("Mio, min Mio"); // Försök låna samma bok igen

    library.returnBook("Mio, min Mio");

    library.printBooks();
}