# Sieć sklepów (Shops)

Limit pamięci: **256MB**  
Limit czasu: **10s C++ / 10s Java**

Sieć sklepów "Bajcik" chce pochwalić się w reklamie, że każdy mieszkaniec ma blisko do ich placówki - planowano hasło "Bajcik - dotrzesz do nas w 5 minut". 
Zarząd nie jest jednak pewien, czy jest to prawda. W tym celu potrzebują twojej pomocy.
Wyznacz minimalny czas T, taki, że z każdego mieszkania w Bajtogrodzie da się dotrzeć do sklepu "Bajcik" w czasie co najwyżej T minut.

Aby tego dokonać, dostaniesz mapę Bajtogrodu.
Ma ona postać kwadratowej siatki o rozmiarach 256⨯256, w której z każdego pola da się przejść na sąsiednie w czasie 1 minuty. Nie można poruszać się na ukos. 
Litera S oznacza sklep, litera M mieszkania, kropka to ulica, a P oznacza teren przemysłowy, na który nie wolno wchodzić. Dodatkowo warto wspomnieć, że mieszkania w Bajtocji budowane są tak, że da się przejść przez zabudowane nimi pole. 
W Bajtogrodzie na pewno istnieje przynajmniej jeden sklep i przynajmniej jedno mieszkanie.

Rozwiązanie zamieść w funkcji
```java
Java:
int getDistance(char[][] map);
```
```C++
Java:
int getDistance(char map[256][256]);
```
Odpowiedzią powinno być maksimum spośród odległości od dowolnego mieszkania do najbliższego sklepu, rozumianą jako ilość przejść na sąsiednie pole.
Jeśli z jakiegoś mieszkania nie da się dotrzeć do żadnego sklepu, należy zwrócić -1.

## Przykład
Dla następującej mapy miasta:
```
........................................
..SPPPPPP........................S......
PPPP....P...............................
........P...............M...............
........P...............................
...M....PP..............................
.......SMP.MM...........................
........P..MM...........................
.PPPPPPPP...............................
........................................
```
Odpowiedzią jest 18.
