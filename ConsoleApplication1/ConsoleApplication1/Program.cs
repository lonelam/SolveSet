using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Win32Main(string[] args)
        {
            Console.WriteLine("nothing");
           // ConsoleKeyInfo key;
            while(true)
            {
                dynamic key = Console.ReadKey();
                Console.Clear();
                Console.WriteLine("{0} Key Pressed!", key.Key);
            }
        }
    }
}
namespace why
{
    class A
    {
        static int Main()
        {
            Console.ReadKey();
            return 0;
        }
    }
}
