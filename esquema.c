/*
 * Entradas:
 * 1. Arquivo (fd)
 * 2. Standard Input (stdin)
 *    - O stdin é chamado quando colocamos 0 ao invés de 1 nas funções da
 *      biblioteca unistd.h, ou seja, no write, read e open
 * 
 * Começando tudo:
 * 1. Verificar se fd e line existem
 * 2. Abrir arquivo com o read
 * 		- variável p/ armazenar texto (temp)
 * 		- variável estática (ret) = armazena bytes lidos (posição/cursor)
 * 3. Armazenar tudo do temp na variável estática resto com strjoin
 * 4. Verificar se temp tem \n
 * 		- se sim
 * 			- alocar tudo até \n na *line com strcut
 * 			- o que sobrou, armazenamos na variável resto com o próprio strcut anterior
 * 			- retornar 1
 * 		- se não
 * 			- Ainda tem o que ser lido?
 * 				- se sim
 * 					- ler novamente pelo read
 * 					- reiniciar processo de verificar se tem /n
 * 				- se não
 * 					- alocar tudo na *line com strdup
 * 					- free no resto e no temp
 * 					- retornar 0
 */

/*
 * ft_strdup (char *string, int posicaoInicial, int posicaoFinal) -> return(char *outraString)
 * Aloca uma varíavel char *outraString e copia nela a variável char *string, 
 * começando em posicaoInicial até posicaoFinal
*/

/*
 * ft_newline (char *string) -> return(int posicao)
 * Descobre se existe \n e retorna sua posição
*/

/*
 * ft_strlen (char *string) -> return(int tamanho)
*/

/*
 * ft_bzero (char *string)
 * Limpa a string com 'NULL'
*/

/*
 * ft_strcpy (char *string, char *temp)
 * Copia de *temp para *string
*/

/*
 * ft_strcut (char *string, int posicaoDivisao) -> return(char *line)
 * Cria variável char *line, aloca memória de tamanho i + 1
 * Cria variável char *temp, aloca memória de tamanho (size(resto) - i) + 1
 * Armazena no *line a string até a posição i, adiciona /0
 * Armazena no *temp a string de (i + 1) até /0 do resto
 * ft_bzero(resto) -> para deixar o resto como NULL
 * ft_strcpy(resto, temp) -> para copiar o que tiver em temp no resto
 * Retorna line
*/