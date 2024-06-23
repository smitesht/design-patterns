#include <iostream>
#include <string>

using namespace std;

// Without SRP
/*class Book{
    
    public:
        string m_title;
        string m_author;
        string m_content;
    
        void printBookDetails(){
            cout << "Title: " << m_title << endl;
            cout << "Author: "<< m_author << endl; 
        }

        void saveBook(){
            cout << "Saving book to database"<<endl;
        }

        void printContent(){
            cout << "Content: "<<m_content<<endl;
        }
};*/

// Book responsible for holding book data
class Book{
    
    public:
        string m_title;
        string m_author;
        string m_content;

        Book(const string& title, const string& author,const string& content)
            :m_title(title), m_author(author), m_content(content){

            }

};

// BookPrinter responsible for printing book details
class BookPrinter{
    public:
        void printBookDetails(const Book& book){
            cout << "Title: " << book.m_title << endl;
            cout << "Author: "<< book.m_author << endl; 
        }

        void printContent(const Book& book){
            cout << "Content: "<<book.m_content<<endl;
        }

};

// Class responsible for persisting book data
class BookRepository {
public:
    void saveBook(const Book& book) {
        // Logic to save the book details to a database
        std::cout << "Saving book to database" << std::endl;
    }
};



int main()
{
    Book myBook("Rich Dad Poor Dad", "Rober K", "Some content here...");
    BookPrinter printer;
    BookRepository repository;

    printer.printBookDetails(myBook);
    printer.printContent(myBook);
    repository.saveBook(myBook);    

    return 0;
}