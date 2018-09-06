
# Parte 1 - Algoritmo básico

## Acertando
```
Escolhi um numero entre 0 e 1000.
Você tem 10 chances de acertar.
$ 20
É maior. Você tem 9 chances.
$ 900
É menor. Você tem 8 chances.
$ 500
É maior. Você tem 7 chances.
$ 728
Parabéns. Você acertou.
```

## Errando
```
Escolhi um numero entre 0 e 1000.
Você tem 10 chances de acertar.
$ 20
É maior. Você tem 9 chances.
$ 900
É menor. Você tem 8 chances.
$ 500
É maior. Você tem 7 chances.
...
Que pena. O número era 728.
```

# Parte 2
- Dê a mensagem de parabéns de acordo com o critério
    - 1 chute: você é o Chuck Noris.
    - < 4 : você o Chapolin.
    - < 9 : você é o Jaspion.
    - 10 : você é cagado.

# Parte 3
- Você começa com 100 reais.
- No começo do jogo, você aposta o tanto que quiser.
- Você recebe (10 - qtdChutes) vezes o que apostou.
- Ex:
    - apostou 50.
    - acertou no 2o chute.
    - ela recebe: (10 - 2) * 50

# Orientação

- Para gerar um número aleatório use a função rand() da biblioteca stdlib.h
- O rand() vai gerar um número entre 0 e MAXINT.

```c
#include <stdio.h>
#include <stdlib.h>//rand()

int main(){
    int number = rand() % 100;
    printf("%d\n", number);
    return 0;
}



```

