# Most Safe Dir

Twoim zadaniem jest napisanie kilku funcji obsługujących podstawowe operacje systemu plików.

```
	void init();
	void makeDir(char *path, char *name);
	void makeLink(char *pathSrc, char *pathDst);
	void makeSystemFile(char *path);
	void getMostSafeDir(char *result);
```

Funkcja `init` rozpoczyna nowy przypadek testowy.
Na początku file system jest pusty, tzn. zawiera tylko katalog główny `'/'`.

Funkcja `makeDir` tworzy nowy katalog o nazwie `name` jako dziecko katalogu określonego przez `path`.

Funkcja `makeLink` tworzy link symboliczny, który pozwala przejść z katalogu `pathSrc` bezpośrednio do katalogu `pathDsc`.

Funkcja `makeSystemFile` oznacza katalog jako systemowy.

Funkcja `getMostSafeDir` przeszukuje file system w poszukiwaniu najbezpieczniejszego katalogu.
Jeśli jest wiele takich katalogów, można zwrócić dowolny z nich.

Aby określić stopień bezpieczeństwa katalogu wyobraźmy sobie, że umieszczamy w nim wirusa.
Ten wirus w każdej kolejnej jednostce czasu rozprzestrzenia się po systemie plików we wszystkich stronach.
W jednym kroku może on:
- przejść do katalogu rodzica,
- przejść do katalogu dziecka,
- przejść po linku symbolicznym.

Stopień bezpieczeństwa katalogu, to czas potrzebny wirusowi do dotarcia do jakiegokolwiek katalogu systemowego.
Oczywiście im większa wartość, tym katalog jest bezpieczniejszy.

![msd1.png](msd1.png)

Rysunek powyżej pokazuje przykład prostego systemu plików.
Stopień bezpieczeństwa katalogu `/a/c/` to `3`.

Warto zauważyć, że w powyższym przykładzie jako najbezpieczniejszy może być również znaleziony katalog `/a/`.

**Ograniczenia:**
- nazwy katalogów `name`: tylko małe literki `'a-z'`, długość od `1` do `10` znaków,
- ścieżki `path`/`pathSrc`/`pathDst`: zawsze zaczynają się i kończą znakiem `/`, maksymalna długość to `1000` znaków,
- maksymalna liczba wywołań `init`: `25`,
- maksymalna liczba wywołań `getMostSafeDir`: `1000` w jednym teście (tzn. po każdym `init`),
- maksymalna liczba wywołań każdej z pozostałych funkcji: `10000` (tzn. po każdym `init`),
- wszystkie napisy przekazane są w stylu napisów `C`, tzn. są zakończone znakiej `'\0'`,
- wszystkie operacje są poprawne, co oznacza w szczególności, że:
  - każda ścieżka pojawiająca się jako parametr opisuje istniejący w systemie plików katalog,
  - przy tworzeniu katalogu: katalog `path` nie ma dziecka o nazwie `name`.

**Przykład:**

```
init();
makeDir("/", "a");
makeDir("/", "b");
makeDir("/a/", "c");
makeDir("/b/", "d");
makeDir("/b/", "e");
makeSystemFile("/b/d/");
getMostSafeDir(...); // => "/a/c/"
makeSystemFile("/a/c");
getMostSafeDir(...); // => "/" lub "/b/e/"
makeLink("/b/e/", "/b/d/");
getMostSafeDir(...); // => "/"
```

Poniższe rysunki są wyjaśnieniem do przykładu.

![msd2.png](msd2.png)

![msd3.png](msd3.png)

![msd4.png](msd4.png)
