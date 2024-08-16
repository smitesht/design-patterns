#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct IMenuComponent
{
    virtual void print() = 0;
    virtual ~IMenuComponent() {}
};

class MenuItem : public IMenuComponent
{
    string _name;
    double _price;
public:
    MenuItem(string name, double price)
        :_name(name), _price(price)
    {}

    void print() override
    {
        cout << _name << "-------------" << _price << endl;
    }
};

class MenuCategory : public IMenuComponent
{
    string _category_name;
    vector<shared_ptr<IMenuComponent>> menuItems;

public:

    MenuCategory(string category_name)
        :_category_name(category_name)
    { }

    void add(shared_ptr<IMenuComponent> menuItem)
    {
        menuItems.push_back(menuItem);
    }

    void print() override
    {
        cout << "Category: " << _category_name << endl;
        for (auto& item : menuItems)
        {
            item->print();
        }
    }
};

int main()
{
    shared_ptr<IMenuComponent> spring_roll = make_shared<MenuItem>("Sprint Roll", 5.99);
    shared_ptr<IMenuComponent> grilled_chiken = make_shared<MenuItem>("Grilled Chiken", 15.99);
    shared_ptr<IMenuComponent> ice_cream = make_shared<MenuItem>("Ice Cream", 5.99);

    shared_ptr<MenuCategory> appetizers = make_shared<MenuCategory>("Appetizers");
    appetizers->add(spring_roll);
        
    shared_ptr<MenuCategory> mainCourse = make_shared<MenuCategory>("Main Course");
    mainCourse->add(grilled_chiken);

    shared_ptr<MenuCategory> desserts = make_shared<MenuCategory>("Desserts");
    desserts->add(ice_cream);

    shared_ptr<MenuCategory> comboMeal = make_shared<MenuCategory>("Combo Meal");
    comboMeal->add(spring_roll);
    comboMeal->add(grilled_chiken);
    comboMeal->add(ice_cream);

    comboMeal->print();
}