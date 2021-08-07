# The multi-thread approach

Wyobraźmy sobie sieć niezalażnych ale połączonych ze sobą komórek, które poruszają się na prostokątnej płaszczyźnie

# The multi-class requ based approach

Bloki dzielą się na dwa typy:

- funkcyjne (posiadające funkcję aktywującą requarencję)
- nie-funkcyjne / reakcyjne

zadaniem silnika jest koordynacja bloków między sobą i aktywowanie bloków funkcyjnych na początku każdej (tury)

Po akrywacji bloki funkcyjne będą generować ścieżki rekurencyjne zmieniające pozycje, stan boków nie-funkcyjnych

Podział bloków

| Bloki Funkcyjne | Bloki nie-funkcyjne|
|:---:|:---:|
|engine|empty| 
|factory |basic|
| |bedrock|
| |tp|
| |goal|
| |turn|

