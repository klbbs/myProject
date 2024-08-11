using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 贪吃蛇.part1;

namespace 贪吃蛇.part2
{
    class BeginScence : BaseScence
    {
        public BeginScence()
        {
            strTitle = "贪吃蛇";
            strOne = "start";
        }
        public override void EnterJDoSometing()
        {
            if (nowSclIndex == 0)
            {
                Game.ChangeScence(EScenceType.Game);
            }
            else
            {
                Environment.Exit(0);
            }
        }
    }
}
