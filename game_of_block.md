# The idea Bard  

recursive approach (last one): 
 -  the blocks need to exist between two planes, that complicates the 'generate new frame function' also in order for block to generate it's new position he first needs to consider   



| id | name | short description | color | killable | moveable |variants: block| variants: square |
|:--:| :---: | :---| :---: | :---: | :---: |  :---: |:---:|
| 1  | empty| is empty | empty | yes | yes | no | no |
| 2  | basic| can be pushed and does nothing |grey | no | yes | 
| 3  | bedrock| can't be pushed, nor killed | black |no | no |
| 4  | turn | changes the direction the block is going  | blue | yes | no  |
| 5  | goal | when all are killed the level is beaten | purple | yes | yes |
| 6  | enemy | kills everything it touches | red | yes | yes |  
| 7  | engine | pushes blocks in front of itself | orange | yes | yes | 
| 8  | factory | copies cell from behind and spawns it in front| green | yes |yes |
| 9  | tp | teleports cell that enter's it to the exit it's exit, linked portals have the same color | light rainbow colors | no | no |
| 10 |      
 
