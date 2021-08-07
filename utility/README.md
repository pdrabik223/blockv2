# Utility

The directory contains different supporting classes

| id | name | description |
|:---:|:---:|:---|
| 1 |[2D point](coord.h)| unified across whole project, represents point in 2d space |
| 2 |[rect](rect.h)| class representing simple rectangle |
| 3 |[transposition](transposition.h)| 1st approach to simplify game engine, the main problem with last iteration was collision handling, this (I suppose) is the answer to the collisions problem
| 4 |[movement-direction](movement_direction.h)| handles  pieces movement |
# movement direction truth table

|  + | none | up| down | left|  right| lock_horizontal|lock_vertical| lock_global| 
|:---:|:---: |:---: |:---:| :---:| :---:| :---: |:---:| :---:|
| **none** |none|up| down | left|  right| lock_horizontal|lock_vertical| lock_global|
| **up** |up| up|lock_vertical|left|up|up|lock_vertical|lock_global|
| **down** |down|lock_vertical|down|down|right|down|lock_vertical|lock_global|
| **left** |left|left|down|left|lock_horizontal|lock_horizontal|left|lock_global|
| **right** |right|up|right|lock_horizontal|right|lock_horizontal|right|lock_global|
| **lock_horizontal** |lock_horizontal|up|down|lock_horizontal|lock_horizontal|lock_horizontal|lock_global |lock_global |
| **lock_vertical** |lock_vertical|lock_vertical|lock_vertical|left|right|lock_global|lock_vertical|lock_global|
| **lock_global** | lock_global |lock_global |lock_global |lock_global |lock_global |lock_global |lock_global |lock_global | 