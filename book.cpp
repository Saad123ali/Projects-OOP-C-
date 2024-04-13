#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Book
{
private:
    string* title;
    string* author;
    string* isbn;

public:
    // Default Constructor
    Book()
    {
        title = new string("");
        author = new string("");
        isbn = new string("");
    }

    // Parameterized Constructor
    void AddBooks(string _title, string _author, string _isbn)
    {
        title = new string(_title);
        author = new string(_author);
        isbn = new string(_isbn);
    }

    // Deep Copy Constructor
    Book(const Book& other)
    {
        title = new string(*other.title);
        author = new string(*other.author);
        isbn = new string(*other.isbn);
    }

    // Destructor
    ~Book()
    {
        delete title;
        delete author;
        delete isbn;
    }

    // Display function
    void displayAllBooks() 
    {
        cout << setw(28) << *title << setw(30) << *author << setw(30) << *isbn << "\n";
    }
};

int main()
{
    int books = 0;
    int bookAdd;
    int bookCapacity = 0;
    
    while (true)
    {
        cout << "\n\n\t\tEnter the initial capacity for the book(s): ";
        cin >> bookCapacity;
        if (bookCapacity <= 0)
        {
            system("cls");
            cout << "Invalid Number! Please enter a positive number." << endl;
        }
        else
        {
            break;
        }
    }
    
    Book* bookArray = new Book[bookCapacity];

    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     Add Book" << setw(27) << "|\n";
        cout << "\t\t| [2]   |     Display Books" << setw(22) << "|\n";
        cout << "\t\t| [3]   |     Test Copy" << setw(26) << "|\n";
        cout << "\t\t| [0]   |     Exit" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        cout << "\n\t\tEnter your choice: ";
        string choice;
        cin >> choice;

       if (choice == "1")
        {
            system("cls");
            if (books < bookCapacity)
            {
                while(true)
                {
                    //  user to enter the number of books they want to add
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
                // Check if adding the entered number of books exceeds the capacity
                if (books + bookAdd <= bookCapacity)
                {
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

                        // Add the book to the array and increment the book count
                        bookArray[books].AddBooks(title, author, isbn);
                        books++;
                    }
                }
                else
                {
                    // If adding books exceeds capacity, display error message
                    cout << "\n\n\tError-> Please add books within the limit.\n" << endl;
                }
            }
            else
            {
                // If there's no space for additional books, display appropriate message
                cout << "\n\n\tNo more space for additional books.\n" << endl;
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
                    bookArray[i].displayAllBooks();
                }
            }
        }
        else if (choice == "3")
        {
            system("cls");
            while(true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Test Shallow Copy" << setw(18) << "|\n";
                cout << "\t\t| [2]   |     Test Deep Copy" << setw(21) << "|\n";
                cout << "\t\t| [0]   |     Main Page" << setw(26) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                cout << "\n\t\tEnter your choice: ";
                string copyChoice;
                cin>>copyChoice;
                if(copyChoice == "1")
                {
                    system("cls");
                    int shallowIndex = -1;
                    if (books == 0)
                    {
                        cout<<"No book in the system"<<endl;
                    }
                    else
                    {
                        while(true)
                        {
                            cout << "Enter the index no for shallow copy: ";
                            cin >> shallowIndex;
                            if (shallowIndex < 0 || shallowIndex >= books )
                            {
                                system("cls");
                                cout << "Invalid index number!" << endl;
                            }
                            else
                            {
                                system("cls");
                                    // Display original book data
                                cout << "Original Book Data: " << setw(15) << "Book Title" << setw(30) << "Book Author" << setw(30) << "Book ISBN" << setw(30) << endl;
                                bookArray[shallowIndex].displayAllBooks();
                                // Perform shallow copy
                                cout << "\nShallow Copy Data: " << endl;
                                Book shallowCopy = bookArray[shallowIndex]; // Shallow copy created
                                shallowCopy.displayAllBooks(); // Display shallow copy data
                                break;
                            }
                        }
                    }
                }
                else if (copyChoice == "2")
                {
                    system("cls");
                    int deepIndex = -1;
                    if (books == 0)
                    {
                        cout<<"No book in the system"<<endl;
                    }
                    else
                    {
                        while(true)
                        {
                            cout << "Enter the index no for deep copy: ";
                            cin >> deepIndex;
                            if (deepIndex < 0 || deepIndex >= books)
                            {
                                system("cls");
                                cout << "Invalid index number!" << endl;
                            }
                            else
                            {
                                system("cls");
                                // Display original book data
                                cout << "Original Book Data: " << setw(15) << "Book Title" << setw(30) << "Book Author" << setw(30) << "Book ISBN" << setw(30) << endl;
                                bookArray[deepIndex].displayAllBooks();
                                // Perform shallow copy
                                cout << "\ndeep Copy Data: " << endl;
                                Book deepCopy(bookArray[deepIndex]); // deep copy created
                                deepCopy.displayAllBooks(); // Display deep copy data
                                break;
                            }
                        }
                    }
                }
                else if (copyChoice == "0")
                {
                    // go to main page ithout any performance 
                    break;
                }
                else
                {
                    cout << "\n\n\tInvalid choice. Please enter a valid option." << endl;
                }
            }
           
        }   
        else if (choice == "0")
        {
            cout<<"\n\n\t\tCode by Saad Ali on Earth\n\n"<<endl;
            delete[] bookArray;
            break;
        }
        else
        {
            cout << "\n\n\tInvalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
