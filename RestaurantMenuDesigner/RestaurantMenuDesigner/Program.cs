
using RestaurantMenuDesigner;

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
