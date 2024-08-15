#include <iostream>
#include <memory>
#include <string>

using namespace std;


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

/*
//    Class Adaptor Implementation


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

*/


 //   Object Adaptor Implementation

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

int main()
{
    // class adapter
    // unique_ptr<PDFConverter> wtopdf = make_unique<WordToPDFAdaptor>();
    // unique_ptr<PDFConverter> epbtopdf = make_unique<EpubToPDFAdaptor>();

    // wtopdf->saveToPDF("mywordfile");
    // epbtopdf->saveToPDF("myepub");

    // Object Adapter
    shared_ptr<WordDocument> wordDoc = make_shared<WordDocument>();
    unique_ptr<PDFConverter> wordTopdf = make_unique<WordToPDFAdaptor>(wordDoc);
    wordTopdf->saveToPDF("myworddoc");

    shared_ptr<EPUBDocument> epubDoc = make_shared<EPUBDocument>();
    unique_ptr<PDFConverter> epubTopdf = make_unique<EpubToPDFAdaptor>(epubDoc);
    wordTopdf->saveToPDF("myepubdoc");

    return 0;
}
