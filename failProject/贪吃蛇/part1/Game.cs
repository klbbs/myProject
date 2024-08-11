using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 贪吃蛇.part2;

namespace 贪吃蛇.part1
{
    enum EScenceType
    {
        Begin,
        Game,
        End
    }
    class Game
    {
        //窗口大小
        public const int h = 20;
        public const int w = 80;
        //当前场景
        public static IScenceUpdate nowScence;

        public Game()
        {
            Console.CursorVisible = false;
            Console.SetWindowSize(w, h);
            Console.SetBufferSize(w, h);

            ChangeScence(EScenceType.Begin); 
        }

        public void Start()
        {
            while (true)
            {
                if (nowScence != null)
                {
                    nowScence.Update();
                }

            }
        }
        public static void  ChangeScence(EScenceType type)
        {
            Console.Clear();
            switch (type)
            {
                case EScenceType.Begin:
                    nowScence = new BeginScence();
                    break;
                case EScenceType.Game:
                    nowScence = new GameScence();
                    break;
                case EScenceType.End:
                    nowScence = new EndScence();
                    break;
            }

        }
    }
}
