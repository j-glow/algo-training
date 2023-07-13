# Przelewanie wody (water)
Dysponujemy n naczyniami. Wszystkie naczynia są początkowo całkowicie wypełnione wodą. Pojemność i-tego naczynia to o[i].

Wolno wykonywać trzy rodzaje ruchów:

Przelanie całej zawartości z jednego naczynia do drugiego. Ruch ten można wykonać tylko wtedy, gdy w drugim naczyniu jest wystarczająco dużo wolnego miejsca.
Dolanie wody do pełna z jednego naczynia do drugiego.
Wylanie całej zawartości jednego naczynia do zlewu.

Twoim zadaniem jest doprowadzenie za pomocą najmniejszej możliwej liczby operacji do sytuacji, w której w i-tym naczyniu będzie się znajdować `w[i]` litrów wody.

Ograniczenia:
- `1 <= n <= 4`
- `0 <= w[i] <= o[i] < 50`

Skorzystaj z interfejsu sędziego. Wynikiem funkcji powinna być minimalna liczba ruchów lub -1, jeśli nie ma możliwości doprowadzenia do sytuacji końcowej.

```cpp
#include "judge.h"

class water : public iwater {
public:
    virtual int minMoves(int n, int c[4], int b[4]) { return 0; }
};

int main() {
    water w;
    judge::run(&w);
}
```
```cpp
public class water {
    
    int minMoves(int n, int o[], int w[]) { return 0; }

    public static void main(String[] args) {
        water c = new water();
        judge.run(c);
    }
}
```

W dziale pliki znajduje się paczka z przykładami.