using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantMenuDesigner
{
	public class MenuCategory : MenuComponent
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
}
