using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantMenuDesigner
{
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
}
