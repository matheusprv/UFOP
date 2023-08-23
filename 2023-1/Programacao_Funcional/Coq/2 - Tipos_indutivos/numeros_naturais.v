Fixpoint add (n m : nat) : nat :=
  match n with
  | O    => m
  | S n' => S (add n' m)
  end.

Lemma zero_identity_add_left : forall n, 0 + n = n.
  intro H.
  simpl.
  reflexivity.
Qed.


Lemma zero_identity_add_right : forall n, n + 0 = n.
Proof.
    intro n.
    induction n as [ | n' IHn'].
    +
      simpl.
      reflexivity.
    +
      simpl.
      rewrite IHn'.
      reflexivity.
Qed.


Lemma add_inc : forall m n, S (m + n) = m + S n.
Proof.
    intros m n.
    induction m as [ | m' IHm'].
    -
        simpl.
        reflexivity.
    -
        simpl.
        rewrite IHm'.
        reflexivity.
Qed.

Lemma add_commut : forall n m, n + m = m + n.
    intros m n.
    induction m as [ | m' IHm'].
    -
        simpl.
        symmetry.
        apply zero_identity_add_right.
    -
        simpl.
        rewrite IHm'.
        apply add_inc.
Qed.
        

(*Exercício 19*)
Lemma add_associative : forall n m p, n + (m + p) = (n + m) + p.
    intros n m p.
    induction n as [ | n' IHn'].
    -
        simpl.
        reflexivity.
    -
        simpl.
        rewrite IHn'.
        reflexivity.
Qed.

Fixpoint even_bool (n : nat) : bool :=
  match n with
  | O => true
  | S O => false
  | S (S m) => even_bool m
  end.

(*Exercicio 21*)
Lemma even_add_n : forall n, even_bool (n + n) = true.
    intro n.
    induction n as [ | n' IHn'].
    -
        simpl.
        reflexivity.
    -
        simpl.
        rewrite <- add_inc.
        apply IHn'.
Qed.


        

        

