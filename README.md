Wizualizacja pola wektorowego
===================================

### Opis projektu

Celem projektu jest napisanie programu, który pozwala wizualizować funkcję V = f(r) , gdzie V oraz r to wektory w przestrzeni 3D. Oczywiście program nie musi umieć interpretować żadnych funkcji wpisywanych przez użytkownika. Zestaw kilku przykładowych funkcji powinien zostać wpisany na stałe do kodu programu, a użytkownik powinien mieć możliwość wyboru jednej z nich i ewentualnie zmiany jej parametrów.

### Wymagania podstawowe

Program pozwala na wizualizację funkcji pola poprzez rysowanie **strzałek**, które mają początek w **punktach węzłowych**. Przedział zmienności argumentów X,Y,Z jak i to na ile odcinków dzielimy te przedziały podaje użytkownik. Współczynnik skalowania określający jak długie są strzałki użytkownik może zmieniać przy użyciu suwaka. Oczywiście całość można dowolnie **obracać**. Program posiada także kilka funkcji do wyboru. Funkcje te mają wstawione parametry swobodne, które użytkownik może zmieniać w trakcie pracy programu.

### Wymagania rozszerzone

W tej wersji program potrafi sam dobrać długość strzałek tak, aby najdłuższa nie była większa niż odległości węzeł-węzeł. Oczywiście użytkownik w dalszym ciągu posiada możliwość zmiany skali ręcznie. Istnieje tryb wyświetlania, w którym długości strzałek są stałe, a o wartości funkcji w węźle informuje nas kolor strzałki (standardowa skala – **niebieski** dla minimum – **czerwony** dla maksimum). Użytkownik ma możliwość zapisania wyniku na dysk w postaci pliku graficznego o zadanym. Program powinien mieć również możliwość „odcięcia” części węzłów poprzez wprowadzenie dodatkowej płaszczyzny. Wszystkie strzałki wychodzące z węzłów po wybranej stronie płaszczyzny nie będą rysowane.



### Plan:
+ Funkcje pola wektorowego wybierane z listy (możliwość manipulacji parametrami funkcji).
+ Wizualizacja pola poprzez rysowanie strzałek
+ Możliwość określenia przedziału zmiennności oraz ilości odcinków na ile dzielimy ten przedział
+ Możliwość zmianny długości strzałek za pomocą suwaka
+ (Rozszerzenie) Automatyczny dobór długości strzałek
+ (Rozszerzenie) Alternatywny sposób wyświetlania strzałek - stała długość + kolor
+ (Rozszerzenie) Możliwość zapisu wyniku na dysku w postaci bit mapy
+ (Rozszerzenie) Odcięcie części pola za pomocą płaszczyzny


### Inspiracje:
+ https://www.geogebra.org/m/u3xregNW
+ https://www.geogebra.org/m/KKB2Ndez
+ https://glennmarshall.wordpress.com/2014/10/31/3d-neon-vector-fields/
+ https://chart-studio.plotly.com/~empet/14971.embed
+ https://forum.dynamobim.com/t/vector-field-visualization/26862

===============================================================================

### Uruchomienie
Do zmiennych środowiskowych należy dodać ścieżkę do bibliotek WxWidgets. Wymagane biblioteki zostały załączone w folderze bin.

### Strzałki:
+ Długość = 1 w osi 0X (w pozostalych 0)
+ Zaczepiona w 0
+ Zmianna strzalki przez zmiane nazwy pliku na arrow1.geo