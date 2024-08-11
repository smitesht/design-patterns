# Decorator Design Pattern

- The decorator pattern is a structure design pattern known as a wrapper pattern.

## Intent

Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

## Details:

It is also known as a wrapper pattern. A wrapper is like a topping that surrounds an object. The enclosing object is often called a decorator which conforms (obeys) to the interface of the component that it decorates.

The pattern is useful when you want to add responsibilities to an object without subclassing and is an alternative to extending functionality using inheritance.

## UML Diagram

![image](https://github.com/user-attachments/assets/ee88951f-27d2-4e2b-9c88-5a4d5440dca6)


## Example

We have a requirement to implement a Text class that provides functionalities to display Plain, Bold, Italic, and Underline text. All the functionalities must be independent without harming each other.

![image](https://github.com/user-attachments/assets/83e32b50-4413-447f-afa3-53916318d1f7)


## Code

```cpp

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

OUTPUT:

Hello World
<b>Hello World</b>
<i><b>Hello World</b></i>
<u><i><b>Hello World</b></i></u>
Dtor UnderlineText...
Dtor ItalicText...
Dtor BoldText...

```
