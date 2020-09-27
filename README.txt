Código feito no e para o Linux. No Windows há problema na contagem do tempo, pois usei a função clock() para contar o tempo,
no lugar da QueryPerfomance. Além disso, o tamanho da pilha de recursão no Windows, por padrão, é menor que a do Linux,
e por isso, o programa crasha no Windows, para a entrada-gigante.txt, sendo necessário usar o editbin.exe do Visual Studio 
para alterar o tamanho da pilha.


Chamada ./lab2 <nome do arquivo de entrada>
Roda as quatro variações do quicksort para os dados do arquivo
