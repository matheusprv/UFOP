Require Import List Arith.Arith_base Bool.

Import ListNotations.

(** Demonstre os teoremas a seguir substituindo a palavra Admitted
    pelos comandos que provam o resultado terminado sua demonstração
    utilizando Qed.

    Cada questão vale 2,0 pontos.
 *)

(** Questão 1. *)

(** Considere o seguinte predicado que representa a especificação
    de uma função para cálculo de fatorial de um número natural. *)

Inductive factorial_spec : nat -> nat -> Prop :=
| Base : factorial_spec 0 1
| Step : forall n m, factorial_spec n m ->
                factorial_spec (1 + n) ((1 + n) * m).

(** A função a seguir, calcula o fatorial de um número natural. *)

Fixpoint factorial (n : nat) : nat :=
  match n with
  | 0 => 1
  | S n => (S n) * factorial n
  end.

(** Prove que a função anterior satisfaz a especificação: *)

Theorem factorial_correct : forall n, factorial_spec n (factorial n).
Proof.
    intro n.
    induction n as [ | n' IHn'].
    -
        simpl.
        apply Base.
    -
        simpl.
        apply Step.
        assumption.
Qed.



(** Considere a seguinte função que verifica se todos os elementos de uma lista
    satisfazem um predicado. *)

Fixpoint all {A : Type}(p : A -> bool)(xs : list A) : bool :=
  match xs with
  | [] => true
  | (x :: xs) => p x && all p xs
  end.

(** Prove os seguintes resultados envolvendo a função all. Você pode considerar
    úteis os seguintes lemmas provados na biblioteca.*)

Check andb_true_iff.
Check andb_assoc.
Check andb_true_intro.

(** Questão 2 *)

Lemma concat_all {A : Type} : forall (xs ys : list A) p,
                                         all p (xs ++ ys) = true ->
                                         all p xs && all p ys = true.
Proof.
    intros xs ys p H.
    induction xs as [| z zs IHzs].
    -
        simpl.
        apply H.
    -
        simpl.
        apply andb_true_iff in H.
        destruct H as [H1 H2].
        rewrite H1.
        apply IHzs.
        auto.
Qed.
        

(** Questão 3 *)
Lemma all_concat {A : Type} : forall (xs ys : list A) p,
                                         all p xs = true ->
                                         all p ys = true ->
                                         all p (xs ++ ys) = true.
Proof.
    intros xs ys ps Hxs Hys.
    induction xs as [| z zs IHzs].
    +
        simpl.
        apply Hys.
    +
        simpl.
        apply andb_true_iff in Hxs.
        destruct Hxs as [Hz Hxs].
        apply andb_true_intro.
        split.
        -
            apply Hz.
        -
            apply IHzs.
            apply Hxs.
Qed.

        

(** Para demonstrar os próximos resultados, pode ser necessário que você
    considere as diferentes possibilidades de uma expressão "e" que é condição
    de um "if". Usando o comando

    destruct e eqn: He

    O Coq dividirá a prova em dois casos (e = true ou e = false) e adicionará
    a hipótese He que define a igualdade e = true ou e = false.
 *)

(** Questão 4 *)

Lemma all_true_filter_eq {A : Type}
  : forall (xs : list A) p, all p xs = true -> (filter p xs) = xs.
Proof.
    intros xs p.
    induction xs as [| x' IHxs].
    +
        simpl.
        symmetry.
        reflexivity.
    +
        simpl.
        intro H.
        destruct p eqn: He.
        Admitted.






(** Questão 5 *)
Lemma all_filter {A : Type}
  : forall (xs : list A) p, all p (filter p xs) = true.
Proof.
    intros xs p.
    induction xs as [| xs' IHxs'].
    -
        simpl.
        reflexivity.
    -
        simpl.
        destruct p eqn: He.
        +
            simpl.
            rewrite He.
            apply andb_true_intro.
            split.
            *
                reflexivity.
            *
                apply IHIHxs'.
        +
        apply IHIHxs'.
Qed.


            