using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantMenuDesigner
{
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
}
