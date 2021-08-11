# The multi-thread approach

Wyobraźmy sobie sieć niezalażnych ale połączonych ze sobą komórek, które poruszają się na prostokątnej płaszczyźnie

# The multi-class requ based approach with movement direction field


Bloki dzielą się na dwa typy:

- funkcyjne (posiadające funkcję aktywującą requarencję)
- nie-funkcyjne / reakcyjne

zadaniem silnika jest koordynacja bloków między sobą i aktywowanie bloków funkcyjnych na początku każdej (tury)

Podział bloków

| Bloki Funkcyjne | Bloki nie-funkcyjne|
|:---:|:---:|
|engine|empty| 
|factory |basic|
| |bedrock|
| |tp|
| |goal|
| |turn|

1. czeszczenie przesunięć z poprzedniej tury 
2. przejście: generacja stron w które blok nie może się udać, (edge lock)
3. przejście: generacja przesunięć bloków 
4. wprowadzenie zmian do tablicy 