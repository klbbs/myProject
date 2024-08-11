using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 贪吃蛇.part1
{
    abstract class BaseScence : IScenceUpdate
    {
        protected int nowSclIndex = 0;
        protected string? strTitle;
        protected string? strOne;
        public abstract void EnterJDoSometing();
        public void Update()
        {
            //场景逻辑

            //场景UI
            Console.ForegroundColor = ConsoleColor.White;
            Console.SetCursorPosition(Game.w / 2 - strTitle.Length, 5);
            Console.Write(strTitle);
            Console.SetCursorPosition(Game.w / 2 - strOne.Length, 8);
            Console.ForegroundColor = nowSclIndex == 0 ? ConsoleColor.Red : ConsoleColor.White;
            Console.Write(strOne);
            Console.SetCursorPosition(Game.w / 2 - 4, 10);
            Console.ForegroundColor = nowSclIndex == 1 ? ConsoleColor.Red : ConsoleColor.White;
            Console.Write("Over && End");
            //检测输入
            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.W:
                    --nowSclIndex;
                    if (nowSclIndex < 0)
                    {
                        nowSclIndex = 0;
                    }
                    break;
                case ConsoleKey.S:
                    ++nowSclIndex;
                    if (nowSclIndex > 1)
                    {
                        nowSclIndex = 1;
                    }
                    break;
                case ConsoleKey.J:
                    EnterJDoSometing();
                    break;
            }
        }

    }
}
