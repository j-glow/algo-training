Jest to zadanie w ramach konkursu na SW Academy Open Day.  

Pierwsza osoba, która rozwiąże je poprawnie (dostanie maksymalną liczbę punktów) otrzyma główną nagrodę.
Oprócz tego, na koniec konkursu wśród pozostałych poprawnych rozwiązań zostaną wylosowane dwa, które również zostaną nagrodzone.

# Bajtazar Fruwa Samolotem (BFS)

Limit pamięci: **256MB**  
Limit czasu: **5s C++ / 5s Java**

Bajtockie linie lotnicze wprowadziły promocyjną, stałą cenę na wybranych odcinkach.

Bajtazar chce skorzystać z tego i dostać się z miasta `start` do miasta `end` za pomocą tych połączeń, wykonując po drodze jak najmniej przesiadek.
Napisz funkcję, który wyznaczy minimalną liczbę lotów potrzebną do pokonania tej trasy. Jeśli to niemożliwe, zwróć `-1`.

Funkcja przyjmuje następujące argumenty:
```cpp
// C++
int solve(int n, int m, const char *start, const char *end, const char **a, const char **b);
```
```Java
// Java
int solve(int n, int m, char[] start, char[] end, char[][] a, char[][] b);
```
- `n` - liczba miast, `2 ≤ n ≤ 1000`
- `m` - liczba połączeń, `1 ≤ m ≤ 10000`
- `start` - miasto z którego Bajtazar wyrusza
- `end` - miasto, do którego Bajtazar chce dotrzeć
- `a, b` - siatka połączeń - możliwe loty mają postać `a[i] -> b[i]`

Miasta są reprezentowane przez nazwy, nie dłuższe niż 10 liter angielskiego alfabetu.
W C++ są one typu `const char*` zakończone zerem, a w Javie `char[]` o odpowiedniej długości.

## Przykład
Jeśli `start = "Vowecopu"`, `end = "Canyn"`, a siatka połączeń to:
```
Vowecopu -> Kanu
Kanu -> Popyjy
Pole -> Kanu
Vowecopu -> Kanu
Popyjy -> Canyn
Canyn -> Popyjy
Pole -> Vowecopu
Pole -> Kanu
Pole -> Vowecopu
Pole -> Popyjy
```
To odpowiedzią jest 3.