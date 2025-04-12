---
author: Construção de compiladores I
title: Exercícios para revisão.
date: Prof. Rodrigo Ribeiro
---

Introdução
==========

Setup inicial
-------------

Inicialmente, vamos importar bibliotecas para construção de
testes de programas Haskell. Utilizaremos funções destas
bibliotecas para construção de testes para os exercícios
deste material.

> import           Control.Monad
> import           Data.Char
> import           Data.List                             hiding (lines)
> import           Prelude                               hiding (words, lines, Word)
> import qualified Prelude                as P (words) 
> import           Test.Tasty
> import           Test.Tasty.HUnit
> import qualified Test.Tasty.QuickCheck  as QC

> import Data.Maybe (fromJust, fromMaybe, isNothing)

A seguinte função `main` é usada apenas para
execução dos testes para a primeira parte dos exercícios propostos.

> main :: IO ()
> main = defaultMain tests

```
$> stack build
$> stack exec haskell-review
```

O primeiro é responsável por compilar o projeto e o
segundo de executá-lo.

Assim como no material da semana anterior, você deve substituir as
chamadas para a função

> tODO :: a
> tODO = undefined

que interompe a execução do programa com uma
mensagem de erro, por código que implementa
as funcionalidades requeridas por cada exercício.

Parte 1. Recursão e funções de ordem superior sobre listas. 
===========================================================

Esse material consiste em exercícios sobre o conteúdo de listas e funções
de ordem superior.

Antes de resolver os exercícios contidos nesse material, recomendo que você
leia os seguintes capítulos de 1 a 6 do livro 
[Learn you a Haskell for Great Good](https://learnyouahaskell.com/chapters).

Criação de um índice
--------------------

Introdução
----------

O objetivo desse exercício é a criação de funções de processamento de texto para
criação de um índice remissivo. É muito comum que livros possuam esse tipo de
índice em que palavras ou termos de interesse são associados a página onde
ocorrem. Como não lidaremos com textos dividos em páginas fixas, nosso índice
indicará em que _linha_ do texto um certo termo ocorre. Como exemplo, considere
o texto:

     Uma rosa é \n uma rosa \n bem rosa.

usando o programa a ser construído sobre o texto devemos obter
o seguinte índice:

      uma  1, 2
      rosa 1, 2, 3
      bem  3

Modelando o problema
--------------------

Para modelar esse problema, devemos inicialmente definir os tipos envolvidos
nos parâmetros de entrada e resultados desse programa. Sabemos que a entrada
corresponde a um texto. Para fins de legibilidade do código, usaremos um
sinônimo de tipo:

> type Text = String

Adicionalmente, devemos produzir um índice composto por palavras e a linha em que
essas ocorrem. Inicialmente, vamos acrescentar sinônimos para linhas e palavras
contidas no texto.

> type Line = String
> type Word = String

Finalmente, representaremos o índice resultante como uma lista formada por
pares contendo a lista de linhas em que uma palavra ocorre e a palavra em si.

> type Index = [([Int], Word)]

A construção `type` de Haskell permite a definição de um _sinônimo de tipo_, isto é,
um novo nome para um tipo existente.

Para solucionar esse problema, vamos adotar uma abordagem _data-driven_, isto é,
desenvolveremos esse algoritmo criando funções que mostram como a entrada é
transformada, passo a passo, no resultado desejado. Os exercícios seguintes
apresentam a solução passo a passo deste problema.


1. Implemente a função `lines` que divide o texto de entrada em uma lista
das linhas que o formam.


> countUntilToken :: Char -> String -> Int
> countUntilToken _ [] = 0
> countUntilToken token (x : xs)
>     | x /= token = 1 + countUntilToken token xs
>     | otherwise = 0

> separateByToken :: Char -> String -> [String]
> separateByToken _ [] = []
> separateByToken token xs = take n xs : separateByToken token resto
>     where
>         n = countUntilToken token xs 
>         resto = drop (n+1) xs

> lines :: Text -> [Line]
> lines = separateByToken '\n'

Os seguintes casos de teste devem ser satisfeitos por sua implementação de `lines`.

> lineTests :: TestTree
> lineTests
>    = testGroup "Tests for lines"
>                [
>                  testCase "lines empty"   $ lines ""              @?= []
>                , testCase "lines single"  $ lines "abc"           @?= ["abc"]
>                , testCase "lines many 1"  $ lines "a\nbc\ncd"     @?= ["a","bc","cd"]
>                , testCase "lines many 2"  $ lines "ab\ncd ef\ngh" @?= ["ab", "cd ef", "gh"]
>                ] 


2. Implemente a função `numberLines` que associa a cada linha o seu respectivo
número.

> numberLines :: [Line] -> [(Int, Line)]
> numberLines = zip [1..]

Os seguintes casos de teste devem ser satisfeitos por sua implementação de `numberLines`.

> numberLinesTests :: TestTree
> numberLinesTests
>   = testGroup "Tests for numberLines"
>               [
>                  testCase "number lines empty"   $ numberLines []                    @?= []
>                , testCase "number lines single"  $ numberLines ["abc"]               @?= [(1,"abc")]
>                , testCase "number lines many 1"  $ numberLines ["a", "bc", "cd"]     @?= [(1,"a"),(2,"bc"),(3,"cd")]
>                , testCase "number lines many 2"  $ numberLines ["ab", "cd ef", "gh"] @?= [(1,"ab"), (2,"cd ef"), (3,"gh")] 
>                ] 


3. Desenvolva a função

> numberWords :: (Int,Line) -> [(Int, Word)]
> numberWords (i, xs) = map (\x -> (i, x)) (separateByToken ' ' xs)

que divide uma linhas nas palavras que a formam adicionando a cada palavra o número da
linha em que essa está contida. Os seguintes casos de teste devem ser satisfeitos por
sua implementação de `numberWords`. 

> numberWordsTests :: TestTree
> numberWordsTests
>   = testGroup "Tests for numberWords"
>               [
>                  testCase "number words single"  $ numberWords (1,"abc")     @?= [(1,"abc")]
>                , testCase "number lines many"  $ numberWords (2, "cd ef gh") @?= [(2,"cd"),(2,"ef"),(2,"gh")] 
>               ] 


4. Utilizando sua função `numberWorlds`, implemente

> numberAll :: [(Int, Line)] -> [(Int, Word)]
> numberAll = concatMap numberWords

que associa a todos palavras de um texto o seu respectivo número de linha.

Sua implementação de `numberAll` deve satisfazer os seguintes casos de teste.

> numberAllTests :: TestTree
> numberAllTests
>   = testGroup "Tests for numberAll"
>               [
>                 testCase "numberAll empty"  $ numberAll []                            @?= []
>               , testCase "numberAll single" $ numberAll [(1, "ab cd ef")]             @?= [(1, "ab"), (1, "cd"), (1,"ef")] 
>               , testCase "numberAll many"   $ numberAll [(1, "ab cd"),  (2, "ef gh")] @?= [(1, "ab"), (1,"cd"), (2, "ef"), (2, "gh")]
>               ]


5. Desenvolva a função

> quicksort :: (a -> a -> Bool) -> [a] -> [a]
> quicksort _ [] = []
> quicksort cmp (pivo : xs) =
>     menores ++ [pivo] ++ maiores
>   where
>     menores = quicksort cmp [x | x <- xs, x `cmp` pivo]
>     maiores = quicksort cmp [x | x <- xs, pivo `cmp` x]
> 
> sortEntries :: [(Int,Word)] -> [(Int, Word)]
> sortEntries = quicksort (.<.)

que ordena uma lista de palavras e números de linhas utilizando a seguinte
função de comparação:

> (.<.) :: (Int, Word) -> (Int, Word) -> Bool
> (l1, w1) .<. (l2, w2)
>    = w1 < w2 || (w1 == w2 && l1 < l2)

Sua função de ordenação deve satisfazer os seguintes testes.

> sortEntriesTests :: TestTree
> sortEntriesTests
>   = testGroup "Tests for sortEntries"
>               [
>                  testCase "sort entries empty"   $ sortEntries []                                       @?= []
>                , testCase "sort entries single"  $ sortEntries [(1,"abc")]                              @?= [(1,"abc")]
>                , testCase "sort entries many 1"  $ sortEntries [(1,"a"),(2,"bc"),(3,"cd")]              @?= [(1,"a"),(2,"bc"),(3,"cd")]
>                , testCase "sort entries many 2"  $ sortEntries [(1,"ab"), (2,"cd"), (2,"af"), (3,"gh")] @?= [(1,"ab"), (2,"af"), (2,"cd"), (3,"gh")] 
>               ] 

6. Implemente a função

> wordIndexes :: [(Int, Word)] -> Word -> [Int]
> wordIndexes [] _ = []
> wordIndexes ((i, w) : xs) word
>     | w == word = i : wordIndexes xs word
>     | otherwise = wordIndexes xs word

> rmDuplicatedWords :: [(Int, Word)] -> [Word]
> rmDuplicatedWords [] = []
> rmDuplicatedWords ((_, w) : xs) 
>     | w `elem` ac = ac
>     | otherwise = w : ac
>     where
>         ac = rmDuplicatedWords xs

> combine :: [(Int, Word)] -> Index
> combine xs = [(wordIndexes xs word, word) | word <- rmDuplicatedWords xs]

que a partir de uma lista contendo pares de palavras e suas respectivas linhas,
combina os números de linha de uma certa palavra em uma lista de números para
formar o índice.

Sua implementação de `combine` deve obedecer os seguintes casos de teste.


> combineTests :: TestTree
> combineTests
>   = testGroup "Tests for combine"
>               [
>                  testCase "combine empty"  $ combine []                                        @?= []
>                , testCase "combine single" $ combine [(1,"a"),(2,"bc"),(3,"cd")]               @?= [([1],"a"),([2],"bc"),([3],"cd")]
>                , testCase "combine many"   $ combine [(1,"ab"), (2,"af"), (3,"af"), (3,"gh")]  @?= [([1],"ab"), ([2,3],"af"),([3],"gh")] 
>               ]


7. Finalmente, de posse de todas as funções anteriores, implemente a função

> makeIndex :: Text -> Index
> makeIndex text = combine . sortEntries . numberAll . concatMap numberWords . numberLines $ lines text

que a partir de um texto retorna o seu índice remissivo. Sua função deve ser
codificada como a composição de todos os exercícios desenvolvidos anteriormente.


Parte 2. Construindo uma máquina virtual simples 
================================================

Para a resolução dos exercícios propostos nesta seção, recomendo a leitura
do capítulo 8 do livro 
[Learn you a Haskell for Great Good](https://learnyouahaskell.com/chapters). 


Introdução
----------

Máquinas virtuais são um mecanismo amplamente utilizado
por compiladores para execução de código. Em especial,
destaca-se a Java Virtual Machine, utilizada para
execução de programas da linguagem Java.

O objetivo deste trabalho é a implementação de um interpretador
para uma máquina virtual simples, que chamaremos de _Small_.
As próximas seções apresentam a sintaxe e a semântica de
programas Small.


Sintaxe e semântica de programas Small
--------------------------------------

Para execução de programas, a máquina virtual small utiliza uma pilha,
uma memória e um contador de instruções. O estado da máquina pode ser
representado pelo seguinte tipo de dados.

> newtype Name
>   = Name String
>     deriving (Eq, Ord, Show)

> data VMState
>   = VMState {
>       pc     :: Int
>     , stack  :: [Int]
>     , memory :: [(Name, Int)]
>    } deriving (Eq, Ord, Show)

O tipo Name representa nomes de variáveis e o tipo VMState a configuração
atual da máquina. Os campos do tipo VMState possuem o seguinte significado:

* pc: Representa o contador de instruções, isto é, a próxima instrução a
ser executada pela máquina.
* stack: Representa a pilha de valores utilizados durante a execução de operações.
* memory: Armazena os valores associados a variáveis presentes no programa.

Programas small consistem de uma lista de instruções. A máquina pode executar
somente 9 tipos de instruções, a saber:

* push(n): insere n no topo da pilha.
* var(x): insere o valor da variável x (contida na memória) no topo da pilha.
* set(x): atribui a variável x o valor do topo da pilha.
* add: soma os valores do topo da pilha e empilha o resultado.
* sub: subtrai os valores do topo da pilha e empilha o resultado.
* jump(n): desvio incondicional.
* jumpeq(n): desvia, se os 2 valores do topo da pilha são iguais.
* jumpneq(n): desvia, se os 2 valores do topo da pilha são diferentes.

Implementação de small
----------------------

Representamos instruções small pelo tipo `Instr` a seguir:

> data Instr
>   = IPush Int
>   | IVar Name
>   | ISet Name
>   | IAdd
>   | ISub
>   | IJump Int
>   | IJumpNeq Int
>   | IJumpEq Int
>   | IHalt
>   deriving (Eq, Ord, Show)

Com base no apresentado, faça o que se pede: 

1 - A instrução push(n) insere o valor inteiro n no topo da pilha presente
no tipo de dados `VMState`. Para implementar a semântica dessa instrução,
implemente a função:

> push :: Int -> VMState -> VMState
> push n (VMState pc stack memory) = VMState pc (n : stack) memory

que altera o estado atual da máquina empilhando o inteiro fornecido como
primeiro parâmetro.


2 - A instrução var(x) armazena o valor associado a variável x no topo da
pilha de execução. Implemente essa funcionalidade na função:

> getVariableValue :: Name -> [(Name, Int)] -> Maybe Int
> getVariableValue _ [] = Nothing
> getVariableValue name ((n, v) : xs)
>     | name == n = Just v
>     | otherwise = getVariableValue name xs
> 
> 
> lookMemory :: Name -> VMState -> VMState
> lookMemory instr vm@(VMState pc stack memory) = push value vm
>     where
>         value = fromMaybe (error "variable not found") (getVariableValue instr memory)


Note que essa função deve retornar o estado da máquina alterado após a
modificação da pilha de execução contendo, em
seu topo, o valor associado
a variável x.



3 - A instrução set(x) atribui à variável x o valor atualmente contido no
topo da pilha de execução. Implemente essa funcionalidade na função:

> setVariableValue :: Name -> Int -> VMState -> VMState
> setVariableValue varName newValue vm@(VMState pc stack mem) = VMState pc stack (updateVariableValue varName newValue mem)
>     where
>         updateVariableValue varName newValue [] = [(varName, newValue)]
>         updateVariableValue varName newValue ((var, value) : xs)
>             | varName == var = (var, newValue) : xs
>             | otherwise = (var, value) : updateVariableValue varName newValue xs
> 
> setMemory :: Name -> VMState -> VMState
> setMemory _ (VMState _ [] _) = error "Not enough elements for operation in stack."
> setMemory varName (VMState pc (x : xs) memory) = setVariableValue varName x (VMState pc xs memory)

4 - As operações add e sub utilizam os dois elementos do topo da pilha
e armazenam o resultado da operação na própria pilha. Ao invés de implementarmos
duas operações para a execução dessas instruções, vamos utilizar uma função
de ordem superior que recebe como parâmetro a operação a ser aplicada sobre
os elementos do topo da pilha. Implemente a função:

> stackOp :: (Int -> Int -> Int) -> VMState -> VMState
> stackOp _ (VMState _ [] _) = error "Not enough elements for operation in stack."
> stackOp op (VMState pc (x:y:stack) memory) = VMState pc (result : stack) memory
>   where
>     result = op x y

que aplica a operação fornecida como primeiro parâmetro aos dois primeiros
elementos da pilha e re-insere o resultado retornando o estado da máquina
alterado.

5 - Após a execução de cada instrução, o contador de programa deve ser
incrementado. Além disso, a máquina small possui instruções de desvio, cujo
principal objetivo é alterar o contador de programa para alterar o fluxo
de execução do código. Pode-se alterar o contador de programa adicionando
um valor inteiro a este. Implemente a função:

> addPC :: Int -> VMState -> VMState
> addPC increment (VMState pc stack memory) = VMState (pc + increment) stack memory

que adiciona ao valor atual do contador de instrução a constante inteira
fornecida como primeiro parâmetro.

6 - Desvios condicionais devem ser implementados analisando os primeiros
dois elementos da pilha (caso esses existam). Novamente, vamos nos valer
de funções de ordem superior para tratamento dos dois tipos de desvio.
Implemente a função:

> condJump :: (Int -> Int -> Bool) -> Int -> VMState -> VMState
> condJump op increment vm@(VMState pc (x : y : stack) memory) = addPC inc (VMState pc stack memory)
>    where
>        inc = if op x y then 1 else increment

que a partir de um teste (igualdade ou desigualdade), um deslocamento e
um estado atual, retorna o novo estado da máquina contendo o contador
de instrução devidamente alterado (usando o deslocamento caso o teste
seja verdadeiro ou incrementado, caso contrário).

7 - De posse de todas as implementações anteriores, a definição da
execução de uma instrução da máquina pode ser implementada pela seguinte
função:

> vmStep :: Instr -> VMState -> VMState
> vmStep (IPush val) vm = addPC 1 $ push val vm
> vmStep (IVar val) vm = addPC 1 $ lookMemory val vm
> vmStep (ISet val) vm = addPC 1 $ setMemory val vm
> vmStep IAdd vm = addPC 1 $ stackOp (+) vm
> vmStep ISub vm = addPC 1 $ stackOp (-) vm
> vmStep (IJump inc) vm = addPC inc vm
> vmStep (IJumpNeq inc) vm = condJump (/=) inc vm
> vmStep (IJumpEq inc) vm = condJump (==) inc vm
> vmStep IHalt vm = vm

que a partir de uma instrução a ser executada e do estado atual da máquina
produz o um novo estado resultante.


8 - Uma etapa importante da máquina é a busca da próxima
execução a ser executada. Implemente a função

> nextInstr :: [Instr] -> VMState -> Maybe Instr
> nextInstr [] _ = Nothing
> nextInstr xs (VMState pc _ _) 
>     | pc < 0 || pc >= length xs = Nothing
>     | (xs !! pc) == IHalt = Nothing
>     | otherwise = Just (xs !! pc)


que a partir de um programa e o estado atual da máquina, retorna
a instrução apontada pelo contador de instruções. Caso o contador
indique uma posição inválida ou a instrução atual seja `halt`, o
valor `Nothing` deve ser retornado.

9 - Utilizando a função `nextInstr`, podemos implementar o interpretador
da máquina small utilizando a seguinte função:

> exec :: [Instr] -> VMState -> VMState
> exec xs vm =
>     case nextInstr xs vm of
>         Nothing -> vm
>         Just instr -> exec xs $ vmStep instr vm

que deve obter a próxima instrução a ser executada e continuar a execução
do programa sobre o estado da máquina alterado pela última instrução. A
função deve parar apenas quando a função `nextInstr` retornar `Nothing`,
quando o estado final da máquina é retornado como resultado.

10 - Elabore testes de unidade para cada uma das funções implementadas 
por você. Na parte 1 desta lista de exercícios, existem alguns exemplos
de uso de testes unitários que você pode utilizar como exemplo. Após 
criar cada teste, inclua-os na lista de nome `parte2`, definida a seguir,
para que seus tests sejam executados pela função `main` deste programa.

> pushTests :: TestTree
> pushTests =
>   testGroup "Tests for push"
>     [ testCase "push 10 em uma pilha vazia" $
>         push 10 (VMState 0 [] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)]) 
>         @?= VMState { pc = 0, stack = [10], memory = [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)] }
>       
>     , testCase "push 20 em uma pilha nao vazia" $
>         push 20 (VMState 0 [10, 30, 40] []) 
>         @?= VMState { pc = 0, stack = [20, 10, 30, 40], memory = [] }
>       
>     , testCase "push 42 na pilha com um elemento" $
>         push 42 (VMState 0 [5] [(Name "a", 1), (Name "b", 2)]) 
>         @?= VMState { pc = 0, stack = [42, 5], memory = [(Name "a", 1), (Name "b", 2)] }
>       
>     , testCase "push 0 com diferentes valores" $
>         push 0 (VMState 0 [5, 10, -5] [(Name "a", 1), (Name "b", 2)]) 
>         @?= VMState { pc = 0, stack = [0, 5, 10, -5], memory = [(Name "a", 1), (Name "b", 2)] }
>     ]


> lookMemoryTests :: TestTree
> lookMemoryTests =
>   testGroup "Tests for lookMemory"
>     [ testCase "Valor de A em pilha vazia" $
>         lookMemory (Name "a") (VMState 0 [] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)]) 
>         @?= VMState { pc = 0, stack = [1], memory = [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)] }
>       
>     , testCase "valor de B em pilha não vazia" $
>         lookMemory (Name "b") (VMState 0 [10, 30, 40] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)])
>         @?= VMState { pc = 0, stack = [2, 10, 30, 40], memory = [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)] }
>       
>     ]



> setMemoryTests :: TestTree
> setMemoryTests =
>   testGroup "Tests for setMemory"
>     [ testCase "Alterando o valor de a" $
>         setMemory (Name "a") (VMState 0 [10, 30, 40] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)])
>         @?= VMState {pc = 0, stack = [30,40], memory = [(Name "a",10),(Name "b",2),(Name "c",3),(Name "d",4),(Name "e",5)]}
>       
>     , testCase "Variavel fora da memoria" $
>         setMemory (Name "NAO EXISTE") (VMState 0 [10, 30, 40] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name "d", 4), (Name "e", 5)])
>         @?= VMState {pc = 0, stack = [30,40], memory = [(Name "a",1),(Name "b",2),(Name "c",3),(Name "d",4),(Name "e",5),(Name "NAO EXISTE",10)]}
>       
>     ]



> stackOpTests :: TestTree
> stackOpTests =
>   testGroup "Tests for stackOp"
>     [ testCase "soma" $ stackOp (+) (VMState 0 [33, 44] [])  @?= VMState {pc = 0, stack = [77], memory = []}
>
>     , testCase "subtracao" $ stackOp (-) (VMState 0 [33, 44] []) @?= VMState {pc = 0, stack = [-11], memory = []}
>     ]



> addPCTest :: TestTree
> addPCTest =
>   testGroup "Tests for addPC"
>     [ testCase "incremento em um" $
>         addPC 1 (VMState 0 [] [])
>         @?= VMState {pc = 1, stack = [], memory = []}
>
>     , testCase "incremento em 10" $
>         addPC 10 (VMState 0 [] [])
>         @?= VMState {pc = 10, stack = [], memory = []}
>     , testCase "decremento em dois" $
>         addPC (-2) (VMState 10 [] [])
>         @?= VMState {pc = 8, stack = [], memory = []}
>     ]



> condJumpTest :: TestTree
> condJumpTest =
>   testGroup "Tests for condJump"
>     [ testCase "igualdade e numeros iguais" $         condJump (==) 25 (VMState 0 [10, 10] [])  @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "igualdade e numeros diferentes" $     condJump (==) 25 (VMState 0 [10, 11] [])  @?= VMState {pc = 25, stack = [], memory = []}
>     , testCase "desigualdade e numeros iguais" $      condJump (/=) 25 (VMState 0 [10, 10] [])  @?= VMState {pc = 25, stack = [], memory = []}
>     , testCase "desigualdade e numeros diferentes" $  condJump (/=) 25 (VMState 0 [10, 11] [])  @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "maior que verdadeiro" $               condJump (>) 25 (VMState 0 [12, 11] [])   @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "maior que falso" $                    condJump (>) 25 (VMState 0 [10, 11] [])   @?= VMState {pc = 25, stack = [], memory = []}
>     , testCase "menor que verdadeiro" $               condJump (<) 25 (VMState 0 [10, 11] [])   @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "menor que falso" $                    condJump (<) 25 (VMState 0 [12, 11] [])   @?= VMState {pc = 25, stack = [], memory = []}
>     ]



> vmStepTest :: TestTree
> vmStepTest =
>   testGroup "Tests for vmStep"
>     [ testCase "IPush 50" $       vmStep (IPush 50) (VMState 0 [] [])                       @?= VMState {pc = 1, stack = [50], memory = []}
>     , testCase "Ivar a" $         vmStep (IVar $ Name "a") (VMState 0 [] [(Name "a", 1)])   @?= VMState {pc = 1, stack = [1], memory = [(Name "a", 1)]}
>     , testCase "ISet f" $         vmStep (ISet $ Name "a") (VMState 0 [10] [(Name "a", 1)]) @?= VMState {pc = 1, stack = [], memory = [(Name "a",10)]}
>     , testCase "IAdd" $           vmStep IAdd (VMState 0 [33, 44] [])                       @?= VMState {pc = 1, stack = [77], memory = []}
>     , testCase "ISub" $           vmStep ISub (VMState 0 [33, 44] [])                       @?= VMState {pc = 1, stack = [-11], memory = []}
>     , testCase "IJump" $          vmStep (IJump 77) (VMState 0 [33, 44] [])                 @?= VMState {pc = 77, stack = [33,44], memory = []}
>     , testCase "IJumpNeq true" $  vmStep (IJumpNeq 25) (VMState 0 [10, 11] [])   @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "IJumpNeq false" $ vmStep (IJumpNeq 25) (VMState 0 [10, 10] [])   @?= VMState {pc = 25, stack = [], memory = []}
>     , testCase "IJumpEq true" $   vmStep (IJumpEq 25)  (VMState 0 [11, 11] [])   @?= VMState {pc =  1, stack = [], memory = []}
>     , testCase "IJumpEq false" $  vmStep (IJumpEq 25)  (VMState 0 [12, 11] [])   @?= VMState {pc = 25, stack = [], memory = []}
>     , testCase "IHalt" $          vmStep IHalt (VMState 0 [12, 11] [])   @?= VMState {pc = 0, stack = [12, 11], memory = []}
>     ]



> nextInstrTest :: TestTree
> nextInstrTest =
>   testGroup "Tests for nextInstr"
>     [ testCase "IPush 50" $         nextInstr [IPush 50, IVar $ Name "a", IHalt] (VMState 0 [] []) @?= Just (IPush 50)
>     , testCase "Ivar a" $           nextInstr [IPush 50, IVar $ Name "a", IHalt] (VMState 1 [] []) @?= Just (IVar (Name "a"))
>     , testCase "Halt" $             nextInstr [IPush 50, IVar $ Name "a", IHalt] (VMState 2 [] []) @?= Nothing
>     , testCase "Posicao invalida" $ nextInstr [IPush 50, IVar $ Name "a", IHalt] (VMState 3 [] []) @?= Nothing
>     ]



> execTest :: TestTree
> execTest =
>   testGroup "Tests for exec"
>     [ testCase "teste simples" $
>           exec [IPush 50, ISet $ Name "b", IVar $ Name "a", IVar $ Name "b", IAdd, IPush 50, IVar $ Name "a", IHalt, IPush 5000] (VMState 0 [] [(Name "a", 100)])
>           @?= VMState {pc = 7, stack = [100,50,150], memory = [(Name "a",100),(Name "b",50)]}
>     
>      , testCase "loop de repeticao indo de 0 ate 50" $ 
>           exec [IPush 0, ISet $ Name "i", IVar $ Name "i", IPush 50, IJumpNeq 8, IVar $ Name "i", IPush 1, IAdd, ISet $ Name "i", IVar $ Name "i", IPush 50, IJump (-7), IHalt] (VMState 0 [] [])
>           @?= VMState {pc = 12, stack = [], memory = [(Name "i",50)]}
>     ]

Funções auxiliares
------------------

> sortedProperty :: QC.Property
> sortedProperty
>   = QC.forAll genText
>            (\ t -> sorted (.<.) (f t))
>     where
>       g = numberLines . lines
>       f = sortEntries . concatMap numberWords . g

> indexProperty :: QC.Property
> indexProperty
>   = QC.forAll genText
>               (\ t -> let ws = map P.words $ lines t
>                           ixs = makeIndex t
>                           isAt is w = all (\i -> w `elem` (ws !! i)) is
>                       in all (uncurry isAt) ixs)


> sorted :: (a -> a -> Bool) -> [a] -> Bool
> sorted p [] = True
> sorted p [_] = True
> sorted p (x : x' : xs)
>   = p x x' && sorted p (x' : xs)


> genText :: QC.Gen Text
> genText
>   = do
>        -- maximum number of lines
>        n <- QC.choose (1,5)
>        -- maximum number of words per line
>        m <- QC.choose (1,5)
>        createText n m

> createText :: Int -> Int -> QC.Gen Text
> createText l w
>   = (concat . intersperse "\n") <$> replicateM l (createLine w)

> createLine :: Int -> QC.Gen Line
> createLine w
>   = (concat . intersperse " ") <$> replicateM w createWord

> createWord :: QC.Gen Word
> createWord
>   = do
>       -- número de letras
>       n <- QC.choose (1,6)
>       QC.vectorOf n genLetter

> genLetter :: QC.Gen Char
> genLetter
>   = chr <$> QC.choose (97,122) 

> parte1 :: TestTree
> parte1
>    = testGroup "Parte 1"
>                 [
>                   lineTests,
>                   numberLinesTests,
>                   numberWordsTests,
>                   numberAllTests,
>                   sortEntriesTests,
>                   combineTests,
>                   QC.testProperty "Sorted property" sortedProperty,
>                   QC.testProperty "makeIndex correct" indexProperty
>                 ]


> parte2 :: TestTree 
> parte2 = testGroup "Parte 2" 
>                   [
>                       pushTests,
>                       lookMemoryTests,
>                       setMemoryTests,
>                       stackOpTests,
>                       addPCTest,
>                       condJumpTest,
>                       vmStepTest,
>                       nextInstrTest,
>                       execTest
>                   ]

> tests :: TestTree 
> tests = testGroup "Testes" 
>                   [
>                     parte1
>                   , parte2
>                   ]
