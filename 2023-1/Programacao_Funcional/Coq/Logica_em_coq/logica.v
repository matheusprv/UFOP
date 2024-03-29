Variables A B C : Prop.

Theorem first_theorem : (A -> B) -> A -> B.
Proof.
  intro Hab.
  intro Ha.
  apply Hab.
  assumption.
Qed.

(* Exercicio 1 *)
Lemma ex1 : A -> B -> A.
Proof.
  intro Ha.
  intro Hb.
  (* Assumption ou Ha funcionam *)
  assumption.
Qed.

(* Exercicio 2 *)
Lemma ex2 : (A -> B) -> (B -> C) -> A -> C.
Proof.
  intro Hab.
  intro Hbc.
  intro Ha.
  apply Hbc.
  apply Hab.
  apply Ha.
Qed.
  

(*Conjunção*)
Lemma and_comm : A /\ B -> B /\ A.
Proof.
  intro Hab.
  destruct Hab as [Ha Hb].
  split.
  +
    apply Hb.
  +
    apply Ha.
Qed.

Lemma and_assoc : A /\ (B /\ C) -> (A /\ B) /\ C.
  intro Habc.
  destruct Habc as [Ha Hbc].
  destruct Hbc as [Hb Hc].
  split.
  +
    split.
      -
        apply Ha.
      -
        apply Hb.
  +
    apply Hc.
Qed.
      
(*Exercicio 3*)
Lemma ex3 : (A /\ B) /\ C -> A /\ (B /\ C).
Proof.
  intro Habc.
  destruct Habc as [Hab Hc].
  destruct Hab as [Ha Hb].
  split.
  +
    assumption.
  +
    split.
    -
      assumption.
    -
      assumption.
Qed.


(*Exercicio 4*)
Lemma ex4 : ((A /\ B) -> C) -> (A -> B -> C).
Proof.
  intro Hab_seta_c.
  intro Ha.
  intro Hb.
  apply Hab_seta_c.
  split.
  +
    assumption.
  +
    assumption.
Qed.

(*Exercicio 5*)
Lemma ex5 : (A -> B -> C) -> ((A /\ B) -> C).
  intro Habc.
  intro Hab.
  destruct Hab as [Ha Hb].
  apply Habc.
  +
    assumption.
  +
    assumption.
Qed.


(*Exercicio 6*)
Lemma ex6 : ((A -> B) /\ (A -> C)) -> A -> (B /\ C).
Proof.
  intro Habac.
  destruct Habac as [Hab Hac].
  intro Ha.
  split.
  +
    apply Hab.
    assumption.
  +
    apply Hac.
    assumption.
Qed.

(*Bicondicional*)
Lemma and_comm_iff : (A /\ B) <-> (B /\ A).
Proof.
  unfold iff.
  split.
  +
    intro Hab.
    destruct Hab as [Ha Hb].
    split.
    -
      assumption.
    -
      assumption.
  +
    intro Hba.
    destruct Hba as [Hb Ha].
    split.
    -
      assumption.
    -
      assumption.
Qed.

Lemma and_comm_iff_2 : (A /\ B) <-> (B /\ A).
Proof.
  unfold iff.
  split.
  +
    apply and_comm.
  +
    intro Hba.
    destruct Hba as [Hb Ha].
    split.
    -
      assumption.
    -
      assumption.
Qed.

(*Negação*)
Lemma modus_tollens : ((A -> B) /\ ~ B) -> ~ A.
Proof.
  intro HAB_notB.
  destruct HAB_notB as [Hab Hnb].
  unfold not.
  unfold not in Hnb.
  intro Ha.
  apply Hnb.
  apply Hab.
  assumption.
Qed.

Lemma contra : A -> ~ A -> B.
Proof.
  intro Ha.
  intro Hna.
  unfold not in Hna.
  contradiction.
Qed.



(*Disjunção*)
Lemma or_comm : (A \/ B) -> (B \/ A).
Proof.
  intro Hab.
  destruct Hab as [Ha | Hb].
  +
    right.
    assumption.
  +
    left.
    assumption.
Qed.

Lemma or_assoc : A \/ (B \/ C) -> (A \/ B) \/ C.
Proof.
  intro Habc.
  destruct Habc as [Ha | [Hb | Hc]].
  +
    left.
    left.
    assumption.
  +
    left.
    right.
    assumption.
  +
    right.
    assumption.
Qed.

(*Exercicio 7*)
Lemma ex7 : ((A \/ B) /\ ~ A) -> B.
Proof.
  intro Hab_na.
  destruct Hab_na as [Hab Hna].
  unfold not in Hna.
  destruct Hab as [Ha | Hb].
  +
    contradiction.
  +
    assumption.
Qed.

(*Exercício 8*)
Lemma ex8 : (A \/ (B /\ C)) -> (A \/ B) /\ (A \/ C).
Proof.
  intro Habc.
  destruct Habc as [Ha | Hbc].
  +
    split.
    -
      left.
      assumption.
    -
      left.
      assumption.
  +
    destruct Hbc as [Hb Hc].
    split.
    -
      right.
      assumption.
    -
      right.
      assumption.
Qed.