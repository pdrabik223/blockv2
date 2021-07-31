# The idea Bard  

recursive approach (last one): 
 -  the blocks need to exist between two planes, that complicates the 'generate new frame function' also in order for block to generate it's new position he first needs to consider   

## Bot/Cell
it's the same thing, but sometimes word robot is better suited 
from the game engine perspective the "bot" is more accurate 
display on the other hand only shows image of occupied cell   

## include file 
to include all the bot classes 
[here](bots_main.h)

## the template class 
[here](bot.h)

| id | name                 | color | killable | movable | short description | 
|:---:| :---:                | :---: | :---:    | :---:   | :--- |
| 1  | [empty](empty.h)     | none  | yes | yes | is empty | 
| 2  | [basic](basic.h)     | grey  | no  | yes | can be pushed and does nothing |
| 3  | [bedrock](bedrock.h) | black | no  | no  | can't be pushed, nor killed |
| 4  | [turn](turn.h)       | blue  | yes | no  | changes the direction the block is going | 
| 5  | [goal](goal.h)       | purple| yes | yes | when all are killed the level is beaten | 
| 6  | [enemy](enemy.h)     | red   | yes | yes | kills everything it touches | 
| 7  | [engine](engine.h)   | orange| yes | yes | pushes blocks in front of itself | 
| 8  | [factory](factory.h) | green | yes | yes | copies cell from behind and spawns it in front|
| 9  | [tp](tp.h)           | rainbow | no | no | teleports cell that enter's it to the exit it's exit, linked portals have the same color |
 
