-- Matheus Peixoto Ribeiro Vieira - 22.1.4104

set schema 'Empresa';

-- Atualiza todos os salários iterativamente. 
-- Retorna um texto com o maior salario atual e quantas modificações foram feitas
CREATE OR REPLACE function aumentar_salario_de_todos(multiplicador real) RETURNS TEXT AS $$
	DECLARE
		reg RECORD;
		maior_salario REAL := 0; 
		pessoa VARCHAR;
		total_de_modificacoes INTEGER := 0;
	BEGIN

		FOR reg IN (SELECT * FROM funcionario) LOOP

			IF reg.salario >= maior_salario THEN
				maior_salario := reg.salario * multiplicador;
				pessoa := reg.nomefunc;
			END IF;
			
			UPDATE funcionario set salario = reg.salario * multiplicador WHERE id_func = reg.id_func;
			total_de_modificacoes := total_de_modificacoes + 1;

		END LOOP;

		RETURN pessoa || ' possui o maior salário no valor de ' || maior_salario || ' reais. E foram feitas ' || total_de_modificacoes || ' modificações';

	END;
$$ LANGUAGE plpgsql;


-- Dado o Id de um departamento, calcula sua média salarial e retorna o menor e o maior salário do mesmo.
CREATE OR REPLACE FUNCTION info_departamento(id_departamento INTEGER) RETURNS TEXT AS $$

	DECLARE 
		soma_salario       REAL := 0;
		total_funcionarios INTEGER := 0;
		menor_salario      REAL :=  2147483647.0;
		maior_salario	   REAL := 0;
		sal 			   funcionario.salario%TYPE;
		media_salarial	   REAL;
	BEGIN

		FOR sal in (SELECT salario FROM funcionario) LOOP
			soma_salario = soma_salario + sal;
			total_funcionarios := total_funcionarios + 1;

			IF sal > maior_salario THEN 
				maior_salario := sal;
			ELSIF sal < menor_salario THEN 
				menor_salario := sal;
			END IF;

		END LOOP;

		media_salarial = soma_salario / total_funcionarios;

		RETURN 'Menor salário: ' || menor_salario || ' - Maior salário: ' || maior_salario || ' - Média salarial: ' || media_salarial; 
	
	END;
$$ LANGUAGE plpgsql;

SELECT info_departamento(3);







