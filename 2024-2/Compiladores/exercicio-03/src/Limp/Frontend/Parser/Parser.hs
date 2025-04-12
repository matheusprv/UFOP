{-# OPTIONS_GHC -w #-}
module Limp.Frontend.Parser.Parser (impParser) where

import Limp.Frontend.Lexer.Lexer
import Limp.Syntax.Syntax
import qualified Data.Array as Happy_Data_Array
import qualified Data.Bits as Bits
import Control.Applicative(Applicative(..))
import Control.Monad (ap)

-- parser produced by Happy Version 1.20.1.1

data HappyAbsSyn t4 t5 t6 t7 t8 t9 t10 t11 t12 t13 t14
	= HappyTerminal (Token)
	| HappyErrorToken Prelude.Int
	| HappyAbsSyn4 t4
	| HappyAbsSyn5 t5
	| HappyAbsSyn6 t6
	| HappyAbsSyn7 t7
	| HappyAbsSyn8 t8
	| HappyAbsSyn9 t9
	| HappyAbsSyn10 t10
	| HappyAbsSyn11 t11
	| HappyAbsSyn12 t12
	| HappyAbsSyn13 t13
	| HappyAbsSyn14 t14

happyExpList :: Happy_Data_Array.Array Prelude.Int Prelude.Int
happyExpList = Happy_Data_Array.listArray (0,168) ([0,0,0,0,0,0,64,2,0,0,0,0,0,0,0,0,0,0,0,43008,531,76,256,0,0,0,0,0,0,0,0,0,0,32,0,8192,0,0,0,0,0,0,0,16384,0,0,1536,16400,12,32816,25088,32768,1025,784,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,64000,5,0,0,0,8204,6272,24576,256,196,0,0,0,0,0,0,57376,23,0,48904,0,16384,0,0,4,0,3072,32800,24,32768,3056,0,1024,0,6144,64,49,0,0,0,0,0,12288,128,98,384,4100,3,8204,6272,24576,256,196,768,8200,6,16408,12544,49152,512,392,0,64,0,0,0,0,51200,47,0,0,0,0,0,0,256,0,0,64512,0,0,480,0,0,47,0,0,0,0,640,0,0,16,0,57344,0,0,24448,0,0,0,0,0,0,0,64,0,0,0,0,0
	])

{-# NOINLINE happyExpListPerState #-}
happyExpListPerState st =
    token_strs_expected
  where token_strs = ["error","%dummy","%start_parser","Program","PreComments","PostComments","CodeBlock","ItemList","Item","Stmt","Id","PTy","Init","Exp","id","num","comment","':='","'read'","'print'","'if'","'then'","'else'","'while'","';'","'('","')'","'{'","'}'","'+'","'*'","'-'","'/'","'=='","'<'","'!'","'&&'","'int'","'bool'","'true'","'false'","'skip'","%eof"]
        bit_start = st Prelude.* 43
        bit_end = (st Prelude.+ 1) Prelude.* 43
        read_bit = readArrayBit happyExpList
        bits = Prelude.map read_bit [bit_start..bit_end Prelude.- 1]
        bits_indexed = Prelude.zip bits [0..42]
        token_strs_expected = Prelude.concatMap f bits_indexed
        f (Prelude.False, _) = []
        f (Prelude.True, nr) = [token_strs Prelude.!! nr]

action_0 (4) = happyGoto action_3
action_0 (5) = happyGoto action_2
action_0 _ = happyReduce_2

action_1 (5) = happyGoto action_2
action_1 _ = happyFail (happyExpListPerState 1)

action_2 (17) = happyShift action_5
action_2 (28) = happyShift action_6
action_2 (7) = happyGoto action_4
action_2 _ = happyFail (happyExpListPerState 2)

action_3 (43) = happyAccept
action_3 _ = happyFail (happyExpListPerState 3)

action_4 (6) = happyGoto action_8
action_4 _ = happyReduce_4

action_5 _ = happyReduce_3

action_6 (8) = happyGoto action_7
action_6 _ = happyReduce_8

action_7 (15) = happyShift action_14
action_7 (17) = happyShift action_15
action_7 (19) = happyShift action_16
action_7 (20) = happyShift action_17
action_7 (21) = happyShift action_18
action_7 (24) = happyShift action_19
action_7 (29) = happyShift action_20
action_7 (38) = happyShift action_21
action_7 (39) = happyShift action_22
action_7 (42) = happyShift action_23
action_7 (9) = happyGoto action_10
action_7 (10) = happyGoto action_11
action_7 (11) = happyGoto action_12
action_7 (12) = happyGoto action_13
action_7 _ = happyFail (happyExpListPerState 7)

action_8 (17) = happyShift action_9
action_8 _ = happyReduce_1

action_9 _ = happyReduce_5

action_10 _ = happyReduce_7

action_11 _ = happyReduce_9

action_12 (18) = happyShift action_36
action_12 _ = happyFail (happyExpListPerState 12)

action_13 (15) = happyShift action_14
action_13 (11) = happyGoto action_35
action_13 _ = happyFail (happyExpListPerState 13)

action_14 _ = happyReduce_18

action_15 _ = happyReduce_10

action_16 (15) = happyShift action_14
action_16 (11) = happyGoto action_34
action_16 _ = happyFail (happyExpListPerState 16)

action_17 (15) = happyShift action_14
action_17 (16) = happyShift action_27
action_17 (26) = happyShift action_28
action_17 (36) = happyShift action_29
action_17 (40) = happyShift action_30
action_17 (41) = happyShift action_31
action_17 (11) = happyGoto action_25
action_17 (14) = happyGoto action_33
action_17 _ = happyFail (happyExpListPerState 17)

action_18 (15) = happyShift action_14
action_18 (16) = happyShift action_27
action_18 (26) = happyShift action_28
action_18 (36) = happyShift action_29
action_18 (40) = happyShift action_30
action_18 (41) = happyShift action_31
action_18 (11) = happyGoto action_25
action_18 (14) = happyGoto action_32
action_18 _ = happyFail (happyExpListPerState 18)

action_19 (15) = happyShift action_14
action_19 (16) = happyShift action_27
action_19 (26) = happyShift action_28
action_19 (36) = happyShift action_29
action_19 (40) = happyShift action_30
action_19 (41) = happyShift action_31
action_19 (11) = happyGoto action_25
action_19 (14) = happyGoto action_26
action_19 _ = happyFail (happyExpListPerState 19)

action_20 _ = happyReduce_6

action_21 _ = happyReduce_19

action_22 _ = happyReduce_20

action_23 (25) = happyShift action_24
action_23 _ = happyFail (happyExpListPerState 23)

action_24 _ = happyReduce_11

action_25 _ = happyReduce_26

action_26 (28) = happyShift action_6
action_26 (30) = happyShift action_42
action_26 (31) = happyShift action_43
action_26 (32) = happyShift action_44
action_26 (33) = happyShift action_45
action_26 (34) = happyShift action_46
action_26 (35) = happyShift action_47
action_26 (37) = happyShift action_48
action_26 (7) = happyGoto action_52
action_26 _ = happyFail (happyExpListPerState 26)

action_27 _ = happyReduce_23

action_28 (15) = happyShift action_14
action_28 (16) = happyShift action_27
action_28 (26) = happyShift action_28
action_28 (36) = happyShift action_29
action_28 (40) = happyShift action_30
action_28 (41) = happyShift action_31
action_28 (11) = happyGoto action_25
action_28 (14) = happyGoto action_51
action_28 _ = happyFail (happyExpListPerState 28)

action_29 (15) = happyShift action_14
action_29 (16) = happyShift action_27
action_29 (26) = happyShift action_28
action_29 (36) = happyShift action_29
action_29 (40) = happyShift action_30
action_29 (41) = happyShift action_31
action_29 (11) = happyGoto action_25
action_29 (14) = happyGoto action_50
action_29 _ = happyFail (happyExpListPerState 29)

action_30 _ = happyReduce_24

action_31 _ = happyReduce_25

action_32 (22) = happyShift action_49
action_32 (30) = happyShift action_42
action_32 (31) = happyShift action_43
action_32 (32) = happyShift action_44
action_32 (33) = happyShift action_45
action_32 (34) = happyShift action_46
action_32 (35) = happyShift action_47
action_32 (37) = happyShift action_48
action_32 _ = happyFail (happyExpListPerState 32)

action_33 (25) = happyShift action_41
action_33 (30) = happyShift action_42
action_33 (31) = happyShift action_43
action_33 (32) = happyShift action_44
action_33 (33) = happyShift action_45
action_33 (34) = happyShift action_46
action_33 (35) = happyShift action_47
action_33 (37) = happyShift action_48
action_33 _ = happyFail (happyExpListPerState 33)

action_34 (25) = happyShift action_40
action_34 _ = happyFail (happyExpListPerState 34)

action_35 (18) = happyShift action_39
action_35 (13) = happyGoto action_38
action_35 _ = happyReduce_22

action_36 (15) = happyShift action_14
action_36 (16) = happyShift action_27
action_36 (26) = happyShift action_28
action_36 (36) = happyShift action_29
action_36 (40) = happyShift action_30
action_36 (41) = happyShift action_31
action_36 (11) = happyGoto action_25
action_36 (14) = happyGoto action_37
action_36 _ = happyFail (happyExpListPerState 36)

action_37 (25) = happyShift action_64
action_37 (30) = happyShift action_42
action_37 (31) = happyShift action_43
action_37 (32) = happyShift action_44
action_37 (33) = happyShift action_45
action_37 (34) = happyShift action_46
action_37 (35) = happyShift action_47
action_37 (37) = happyShift action_48
action_37 _ = happyFail (happyExpListPerState 37)

action_38 (25) = happyShift action_63
action_38 _ = happyFail (happyExpListPerState 38)

action_39 (15) = happyShift action_14
action_39 (16) = happyShift action_27
action_39 (26) = happyShift action_28
action_39 (36) = happyShift action_29
action_39 (40) = happyShift action_30
action_39 (41) = happyShift action_31
action_39 (11) = happyGoto action_25
action_39 (14) = happyGoto action_62
action_39 _ = happyFail (happyExpListPerState 39)

action_40 _ = happyReduce_16

action_41 _ = happyReduce_15

action_42 (15) = happyShift action_14
action_42 (16) = happyShift action_27
action_42 (26) = happyShift action_28
action_42 (36) = happyShift action_29
action_42 (40) = happyShift action_30
action_42 (41) = happyShift action_31
action_42 (11) = happyGoto action_25
action_42 (14) = happyGoto action_61
action_42 _ = happyFail (happyExpListPerState 42)

action_43 (15) = happyShift action_14
action_43 (16) = happyShift action_27
action_43 (26) = happyShift action_28
action_43 (36) = happyShift action_29
action_43 (40) = happyShift action_30
action_43 (41) = happyShift action_31
action_43 (11) = happyGoto action_25
action_43 (14) = happyGoto action_60
action_43 _ = happyFail (happyExpListPerState 43)

action_44 (15) = happyShift action_14
action_44 (16) = happyShift action_27
action_44 (26) = happyShift action_28
action_44 (36) = happyShift action_29
action_44 (40) = happyShift action_30
action_44 (41) = happyShift action_31
action_44 (11) = happyGoto action_25
action_44 (14) = happyGoto action_59
action_44 _ = happyFail (happyExpListPerState 44)

action_45 (15) = happyShift action_14
action_45 (16) = happyShift action_27
action_45 (26) = happyShift action_28
action_45 (36) = happyShift action_29
action_45 (40) = happyShift action_30
action_45 (41) = happyShift action_31
action_45 (11) = happyGoto action_25
action_45 (14) = happyGoto action_58
action_45 _ = happyFail (happyExpListPerState 45)

action_46 (15) = happyShift action_14
action_46 (16) = happyShift action_27
action_46 (26) = happyShift action_28
action_46 (36) = happyShift action_29
action_46 (40) = happyShift action_30
action_46 (41) = happyShift action_31
action_46 (11) = happyGoto action_25
action_46 (14) = happyGoto action_57
action_46 _ = happyFail (happyExpListPerState 46)

action_47 (15) = happyShift action_14
action_47 (16) = happyShift action_27
action_47 (26) = happyShift action_28
action_47 (36) = happyShift action_29
action_47 (40) = happyShift action_30
action_47 (41) = happyShift action_31
action_47 (11) = happyGoto action_25
action_47 (14) = happyGoto action_56
action_47 _ = happyFail (happyExpListPerState 47)

action_48 (15) = happyShift action_14
action_48 (16) = happyShift action_27
action_48 (26) = happyShift action_28
action_48 (36) = happyShift action_29
action_48 (40) = happyShift action_30
action_48 (41) = happyShift action_31
action_48 (11) = happyGoto action_25
action_48 (14) = happyGoto action_55
action_48 _ = happyFail (happyExpListPerState 48)

action_49 (28) = happyShift action_6
action_49 (7) = happyGoto action_54
action_49 _ = happyFail (happyExpListPerState 49)

action_50 _ = happyReduce_34

action_51 (27) = happyShift action_53
action_51 (30) = happyShift action_42
action_51 (31) = happyShift action_43
action_51 (32) = happyShift action_44
action_51 (33) = happyShift action_45
action_51 (34) = happyShift action_46
action_51 (35) = happyShift action_47
action_51 (37) = happyShift action_48
action_51 _ = happyFail (happyExpListPerState 51)

action_52 _ = happyReduce_17

action_53 _ = happyReduce_35

action_54 (23) = happyShift action_65
action_54 _ = happyFail (happyExpListPerState 54)

action_55 (30) = happyShift action_42
action_55 (31) = happyShift action_43
action_55 (32) = happyShift action_44
action_55 (33) = happyShift action_45
action_55 (34) = happyShift action_46
action_55 (35) = happyShift action_47
action_55 _ = happyReduce_33

action_56 (30) = happyShift action_42
action_56 (31) = happyShift action_43
action_56 (32) = happyShift action_44
action_56 (33) = happyShift action_45
action_56 (35) = happyFail []
action_56 _ = happyReduce_31

action_57 (30) = happyShift action_42
action_57 (31) = happyShift action_43
action_57 (32) = happyShift action_44
action_57 (33) = happyShift action_45
action_57 (34) = happyFail []
action_57 (35) = happyShift action_47
action_57 _ = happyReduce_32

action_58 _ = happyReduce_30

action_59 (31) = happyShift action_43
action_59 (33) = happyShift action_45
action_59 _ = happyReduce_29

action_60 (33) = happyShift action_45
action_60 _ = happyReduce_28

action_61 (31) = happyShift action_43
action_61 (32) = happyShift action_44
action_61 (33) = happyShift action_45
action_61 _ = happyReduce_27

action_62 (30) = happyShift action_42
action_62 (31) = happyShift action_43
action_62 (32) = happyShift action_44
action_62 (33) = happyShift action_45
action_62 (34) = happyShift action_46
action_62 (35) = happyShift action_47
action_62 (37) = happyShift action_48
action_62 _ = happyReduce_21

action_63 _ = happyReduce_13

action_64 _ = happyReduce_12

action_65 (28) = happyShift action_6
action_65 (7) = happyGoto action_66
action_65 _ = happyFail (happyExpListPerState 65)

action_66 _ = happyReduce_14

happyReduce_1 = happySpecReduce_3  4 happyReduction_1
happyReduction_1 (HappyAbsSyn6  happy_var_3)
	(HappyAbsSyn7  happy_var_2)
	(HappyAbsSyn5  happy_var_1)
	 =  HappyAbsSyn4
		 (Program (Block (reverse happy_var_1 ++ unBlock happy_var_2 ++ reverse happy_var_3))
	)
happyReduction_1 _ _ _  = notHappyAtAll 

happyReduce_2 = happySpecReduce_0  5 happyReduction_2
happyReduction_2  =  HappyAbsSyn5
		 ([]
	)

happyReduce_3 = happySpecReduce_2  5 happyReduction_3
happyReduction_3 (HappyTerminal (Token _ (TComment happy_var_2)))
	(HappyAbsSyn5  happy_var_1)
	 =  HappyAbsSyn5
		 (Comment happy_var_2 : happy_var_1
	)
happyReduction_3 _ _  = notHappyAtAll 

happyReduce_4 = happySpecReduce_0  6 happyReduction_4
happyReduction_4  =  HappyAbsSyn6
		 ([]
	)

happyReduce_5 = happySpecReduce_2  6 happyReduction_5
happyReduction_5 (HappyTerminal (Token _ (TComment happy_var_2)))
	(HappyAbsSyn6  happy_var_1)
	 =  HappyAbsSyn6
		 (Comment happy_var_2 : happy_var_1
	)
happyReduction_5 _ _  = notHappyAtAll 

happyReduce_6 = happySpecReduce_3  7 happyReduction_6
happyReduction_6 _
	(HappyAbsSyn8  happy_var_2)
	_
	 =  HappyAbsSyn7
		 (Block (reverse happy_var_2)
	)
happyReduction_6 _ _ _  = notHappyAtAll 

happyReduce_7 = happySpecReduce_2  8 happyReduction_7
happyReduction_7 (HappyAbsSyn9  happy_var_2)
	(HappyAbsSyn8  happy_var_1)
	 =  HappyAbsSyn8
		 (happy_var_2 : happy_var_1
	)
happyReduction_7 _ _  = notHappyAtAll 

happyReduce_8 = happySpecReduce_0  8 happyReduction_8
happyReduction_8  =  HappyAbsSyn8
		 ([]
	)

happyReduce_9 = happySpecReduce_1  9 happyReduction_9
happyReduction_9 (HappyAbsSyn10  happy_var_1)
	 =  HappyAbsSyn9
		 (ItemStmt happy_var_1
	)
happyReduction_9 _  = notHappyAtAll 

happyReduce_10 = happySpecReduce_1  9 happyReduction_10
happyReduction_10 (HappyTerminal (Token _ (TComment happy_var_1)))
	 =  HappyAbsSyn9
		 (Comment happy_var_1
	)
happyReduction_10 _  = notHappyAtAll 

happyReduce_11 = happySpecReduce_2  10 happyReduction_11
happyReduction_11 _
	_
	 =  HappyAbsSyn10
		 (Skip
	)

happyReduce_12 = happyReduce 4 10 happyReduction_12
happyReduction_12 (_ `HappyStk`
	(HappyAbsSyn14  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn11  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn10
		 (happy_var_1 := happy_var_3
	) `HappyStk` happyRest

happyReduce_13 = happyReduce 4 10 happyReduction_13
happyReduction_13 (_ `HappyStk`
	(HappyAbsSyn13  happy_var_3) `HappyStk`
	(HappyAbsSyn11  happy_var_2) `HappyStk`
	(HappyAbsSyn12  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn10
		 (Def happy_var_1 happy_var_2 happy_var_3
	) `HappyStk` happyRest

happyReduce_14 = happyReduce 6 10 happyReduction_14
happyReduction_14 ((HappyAbsSyn7  happy_var_6) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn7  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn14  happy_var_2) `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn10
		 (If happy_var_2 happy_var_4 happy_var_6
	) `HappyStk` happyRest

happyReduce_15 = happySpecReduce_3  10 happyReduction_15
happyReduction_15 _
	(HappyAbsSyn14  happy_var_2)
	_
	 =  HappyAbsSyn10
		 (Print happy_var_2
	)
happyReduction_15 _ _ _  = notHappyAtAll 

happyReduce_16 = happySpecReduce_3  10 happyReduction_16
happyReduction_16 _
	(HappyAbsSyn11  happy_var_2)
	_
	 =  HappyAbsSyn10
		 (SRead happy_var_2
	)
happyReduction_16 _ _ _  = notHappyAtAll 

happyReduce_17 = happySpecReduce_3  10 happyReduction_17
happyReduction_17 (HappyAbsSyn7  happy_var_3)
	(HappyAbsSyn14  happy_var_2)
	_
	 =  HappyAbsSyn10
		 (While happy_var_2 happy_var_3
	)
happyReduction_17 _ _ _  = notHappyAtAll 

happyReduce_18 = happySpecReduce_1  11 happyReduction_18
happyReduction_18 (HappyTerminal (Token _ (TIdent happy_var_1)))
	 =  HappyAbsSyn11
		 (Var happy_var_1
	)
happyReduction_18 _  = notHappyAtAll 

happyReduce_19 = happySpecReduce_1  12 happyReduction_19
happyReduction_19 _
	 =  HappyAbsSyn12
		 (TInt
	)

happyReduce_20 = happySpecReduce_1  12 happyReduction_20
happyReduction_20 _
	 =  HappyAbsSyn12
		 (TBool
	)

happyReduce_21 = happySpecReduce_2  13 happyReduction_21
happyReduction_21 (HappyAbsSyn14  happy_var_2)
	_
	 =  HappyAbsSyn13
		 (Just happy_var_2
	)
happyReduction_21 _ _  = notHappyAtAll 

happyReduce_22 = happySpecReduce_0  13 happyReduction_22
happyReduction_22  =  HappyAbsSyn13
		 (Nothing
	)

happyReduce_23 = happySpecReduce_1  14 happyReduction_23
happyReduction_23 (HappyTerminal (Token _ (TNumber happy_var_1)))
	 =  HappyAbsSyn14
		 (EValue (EInt happy_var_1)
	)
happyReduction_23 _  = notHappyAtAll 

happyReduce_24 = happySpecReduce_1  14 happyReduction_24
happyReduction_24 _
	 =  HappyAbsSyn14
		 (EValue (EBool True)
	)

happyReduce_25 = happySpecReduce_1  14 happyReduction_25
happyReduction_25 _
	 =  HappyAbsSyn14
		 (EValue (EBool False)
	)

happyReduce_26 = happySpecReduce_1  14 happyReduction_26
happyReduction_26 (HappyAbsSyn11  happy_var_1)
	 =  HappyAbsSyn14
		 (EVar happy_var_1
	)
happyReduction_26 _  = notHappyAtAll 

happyReduce_27 = happySpecReduce_3  14 happyReduction_27
happyReduction_27 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :+: happy_var_3
	)
happyReduction_27 _ _ _  = notHappyAtAll 

happyReduce_28 = happySpecReduce_3  14 happyReduction_28
happyReduction_28 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :*: happy_var_3
	)
happyReduction_28 _ _ _  = notHappyAtAll 

happyReduce_29 = happySpecReduce_3  14 happyReduction_29
happyReduction_29 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :-: happy_var_3
	)
happyReduction_29 _ _ _  = notHappyAtAll 

happyReduce_30 = happySpecReduce_3  14 happyReduction_30
happyReduction_30 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :/: happy_var_3
	)
happyReduction_30 _ _ _  = notHappyAtAll 

happyReduce_31 = happySpecReduce_3  14 happyReduction_31
happyReduction_31 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :<: happy_var_3
	)
happyReduction_31 _ _ _  = notHappyAtAll 

happyReduce_32 = happySpecReduce_3  14 happyReduction_32
happyReduction_32 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :==: happy_var_3
	)
happyReduction_32 _ _ _  = notHappyAtAll 

happyReduce_33 = happySpecReduce_3  14 happyReduction_33
happyReduction_33 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn14  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 :&: happy_var_3
	)
happyReduction_33 _ _ _  = notHappyAtAll 

happyReduce_34 = happySpecReduce_2  14 happyReduction_34
happyReduction_34 (HappyAbsSyn14  happy_var_2)
	_
	 =  HappyAbsSyn14
		 (ENot happy_var_2
	)
happyReduction_34 _ _  = notHappyAtAll 

happyReduce_35 = happySpecReduce_3  14 happyReduction_35
happyReduction_35 _
	(HappyAbsSyn14  happy_var_2)
	_
	 =  HappyAbsSyn14
		 (happy_var_2
	)
happyReduction_35 _ _ _  = notHappyAtAll 

happyNewToken action sts stk [] =
	action 43 43 notHappyAtAll (HappyState action) sts stk []

happyNewToken action sts stk (tk:tks) =
	let cont i = action i i tk (HappyState action) sts stk tks in
	case tk of {
	Token _ (TIdent happy_dollar_dollar) -> cont 15;
	Token _ (TNumber happy_dollar_dollar) -> cont 16;
	Token _ (TComment happy_dollar_dollar) -> cont 17;
	Token _ TAssign -> cont 18;
	Token _ TRead -> cont 19;
	Token _ TPrint -> cont 20;
	Token _ TIf -> cont 21;
	Token _ TThen -> cont 22;
	Token _ TElse -> cont 23;
	Token _ TWhile -> cont 24;
	Token _ TSemi -> cont 25;
	Token _ TLParen -> cont 26;
	Token _ TRParen -> cont 27;
	Token _ TLBrace -> cont 28;
	Token _ TRBrace -> cont 29;
	Token _ TPlus -> cont 30;
	Token _ TTimes -> cont 31;
	Token _ TMinus -> cont 32;
	Token _ TDiv -> cont 33;
	Token _ TEq -> cont 34;
	Token _ TLt -> cont 35;
	Token _ TNot -> cont 36;
	Token _ TAnd -> cont 37;
	Token _ TTInt -> cont 38;
	Token _ TTBool -> cont 39;
	Token _ TTrue -> cont 40;
	Token _ TFalse -> cont 41;
	Token _ TSkip -> cont 42;
	_ -> happyError' ((tk:tks), [])
	}

happyError_ explist 43 tk tks = happyError' (tks, explist)
happyError_ explist _ tk tks = happyError' ((tk:tks), explist)

newtype HappyIdentity a = HappyIdentity a
happyIdentity = HappyIdentity
happyRunIdentity (HappyIdentity a) = a

instance Prelude.Functor HappyIdentity where
    fmap f (HappyIdentity a) = HappyIdentity (f a)

instance Applicative HappyIdentity where
    pure  = HappyIdentity
    (<*>) = ap
instance Prelude.Monad HappyIdentity where
    return = pure
    (HappyIdentity p) >>= q = q p

happyThen :: () => HappyIdentity a -> (a -> HappyIdentity b) -> HappyIdentity b
happyThen = (Prelude.>>=)
happyReturn :: () => a -> HappyIdentity a
happyReturn = (Prelude.return)
happyThen1 m k tks = (Prelude.>>=) m (\a -> k a tks)
happyReturn1 :: () => a -> b -> HappyIdentity a
happyReturn1 = \a tks -> (Prelude.return) a
happyError' :: () => ([(Token)], [Prelude.String]) -> HappyIdentity a
happyError' = HappyIdentity Prelude.. (\(tokens, _) -> parseError tokens)
parser tks = happyRunIdentity happySomeParser where
 happySomeParser = happyThen (happyParse action_0 tks) (\x -> case x of {HappyAbsSyn4 z -> happyReturn z; _other -> notHappyAtAll })

happySeq = happyDontSeq


parseError :: [Token] -> a
parseError [] = error "Parse error!"
parseError (t : _) = error $ "Parse error " ++ (show t)

impParser :: String -> Program
impParser = parser . lexer
{-# LINE 1 "templates/GenericTemplate.hs" #-}
-- $Id: GenericTemplate.hs,v 1.26 2005/01/14 14:47:22 simonmar Exp $










































data Happy_IntList = HappyCons Prelude.Int Happy_IntList








































infixr 9 `HappyStk`
data HappyStk a = HappyStk a (HappyStk a)

-----------------------------------------------------------------------------
-- starting the parse

happyParse start_state = happyNewToken start_state notHappyAtAll notHappyAtAll

-----------------------------------------------------------------------------
-- Accepting the parse

-- If the current token is ERROR_TOK, it means we've just accepted a partial
-- parse (a %partial parser).  We must ignore the saved token on the top of
-- the stack in this case.
happyAccept (1) tk st sts (_ `HappyStk` ans `HappyStk` _) =
        happyReturn1 ans
happyAccept j tk st sts (HappyStk ans _) = 
         (happyReturn1 ans)

-----------------------------------------------------------------------------
-- Arrays only: do the next action









































indexShortOffAddr arr off = arr Happy_Data_Array.! off


{-# INLINE happyLt #-}
happyLt x y = (x Prelude.< y)






readArrayBit arr bit =
    Bits.testBit (indexShortOffAddr arr (bit `Prelude.div` 16)) (bit `Prelude.mod` 16)






-----------------------------------------------------------------------------
-- HappyState data type (not arrays)



newtype HappyState b c = HappyState
        (Prelude.Int ->                    -- token number
         Prelude.Int ->                    -- token number (yes, again)
         b ->                           -- token semantic value
         HappyState b c ->              -- current state
         [HappyState b c] ->            -- state stack
         c)



-----------------------------------------------------------------------------
-- Shifting a token

happyShift new_state (1) tk st sts stk@(x `HappyStk` _) =
     let i = (case x of { HappyErrorToken (i) -> i }) in
--     trace "shifting the error token" $
     new_state i i tk (HappyState (new_state)) ((st):(sts)) (stk)

happyShift new_state i tk st sts stk =
     happyNewToken new_state ((st):(sts)) ((HappyTerminal (tk))`HappyStk`stk)

-- happyReduce is specialised for the common cases.

happySpecReduce_0 i fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happySpecReduce_0 nt fn j tk st@((HappyState (action))) sts stk
     = action nt j tk st ((st):(sts)) (fn `HappyStk` stk)

happySpecReduce_1 i fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happySpecReduce_1 nt fn j tk _ sts@(((st@(HappyState (action))):(_))) (v1`HappyStk`stk')
     = let r = fn v1 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happySpecReduce_2 i fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happySpecReduce_2 nt fn j tk _ ((_):(sts@(((st@(HappyState (action))):(_))))) (v1`HappyStk`v2`HappyStk`stk')
     = let r = fn v1 v2 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happySpecReduce_3 i fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happySpecReduce_3 nt fn j tk _ ((_):(((_):(sts@(((st@(HappyState (action))):(_))))))) (v1`HappyStk`v2`HappyStk`v3`HappyStk`stk')
     = let r = fn v1 v2 v3 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happyReduce k i fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happyReduce k nt fn j tk st sts stk
     = case happyDrop (k Prelude.- ((1) :: Prelude.Int)) sts of
         sts1@(((st1@(HappyState (action))):(_))) ->
                let r = fn stk in  -- it doesn't hurt to always seq here...
                happyDoSeq r (action nt j tk st1 sts1 r)

happyMonadReduce k nt fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happyMonadReduce k nt fn j tk st sts stk =
      case happyDrop k ((st):(sts)) of
        sts1@(((st1@(HappyState (action))):(_))) ->
          let drop_stk = happyDropStk k stk in
          happyThen1 (fn stk tk) (\r -> action nt j tk st1 sts1 (r `HappyStk` drop_stk))

happyMonad2Reduce k nt fn (1) tk st sts stk
     = happyFail [] (1) tk st sts stk
happyMonad2Reduce k nt fn j tk st sts stk =
      case happyDrop k ((st):(sts)) of
        sts1@(((st1@(HappyState (action))):(_))) ->
         let drop_stk = happyDropStk k stk





             _ = nt :: Prelude.Int
             new_state = action

          in
          happyThen1 (fn stk tk) (\r -> happyNewToken new_state sts1 (r `HappyStk` drop_stk))

happyDrop (0) l = l
happyDrop n ((_):(t)) = happyDrop (n Prelude.- ((1) :: Prelude.Int)) t

happyDropStk (0) l = l
happyDropStk n (x `HappyStk` xs) = happyDropStk (n Prelude.- ((1)::Prelude.Int)) xs

-----------------------------------------------------------------------------
-- Moving to a new state after a reduction









happyGoto action j tk st = action j j tk (HappyState action)


-----------------------------------------------------------------------------
-- Error recovery (ERROR_TOK is the error token)

-- parse error if we are in recovery and we fail again
happyFail explist (1) tk old_st _ stk@(x `HappyStk` _) =
     let i = (case x of { HappyErrorToken (i) -> i }) in
--      trace "failing" $ 
        happyError_ explist i tk

{-  We don't need state discarding for our restricted implementation of
    "error".  In fact, it can cause some bogus parses, so I've disabled it
    for now --SDM

-- discard a state
happyFail  ERROR_TOK tk old_st CONS(HAPPYSTATE(action),sts) 
                                                (saved_tok `HappyStk` _ `HappyStk` stk) =
--      trace ("discarding state, depth " ++ show (length stk))  $
        DO_ACTION(action,ERROR_TOK,tk,sts,(saved_tok`HappyStk`stk))
-}

-- Enter error recovery: generate an error token,
--                       save the old token and carry on.
happyFail explist i tk (HappyState (action)) sts stk =
--      trace "entering error recovery" $
        action (1) (1) tk (HappyState (action)) sts ((HappyErrorToken (i)) `HappyStk` stk)

-- Internal happy errors:

notHappyAtAll :: a
notHappyAtAll = Prelude.error "Internal Happy error\n"

-----------------------------------------------------------------------------
-- Hack to get the typechecker to accept our action functions







-----------------------------------------------------------------------------
-- Seq-ing.  If the --strict flag is given, then Happy emits 
--      happySeq = happyDoSeq
-- otherwise it emits
--      happySeq = happyDontSeq

happyDoSeq, happyDontSeq :: a -> b -> b
happyDoSeq   a b = a `Prelude.seq` b
happyDontSeq a b = b

-----------------------------------------------------------------------------
-- Don't inline any functions from the template.  GHC has a nasty habit
-- of deciding to inline happyGoto everywhere, which increases the size of
-- the generated parser quite a bit.









{-# NOINLINE happyShift #-}
{-# NOINLINE happySpecReduce_0 #-}
{-# NOINLINE happySpecReduce_1 #-}
{-# NOINLINE happySpecReduce_2 #-}
{-# NOINLINE happySpecReduce_3 #-}
{-# NOINLINE happyReduce #-}
{-# NOINLINE happyMonadReduce #-}
{-# NOINLINE happyGoto #-}
{-# NOINLINE happyFail #-}

-- end of Happy Template.
