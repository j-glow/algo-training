# Logo (LOG)

Limit pamięci: **64MB**  

Bajtazar chce za pomocą pieczątek nanieść logo swojej firmy na papier firmowy.
Papier to kwadrat o wymiarach 10×10. Pieczątki również są kwadratowe, o wymiarach 4×4. Bajtazar może je obracać oraz przybić w dowolnym miejscu kartki, ale cały obszar pieczątki musi się na niej mieścić.
Każdą pieczątkę można użyć co najwyżej raz. Dodatkowo Bajtazar chciałby użyć ich jak najmniej.

Napisz funkcję, która obliczy minimalną liczbę pieczątek potrzebnych do wykonania logo. 
Jeśli to niemożliwe, zwróć -1.

```java
Java:
int solve(int n, char[][] logo, char stamps[][][])
```
```cpp
C++:
int solve(int n, char[10][10] logo, char stamps[][4][4])
```

Tablica `logo` pokazuje jak ma wyglądać efekt końcowy. Tablica `stamps` zawiera `n` pieczątek.
W obu tablicach `1` oznacza zamalowany obszar, a `0` - niezamalowany.

Można odcisnąć wiele pieczątek w tym samym miejscu - obszar będzie dalej prawidłowo zamalowany.

## Ograniczenia
`n ≤ 8`  
Funkcja `solve` zostanie wywołana najwyżej 10 razy.

## Przykład
Jeśli logo Bajtazara wygląda tak:  
![image](logo.png)

I mamy do dyspozycji 3 pieczątki:  
![image](123.png)  
To nie uda się stworzyć logo (pamiętajmy - pieczątki nie mogą wystawać za kartkę!).  
Odpowiedzią jest zatem `-1`.

Natomiast jeśli dodamy czwartą pieczątkę:  
![image](4.png)

Wówczas da się uzyskać logo - wystarczy użyć pierwszej obróconej w lewo (podświetlona na czerwono) oraz czwartej obróconej w prawo (podświetlona na niebiesko).  
Odpowiedzią jest zatem `2`.  
![image](logo2.png)  

Ten sam przykład znajduje się w pliku `LOG0.in`.