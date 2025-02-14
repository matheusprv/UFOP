-- Matheus Peixoto Ribeiro Vieira - 22.1.4104
-- Sempre que um novo funcionário for adicionado a um departamento, o gerente ganha um acréscimo de 500
-- Se o funcionário for removido, diminui 500 do salario
set schema 'Empresa';

CREATE OR REPLACE FUNCTION bonificacao_gerente() RETURNS trigger AS $bonificacao_gerente$
DECLARE
	incremento REAL := 500; 
BEGIN
        IF (TG_OP = 'DELETE') THEN
                UPDATE funcionario SET salario = salario - incremento WHERE funcionario.id_func = OLD.id_superv;
        ELSIF (TG_OP = 'UPDATE') THEN
                UPDATE funcionario SET salario = salario - incremento WHERE funcionario.id_func = OLD.id_superv;
                UPDATE funcionario SET salario = salario + incremento WHERE funcionario.id_func = NEW.id_superv;
        ELSE
                UPDATE funcionario SET salario = salario + incremento WHERE funcionario.id_func = NEW.id_superv;
        END IF;

        RETURN NEW;
END;
$bonificacao_gerente$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER bonificacao_gerente AFTER INSERT OR UPDATE OR DELETE ON funcionario
FOR EACH ROW EXECUTE PROCEDURE bonificacao_gerente();
