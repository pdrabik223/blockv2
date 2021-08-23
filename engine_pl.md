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

ok działa kysz

pytanie 
jeżeli wstawiamy bloki tylko tam gdzie są jeszcze nullptr'y 
działa w prawo i na dół 

jeżeli nie to lewo i góra 
ok I got it 


zapisujemy wartości potem ją nadpisujemy 
bo wracamy sie do tego samego miejsca 
czyli napierw stawiamy blok w pozycji "po prawo", potem idziemy do bloku "po prawo" i on chce być tam gdzie jest 
więc nadpisujemy blok

kolejne pytanie brzmi: 
jak zrobić custom'owe ruchy gdyż one muszą mieć jakąś kolejność wykonywania się 
i teraz jak to wszystko zegrać razem nie męcząc się za bardzo 


do każdego kierunku w "transformation" powinna przypisana być wartość siły 
to poniekąd robi funkcja CrushBots 

ten pomysł jest dobry, ale rozwiązuje tylko jeden problem, jednego bloku 
a potrzebował 2 funkcji w każdym bloku i tablicy twardości w silniku, nie zadziała

trzeba wymyślić coś lepszego

