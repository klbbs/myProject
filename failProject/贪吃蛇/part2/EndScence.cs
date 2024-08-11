using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 贪吃蛇.part1;

namespace 贪吃蛇.part2
{
    class EndScence:BaseScence
    {
        public EndScence()
        {
            strTitle = "GameOver";
            strOne = "back to BeginSence";
        }
        public override void EnterJDoSometing()
        {
            if (nowSclIndex == 0) {
                Game.ChangeScence(EScenceType.Begin);

            }
            else
            {
                Environment.Exit(0);
            }
        }
    }
}
