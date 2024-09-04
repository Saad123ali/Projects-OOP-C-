#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string isbn;

public:
    // Default Constructor
    Book() : title(""), author(""), isbn("") {}

    // Parameterized Constructor
    Book(string _title, string _author, string _isbn)
        : title(_title), author(_author), isbn(_isbn) {}

    // Deep Copy Constructor
    Book(const Book &other)
        : title(other.title), author(other.author), isbn(other.isbn) {}

    // Display function
    void displayAllBooks() const
    {
        cout << setw(28) << title << setw(30) << author << setw(30) << isbn << "\n";
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
};

void displayMenu()
{
    cout << "\n\t\t ______________________________________________\n";
    cout << "\t\t|       |" << setw(40) << "|\n";
    cout << "\t\t| [1]   |     Add Book" << setw(27) << "|\n";
    cout << "\t\t| [2]   |     Display Books" << setw(22) << "|\n";
    cout << "\t\t| [3]   |     Delete Book" << setw(22) << "|\n";
    cout << "\t\t| [4]   |     Delete All Books" << setw(20) << "|\n";
    cout << "\t\t| [0]   |     Exit" << setw(31) << "|\n";
    cout << "\t\t|       |" << setw(40) << "|\n";
    cout << "\t\t|_______|______________________________________|\n";
    cout << "\n\t\tEnter your choice: ";
}

void deleteBook(vector<Book> &bookVector)
{
    int deleteIndex = -1;
    if (bookVector.empty())
    {
        cout << "No books in the system" << endl;
    }
    else
    {
        while (true)
        {
            cout << "Enter the index number of the book to delete: ";
            cin >> deleteIndex;
            if (deleteIndex < 0 || deleteIndex >= bookVector.size())
            {
                cout << "Invalid index number!" << endl;
            }
            else
            {
                bookVector.erase(bookVector.begin() + deleteIndex);
                cout << "Book deleted successfully!" << endl;
                break;
            }
        }
    }
}

void deleteAllBooks(vector<Book> &bookVector)
{
    bookVector.clear();
    cout << "All books have been deleted." << endl;
}

int main()
{
    vector<Book> bookVector;
    int books = 0;
    int bookAdd;

    // Add initial books
    bookVector.push_back(Book("Book 1", "Author 1", "1234567890"));
    bookVector.push_back(Book("Book 2", "Author 2", "0987654321"));
    bookVector.push_back(Book("Book 3", "Author 3", "1122334455"));
    books = bookVector.size();

    while (true)
    {
        system("cls");
        displayMenu();
        string choice;
        cin >> choice;

        if (choice == "1")
        {
            system("cls");
            while (true)
            {
                // User to enter the number of books they want to add
                cout << "\n\tEnter the number of books you want to add: ";
                cin >> bookAdd;
                if (bookAdd <= 0)
                {
                    system("cls");
                    cout << "Invalid Number! Please enter a positive number." << endl;
                }
                else
                {
                    break;
                }
            }

            // Loop to add each book
            for (int i = 0; i < bookAdd; i++)
            {
                cout << "\n\nEnter Detail of Book " << i + 1 << endl;
                string title, author, isbn;
                // Prompt user to enter book details
                while (true)
                {
                    cout << "Enter Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    if (title.empty())
                    {
                        cout << "Title cannot be empty. Please try again." << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while (true)
                {
                    cout << "Enter Book Author name: ";
                    getline(cin, author);
                    if (author.empty())
                    {
                        cout << "Author name cannot be empty. Please try again." << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while (true)
                {
                    cout << "Enter Book ISBN (International Standard Book Number): ";
                    getline(cin, isbn);
                    if (isbn.empty())
                    {
                        cout << "ISBN cannot be empty. Please try again." << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                // Add the book to the vector and increment the book count
                bookVector.push_back(Book(title, author, isbn));
                books++;
            }
        }
        else if (choice == "2")
        {
            if (books == 0)
            {
                cout << "No books in the system." << endl;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\t\t\t\tAll books in the system.\n\n";
                cout << setw(35) << "Book Title" << setw(30) << "Book Author" << setw(30) << "Book ISBN" << setw(30) << "\n";
                cout << "\t\t________________________________________________________________________________________\n" << endl;
                for (int i = 0; i < books; ++i)
                {
                    bookVector[i].displayAllBooks();
                }
            }
        }
        else if (choice == "3")
        {
            system("cls");
            deleteBook(bookVector);
            books = bookVector.size();
        }
        else if (choice == "4")
        {
            system("cls");
            deleteAllBooks(bookVector);
            books = 0;
        }
        else if (choice == "0")
        {
            cout << "\n\n\t\tCode by Saad Ali on Earth\n\n" << endl;
            break;
        }
        else
        {
            cout << "\n\n\tInvalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
