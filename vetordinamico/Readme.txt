Essa é uma atividade para a matéria de Algoritmos do curso de Tecnologia em Análise e Desenvolvimento de Sistemas.

Arquivos e Classes
Temos duas classes principais: Lista_ligada e Vetor_dinamico, cada uma com seus próprios arquivos de cabeçalho e implementação (Lista_ligada.hpp, Lista_ligada.cpp, Vetor_dinamico.hpp, e Vetor_dinamico.cpp).

Testes Básicos
Fornecemos alguns arquivos de teste básicos. Um arquivo de teste se chama push, e o outro remove_at. Esses programas mostram na saída de erro o tempo total necessário para realizar o teste a que se propõem.

Exemplos de Compilação e Execução
Para compilar e executar o arquivo de teste de push_front em uma Lista_ligada, use os comandos:

Copiar código
g++ -Wall -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp
./test-pushfront-linked-list-01 < push/e1.txt
Para compilar e executar o arquivo de teste de push_front em um Vetor_dinamico, use:

Copiar código
g++ -Wall -o test-pushfront-array-list-01 test-pushfront-array-list-01.cpp
./test-pushfront-array-list-01 < push/e1.txt
Arquivos de Base
Os arquivos de base para os testes de inserção são e1.txt, e2.txt, e3.txt, e4.txt, e5.txt, e6.txt, e7.txt, e e8.txt, localizados no diretório push/ ou remove_at/.

Cada arquivo começa com um número inteiro n, representando a quantidade total de números no arquivo. Seguem-se n linhas, cada uma com um número inteiro gerado aleatoriamente através do programa gen_array.cpp.

Gerar Arquivos Aleatórios
Para compilar o programa gen_array.cpp:

Copiar código
g++ -Wall -o gen_array gen_array.cpp
Para gerar um arquivo com 1000 números inteiros:

Copiar código
./gen_array 1000 > meu_teste.txt
O arquivo gerado meu_teste.txt terá n+1 linhas, com a primeira linha sendo o valor 1000 e as demais contendo valores inteiros gerados aleatoriamente.

Testes de remove_at
No diretório remove_at/, existem arquivos de teste r1.txt, r2.txt, r3.txt, r4.txt, r5.txt, e r6.txt. Esses arquivos inserem uma série de elementos e depois removem alguns pelo índice. Por exemplo, r1.txt e r2.txt inserem 15 elementos e depois removem 10, enquanto r3.txt, r4.txt, r5.txt, e r6.txt inserem 100, 1000, 10000, e 100000 elementos respectivamente, removendo uma porção específica desses elementos.

Exemplos de Compilação e Execução para remove_at
Para compilar e executar o arquivo de teste de remove_at em uma Lista_ligada, use:

Copiar código
g++ -Wall -o test-removeat-linked-list-01 test-removeat-linked-list-01.cpp
./test-removeat-linked-list-01 < remove_at/r1.txt
Para compilar e executar o arquivo de teste de remove_at em um Vetor_dinamico, use:

Copiar código
g++ -Wall -o test-removeat-array-list-01 test-removeat-array-list-01.cpp
./test-removeat-array-list-01 < remove_at/r1.txt