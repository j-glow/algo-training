# Nadgodziny

Limit czasu wykonania: 1 sek. Limit dostępnej pamięci: 60 MB

Firma Bajtung jest przyjazna dla swoich pracowników. Panuje tu miła atmosfera, zadania do wykonania są ciekawe i ambitne, a dodatkowo firma znana jest z wysokich zarobków oraz atrakcyjnych benefitów.

Bajtazar kieruje n osobowym zespołem. Właśnie otrzymał od szefów z BQ k dodatkowych zadań, które chce przydzielić do wykonania swoim pracownikom w ramach dodatkowo płatnych nadgodzin. Bajtazar wie, że pojedynczego zadania nie można podzielić pomiędzy kilka osób a ponadto jego pracownicy tracą motywację do pracy, gdy w ramach nadgodzin muszą zajmować się więcej niż jednym zadaniem. A wiadomo, że brak motywacji u pracowników to najgorsza rzecz, która mogłaby się zdarzyć w firmie Bajtung. Bajtazar doskonale zna swój zespół i wie dokładnie jaki jest czas wykonania zadania nr j przez osobę nr i; konkretnie Bajtazar zna wartość cost[i][j], czyli kwota, którą musiałby wypłacić osobie nr i za wykonanie zadania nr j. Oczywiście Bajtazar dba o budżet projektu, więc chciałby zminimalizować koszt nadgodzin.

Pomóż Bajtazarowi przydzielić zadania do pracowników tak, aby:

 - każde zadanie zostało przydzielone do dokładnie jednej osoby,
 - każda osoba otrzymała co najwyżej jedno zadanie do wykonania,
 - sumaryczny koszt wykonania zadań był jak najniższy.

Jako odpowiedź wystarczy, że podasz ten minimalny koszt.

Napisz funkcję, która obliczy minimalny koszt wykonania zadań:

```C++
    long long getMinimumCost(int n, int k, long long cost[15][8]);
```
```Java
    long getMinimumCost(int n, int k, long[][] cost);
```
Ograniczenia:
- `1 <= n <= 15`,
- `1 <= k <= 8`,
- `k <= n`,
- `1 <= cost[i][j] <= 10^16`,
- liczba wywołań funkcji `getMinimumCost` nie przekracza 10.
