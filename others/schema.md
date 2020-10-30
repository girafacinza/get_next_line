## Entradas
1. Arquivo (fd)
1. Standard Input (stdin)
   * O stdin é chamado quando colocamos 0 ao invés de 1 nas funções da biblioteca unistd.h, ou seja, no write, read e open

## Lógica
1. Verificar se fd e line existem
1. Abrir arquivo com o read
	* variável p/ armazenar texto (__temp__)
	* variável estática (__ret__) = armazena bytes lidos (posição/cursor)
1. Armazenar tudo do __temp__ na variável estática resto com __strjoin__
1. Verificar se temp tem '\n'
	* sim
		* alocar tudo até '\n' na __\*line__ com strcut
		* o que sobrou, armazenamos na variável resto com o próprio strcut anterior
		* retornar 1
	* não
		* Ainda tem o que ser lido?
			* sim
				* ler novamente pelo read
				* reiniciar processo de verificar se tem '/n'
			* não
				* alocar tudo na __\*line__ com strdup
				* free no resto e no temp
				* retornar 0
