# Adapter Design Pattern

- Adapter is a structural design pattern that allows objects with incompatible interfaces to work together.
- It acts as a bridge between two incompatible interfaces by wrapping an existing class with a new interface.
- The Adapter Pattern is commonly used when you want to integrate a class that doesn't match the required interface.

### Intent

It converts the interface of a class into another interface that clients expect. The Adapter pattern lets classes work together that could not otherwise because of incompatible interfaces.

### UML Diagram

![image](https://github.com/user-attachments/assets/e8e3898b-1595-4d03-aaef-56c67841eaf5)


### Types of Adapter Patterns

There are mainly two types of Adapter Patterns

- Class Adapter ( Multiple Inheritance )
- Object Adapter ( Composittion )

#### Class Adapter

The class Adapter Pattern uses multiple inheritance to adapt one interface to another. It inherits from both the target interface and the adaptee class.

Since it uses inheritance, it can only be used in languages that support multiple inheritance

![image](https://github.com/user-attachments/assets/c4fdf292-3298-4cee-a9e8-a8878fbf6e4d)


**Example**

```cpp

class PDFConverter {
public:

    virtual void saveToPDF(string filename) = 0;
};

class WordDocument
{
    string filename;
public:
    void readDocument(string file) {
        filename = file;
        cout << "Read Word File " + file << endl;
    }

    string processDocument() {
        string str = "Process file " +  filename;
        cout << str <<endl;
        return str;
    }
};

class EPUBDocument
{
    string filename;
public:
    void readDocument(string file) {
        filename = file;
        cout << "Read Epub File " + file << endl;
    }

    string processDocument() {
        string str = "Process file " + filename;
        cout << str << endl;
        return str;
    }
};

class WordToPDFAdaptor : public PDFConverter, public WordDocument
{
public:

    void saveToPDF(string filename) {
        WordDocument::readDocument(filename);
        string s = WordDocument::processDocument();
        cout << s + " Converted into PDF" << endl;
    }
};

class EpubToPDFAdaptor : public PDFConverter, public EPUBDocument
{
public:

    void saveToPDF(string filename) {
        EPUBDocument::readDocument(filename);
        string s = EPUBDocument::processDocument();
        cout << s + " Converted into PDF" << endl;
    }
};

```

Main:

```cpp

int main()
{
    // class adapter
     unique_ptr<PDFConverter> wtopdf = make_unique<WordToPDFAdaptor>();
     unique_ptr<PDFConverter> epbtopdf = make_unique<EpubToPDFAdaptor>();

     wtopdf->saveToPDF("mywordfile");
     epbtopdf->saveToPDF("myepub");

    return 0;
}

```

#### Object Adapter

The Object Adapter pattern uses composition instead of inheritance. The adapter holds a reference to an instance of the adaptee calss and translates the interface into something the client expects.

![image](https://github.com/user-attachments/assets/555e764e-83d6-4d35-9b25-16257485ae28)


```cpp

class PDFConverter {
public:

    virtual void saveToPDF(string filename) = 0;
};

class WordDocument
{
    string filename;
public:
    void readDocument(string file) {
        filename = file;
        cout << "Read Word File " + file << endl;
    }

    string processDocument() {
        string str = "Process file " +  filename;
        cout << str <<endl;
        return str;
    }
};

class EPUBDocument
{
    string filename;
public:
    void readDocument(string file) {
        filename = file;
        cout << "Read Epub File " + file << endl;
    }

    string processDocument() {
        string str = "Process file " + filename;
        cout << str << endl;
        return str;
    }
};

class WordToPDFAdaptor : public PDFConverter
{
private:
    shared_ptr<WordDocument> _wordDoc;

public:

    WordToPDFAdaptor(shared_ptr<WordDocument> wordDoc) {
        _wordDoc = wordDoc;
    }

    void saveToPDF(string filename) override {
        _wordDoc->readDocument(filename);
        string s = _wordDoc->processDocument();
        cout << s + " Converted into PDF" << endl;
    }
};

class EpubToPDFAdaptor : public PDFConverter
{
private:
    shared_ptr<EPUBDocument> _epubDoc;

public:

    EpubToPDFAdaptor(shared_ptr<EPUBDocument> epubDoc) {
        _epubDoc = epubDoc;
    }

    void saveToPDF(string filename) override {
        _epubDoc->readDocument(filename);
        string s = _epubDoc->processDocument();
        cout << s + " Converted into PDF" << endl;
    }
};

```

Main

```cpp

int main()
{
    shared_ptr<WordDocument> wordDoc = make_shared<WordDocument>();
    unique_ptr<PDFConverter> wordTopdf = make_unique<WordToPDFAdaptor>(wordDoc);
    wordTopdf->saveToPDF("myworddoc");

    shared_ptr<EPUBDocument> epubDoc = make_shared<EPUBDocument>();
    unique_ptr<PDFConverter> epubTopdf = make_unique<EpubToPDFAdaptor>(epubDoc);
    wordTopdf->saveToPDF("myepubdoc");

    return 0;
}

```
