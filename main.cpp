#include <iostream>
#include <string>
#include "binarySearchTree.h"
using namespace std;


class Book {
private:
    string title;
    string author;
    string genre;
    int isbn;
    int quantity;
    int sales;

public:
    // default Constructor
        Book() {
        title = "";
        author = "";
        genre = "";
        isbn = 0;
        quantity = 0;
    }

    // user defined Constructor
    Book(string& title, string& author, string& genre, int& isbn, int quantity)
    {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->isbn = isbn;
        this->quantity = quantity;
    }

    // setters
    void setTitle(string& title) 
    {
        this->title = title; 
    }
    void setAuthor(string& author) 
    { 
        this->author = author; 
    }
    void setGenre(string& genre) 
    {
        this->genre = genre; 
    }
    void setISBN(int isbn) 
    { 
        this->isbn = isbn; 
    }
    void setQuantity(int quantity) 
    { 
        this->quantity = quantity; 
    }
    

    // getters
    string getTitle() const 
    { 
        return title; 
    }
    string getAuthor() const 
    {
        return author; 
    }
    string getGenre() const 
    { 
        return genre; 
    }
    int getISBN() const 
    {
        return isbn; 
    }
    int getQuantity() const 
    {
        return quantity; 
    }
    

    // operator overloading for comparison for book obj
    bool operator==(const Book& other) const 
    {
        // comparison by ISBN
        return isbn == other.isbn;
    }

    bool operator>(const Book& other) const 
    {
        // comparison for ordering using ISBN
        return isbn > other.isbn;
    }

    bool operator<(const Book& other) const 
    {
        // Comparison for ordering using ISBN
        return isbn < other.isbn;
    }

    // overloading the output stream to print the details of the book 
    friend ostream& operator<<(ostream& os, const Book& book) 
    {
        os << "ISBN: " << book.isbn
            << ", Title: " << book.title
            << ", Author: " << book.author
            << ", Genre: " << book.genre
            << ", Quantity: " << book.quantity;
        return os;
    }
    
    // overloading the input stream operator to read book details. 
    friend istream& operator>>(istream& is, Book& book) {
    string isbn, title, author, genre, quantity;

    getline(is, isbn, ',');
    getline(is, title, ',');
    getline(is, author, ',');
    getline(is, genre, ',');
    getline(is, quantity, ',');

    // inititally I was using setISBN only to set isbn as well as quantity and was getting error. 
    // I learnt about stoi function from stack overflow to convert string to int
    book.setISBN(stoi(isbn));
    book.setTitle(title);
    book.setAuthor(author);
    book.setGenre(genre);
    book.setQuantity(stoi(quantity));
    

    return is;
}

};


// display menu function
void displayOptions() {
    cout << endl;
    cout << "Please choose from the following options: " << endl;
    cout << endl;
    cout << "1. Display All Books (Inorder Traversal)" << endl;;
    cout << "2. Add a New Book" << endl;;
    cout << "3. Remove a Book by ISBN" << endl;;
    cout << "4. Search for a Book" << endl;
    cout << "5. Update Book Quantity" << endl;
    cout << "6. Find Popular Genre" << endl;
    cout << "7. Buy a Book" << endl;
    cout << "8. Total Books Sold" << endl;
    cout << "9. Load from a file" << endl;
    cout << "10. Exit" << endl;
}


int main() 
{
    cout << endl;
    cout << "Welcome to Divas's Online Bookstore Inventory System" << endl;

    bSearchTreeType<Book> bookInventory;
    int userChoice;
    int quantityAmt;
    int isbnToSearch;
    int searchOption;
    
    // counter for book sales 
    int totalBooksSold = 0;
    
    // constant for minimum valid menu choice and maximum valid menu choice
    const int lowerNum = 1;
    const int upperNum = 10;
    
    Book searchBook;

    while (true) 
    {
        displayOptions();
        
        // validate the userChoice 
        do {
            cout << endl;
            cout << "Enter your choice: ";
            cin >> userChoice;
        } while (userChoice < lowerNum || userChoice > upperNum);

        if (userChoice == 1)  
        {
            bookInventory.inorderTraversal();
        } 
        else if (userChoice == 2) 
        {
            string title, author, genre;
            int isbn, quantityAmt;
            
            cout << endl;
            cout << "Enter the title of the book: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter the author of the book: ";
            getline(cin, author);

            cout << "Enter the genre of the book: ";
            getline(cin, genre);

            cout << "Enter the ISBN of the book: ";
            cin >> isbn;

            cout << "Enter the quantity of the book: ";
            cin >> quantityAmt;

            Book newBook(title, author, genre, isbn, quantityAmt);
            bookInventory.insert(newBook);
            cout << endl;
            cout << "Book added successfully." << endl;
        
        } 
        // remove the entire node if the user wants to delte using isbn
        else if (userChoice == 3) 
        {
            Book removeBook;
            int isbnToRemove;
            
            cout << endl;
            cout << "Enter the ISBN of the book you want to remove: ";
            cin >> isbnToRemove;
            removeBook.setISBN(isbnToRemove);
            
            // if book is found in inventory, delete 
            if (bookInventory.search(removeBook)) 
            {
                bookInventory.deleteNodeEntirely(removeBook);
                cout << endl;
                cout << "Selected book removed successfully" << endl;
            } 
            else 
            {
                cout << "Book not found." << endl;
            }
        } 
        else if (userChoice == 4) 
        {
            cout << "Please select a search option: " << endl;
            cout << "1. Search by ISBN" << endl;
            cout << "2. Search by title" << endl;
            cout << "3. Search by author" << endl;
            cout << "4. Search by genre" << endl;
            
            do
            {
                cout << "Enter your choice: ";
                cin >> searchOption;
            }while(searchOption < 1 || searchOption > 4);

            if (searchOption == 1) 
            {
                cout << "Enter the ISBN of the book you want to search: ";
                cin >> isbnToSearch;
                searchBook.setISBN(isbnToSearch);
            } 
            else if (searchOption == 2) 
            {
                string titleSearch;
                cout << "Enter the title of the book you want to search: ";
                cin.ignore();
                getline(cin, titleSearch);
                searchBook.setTitle(titleSearch);
            } 
            else if (searchOption == 3) 
            {
                string searchAuthor;
                cout << "Enter the author of the book you want to search: ";
                cin.ignore();
                getline(cin, searchAuthor);
                searchBook.setAuthor(searchAuthor);
            } 
            else if (searchOption == 4) 
            {
                string searchGenre;
                cout << "Enter the genre of the book you want to search: ";
                cin.ignore();
                getline(cin, searchGenre);
                searchBook.setGenre(searchGenre);
            } 
            else 
            {
                cout << "Invalid option!" << endl;
                return 0;
            }
            
            if (bookInventory.searchWithOptions(searchBook, searchOption)) 
            {
                cout << "Book found!" << endl;
            } 
            else 
            {
                cout << "Book not found." << endl;
            }
        } 
        // this choice allows user to update the quantity of the book 
        else if (userChoice == 5) 
        {
            Book updateBook;
            int isbnToUpdate;

            cout << "Enter the ISBN of the book you want to update: ";
            cin >> isbnToUpdate;
            updateBook.setISBN(isbnToUpdate);

            Book resultBook;
            if (bookInventory.searchRetrieval(updateBook, resultBook)) 
            {
                cout << "Book found." << endl;
                int newQuantity;
                do 
                {
                    cout << "Enter the new quantity: ";
                    cin >> newQuantity;
                } while (newQuantity <= 0);

                resultBook.setQuantity(newQuantity);
                bookInventory.deleteNodeEntirely(updateBook);
                bookInventory.insert(resultBook);

                cout << "Quantity updated successfully." << endl;
            } 
            else 
            {
                cout << "Book not found." << endl;
            }
        } 
        else if (userChoice == 6) 
        {
            bookInventory.findPopularGenre();
        } 
        else if (userChoice == 7) 
        {
            int isbnToBuy, quantityToBuy;

            cout << "Enter the ISBN of the book: ";
            cin >> isbnToBuy;
            cout << "Enter the quantity: ";
            cin >> quantityToBuy;

            Book buyBook;
            buyBook.setISBN(isbnToBuy);

            Book resultBook;
            if (bookInventory.searchRetrieval(buyBook, resultBook)) 
            {
                if (resultBook.getQuantity() >= quantityToBuy) 
                {
                    totalBooksSold += quantityToBuy;
                    resultBook.setQuantity(resultBook.getQuantity() - quantityToBuy);
                    bookInventory.deleteNodeEntirely(resultBook);
                    bookInventory.insert(resultBook);

                    cout << "Transaction successful. Remaining stock: " << resultBook.getQuantity() << endl;
                } 
                else 
                {
                    cout << "Insufficient stock. Available quantity: " << resultBook.getQuantity() << endl;
                }
            } 
            else 
            {
                cout << "Book not found." << endl;
            }
        } 
        else if (userChoice == 8) 
        {
            cout << "Total books sold: " << totalBooksSold << endl;
        } 
        else if (userChoice == 9) 
        {
            string filename;
            cout << "Enter filename to load inventory: ";
            cin >> filename;
            
            loadInventoryFromFile(bookInventory, filename);
        } 
        else if (userChoice == 10) 
        {
            cout << "Exiting..." << endl;
            break;
        } 
        else 
        {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
