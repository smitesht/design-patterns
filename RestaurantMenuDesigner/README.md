🚀 𝐃𝐞𝐬𝐢𝐠𝐧𝐢𝐧𝐠 𝐚 𝐑𝐞𝐬𝐭𝐚𝐮𝐫𝐚𝐧𝐭 𝐌𝐞𝐧𝐮 𝐮𝐬𝐢𝐧𝐠 𝐭𝐡𝐞 𝐂𝐨𝐦𝐩𝐨𝐬𝐢𝐭𝐞 𝐃𝐞𝐬𝐢𝐠𝐧 𝐏𝐚𝐭𝐭𝐞𝐫𝐧! 🍽️

Ever wondered how to organize a restaurant menu efficiently? The 𝐂𝐨𝐦𝐩𝐨𝐬𝐢𝐭𝐞 𝐃𝐞𝐬𝐢𝐠𝐧 𝐏𝐚𝐭𝐭𝐞𝐫𝐧 can help you design a menu where both individual items (like burgers) and categories (like combo meals) are managed uniformly.

Here’s a quick example:

Menu Structure:

𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲: 𝐁𝐮𝐫𝐠𝐞𝐫𝐬
Panner Burger...........$20
Chicken Burger...........$30

𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲: 𝐁𝐞𝐯𝐞𝐫𝐚𝐠𝐞𝐬
Pepsi...........$3
Cocacola...........$3

𝐂𝐨𝐦𝐛𝐨: 𝐕𝐞𝐠 𝐌𝐞𝐚𝐥...........$𝟐𝟑
Panner Burger
Potato Wedges
Pepsi

𝐖𝐡𝐚𝐭 𝐢𝐬 𝐭𝐡𝐞 𝐂𝐨𝐦𝐩𝐨𝐬𝐢𝐭𝐞 𝐏𝐚𝐭𝐭𝐞𝐫𝐧?
The Composite Design Pattern lets you treat individual objects (like a menu item) and groups of objects (like a category) the same way, making it easier to work with complex structures.

In my project, MenuItem represents a single dish, while MenuCategory and ComboCategory group those items into logical sections.

𝐇𝐞𝐫𝐞'𝐬 𝐚 𝐛𝐫𝐢𝐞𝐟 𝐜𝐨𝐝𝐞 𝐬𝐧𝐢𝐩𝐩𝐞𝐭:

𝐌𝐞𝐧𝐮𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲 𝐛𝐮𝐫𝐠𝐞𝐫𝐬 = 𝐧𝐞𝐰 𝐌𝐞𝐧𝐮𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲("𝐁𝐮𝐫𝐠𝐞𝐫𝐬");
burgers.addMenuItem(new MenuItem("Panner Burger", 20.0));
burgers.addMenuItem(new MenuItem("Chicken Burger", 30.0));

𝐂𝐨𝐦𝐛𝐨𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲 𝐯𝐞𝐠𝐌𝐞𝐚𝐥 = 𝐧𝐞𝐰 𝐂𝐨𝐦𝐛𝐨𝐂𝐚𝐭𝐞𝐠𝐨𝐫𝐲("𝐕𝐞𝐠. 𝐌𝐞𝐚𝐥", 𝟐𝟑.𝟎);
vegMeal.addMenuItem(new MenuItem("Panner Burger", 20.0));
vegMeal.addMenuItem(new MenuItem("Pepsi", 3.0));

## Code Snippet

```c#

public abstract class MenuComponent
{
	public abstract void Display();
}

```

```c#

public class MenuItem : MenuComponent
{
    public string itemName { get; set; }
	public double itemPrice { get; set; }

    public MenuItem(string name, double price)
    {
        this.itemName = name;
		    this.itemPrice = price;
    }

    public override void Display()
	{
		Console.WriteLine($"{itemName}...........${itemPrice}");
	}
}

```

```c#

public class MenuCategory: MenuComponent
{
    public string categoryName { get; set; }
    private List<MenuComponent> menuItems;

    public MenuCategory(string categoryName)
    {
        this.categoryName = categoryName;
        menuItems = new List<MenuComponent>();
    }

    public void addMenuItem(MenuComponent menuItem)
    {
        menuItems.Add(menuItem);
    }

    public void removeMenuItem(MenuComponent menuItem)
    {
        menuItems.Remove(menuItem);
    }

	  public override void Display()
	  {
        Console.WriteLine($"Category: {categoryName}");
        foreach(MenuComponent menuItem in menuItems)
        {
            menuItem.Display();
        }
        Console.WriteLine();
	 }

}
```

```c#

public class ComboCategory : MenuComponent
{
    public string comboName { get; set; }
    public double comboPrice { get; set; }

    private List<MenuComponent> menuItems;

    public ComboCategory(string comboName, double comboPrice)
    {
        this.comboName = comboName;
        this.comboPrice = comboPrice;
        menuItems = new List<MenuComponent>();
    }

    public void addMenuItem(MenuComponent menuItem) { menuItems.Add(menuItem); }
    public void removeMenuItem(MenuComponent menuItem) {  menuItems.Remove(menuItem); }
    public override void Display()
	  {
        Console.WriteLine($"Combo: {comboName}..............${comboPrice}");
        foreach(MenuItem menuItem in menuItems)
        {
            Console.WriteLine($"{menuItem.itemName}");
        }
        Console.WriteLine();
	  }
}

```

```c#

MenuItem pannerBurger = new MenuItem("Panner Burger", 20.0);
MenuItem chickenBurger = new MenuItem("Chicken Burger", 30.0);

MenuItem potatoWedge = new MenuItem("Potato Wedges", 3.0);
MenuItem chickenNugget = new MenuItem("Chicken Nugget", 5.0);

MenuItem coke = new MenuItem("Cocacola", 3.0);
MenuItem pepsi = new MenuItem("Pepsi", 3.0);

MenuCategory burgers = new MenuCategory("Burgers");
burgers.addMenuItem(pannerBurger);
burgers.addMenuItem(chickenBurger);

MenuCategory sideOrder = new MenuCategory("Side Order");
sideOrder.addMenuItem(potatoWedge);
sideOrder.addMenuItem(chickenNugget);

MenuCategory beverages = new MenuCategory("Beverages");
beverages.addMenuItem(pepsi);
beverages.addMenuItem(coke);

ComboCategory vegMeal = new ComboCategory("Veg. Meal", 23.0);
vegMeal.addMenuItem(pannerBurger);
vegMeal.addMenuItem(potatoWedge);
vegMeal.addMenuItem(pepsi);

ComboCategory chickenMeal = new ComboCategory("Chicken Meal", 35.0);
chickenMeal.addMenuItem(chickenBurger);
chickenMeal.addMenuItem(chickenNugget);
chickenMeal.addMenuItem(coke);

MenuCategory restaurantMenu = new MenuCategory("Restaurant Menu");
restaurantMenu.addMenuItem(burgers);
restaurantMenu.addMenuItem(sideOrder);
restaurantMenu.addMenuItem(beverages);
restaurantMenu.addMenuItem(vegMeal);
restaurantMenu.addMenuItem(chickenMeal);

restaurantMenu.Display();

```
