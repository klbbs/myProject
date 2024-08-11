using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 贪吃蛇.part3draw;

namespace 贪吃蛇.part4Res
{
    enum E_SnakeBody
    {
        Head,
        Body
    }
    class SnakeBody:GameObject
    {
        private E_SnakeBody type;

        public SnakeBody(E_SnakeBody type,int x,int y)
        {
            this.type = type;
            this.pos = new Position(x,y);
        }
        public override void Draw()
        {
            Console.SetCursorPosition(pos.x,pos.y);
            Console.ForegroundColor = type == E_SnakeBody.Head ? ConsoleColor.Yellow : ConsoleColor.Green;
            Console.Write(type == E_SnakeBody.Head ? "©" : "※");
        }
    }
}
