cmake_minimum_required(VERSION 3.10)

# set the project name
project(E0)

SET (LinkedListFiles E0-Base/LinkedList/main.cpp E0-Base/Data\ Structures/LinkedList.h)
SET(TreeNodeFiles "./E0-Base/Data Structures/TreeNode.h" ./E0-Base/WumpusWorld/BehaviorTree/Behavior.cpp ./E0-Base/WumpusWorld/Game/Agent.cpp ./E0-Base/WumpusWorld/Game/Behaviors.cpp ./E0-Base/WumpusWorld/Game/Game.cpp ./E0-Base/WumpusWorld/Game/World.cpp)

# add the executable
add_executable(E0 ${TreeNodeFiles})