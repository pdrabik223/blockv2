# blockv2

The second iteration of my version of logic block and automata game. This time (after learning a lesson), will be better
[trello](https://trello.com/b/0EFQH3JJ/block-v2) 


# My mistakes

- to complicated engine
- the double buffer, recursive approach to moving pieces it was the biggest problem
- bad gui, in console it looked good but worked only on clion console
- more pieces, for now 10
- gui allows for better user experience
- animations
- The style of app will be mini-metro like a.k.a. clean, simple and smart
- oh and the used Api will be sfml coz I'm psycho

# How to do it 

| id | name | description | implementation |
|:---:| :---| :--- | :---:|
| 1  |documentation|the proper documentation is a key here, because I deal with old and low level API, the proper documentation will e key.| the whole project will be documented using doxygen|
| 2  |error handling| for the same reasons i.e. the old API, my own sanity and the size of the project, errors must be detected quickly | I propose throw "error" used everywhere|
| 3  |cool tests| maybe a lot of executables, one for every stage but the most of it will be display tests | cmake can do it |


# Todo 

- same as in the v1 implementation, the project will be divided  in the 3 steps   
    1 . menu/ chose level screen 
  
    2 . the game itself 
   
    3 . level editor
  
- this time let's push with AI
- the achievement idea was good imo 
- gui interaction with mouse (the simple one) pieces can be selected, and placed  with mouse but not moved on the screen, so the display function will be simpler 
- very simple ui
- I like the Idea of moving background on chose level screen, so the screen will be moving when player is in menu and in chose level screen   

# Documentation
- the main thing will be done in doxygen
- few readme files to organise documentation


| id | name |
| :---: |:---:|
| 1 | main documentation(current file)|
| 2 | [cells/bots](bots/game_of_block.md)|
| 2 | [utility](utility/README.md)|
| 3 | [sfml window](sfml_window/window.md)

# Level 

consists of :
- level file a.k.a. .txt file with positions of block,
game state and so on 
- the block assets (all must be there if not the game won't start)
- background image 

# The plans for next week 
    - using trello as mouch as possible 
    - ending it, 
    - send it out to people 
    - and create a lot of levels with assets and stuff 