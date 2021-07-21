using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperionCodeChallenge1
{
    class Program
    {
        /// <summary>
        /// Main function
        /// </summary>

        static void Main(string[] args)
        {

            int[] houses = new int[] { 0, -1, 1, 5, 3, -160000,100 };     //Enter Your values for House here
            int[] stores = new int[] { -1, 1, -3, 3, 7 ,4,5,2,57,3,567,4,3,57,3,546,542,34,3,34,2,5,7,4,3,546,4,3,6,8,99,2,346,368,34,346,72,4568,82345,342,245,234,56,256,3756,758,5672,524,52,2,34,54,4675,6647,464,34, -1, 1, -3, 3, 7, 4, 5, 2, 57, 3, 567, 4, 3, 57, 3, 546, 542, 34, 3, 34, 2, 5, 7, 4, 3, 546, 4, 3, 6, 8, 99, 2, 346, 368, 34, 346, 72, 4568, 82345, 342, 245, 234, 56, 256, 3756, 758, 5672, 524, 52, 2, 34, 54, 4675, 6647, 464, 34 };            //Enter Your values for House here


            #region Declartions
            int[] closestStores = new int[houses.Length];
            int count = 0;
            #endregion

            #region Validations
             if (stores.Length == 0 && houses.Length != 0)
            {
                Console.WriteLine("No Stores Near You , Get Another House or Build a Store Yourself");
                Console.ReadKey(true);
                return;
            }
            else if (stores.Length == 0 && houses.Length == 0)
            {
                Console.WriteLine("You are at the the Middle of Nowhere,Run for Your Life");
                Console.ReadKey(true);
                return;
            }
            else if (houses.Length == 0)
            {
                Console.WriteLine("You do not have a house, So no Stores for you");
                Console.ReadKey(true);
                return;
            }
            #endregion

            #region Pre Processing
                stores = stores.Distinct().ToArray();  // Remove duplicates from store values 
            Array.Sort(stores);                    //Sort Store Values
            #endregion

            #region Logic
            foreach (int house in houses)    //Iterate through Each House to find the closest House
            {
                closestStores[count] = SearchClosest(stores, house);
                Console.Write(closestStores[count]);
                if (count != houses.Length - 1)
                {
                    Console.Write(",");
                }
                count++;
            }
            #endregion

            Console.ReadKey(true);
        }


        /// <summary>
        /// Function to find closest element in Stoers to given House
        ///<param name="stores">Array containing values for stores locations</param>
        ///<param name="house"> integer containig the value for house location </param>
        /// <returns>Returns the Stores location value closes to the House location value as an integer </returns>
        /// </summary>
        static int SearchClosest(int[] stores, int house)
        {
            int begin = 0;
            int end = stores.Length - 1;


            while (begin < end)
            {
                int mid = (begin + end) / 2;
                if (stores[mid] == house)
                {
                    return house;
                }
                if (end - begin == 1)
                {
                    if (Math.Abs(house - stores[end]) < Math.Abs(house - stores[begin]))
                    {
                        return stores[end];
                    }

                    else
                    {
                        return stores[begin];
                    }
                }
                if (stores[mid] < house)
                {
                    begin = mid;
                }
                else
                {
                    end = mid;
                }

            }
            return 0;
        }

    }
}
