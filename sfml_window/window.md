# Window readme 

## images or custom shapes 
Because of simple and clean nature of game graphics 
the question unfolds:

should the images be simple 2d asset or custom colored polygon shape

| id |idea | image |polygon| 
| :---:| :---:| :---|:---|
| 1 | upload        |easy | will require a lot of work|
| 2 | scale   |images can be scaled, but there are definitely some minimal and maximal scale factor |limitless|
| 3 | color change  | no without custom loader (or some kind of vector loader and than sprite modification)|limitless|

# The decision

Images, but users can load their own assets (yey)

# Gui_context 

app will be divided in 4 parts
- intro with authors and stuff  
- level chose screen
- play level screen 
- edit level

and we need to switch between these on the go 
so the class [context](context/context.h) will keep all info about current displayed state 
buttons, text, and stuff this will simplify code 

#TODO


| id | story | description | completeness level| 
|:---:|:---:|:---| :---:|
| 1 | buttons with image| buttons witch load image from assets| 0%|
| 2 | repair existing buttons| they are not recognizing the hover neither the press| **done**|
| 3 | more contexts| 3 new screens | 0%|
| 4 | make it look pretty | better color composition and spacing and better player experience| 20%|
| 5 | react to the player input | change screen when requested, load level etc| 10%|

# why da fuck 
ok ok, so there's a bug: sometimes the cells overlap, 
a.k.a. are placed on top of each other 

| potential solution | more info|
|:---:|:---|
| weird data race| the text cell overrides position of the asset before the display happens| 
| wrong square positions| from the beginning the grid is fucked|

# final window customisation setting

|name |implementation form| description|
|:---:|:---:|:---|
|bloom effect| simple check box maybe with value attached to it| bloom is cool, and I always wanted to learn how to write cereals|
|custom assets| simply copy and paste to the level directory| 
|ui colors| value box in rgb| customize ui colors for you level|

# Questions to play and run sim and gen level

1. Do we need to keep board info as LevelInfo
    or should we keep directory path and game on their own  

2. How high should load assets be declared 
    I say let's implement it naively and one it works make it good 
    