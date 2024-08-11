using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 贪吃蛇.part1;
using 贪吃蛇.part4Res;

namespace 贪吃蛇.part2
{
    class GameScence : IScenceUpdate
    {
        Map? map;
        public GameScence()
        {
            map = new Map();
        }
        public void Update()
        {
            map.Draw();
        }
    }
}
