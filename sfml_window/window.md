# Window readme 

## images or custom shapes 
Because of simple and clean nature of game graphics 
the question unfolds:

should the images be simple 2d asset or custom colored polygon shape

| id |idea | image |polygon| 
| :---:| :---:| :---|:---|
| 1 | upload        |easy | will require a lot of work|
| 2 | saleability   |images can be scaled, but there are definitely some minimal and maximal scale factor |limitless|
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
so the class [context](context.h) will keep all info about current displayed state 
buttons, text, and stuff this will simplify code 

#TODO


| id | story | description | completeness level| 
|:---:|:---:|:---| :---:|
| 1 | buttons with image| buttons witch load image from assets| 0%|
| 2 | repair existing buttons| they are not recognizing the hover neither the press|40%|
| 3 | more contexts| 3 new screens | 0%|
| 4 | make it look pretty | better color composition and spacing and better player experience| 20%|
| 5 | react to the player input | change screen when requested, load level etc| 0%|

