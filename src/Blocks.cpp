#include "Blocks.h"
//4x4
BlockI::BlockI()
{
  id = 1;
  pos[0]={Position{1,0},Position{1,1},Position{1,2},Position{1,3}};
  pos[1]={Position{0,2},Position{1,2},Position{2,2},Position{3,2}};
  pos[2]={Position{2,0},Position{2,1},Position{2,2},Position{2,3}};
  pos[3]={Position{0,1},Position{1,1},Position{2,1},Position{3,1}};
  Move(-1,4);
}
//3x3
BlockJ::BlockJ()
{
  id = 2;
  pos[0]={Position{0,0},Position{1,0},Position{1,1},Position{1,2}};
  pos[1]={Position{0,2},Position{0,1},Position{1,1},Position{2,1}};
  pos[2]={Position{2,2},Position{1,2},Position{1,1},Position{1,0}};
  pos[3]={Position{2,0},Position{2,1},Position{1,1},Position{0,1}};
  Move(0,4);
}

//3x3
BlockL::BlockL()
{
  id = 3;
  pos[0]={Position{0,2},Position{1,2},Position{1,1},Position{1,0}};
  pos[1]={Position{2,2},Position{2,1},Position{1,1},Position{0,1}};
  pos[2]={Position{2,0},Position{1,0},Position{1,1},Position{1,2}};
  pos[3]={Position{0,0},Position{0,1},Position{1,1},Position{2,1}};
  Move(0,4);
}

//2x2
BlockO::BlockO()
{
  id = 4;
  pos[0]={Position{0,0},Position{0,1},Position{1,0},Position{1,1}};
  Move(0,4);
}

//3x3
BlockS::BlockS()
{
  id = 5;
  pos[0]={Position{1,0},Position{1,1},Position{0,1},Position{0,2}};
  pos[1]={Position{0,1},Position{1,1},Position{1,2},Position{2,2}};
  pos[2]={Position{2,0},Position{2,1},Position{1,1},Position{1,2}};
  pos[3]={Position{0,0},Position{1,0},Position{1,1},Position{2,1}};
  Move(0,4);
}

//3x3
BlockT::BlockT()
{
  id = 6;
  pos[0]={Position{0,1},Position{1,0},Position{1,1},Position{1,2}};
  pos[1]={Position{0,1},Position{1,1},Position{1,2},Position{2,1}};
  pos[2]={Position{1,0},Position{1,1},Position{1,2},Position{2,1}};
  pos[3]={Position{0,1},Position{1,0},Position{1,1},Position{2,1}};
  Move(0,4);
}

//3x3
BlockZ::BlockZ()
{
  id = 7;
  pos[0]={Position{0,0},Position{0,1},Position{1,1},Position{1,2}};
  pos[1]={Position{0,2},Position{1,1},Position{1,2},Position{2,1}};
  pos[2]={Position{1,0},Position{1,1},Position{2,1},Position{2,2}};
  pos[3]={Position{0,1},Position{1,0},Position{1,1},Position{2,0}};
  Move(0,4);
}




