# Single Responsibility Principle (SRP)

The Single Responsibility Principle state that a class should have only one reason to change. In other words, a class should only have one job or responsibility. This principle aims to make classes more cohesive and less coupled to other parts of the system, improving maintanability and scalability.

## Why Need SRP:

- **Maintainability**: When a class has only one responsibility, it is easier to understand, maintain, and debug. Changes to a specific functionality affect only the relevant class, reducing the risk of introducting bugs.

- **Reusability**: A class with a single responsibility can be more easily reused in different parts of an application or in different projects.

- **Testability**: Classes with a single responsibility are easier to test because they have a clear and focused purpose.

- **Separation of Concerns**: SRP promotes the separation of concerns, meaning different parts of the application handle different aspects of the problem, leading to a cleaner and more organized codebase.

## Without SRP

```cpp
class Book{

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
};
```

Consider the above example, the Book class holding multiple responsibilities:

- Printing book details
- Saving book details to the database
- Printing book content

If we need to change how books are saved to the database, we must modify the Book class, which can introduce bugs of side effects.

## With SRP

Consider this example,

```cpp
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

```

- The Book class is only responsible for holding book data.
- BookPrinter class is responsible for printing book details and content.
- BookRepository class is responsible for saving book data to the database
