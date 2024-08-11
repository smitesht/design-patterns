#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct IText
{
public:
    virtual string render() = 0;
    virtual ~IText() {}
};


class PlainText : public IText
{
private:

    string _content;
public:
    PlainText(const string content) : _content(content) {

    }

    string render() override{
        return _content;
    }
};

class TextDecorator : public IText 
{
private:
    unique_ptr<IText> textComponent;

public:

    TextDecorator(unique_ptr<IText> component)
        :textComponent(std::move(component))
    {}
    
    string render() override
    {
        return textComponent->render();
    }

};

class BoldText : public TextDecorator
{
public:
    BoldText(unique_ptr<IText> component)
        :TextDecorator(std::move(component))
    {}

    string render() override
    {
        return "<b>" + TextDecorator::render() + "</b>";
    }

    ~BoldText() {
        cout << "Dtor BoldText..." << endl;
    }
};

class ItalicText : public TextDecorator
{
public:
    ItalicText(unique_ptr<IText> component)
        :TextDecorator(std::move(component))
    {}

    string render() override
    {
        return "<i>" + TextDecorator::render() + "</i>";
    }

    ~ItalicText() {
        cout << "Dtor ItalicText..." << endl;
    }
};

class UnderlineText : public TextDecorator
{
public:
    UnderlineText(unique_ptr<IText> component)
        :TextDecorator(std::move(component))
    {}

    string render() override
    {
        return "<u>" + TextDecorator::render() + "</u>";
    }

    ~UnderlineText() {
        cout << "Dtor UnderlineText..." << endl;
    }
};

int main()
{
    unique_ptr<IText> plainText = make_unique<PlainText>("Hello World");
    cout << plainText->render() << endl;

    unique_ptr<TextDecorator> boldText = make_unique<BoldText>(std::move(plainText));
    cout << boldText->render() << endl;

    unique_ptr<TextDecorator> italicText = make_unique<ItalicText>(std::move(boldText));
    cout << italicText->render() << endl;

    unique_ptr<TextDecorator> underlineText = make_unique<UnderlineText>(std::move(italicText));
    cout << underlineText->render() << endl;
}