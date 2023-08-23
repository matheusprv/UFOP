Require Import Coq.Lists.List.

Inductive list (A : Type) : Type :=
| nil : list A
| cons : A -> list A -> list A.

Definition list1 : list nat := 1 :: 2 :: 3 :: nil.
Definition list2 : list nat := [1 ; 2 ; 3].