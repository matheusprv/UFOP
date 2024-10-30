-- 1. Liste o nome e a data de nascimento do empregado 'Joao Silva'.
SELECT NomeFunc, DataNasc from funcionario WHERE funcionario.NomeFunc = "Joao Silva";


-- 2. Liste o nome e o endereço de todos os empregados que pertencem ao departamento 'Pesquisa'.
SELECT funcionario.NomeFunc, funcionario.Endereco 
from Funcionario natural join departamento 
where departamento.NomeDepto = 'Pesquisa';


-- 3. Para cada projeto localizado no 'Luxemburgo', liste o numero do projeto, o número do departamento
-- que o controla e o nome, endereço e data de aniversário do gerente do departamento.
SELECT projeto.ID_Proj as 'Num projeto', 
		departamento.ID_Depto as 'Número departamento', 
		funcionario.NomeFunc as Nome, 
        funcionario.DataNasc as Aniversário
from projeto 
	join departamento on projeto.ID_Depto = departamento.ID_Depto
    join funcionario on funcionario.ID_Func = departamento.ID_Gerente
where projeto.Localizacao = "Luxemburgo";


-- 4. Para cada empregado, recupere o seu nome e o nome de seu supervisor.
SELECT funcionario.NomeFunc, supervisor.NomeFunc 
from funcionario left join funcionario as supervisor 
on funcionario.ID_Superv = supervisor.ID_Func;


-- 5. Selecione os empregados do departamento de número 1.
SELECT NomeFunc from funcionario where ID_Depto = 1;


-- 6. Liste o salário de todos os empregados, de tal forma que não apareçam salários iguais.
SELECT distinct salario from funcionario;


-- 7. Liste todos os dados dos empregados que moram na 'Irai'.
SELECT * from funcionario where Endereco LIKE "%Irai%";


-- 8. Liste o número de todos os projetos que possuem empregados com sobrenome 'Santos', como
-- trabalhador ou como gerente do departamento que controla os projetos.
SELECT ID_Proj 
from projeto
where ID_Proj in (
	SELECT ID_Proj 
    from funcionario join trabalha on funcionario.ID_Func = trabalha.ID_Func 
    where funcionario.NomeFunc LIKE "%Santos%"
    
    UNION
    
    SELECT ID_Proj
    from funcionario join departamento on funcionario.ID_Func=departamento.ID_Depto
    join projeto on departamento.ID_Depto = projeto.ID_Depto
);


-- 9. Mostre o resultado do aumento de 20% sobre o salário dos empregados que trabalham no projeto de
-- nome 'ProdX'.
SELECT salario*1.20 
from funcionario where funcionario.ID_Func in (
	SELECT ID_Func from trabalha join projeto on trabalha.ID_Proj=projeto.ID_Proj
    WHERE projeto.NomeProj = "ProdX"
);


-- 10. Liste o nome dos empregados do departamento 3 que possuem salário entre R$800,00 e R$1.200,00.
SELECT funcionario.NomeFunc from funcionario 
where (funcionario.Salario between 800 and 1200) and funcionario.ID_Depto = 3;


-- 11. Liste o nome dos empregados, o nome dos seus departamentos e o nome dos projetos em que eles
-- trabalham, ordenados pelo departamento e pelo nome do projeto.
SELECT funcionario.NomeFunc, departamento.NomeDepto, projeto.NomeProj
from funcionario 
	join trabalha on funcionario.ID_Func = trabalha.ID_Func 
    join projeto on trabalha.ID_Proj = projeto.ID_Proj 
    join departamento on funcionario.ID_Depto = departamento.ID_Depto
ORDER BY departamento.NomeDepto, projeto.NomeProj;

-- 12. Liste o nome dos empregados que trabalham em algum dos projetos em que o 'Joao Silva' trabalha.

SELECT funcionario.NomeFunc from funcionario
join trabalha on trabalha.ID_Func = funcionario.ID_Func 
where trabalha.ID_Proj IN (
	SELECT trabalha.ID_Proj from funcionario natural join trabalha where funcionario.NomeFunc = 'Joao Silva'
);

-- 13. Liste o nome dos empregados que não possuem supervisores.
SELECT funcionario.NomeFunc from funcionario where funcionario.ID_Superv IS NULL;


-- 14. Liste o nome dos empregados que possuem mais que 2 dependentes, juntamente com os nomes dos
-- seus dependentes.
SELECT funcionario.NomeFunc, dependente.NomeDep 
from funcionario join dependente on funcionario.ID_Func = dependente.ID_Func 
where funcionario.ID_Func IN (
	SELECT dependente.ID_Func from dependente group by dependente.ID_Func having count(*) > 2
);


-- 15. Liste a soma, a média, o maior e o menor salário de todos os empregados.
SELECT SUM(Salario), avg(Salario), max(Salario), min(Salario) from funcionario;


-- 16. Liste a soma, a média, o maior e o menor salário dos empregados do departamento 'Pesquisa'.
SELECT SUM(Salario), avg(Salario), max(Salario), min(Salario) 
from funcionario join departamento on funcionario.ID_Depto = departamento.ID_Depto
where departamento.NomeDepto = 'Pesquisa';


-- 17. Liste o nome de cada supervisor com a quantidade de supervisionados.
SELECT supervisores.NomeFunc, qtdSupervisionados 
	FROM(
		-- Nome dos supervisores e seus ID's
		Select distinct supervisor.ID_Func, supervisor.NomeFunc 
		from funcionario as supervisor 
			join funcionario on supervisor.ID_Func = funcionario.ID_Superv
	) AS supervisores
    JOIN(
		-- Quantidade de supervisionados por supervisor
		SELECT funcionario.ID_Superv, count(*) as qtdSupervisionados from
		funcionario
		group by funcionario.ID_Superv
    ) AS supervisionados
    ON supervisionados.ID_Superv= supervisores.ID_Func;
	

-- 18. Liste o nome de cada projeto com o número de empregados que trabalham no projeto.
SELECT projeto.NomeProj, count(trabalha.ID_Proj) from projeto join trabalha on projeto.ID_Proj = trabalha.ID_Proj
group by projeto.ID_Proj;


-- 19. Para cada projeto que possua mais de 2 empregados na equipe, liste o nome do projeto e a quantidade
-- de empregados que trabalham no mesmo.
SELECT projeto.NomeProj, count(trabalha.ID_Proj) from projeto join trabalha on projeto.ID_Proj = trabalha.ID_Proj
group by projeto.ID_Proj having count(trabalha.ID_Proj) > 2;

-- 20. Para cada departamento que possua mais do que 2 empregados, liste o nome do departamento e o
-- nome dos empregados que ganham mais do que 800,00. 
SELECT departamento.NomeDepto, funcionario.NomeFunc 
from departamento join funcionario on departamento.ID_Depto = funcionario.ID_Depto 
where funcionario.salario > 800 and departamento.ID_Depto IN(
	SELECT funcionario.ID_Depto from funcionario group by funcionario.ID_Depto having count(*) > 2
);




