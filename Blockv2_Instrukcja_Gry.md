# Block v2

## Kompilacja

Projekt przygotowany jest w oparciu o darmowe [SFML](https://www.sfml-dev.org/) Api i kompilowany przy użyciu
kompilatora [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/) w wersji 2019. Do koordynacji pakietów
wchodzących w skład projektu i generowania plików budujących użyto narzędzia [CMake](https://cmake.org/).

Projekt napisany przy użyciu narzędzia Cmake z łatwością może być konwertowany do projektu CodeBlocks.

Polecenie konsolowe konwertujące projekt Cmake do CodeBlocks:

```
cmake -G "CodeBlocks - MinGW Makefiles" -B <out-folder>
```

Oczywiście do uruchomienia polecenia wymagane jest posiadanie [aktualnej wersji Cmake](https://cmake.org/download/).

## Dodatkowe wymagane pliki

Z uwagi na przygotowany graficzny Interfejs wymagane, jest by pliki wyjściowe kompilacji znalazły się w konkretnej
orientacji względem folderu zawierającego grafiki użyte w projekcie. To samo tyczy się folderu zawierającego grywalne
poziomy.

Graf przedstawiający poprawne nazewnictwo i orientacje folderów:

```
Blockv2:
|
| -- Folder wyjściowy kompilacji 
|    |   
|    |  blockv2_main.exe
|    |  pliki.dll biblioteki sfml
| 
| -- levels 
|    |   
|    | -- default
|    |    |
|    |    | bazowe ikony gry
|    |   
|    | -- poziomy generowane przez użytkownika
|  
| -- sfml_window
|    |   
|    | -- assets
|    |    |
|    |    | -- level_creator
|    |    |
|    |    | -- level_player
|    |    |
|    |    | -- level_picker
|    |    |
|    |    | -- main_menu
|    |    |
|    |    | -- run_simulation
```

Foldery levels i sfml_window dostarczane wraz z kodem źródłowym, nie wymagają modyfikacji, tylko poprawnego ułożenia
względem wyjściowego folderu kompilacji.

## Pierwsze uruchomienie

Po udanej kompilacji i uruchomieniu pliku wejściowego "blockv2_main.cpp" oczom użytkownika powinien ukazać się ekran
startowy gry, wraz z wyborem trybów gry. Przy każdym uruchomieniu gry do głównego okienka uruchamiany jest wiersz
poleceń, używany do wyświetlania ewentualnych wiadomości błędów. Jeżeli główne okienko aplikacji nie zostanie
uruchomione a w wiersz poleceń ukaże się wiadomość "Failed to load Image", najprawdopodobniej      
dodatkowe wymagane pliki zostały żle zorientowane względem pliku ".exe", proszę raz jeszcze wykonać polecenia etapu "
Dodatkowe wymagane pliki".

## Opis Interfejsu

Interfejs graficzny dzieli się na kilka okienek (widoków/ kontekstów). Jako pierwsze użytkownikowi ukazuje się panel
głównego menu.

![main_manu](images/main_menu.jpg "Główne Menu")

Stąd gracz ma możliwość gry w zapisany na dysku poziom, lub przy użyciu narzędzia LevelCreator w prosty sposób stworzyć
własny poziom.

Po wybraniu Play level gracz przechodzi do okienka "Wybór Poziomów"

![level_picker](images/level_picker.jpg "Wybór Poziomów")

Po wejściu w jeden z poziomów na liście poziom ten zostanie załadowany z pamięci i zaprezentowany w oknie gry.

![level_player](images/level_player.jpg "Okno Gry")

LevelCreator pozwala na tworzenie i nazywanie własnych poziomów. stworzone w ten sposób łamigłówki dodawane są do listy
poziomów. Twórca ma możliwość tworzenia własnych skórek obiektów poruszających się po ekranie, jak i dodania własnego   
tła do poziomu. Wystarczy poprawnie nazwać dodawane przez siebie skórki (wymagane jest poprawne nazewnictwo, takie jak w
folderze default) i zapisanie ich w folderze o nazwie swojego poziomu.

![level_creator](images/level_creator.jpg "LevelCreator")

Przykład poziomu:
![example_level](images/example_level.jpg "Przykładowy level")

Przykład poziomu z tłem użytkownika:
![example_level](images/example_level2.jpg "Przykładowy level ze skórkami użytkownika")

