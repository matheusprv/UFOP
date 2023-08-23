Inductive True1 : Prop := | tt1 : True1.

Inductive False1 : Prop := .

Inductive conj1 (A B : Prop) : Prop := | and1 : A -> B -> conj1 A B.

Inductive disj1 (A B : Prop) : Prop := | or1 : A -> B -> disj1 A B.

Inductive bool1 : Set :=
  | true1 : bool1
  | false1 : bool1.

Require Import Bool.


Definition not_bool (b : bool) : bool :=
  match b with 
  | false => true
  | true => false
  end.

Definition and_bool (b1 b2 : bool) : bool :=
  match b1, b2 with
  | true, b2 => b2
  | false, b2 => false
  end.

Definition or_bool (b1 b2 : bool) : bool :=
  match b1, b2 with
  | true, b2 => true
  | false, b2 => b2
  end.

Definition xor_bool (b1 b2 : bool) : bool :=
  match b1, b2 with
  | true, true => false
  | false, false => false
  | _, _ => true
  end.

Eval compute in xor_bool false false.


Lemma not_bool_inv : forall b : bool, not_bool (not_bool b) = b.
Proof.
  intro b.
  destruct b.
  -
    simpl.
    reflexivity.
  - 
    simpl.
    reflexivity.
Qed.




(*Exercício 15*)
Lemma and_true_left : forall b, and_bool true b = b.
 Proof.
  intro b.
  destruct b.
  -
    simpl.
    reflexivity.
  -
    simpl.
    reflexivity.
Qed.

(*Exercício 16*)
Lemma and_false_left : forall b, and_bool false b = false.
Proof.
  intro b.
  destruct b.
  -
    simpl.
    reflexivity.  
  -
    simpl.
    reflexivity.
Qed.
  

(*Exercício 17*)
Lemma and_com : forall b b', and_bool b b' = and_bool b' b.
Proof.  
    intros b b'.
    destruct b'.
    -
        destruct b.
        +
            simpl.
            reflexivity.
        +
            simpl.
            reflexivity.
    -
        destruct b.    
        +
            simpl.
            reflexivity.
        +
            simpl.
            reflexivity.
Qed.

(*Exercicio 18*)
Lemma and_assocc : forall b1 b2 b3, and_bool b1 (and_bool b2 b3) = and_bool (and_bool b1 b2) b3.
Proof.
    intros b1 b2 b3.
    destruct b1.
    -
        destruct b2.
        +
            destruct b3.
            simpl.
            reflexivity.
            simpl.
            reflexivity.
        +
            destruct b3.
            simpl.
            reflexivity.
            simpl.
            reflexivity.
    -
    destruct b2.
    +
        destruct b3.
        simpl.
        reflexivity.
        simpl.
        reflexivity.
    +
        destruct b3.
        simpl.
        reflexivity.
        simpl.
        reflexivity.
Qed.

