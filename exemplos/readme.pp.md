# Introdução ao C

!TOC

## Compilando
- O seu código deve ter a extensão .c
- Ele pode ser compilado com o gcc. 
    - No Windows instale o Mingw.
    - No linux, só instalar o pacote básico de desenvolvimento.
        - Ubuntu: sudo apt-get install build-essential
        - Arch: sudo pacman -S base-devel
- O seguinte Makefile pode ser utilizado para compilar e executar arquivos .c

        C = -std=c99 -Wall -Werror
        %: %.c
            g++ $(CFLAGS) $@.cpp -o exe_$@
            @ ./exe_$@
        clean:
            rm -rf exe_*

- Após isso, se o código fonte se charmar soma.c, digite 

        make soma

***
## Escopo

- Protótipo, argumentos, tipo de retorno
- Escopo Global e Local
- Operador de Resolução de Escopo (::)

!INCLUDECODE "00_escopo.cpp" (c++)

***
## Static

- Prefixadas pela palavra chave static
- Uma função declarada como estática só é acessı́vel dentro do arquivo onde foi criada.
- Variáveis estáticas são sensı́veis ao contexto.

!INCLUDECODE "00_static.cpp" (c++)

***
## Args

- argc é a quantidade de argumentos
- argv é a lista de argumentos

!INCLUDECODE "00_args.cpp" (c++)

***
## Memória dinãmica

- Memória dinâmica é alocada e desalocada com new e delete

!INCLUDECODE "00_dinamic.cpp" (c++)

***
## C - Funções

- Ponteiros para função do jeito C de ser
 
!INCLUDECODE "00_fpointer.cpp" (c++)

 ***
 ## C++ - Funções

- Jeito c++ de ser de passar funcoes c++11

!INCLUDECODE "00_fpointer2.cpp" (c++)

***
## Referências Dummy

 - Uso de variáveis dummy static para retornar referências

!INCLUDECODE "00_returnref.cpp" (c++)