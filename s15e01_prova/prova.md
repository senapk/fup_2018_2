# (Auto) Avaliação de FUP

A prova deve ser feita de forma individual sem ajuda externa. Você pode fazer consulta a internet para tirar dúvidas de linguagem ou debugar um erro, mas não para procurar uma solução específica ou copiar de algum exercício que já tenha feito ou visto.

O tempo total de prova é 4 horas que você deve marcar. Pode dar um intervalo de 1 hora longe do computador. O que daria até 5 horas. 
Exemplo: 
- Senta, começa a fazer, 2 horas de prova.
- Sai pra tomar um banho e merendar. 30 min.
- Volta, passa mais 1 hora de prova. 
- Sai pra rezar, 30 min. 
- Volta e completa a prova com mais 1 hora.
- Total: 4 horas de prova, 1 de descanso.

Se por diversão, quiser continuar tentando uma questão por 20 horas seguidas por exemplo, pela sua honra, você pode, mas deixe claro no relatório o que você fez dentro das 5 horas e o que fez fora das 5 horas. Sugiro fazer o máximo que puder dentro do tempo, começando pelas mais fáceis.

Ao final, você deve enviar um arquivo zipado com seu nome no formato fulano_da_silva.zip.
Dentro dele deve ter.
- relatorio.txt
- 1a_exemplares.c
- 1a_sozinha.c
- 1a_repetida.c
- 2a_gerador_nomes.c
- passando_a_limpo.txt

No relatório, você faz escrever como foi a prova, quais as questões que fez ou que não fez e se fez algo além fora das 5 horas de prova.

O que for feito fora do tempo vai ser considerado parcialmente como extra. Lembre que essa não é uma nota absoluta, é uma avaliação com auto avaliação. O importante é o conjunto daquilo que você já fez, aprendeu, colocou no moodle, desenvolveu em sala.

Lembre: envie o arquivo seu_nome.zip para o link a seguir até meio dia.

https://www.dropbox.com/request/G5lOPf5lPqA8uRLk9fB4

## Vetores

### Grande fila colorida

- Na entrada de um evento, os participantes ganhavam uma camisa de brinde para usar.
- A camisa era sempre de uma cor só e eles podiam escolher a cor que quisessem.
- Cada camisa tinha um número que ia de -10 até 10 que representava aquela cor.
- Após vestirem suas camisas, os participantes formaram uma grande fila.
- A cor -10 representa a cor azul e a 10 a cor vermelha.
- Dois números iguais significam duas cores iguais. 
- As cores vão gradativamente da mais fria até a mais quente.
- Uma camera sobre o saguao do evento coletou as cores da fila e enviou para um computador que vai processar e responder as seguintes perguntas.

Questões:

- 1. **exemplares**: Quais cores apareceram na fila? Mostre ordenadamente. (2 pontos)
- 2. **sozinhas**: Quantas pessoas eram a única representate da sua cor na fila? Mostre ordenado. (1 ponto).
- 3. **repetida**: Qual cor apareceu mais vezes na fila e quantas vezes ela apareceu? Se houver empate, mostre todas as vencedoras. (3 pontos)

Entrada: 
- 1a linha: a quantidade de elementos
- 2a linha: o valor dos elementos

```
>>
10
-1 1 4 3 9 -5 -5 3 2 1
<<
exemplares: -5, -1, 1, 2, 3, 4, 9
sozinhas: -1, 2, 4, 9
mais vezes: 2 vezes: -5, 1
```

# Strings

- Faça um gerador de nomes aleatório. Cada nome é composto de nome e sobrenome. (3 pontos)
- Sugestões:
    - Cada palavra deve ter entre uma quantidade variável de letras.
    - Pode alternar vogais e consoantes.
    - A primeira letra deve ser maiúscula
    - Se preferir, pode inventar regra, desde que gere um nome legível.

```ruby
./novo_nome
>> Pali Mulaco

./novo_nome
>> Ubip Noveki

./novo_nome
>> Picole Capu
```

# Passando a limpo.
- Marque com honestidade quais temas você estudou ou fez práticas com valores de 1 a 3, usando a seguinte referência:
- 1. Nunca fiz uma prática do tema.
- 2. Fiz apenas a prática em sala de aula.
- 3. Revi o conteúdo ou estudei o tema em casa.

- [ ] Matrizes
- [ ] Ponteiros
- [ ] Alocação dinâmica
- [ ] Arquivos
- [ ] Compilação Separada
- [ ] SDL