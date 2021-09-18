# Block v2

Gra Block v2 napisana została w języku c++ standardzie 11+, kompilowana przy użyciu
kompilatora [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/) w wersji 2019.

## Schemat klas

Strzałki zakończone grotem symbolizują dziedziczenie, zakończone okręgiem zawieranie.
[Link do wersji online poniższego grafu.](https://miro.com/app/board/o9J_lwSBXYM=/)

![project](images/klas.png "blockv2")

Jak widać na załączonym schemacie projekt można podzielić na trzy drzewa klas, kilka klas grupujących odpowiedzialnych
za koordynacje elementów i dodatkowe struktury pomocnicze.

## Drzewo klas "Button"

![button](images/button.png "blockv2")

Odpowiadają za reakcje na informacje wprowadzane przez użytkownika, są ściśle związane z biblioteką SFML.

## Drzewo klas "Context"

![button](images/context.png "blockv2")

Obsługują poszczególne okna aplikacji, bezpośrednio pisane pod współpracę z biblioteką SFML.

## Drzewo klas "Bot"

![bot](images/Bot.png "blockv2")

Niezależne od żadnej z bibliotek, stanową logiczną podstawę silnika gry. Do poprawnego funkcjonowania nie wymagają
informacji o peryferiach.

## Silnik gry

Klasa GameEngine zarówno, jak i Level info, nie mają wiedzy o sposobie ich używania, istnieją tylko jako logiczne
obiekty, nie wymagają przez to zewnętrznych bibliotek do funkcjonowania.

## Plik wejściowy aplikacji

![main](images/main.png "blockv2")

Tak wyglądać powinien plik mian.cpp używający biblioteki Block v2.