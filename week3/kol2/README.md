# Kolorowanie grafu

Dany jest graf. Każdy wierzchołek grafu chcemy pomalować na biało lub czarno tak, aby końce każdej z krawędzi były różnych kolorów. Czy da się to zrobić?

Napisz program, który odpowie na postawione powyżej pytanie dla kilku różnych grafów.

Napisz funkcję:

```
	bool isGraph2Colorable(int vertexCount, int edgeCount, int *edge1, int *edge2);
```

Parametr `vertexCount` oznacza liczbę wierzchołków. Wierzchołki oznaczamy liczbami od `1` do `vertexCount`.
Parametr `edgeCount` oznacza liczbę krawędzi.
Tablice `edge1` i `edge2` zawierają co najmniej `edgeCount` elementów. Każdy z nich oznacza krawędź: z wierzchołka `edge1[i]` do wierzchołka `edge2[i]` (dla `0 <= i < edgeCount`).

Ograniczenia:
Liczba grafów do zbadania: maksymalnie 20.
Łączna liczba wiechołków grafów we wszystkich przypadkach testowych: maksymalnie 100000.
Łączna liczba krawędzi we wszystkich przypadkach testowych: maksymalnie 200000.

