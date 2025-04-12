{-# OPTIONS_GHC -w #-}
module Frontend.Parser.LALR.Parser (langParser) where

import Syntax.Syntax
import Frontend.Lexer.Lexer hiding (lexer)
import qualified Data.Array as Happy_Data_Array
import qualified Data.Bits as Bits
import Control.Applicative(Applicative(..))
import Control.Monad (ap)

-- parser produced by Happy Version 1.20.1.1

data HappyAbsSyn t4 t5 t6 t7 t8 t9 t10 t11 t12 t13 t14 t15 t16 t17 t18 t19 t20 t21 t22 t23 t24 t25 t26
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
	| HappyAbsSyn15 t15
	| HappyAbsSyn16 t16
	| HappyAbsSyn17 t17
	| HappyAbsSyn18 t18
	| HappyAbsSyn19 t19
	| HappyAbsSyn20 t20
	| HappyAbsSyn21 t21
	| HappyAbsSyn22 t22
	| HappyAbsSyn23 t23
	| HappyAbsSyn24 t24
	| HappyAbsSyn25 t25
	| HappyAbsSyn26 t26

happyExpList :: Happy_Data_Array.Array Prelude.Int Prelude.Int
happyExpList = Happy_Data_Array.listArray (0,408) ([0,1024,0,0,4,0,1,0,256,0,0,0,0,0,4096,0,0,16,0,0,4,0,0,512,0,0,0,0,0,0,0,0,0,64,0,0,1024,0,0,0,0,0,0,0,0,0,128,0,0,0,0,0,0,0,0,2,0,0,0,32,0,0,16384,0,0,0,0,0,128,0,0,1024,0,0,0,0,8192,0,0,0,128,0,1920,0,4096,0,0,0,0,16384,0,0,0,0,1024,0,0,32768,0,32768,7,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,480,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,128,0,0,16384,368,1,256,0,0,0,0,0,0,8192,0,0,0,1473,4,1024,0,2048,0,0,0,0,5632,1,0,0,4,0,0,0,7424,256,57473,2,0,16384,0,0,0,0,16,0,0,1024,4119,0,16,0,29,33025,736,0,128,0,1920,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8192,0,0,0,0,0,0,0,0,512,1535,0,0,16384,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7424,256,57473,2,16384,16391,8256,184,0,464,4112,11784,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8192,0,57344,1,0,0,32,0,0,7424,256,57473,2,16384,16391,8256,184,0,32768,64512,23,0,0,32,0,0,0,16384,16,0,0,0,0,0,0,8192,0,57344,1,0,4,0,0,0,7424,256,57473,2,16384,16391,8256,184,0,464,4112,11784,0,0,0,0,0,0,0,0,0,0,0,61442,95,0,0,0,6142,0,0,0,8,0,0,0,49280,383,0,0,4096,4,0,0,33280,0,0,0,0,0,0,0,0,0,0,0,0,1856,16448,47136,0,53248,4097,2064,46,0,116,1028,2946,0,7424,256,57473,2,16384,16391,8256,184,0,464,4112,11784,0,29696,1024,33284,11,0,29,33025,736,0,1856,16448,47136,0,53248,4097,2064,46,0,0,65288,5,0,0,49664,383,0,0,0,0,0,0,0,256,0,0,0,0,0,0,0,0,1664,0,0,0,61568,95,0,53248,4097,2064,46,0,8192,0,0,0,7424,256,57473,2,32768,0,32768,7,0,0,0,0,0,0,512,1535,0,0,0,0,0,0,0,128,0,0,0,0,0,0,0,116,1028,2946,0,49408,1029,0,4,16384,368,1,256,0,0,64512,7,0,0,0,31,0,0,0,1984,0,0,0,61440,25,0,0,0,1660,0,0,0,0,0,0,0,0,0,0,0,0,416,0,0,0,0,0,0,0,0,26,0,0,29,33025,736,0,0,0,0,0,53248,4097,2064,46,0,8192,32768,0,0,0,4160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2048,6140,0,0,8192,65280,5,0,0,2,0,0,0,0,0,0,0,0,512,0,0,0,16384,0,0,0,0,0,0,0,1856,16448,47136,0,0,0,0,0,0,5892,16,4096,0,0,0,0,0,16384,16391,8256,184,0,0,0,4,0,0,512,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,57344,383,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32768,0,0,0,64,0,0,0,0,0,0,0,0
	])

{-# NOINLINE happyExpListPerState #-}
happyExpListPerState st =
    token_strs_expected
  where token_strs = ["error","%dummy","%start_parser","Prog","Defs","Def","Decls","Decl","Params","ParamList","Param","ReturnType","Types","TypeList","Type","BaseType","Cmds","Cmd","ReturnList","Exps","ExpList","LValues","LValueList","LValue","LValueLinha","Exp","id","typeName","intNumber","floatNumber","character","\"=\"","\"read\"","\"print\"","\"if\"","\"else\"","\"iterate\"","\";\"","\":\"","\"::\"","\".\"","\",\"","\"(\"","\")\"","\"{\"","\"}\"","\"[\"","\"]\"","\"+\"","\"*\"","\"-\"","\"/\"","\"%\"","\"==\"","\"!=\"","\"<\"","\">\"","\"!\"","\"&&\"","\"Int\"","\"Float\"","\"Char\"","\"Bool\"","\"true\"","\"false\"","\"null\"","\"data\"","\"new\"","\"return\"","%eof"]
        bit_start = st Prelude.* 70
        bit_end = (st Prelude.+ 1) Prelude.* 70
        read_bit = readArrayBit happyExpList
        bits = Prelude.map read_bit [bit_start..bit_end Prelude.- 1]
        bits_indexed = Prelude.zip bits [0..69]
        token_strs_expected = Prelude.concatMap f bits_indexed
        f (Prelude.False, _) = []
        f (Prelude.True, nr) = [token_strs Prelude.!! nr]

action_0 (27) = happyShift action_4
action_0 (67) = happyShift action_5
action_0 (4) = happyGoto action_6
action_0 (5) = happyGoto action_2
action_0 (6) = happyGoto action_3
action_0 _ = happyReduce_3

action_1 (27) = happyShift action_4
action_1 (67) = happyShift action_5
action_1 (5) = happyGoto action_2
action_1 (6) = happyGoto action_3
action_1 _ = happyFail (happyExpListPerState 1)

action_2 _ = happyReduce_1

action_3 (27) = happyShift action_4
action_3 (67) = happyShift action_5
action_3 (5) = happyGoto action_9
action_3 (6) = happyGoto action_3
action_3 _ = happyReduce_3

action_4 (43) = happyShift action_8
action_4 _ = happyFail (happyExpListPerState 4)

action_5 (28) = happyShift action_7
action_5 _ = happyFail (happyExpListPerState 5)

action_6 (70) = happyAccept
action_6 _ = happyFail (happyExpListPerState 6)

action_7 (45) = happyShift action_14
action_7 _ = happyFail (happyExpListPerState 7)

action_8 (27) = happyShift action_13
action_8 (9) = happyGoto action_10
action_8 (10) = happyGoto action_11
action_8 (11) = happyGoto action_12
action_8 _ = happyReduce_10

action_9 _ = happyReduce_2

action_10 (44) = happyShift action_20
action_10 _ = happyFail (happyExpListPerState 10)

action_11 _ = happyReduce_9

action_12 (42) = happyShift action_19
action_12 _ = happyReduce_12

action_13 (40) = happyShift action_18
action_13 _ = happyFail (happyExpListPerState 13)

action_14 (27) = happyShift action_17
action_14 (7) = happyGoto action_15
action_14 (8) = happyGoto action_16
action_14 _ = happyReduce_7

action_15 (46) = happyShift action_33
action_15 _ = happyFail (happyExpListPerState 15)

action_16 (27) = happyShift action_17
action_16 (7) = happyGoto action_32
action_16 (8) = happyGoto action_16
action_16 _ = happyReduce_7

action_17 (40) = happyShift action_31
action_17 _ = happyFail (happyExpListPerState 17)

action_18 (28) = happyShift action_26
action_18 (60) = happyShift action_27
action_18 (61) = happyShift action_28
action_18 (62) = happyShift action_29
action_18 (63) = happyShift action_30
action_18 (15) = happyGoto action_24
action_18 (16) = happyGoto action_25
action_18 _ = happyFail (happyExpListPerState 18)

action_19 (27) = happyShift action_13
action_19 (10) = happyGoto action_23
action_19 (11) = happyGoto action_12
action_19 _ = happyFail (happyExpListPerState 19)

action_20 (39) = happyShift action_22
action_20 (12) = happyGoto action_21
action_20 _ = happyReduce_15

action_21 (45) = happyShift action_38
action_21 _ = happyFail (happyExpListPerState 21)

action_22 (28) = happyShift action_26
action_22 (60) = happyShift action_27
action_22 (61) = happyShift action_28
action_22 (62) = happyShift action_29
action_22 (63) = happyShift action_30
action_22 (13) = happyGoto action_36
action_22 (15) = happyGoto action_37
action_22 (16) = happyGoto action_25
action_22 _ = happyFail (happyExpListPerState 22)

action_23 _ = happyReduce_11

action_24 _ = happyReduce_13

action_25 (47) = happyShift action_35
action_25 _ = happyReduce_21

action_26 _ = happyReduce_26

action_27 _ = happyReduce_22

action_28 _ = happyReduce_25

action_29 _ = happyReduce_24

action_30 _ = happyReduce_23

action_31 (28) = happyShift action_26
action_31 (60) = happyShift action_27
action_31 (61) = happyShift action_28
action_31 (62) = happyShift action_29
action_31 (63) = happyShift action_30
action_31 (15) = happyGoto action_34
action_31 (16) = happyGoto action_25
action_31 _ = happyFail (happyExpListPerState 31)

action_32 _ = happyReduce_6

action_33 _ = happyReduce_4

action_34 (38) = happyShift action_52
action_34 _ = happyFail (happyExpListPerState 34)

action_35 (48) = happyShift action_51
action_35 _ = happyFail (happyExpListPerState 35)

action_36 _ = happyReduce_14

action_37 (42) = happyShift action_50
action_37 _ = happyReduce_17

action_38 (27) = happyShift action_43
action_38 (33) = happyShift action_44
action_38 (34) = happyShift action_45
action_38 (35) = happyShift action_46
action_38 (37) = happyShift action_47
action_38 (45) = happyShift action_48
action_38 (69) = happyShift action_49
action_38 (8) = happyGoto action_39
action_38 (17) = happyGoto action_40
action_38 (18) = happyGoto action_41
action_38 (24) = happyGoto action_42
action_38 _ = happyReduce_28

action_39 _ = happyReduce_39

action_40 (46) = happyShift action_81
action_40 _ = happyFail (happyExpListPerState 40)

action_41 (27) = happyShift action_43
action_41 (33) = happyShift action_44
action_41 (34) = happyShift action_45
action_41 (35) = happyShift action_46
action_41 (37) = happyShift action_47
action_41 (45) = happyShift action_48
action_41 (69) = happyShift action_49
action_41 (8) = happyGoto action_39
action_41 (17) = happyGoto action_80
action_41 (18) = happyGoto action_41
action_41 (24) = happyGoto action_42
action_41 _ = happyReduce_28

action_42 (32) = happyShift action_79
action_42 _ = happyFail (happyExpListPerState 42)

action_43 (40) = happyShift action_75
action_43 (41) = happyShift action_76
action_43 (43) = happyShift action_77
action_43 (47) = happyShift action_78
action_43 (25) = happyGoto action_74
action_43 _ = happyReduce_53

action_44 (27) = happyShift action_73
action_44 (24) = happyGoto action_72
action_44 _ = happyFail (happyExpListPerState 44)

action_45 (27) = happyShift action_57
action_45 (29) = happyShift action_58
action_45 (30) = happyShift action_59
action_45 (31) = happyShift action_60
action_45 (43) = happyShift action_61
action_45 (51) = happyShift action_62
action_45 (58) = happyShift action_63
action_45 (64) = happyShift action_64
action_45 (65) = happyShift action_65
action_45 (66) = happyShift action_66
action_45 (68) = happyShift action_67
action_45 (24) = happyGoto action_55
action_45 (26) = happyGoto action_71
action_45 _ = happyFail (happyExpListPerState 45)

action_46 (43) = happyShift action_70
action_46 _ = happyFail (happyExpListPerState 46)

action_47 (43) = happyShift action_69
action_47 _ = happyFail (happyExpListPerState 47)

action_48 (27) = happyShift action_43
action_48 (33) = happyShift action_44
action_48 (34) = happyShift action_45
action_48 (35) = happyShift action_46
action_48 (37) = happyShift action_47
action_48 (45) = happyShift action_48
action_48 (69) = happyShift action_49
action_48 (8) = happyGoto action_39
action_48 (17) = happyGoto action_68
action_48 (18) = happyGoto action_41
action_48 (24) = happyGoto action_42
action_48 _ = happyReduce_28

action_49 (27) = happyShift action_57
action_49 (29) = happyShift action_58
action_49 (30) = happyShift action_59
action_49 (31) = happyShift action_60
action_49 (43) = happyShift action_61
action_49 (51) = happyShift action_62
action_49 (58) = happyShift action_63
action_49 (64) = happyShift action_64
action_49 (65) = happyShift action_65
action_49 (66) = happyShift action_66
action_49 (68) = happyShift action_67
action_49 (24) = happyGoto action_55
action_49 (26) = happyGoto action_56
action_49 _ = happyFail (happyExpListPerState 49)

action_50 (28) = happyShift action_26
action_50 (60) = happyShift action_27
action_50 (61) = happyShift action_28
action_50 (62) = happyShift action_29
action_50 (63) = happyShift action_30
action_50 (14) = happyGoto action_53
action_50 (15) = happyGoto action_54
action_50 (16) = happyGoto action_25
action_50 _ = happyFail (happyExpListPerState 50)

action_51 _ = happyReduce_20

action_52 _ = happyReduce_8

action_53 _ = happyReduce_16

action_54 (42) = happyShift action_110
action_54 _ = happyReduce_19

action_55 _ = happyReduce_79

action_56 (42) = happyShift action_109
action_56 (49) = happyShift action_90
action_56 (50) = happyShift action_91
action_56 (51) = happyShift action_92
action_56 (52) = happyShift action_93
action_56 (53) = happyShift action_94
action_56 (54) = happyShift action_95
action_56 (55) = happyShift action_96
action_56 (56) = happyShift action_97
action_56 (57) = happyShift action_98
action_56 (59) = happyShift action_99
action_56 (19) = happyGoto action_108
action_56 _ = happyReduce_42

action_57 (41) = happyShift action_76
action_57 (43) = happyShift action_107
action_57 (47) = happyShift action_78
action_57 (25) = happyGoto action_74
action_57 _ = happyReduce_53

action_58 _ = happyReduce_74

action_59 _ = happyReduce_75

action_60 _ = happyReduce_76

action_61 (27) = happyShift action_57
action_61 (29) = happyShift action_58
action_61 (30) = happyShift action_59
action_61 (31) = happyShift action_60
action_61 (43) = happyShift action_61
action_61 (51) = happyShift action_62
action_61 (58) = happyShift action_63
action_61 (64) = happyShift action_64
action_61 (65) = happyShift action_65
action_61 (66) = happyShift action_66
action_61 (68) = happyShift action_67
action_61 (24) = happyGoto action_55
action_61 (26) = happyGoto action_106
action_61 _ = happyFail (happyExpListPerState 61)

action_62 (27) = happyShift action_57
action_62 (29) = happyShift action_58
action_62 (30) = happyShift action_59
action_62 (31) = happyShift action_60
action_62 (43) = happyShift action_61
action_62 (51) = happyShift action_62
action_62 (58) = happyShift action_63
action_62 (64) = happyShift action_64
action_62 (65) = happyShift action_65
action_62 (66) = happyShift action_66
action_62 (68) = happyShift action_67
action_62 (24) = happyGoto action_55
action_62 (26) = happyGoto action_105
action_62 _ = happyFail (happyExpListPerState 62)

action_63 (27) = happyShift action_57
action_63 (29) = happyShift action_58
action_63 (30) = happyShift action_59
action_63 (31) = happyShift action_60
action_63 (43) = happyShift action_61
action_63 (51) = happyShift action_62
action_63 (58) = happyShift action_63
action_63 (64) = happyShift action_64
action_63 (65) = happyShift action_65
action_63 (66) = happyShift action_66
action_63 (68) = happyShift action_67
action_63 (24) = happyGoto action_55
action_63 (26) = happyGoto action_104
action_63 _ = happyFail (happyExpListPerState 63)

action_64 _ = happyReduce_71

action_65 _ = happyReduce_72

action_66 _ = happyReduce_73

action_67 (28) = happyShift action_26
action_67 (60) = happyShift action_27
action_67 (61) = happyShift action_28
action_67 (62) = happyShift action_29
action_67 (63) = happyShift action_30
action_67 (16) = happyGoto action_103
action_67 _ = happyFail (happyExpListPerState 67)

action_68 (46) = happyShift action_102
action_68 _ = happyFail (happyExpListPerState 68)

action_69 (27) = happyShift action_57
action_69 (29) = happyShift action_58
action_69 (30) = happyShift action_59
action_69 (31) = happyShift action_60
action_69 (43) = happyShift action_61
action_69 (51) = happyShift action_62
action_69 (58) = happyShift action_63
action_69 (64) = happyShift action_64
action_69 (65) = happyShift action_65
action_69 (66) = happyShift action_66
action_69 (68) = happyShift action_67
action_69 (24) = happyGoto action_55
action_69 (26) = happyGoto action_101
action_69 _ = happyFail (happyExpListPerState 69)

action_70 (27) = happyShift action_57
action_70 (29) = happyShift action_58
action_70 (30) = happyShift action_59
action_70 (31) = happyShift action_60
action_70 (43) = happyShift action_61
action_70 (51) = happyShift action_62
action_70 (58) = happyShift action_63
action_70 (64) = happyShift action_64
action_70 (65) = happyShift action_65
action_70 (66) = happyShift action_66
action_70 (68) = happyShift action_67
action_70 (24) = happyGoto action_55
action_70 (26) = happyGoto action_100
action_70 _ = happyFail (happyExpListPerState 70)

action_71 (38) = happyShift action_89
action_71 (49) = happyShift action_90
action_71 (50) = happyShift action_91
action_71 (51) = happyShift action_92
action_71 (52) = happyShift action_93
action_71 (53) = happyShift action_94
action_71 (54) = happyShift action_95
action_71 (55) = happyShift action_96
action_71 (56) = happyShift action_97
action_71 (57) = happyShift action_98
action_71 (59) = happyShift action_99
action_71 _ = happyFail (happyExpListPerState 71)

action_72 (38) = happyShift action_88
action_72 _ = happyFail (happyExpListPerState 72)

action_73 (41) = happyShift action_76
action_73 (47) = happyShift action_78
action_73 (25) = happyGoto action_74
action_73 _ = happyReduce_53

action_74 _ = happyReduce_54

action_75 (28) = happyShift action_26
action_75 (60) = happyShift action_27
action_75 (61) = happyShift action_28
action_75 (62) = happyShift action_29
action_75 (63) = happyShift action_30
action_75 (15) = happyGoto action_87
action_75 (16) = happyGoto action_25
action_75 _ = happyFail (happyExpListPerState 75)

action_76 (27) = happyShift action_86
action_76 _ = happyFail (happyExpListPerState 76)

action_77 (27) = happyShift action_57
action_77 (29) = happyShift action_58
action_77 (30) = happyShift action_59
action_77 (31) = happyShift action_60
action_77 (43) = happyShift action_61
action_77 (51) = happyShift action_62
action_77 (58) = happyShift action_63
action_77 (64) = happyShift action_64
action_77 (65) = happyShift action_65
action_77 (66) = happyShift action_66
action_77 (68) = happyShift action_67
action_77 (20) = happyGoto action_84
action_77 (24) = happyGoto action_55
action_77 (26) = happyGoto action_85
action_77 _ = happyReduce_45

action_78 (27) = happyShift action_57
action_78 (29) = happyShift action_58
action_78 (30) = happyShift action_59
action_78 (31) = happyShift action_60
action_78 (43) = happyShift action_61
action_78 (51) = happyShift action_62
action_78 (58) = happyShift action_63
action_78 (64) = happyShift action_64
action_78 (65) = happyShift action_65
action_78 (66) = happyShift action_66
action_78 (68) = happyShift action_67
action_78 (24) = happyGoto action_55
action_78 (26) = happyGoto action_83
action_78 _ = happyFail (happyExpListPerState 78)

action_79 (27) = happyShift action_57
action_79 (29) = happyShift action_58
action_79 (30) = happyShift action_59
action_79 (31) = happyShift action_60
action_79 (43) = happyShift action_61
action_79 (51) = happyShift action_62
action_79 (58) = happyShift action_63
action_79 (64) = happyShift action_64
action_79 (65) = happyShift action_65
action_79 (66) = happyShift action_66
action_79 (68) = happyShift action_67
action_79 (24) = happyGoto action_55
action_79 (26) = happyGoto action_82
action_79 _ = happyFail (happyExpListPerState 79)

action_80 _ = happyReduce_27

action_81 _ = happyReduce_5

action_82 (38) = happyShift action_134
action_82 (49) = happyShift action_90
action_82 (50) = happyShift action_91
action_82 (51) = happyShift action_92
action_82 (52) = happyShift action_93
action_82 (53) = happyShift action_94
action_82 (54) = happyShift action_95
action_82 (55) = happyShift action_96
action_82 (56) = happyShift action_97
action_82 (57) = happyShift action_98
action_82 (59) = happyShift action_99
action_82 _ = happyFail (happyExpListPerState 82)

action_83 (48) = happyShift action_133
action_83 (49) = happyShift action_90
action_83 (50) = happyShift action_91
action_83 (51) = happyShift action_92
action_83 (52) = happyShift action_93
action_83 (53) = happyShift action_94
action_83 (54) = happyShift action_95
action_83 (55) = happyShift action_96
action_83 (56) = happyShift action_97
action_83 (57) = happyShift action_98
action_83 (59) = happyShift action_99
action_83 _ = happyFail (happyExpListPerState 83)

action_84 (44) = happyShift action_132
action_84 _ = happyFail (happyExpListPerState 84)

action_85 (42) = happyShift action_131
action_85 (49) = happyShift action_90
action_85 (50) = happyShift action_91
action_85 (51) = happyShift action_92
action_85 (52) = happyShift action_93
action_85 (53) = happyShift action_94
action_85 (54) = happyShift action_95
action_85 (55) = happyShift action_96
action_85 (56) = happyShift action_97
action_85 (57) = happyShift action_98
action_85 (59) = happyShift action_99
action_85 _ = happyReduce_44

action_86 (41) = happyShift action_76
action_86 (47) = happyShift action_78
action_86 (25) = happyGoto action_130
action_86 _ = happyReduce_56

action_87 (32) = happyShift action_129
action_87 (38) = happyShift action_52
action_87 _ = happyFail (happyExpListPerState 87)

action_88 _ = happyReduce_34

action_89 _ = happyReduce_33

action_90 (27) = happyShift action_57
action_90 (29) = happyShift action_58
action_90 (30) = happyShift action_59
action_90 (31) = happyShift action_60
action_90 (43) = happyShift action_61
action_90 (51) = happyShift action_62
action_90 (58) = happyShift action_63
action_90 (64) = happyShift action_64
action_90 (65) = happyShift action_65
action_90 (66) = happyShift action_66
action_90 (68) = happyShift action_67
action_90 (24) = happyGoto action_55
action_90 (26) = happyGoto action_128
action_90 _ = happyFail (happyExpListPerState 90)

action_91 (27) = happyShift action_57
action_91 (29) = happyShift action_58
action_91 (30) = happyShift action_59
action_91 (31) = happyShift action_60
action_91 (43) = happyShift action_61
action_91 (51) = happyShift action_62
action_91 (58) = happyShift action_63
action_91 (64) = happyShift action_64
action_91 (65) = happyShift action_65
action_91 (66) = happyShift action_66
action_91 (68) = happyShift action_67
action_91 (24) = happyGoto action_55
action_91 (26) = happyGoto action_127
action_91 _ = happyFail (happyExpListPerState 91)

action_92 (27) = happyShift action_57
action_92 (29) = happyShift action_58
action_92 (30) = happyShift action_59
action_92 (31) = happyShift action_60
action_92 (43) = happyShift action_61
action_92 (51) = happyShift action_62
action_92 (58) = happyShift action_63
action_92 (64) = happyShift action_64
action_92 (65) = happyShift action_65
action_92 (66) = happyShift action_66
action_92 (68) = happyShift action_67
action_92 (24) = happyGoto action_55
action_92 (26) = happyGoto action_126
action_92 _ = happyFail (happyExpListPerState 92)

action_93 (27) = happyShift action_57
action_93 (29) = happyShift action_58
action_93 (30) = happyShift action_59
action_93 (31) = happyShift action_60
action_93 (43) = happyShift action_61
action_93 (51) = happyShift action_62
action_93 (58) = happyShift action_63
action_93 (64) = happyShift action_64
action_93 (65) = happyShift action_65
action_93 (66) = happyShift action_66
action_93 (68) = happyShift action_67
action_93 (24) = happyGoto action_55
action_93 (26) = happyGoto action_125
action_93 _ = happyFail (happyExpListPerState 93)

action_94 (27) = happyShift action_57
action_94 (29) = happyShift action_58
action_94 (30) = happyShift action_59
action_94 (31) = happyShift action_60
action_94 (43) = happyShift action_61
action_94 (51) = happyShift action_62
action_94 (58) = happyShift action_63
action_94 (64) = happyShift action_64
action_94 (65) = happyShift action_65
action_94 (66) = happyShift action_66
action_94 (68) = happyShift action_67
action_94 (24) = happyGoto action_55
action_94 (26) = happyGoto action_124
action_94 _ = happyFail (happyExpListPerState 94)

action_95 (27) = happyShift action_57
action_95 (29) = happyShift action_58
action_95 (30) = happyShift action_59
action_95 (31) = happyShift action_60
action_95 (43) = happyShift action_61
action_95 (51) = happyShift action_62
action_95 (58) = happyShift action_63
action_95 (64) = happyShift action_64
action_95 (65) = happyShift action_65
action_95 (66) = happyShift action_66
action_95 (68) = happyShift action_67
action_95 (24) = happyGoto action_55
action_95 (26) = happyGoto action_123
action_95 _ = happyFail (happyExpListPerState 95)

action_96 (27) = happyShift action_57
action_96 (29) = happyShift action_58
action_96 (30) = happyShift action_59
action_96 (31) = happyShift action_60
action_96 (43) = happyShift action_61
action_96 (51) = happyShift action_62
action_96 (58) = happyShift action_63
action_96 (64) = happyShift action_64
action_96 (65) = happyShift action_65
action_96 (66) = happyShift action_66
action_96 (68) = happyShift action_67
action_96 (24) = happyGoto action_55
action_96 (26) = happyGoto action_122
action_96 _ = happyFail (happyExpListPerState 96)

action_97 (27) = happyShift action_57
action_97 (29) = happyShift action_58
action_97 (30) = happyShift action_59
action_97 (31) = happyShift action_60
action_97 (43) = happyShift action_61
action_97 (51) = happyShift action_62
action_97 (58) = happyShift action_63
action_97 (64) = happyShift action_64
action_97 (65) = happyShift action_65
action_97 (66) = happyShift action_66
action_97 (68) = happyShift action_67
action_97 (24) = happyGoto action_55
action_97 (26) = happyGoto action_121
action_97 _ = happyFail (happyExpListPerState 97)

action_98 (27) = happyShift action_57
action_98 (29) = happyShift action_58
action_98 (30) = happyShift action_59
action_98 (31) = happyShift action_60
action_98 (43) = happyShift action_61
action_98 (51) = happyShift action_62
action_98 (58) = happyShift action_63
action_98 (64) = happyShift action_64
action_98 (65) = happyShift action_65
action_98 (66) = happyShift action_66
action_98 (68) = happyShift action_67
action_98 (24) = happyGoto action_55
action_98 (26) = happyGoto action_120
action_98 _ = happyFail (happyExpListPerState 98)

action_99 (27) = happyShift action_57
action_99 (29) = happyShift action_58
action_99 (30) = happyShift action_59
action_99 (31) = happyShift action_60
action_99 (43) = happyShift action_61
action_99 (51) = happyShift action_62
action_99 (58) = happyShift action_63
action_99 (64) = happyShift action_64
action_99 (65) = happyShift action_65
action_99 (66) = happyShift action_66
action_99 (68) = happyShift action_67
action_99 (24) = happyGoto action_55
action_99 (26) = happyGoto action_119
action_99 _ = happyFail (happyExpListPerState 99)

action_100 (44) = happyShift action_118
action_100 (49) = happyShift action_90
action_100 (50) = happyShift action_91
action_100 (51) = happyShift action_92
action_100 (52) = happyShift action_93
action_100 (53) = happyShift action_94
action_100 (54) = happyShift action_95
action_100 (55) = happyShift action_96
action_100 (56) = happyShift action_97
action_100 (57) = happyShift action_98
action_100 (59) = happyShift action_99
action_100 _ = happyFail (happyExpListPerState 100)

action_101 (44) = happyShift action_117
action_101 (49) = happyShift action_90
action_101 (50) = happyShift action_91
action_101 (51) = happyShift action_92
action_101 (52) = happyShift action_93
action_101 (53) = happyShift action_94
action_101 (54) = happyShift action_95
action_101 (55) = happyShift action_96
action_101 (56) = happyShift action_97
action_101 (57) = happyShift action_98
action_101 (59) = happyShift action_99
action_101 _ = happyFail (happyExpListPerState 101)

action_102 _ = happyReduce_29

action_103 (47) = happyShift action_116
action_103 _ = happyFail (happyExpListPerState 103)

action_104 _ = happyReduce_69

action_105 (50) = happyShift action_91
action_105 (52) = happyShift action_93
action_105 (53) = happyShift action_94
action_105 _ = happyReduce_70

action_106 (44) = happyShift action_115
action_106 (49) = happyShift action_90
action_106 (50) = happyShift action_91
action_106 (51) = happyShift action_92
action_106 (52) = happyShift action_93
action_106 (53) = happyShift action_94
action_106 (54) = happyShift action_95
action_106 (55) = happyShift action_96
action_106 (56) = happyShift action_97
action_106 (57) = happyShift action_98
action_106 (59) = happyShift action_99
action_106 _ = happyFail (happyExpListPerState 106)

action_107 (27) = happyShift action_57
action_107 (29) = happyShift action_58
action_107 (30) = happyShift action_59
action_107 (31) = happyShift action_60
action_107 (43) = happyShift action_61
action_107 (51) = happyShift action_62
action_107 (58) = happyShift action_63
action_107 (64) = happyShift action_64
action_107 (65) = happyShift action_65
action_107 (66) = happyShift action_66
action_107 (68) = happyShift action_67
action_107 (20) = happyGoto action_114
action_107 (24) = happyGoto action_55
action_107 (26) = happyGoto action_85
action_107 _ = happyReduce_45

action_108 (38) = happyShift action_113
action_108 _ = happyFail (happyExpListPerState 108)

action_109 (27) = happyShift action_57
action_109 (29) = happyShift action_58
action_109 (30) = happyShift action_59
action_109 (31) = happyShift action_60
action_109 (43) = happyShift action_61
action_109 (51) = happyShift action_62
action_109 (58) = happyShift action_63
action_109 (64) = happyShift action_64
action_109 (65) = happyShift action_65
action_109 (66) = happyShift action_66
action_109 (68) = happyShift action_67
action_109 (24) = happyGoto action_55
action_109 (26) = happyGoto action_112
action_109 _ = happyFail (happyExpListPerState 109)

action_110 (28) = happyShift action_26
action_110 (60) = happyShift action_27
action_110 (61) = happyShift action_28
action_110 (62) = happyShift action_29
action_110 (63) = happyShift action_30
action_110 (14) = happyGoto action_111
action_110 (15) = happyGoto action_54
action_110 (16) = happyGoto action_25
action_110 _ = happyFail (happyExpListPerState 110)

action_111 _ = happyReduce_18

action_112 (42) = happyShift action_109
action_112 (49) = happyShift action_90
action_112 (50) = happyShift action_91
action_112 (51) = happyShift action_92
action_112 (52) = happyShift action_93
action_112 (53) = happyShift action_94
action_112 (54) = happyShift action_95
action_112 (55) = happyShift action_96
action_112 (56) = happyShift action_97
action_112 (57) = happyShift action_98
action_112 (59) = happyShift action_99
action_112 (19) = happyGoto action_145
action_112 _ = happyReduce_42

action_113 _ = happyReduce_36

action_114 (44) = happyShift action_144
action_114 _ = happyFail (happyExpListPerState 114)

action_115 _ = happyReduce_77

action_116 (27) = happyShift action_57
action_116 (29) = happyShift action_58
action_116 (30) = happyShift action_59
action_116 (31) = happyShift action_60
action_116 (43) = happyShift action_61
action_116 (51) = happyShift action_62
action_116 (58) = happyShift action_63
action_116 (64) = happyShift action_64
action_116 (65) = happyShift action_65
action_116 (66) = happyShift action_66
action_116 (68) = happyShift action_67
action_116 (21) = happyGoto action_143
action_116 (24) = happyGoto action_55
action_116 (26) = happyGoto action_139
action_116 _ = happyFail (happyExpListPerState 116)

action_117 (27) = happyShift action_43
action_117 (33) = happyShift action_44
action_117 (34) = happyShift action_45
action_117 (35) = happyShift action_46
action_117 (37) = happyShift action_47
action_117 (45) = happyShift action_48
action_117 (69) = happyShift action_49
action_117 (8) = happyGoto action_39
action_117 (18) = happyGoto action_142
action_117 (24) = happyGoto action_42
action_117 _ = happyFail (happyExpListPerState 117)

action_118 (27) = happyShift action_43
action_118 (33) = happyShift action_44
action_118 (34) = happyShift action_45
action_118 (35) = happyShift action_46
action_118 (37) = happyShift action_47
action_118 (45) = happyShift action_48
action_118 (69) = happyShift action_49
action_118 (8) = happyGoto action_39
action_118 (18) = happyGoto action_141
action_118 (24) = happyGoto action_42
action_118 _ = happyFail (happyExpListPerState 118)

action_119 (49) = happyShift action_90
action_119 (50) = happyShift action_91
action_119 (51) = happyShift action_92
action_119 (52) = happyShift action_93
action_119 (53) = happyShift action_94
action_119 (54) = happyShift action_95
action_119 (55) = happyShift action_96
action_119 (56) = happyShift action_97
action_119 (57) = happyShift action_98
action_119 _ = happyReduce_59

action_120 (49) = happyShift action_90
action_120 (50) = happyShift action_91
action_120 (51) = happyShift action_92
action_120 (52) = happyShift action_93
action_120 (53) = happyShift action_94
action_120 (56) = happyFail []
action_120 (57) = happyFail []
action_120 _ = happyReduce_63

action_121 (49) = happyShift action_90
action_121 (50) = happyShift action_91
action_121 (51) = happyShift action_92
action_121 (52) = happyShift action_93
action_121 (53) = happyShift action_94
action_121 (56) = happyFail []
action_121 (57) = happyFail []
action_121 _ = happyReduce_62

action_122 (49) = happyShift action_90
action_122 (50) = happyShift action_91
action_122 (51) = happyShift action_92
action_122 (52) = happyShift action_93
action_122 (53) = happyShift action_94
action_122 (56) = happyShift action_97
action_122 (57) = happyShift action_98
action_122 _ = happyReduce_61

action_123 (49) = happyShift action_90
action_123 (50) = happyShift action_91
action_123 (51) = happyShift action_92
action_123 (52) = happyShift action_93
action_123 (53) = happyShift action_94
action_123 (56) = happyShift action_97
action_123 (57) = happyShift action_98
action_123 _ = happyReduce_60

action_124 _ = happyReduce_68

action_125 _ = happyReduce_67

action_126 (50) = happyShift action_91
action_126 (52) = happyShift action_93
action_126 (53) = happyShift action_94
action_126 _ = happyReduce_65

action_127 _ = happyReduce_66

action_128 (50) = happyShift action_91
action_128 (52) = happyShift action_93
action_128 (53) = happyShift action_94
action_128 _ = happyReduce_64

action_129 (27) = happyShift action_57
action_129 (29) = happyShift action_58
action_129 (30) = happyShift action_59
action_129 (31) = happyShift action_60
action_129 (43) = happyShift action_61
action_129 (51) = happyShift action_62
action_129 (58) = happyShift action_63
action_129 (64) = happyShift action_64
action_129 (65) = happyShift action_65
action_129 (66) = happyShift action_66
action_129 (68) = happyShift action_67
action_129 (24) = happyGoto action_55
action_129 (26) = happyGoto action_140
action_129 _ = happyFail (happyExpListPerState 129)

action_130 _ = happyReduce_58

action_131 (27) = happyShift action_57
action_131 (29) = happyShift action_58
action_131 (30) = happyShift action_59
action_131 (31) = happyShift action_60
action_131 (43) = happyShift action_61
action_131 (51) = happyShift action_62
action_131 (58) = happyShift action_63
action_131 (64) = happyShift action_64
action_131 (65) = happyShift action_65
action_131 (66) = happyShift action_66
action_131 (68) = happyShift action_67
action_131 (21) = happyGoto action_138
action_131 (24) = happyGoto action_55
action_131 (26) = happyGoto action_139
action_131 _ = happyFail (happyExpListPerState 131)

action_132 (38) = happyShift action_136
action_132 (56) = happyShift action_137
action_132 _ = happyFail (happyExpListPerState 132)

action_133 (41) = happyShift action_76
action_133 (47) = happyShift action_78
action_133 (25) = happyGoto action_135
action_133 _ = happyReduce_55

action_134 _ = happyReduce_30

action_135 _ = happyReduce_57

action_136 _ = happyReduce_38

action_137 (27) = happyShift action_73
action_137 (22) = happyGoto action_151
action_137 (24) = happyGoto action_152
action_137 _ = happyReduce_50

action_138 _ = happyReduce_43

action_139 (42) = happyShift action_150
action_139 (49) = happyShift action_90
action_139 (50) = happyShift action_91
action_139 (51) = happyShift action_92
action_139 (52) = happyShift action_93
action_139 (53) = happyShift action_94
action_139 (54) = happyShift action_95
action_139 (55) = happyShift action_96
action_139 (56) = happyShift action_97
action_139 (57) = happyShift action_98
action_139 (59) = happyShift action_99
action_139 _ = happyReduce_47

action_140 (38) = happyShift action_149
action_140 (49) = happyShift action_90
action_140 (50) = happyShift action_91
action_140 (51) = happyShift action_92
action_140 (52) = happyShift action_93
action_140 (53) = happyShift action_94
action_140 (54) = happyShift action_95
action_140 (55) = happyShift action_96
action_140 (56) = happyShift action_97
action_140 (57) = happyShift action_98
action_140 (59) = happyShift action_99
action_140 _ = happyFail (happyExpListPerState 140)

action_141 (27) = happyReduce_31
action_141 (33) = happyReduce_31
action_141 (34) = happyReduce_31
action_141 (35) = happyReduce_31
action_141 (36) = happyShift action_148
action_141 (37) = happyReduce_31
action_141 (45) = happyReduce_31
action_141 (46) = happyReduce_31
action_141 (69) = happyReduce_31
action_141 _ = happyReduce_31

action_142 _ = happyReduce_35

action_143 (48) = happyShift action_147
action_143 _ = happyFail (happyExpListPerState 143)

action_144 (47) = happyShift action_146
action_144 _ = happyFail (happyExpListPerState 144)

action_145 _ = happyReduce_41

action_146 (27) = happyShift action_57
action_146 (29) = happyShift action_58
action_146 (30) = happyShift action_59
action_146 (31) = happyShift action_60
action_146 (43) = happyShift action_61
action_146 (51) = happyShift action_62
action_146 (58) = happyShift action_63
action_146 (64) = happyShift action_64
action_146 (65) = happyShift action_65
action_146 (66) = happyShift action_66
action_146 (68) = happyShift action_67
action_146 (24) = happyGoto action_55
action_146 (26) = happyGoto action_157
action_146 _ = happyFail (happyExpListPerState 146)

action_147 _ = happyReduce_80

action_148 (27) = happyShift action_43
action_148 (33) = happyShift action_44
action_148 (34) = happyShift action_45
action_148 (35) = happyShift action_46
action_148 (37) = happyShift action_47
action_148 (45) = happyShift action_48
action_148 (69) = happyShift action_49
action_148 (8) = happyGoto action_39
action_148 (18) = happyGoto action_156
action_148 (24) = happyGoto action_42
action_148 _ = happyFail (happyExpListPerState 148)

action_149 _ = happyReduce_40

action_150 (27) = happyShift action_57
action_150 (29) = happyShift action_58
action_150 (30) = happyShift action_59
action_150 (31) = happyShift action_60
action_150 (43) = happyShift action_61
action_150 (51) = happyShift action_62
action_150 (58) = happyShift action_63
action_150 (64) = happyShift action_64
action_150 (65) = happyShift action_65
action_150 (66) = happyShift action_66
action_150 (68) = happyShift action_67
action_150 (21) = happyGoto action_155
action_150 (24) = happyGoto action_55
action_150 (26) = happyGoto action_139
action_150 _ = happyFail (happyExpListPerState 150)

action_151 (57) = happyShift action_154
action_151 _ = happyFail (happyExpListPerState 151)

action_152 (42) = happyShift action_153
action_152 _ = happyReduce_49

action_153 (27) = happyShift action_73
action_153 (23) = happyGoto action_160
action_153 (24) = happyGoto action_161
action_153 _ = happyFail (happyExpListPerState 153)

action_154 (38) = happyShift action_159
action_154 _ = happyFail (happyExpListPerState 154)

action_155 _ = happyReduce_46

action_156 _ = happyReduce_32

action_157 (48) = happyShift action_158
action_157 (49) = happyShift action_90
action_157 (50) = happyShift action_91
action_157 (51) = happyShift action_92
action_157 (52) = happyShift action_93
action_157 (53) = happyShift action_94
action_157 (54) = happyShift action_95
action_157 (55) = happyShift action_96
action_157 (56) = happyShift action_97
action_157 (57) = happyShift action_98
action_157 (59) = happyShift action_99
action_157 _ = happyFail (happyExpListPerState 157)

action_158 _ = happyReduce_78

action_159 _ = happyReduce_37

action_160 _ = happyReduce_48

action_161 (42) = happyShift action_162
action_161 _ = happyReduce_52

action_162 (27) = happyShift action_73
action_162 (23) = happyGoto action_163
action_162 (24) = happyGoto action_161
action_162 _ = happyFail (happyExpListPerState 162)

action_163 _ = happyReduce_51

happyReduce_1 = happySpecReduce_1  4 happyReduction_1
happyReduction_1 (HappyAbsSyn5  happy_var_1)
	 =  HappyAbsSyn4
		 (Prog happy_var_1
	)
happyReduction_1 _  = notHappyAtAll 

happyReduce_2 = happySpecReduce_2  5 happyReduction_2
happyReduction_2 (HappyAbsSyn5  happy_var_2)
	(HappyAbsSyn6  happy_var_1)
	 =  HappyAbsSyn5
		 (happy_var_1 : happy_var_2
	)
happyReduction_2 _ _  = notHappyAtAll 

happyReduce_3 = happySpecReduce_0  5 happyReduction_3
happyReduction_3  =  HappyAbsSyn5
		 ([]
	)

happyReduce_4 = happyReduce 5 6 happyReduction_4
happyReduction_4 (_ `HappyStk`
	(HappyAbsSyn7  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TTypeName happy_var_2))) `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn6
		 (DataDef (Data happy_var_2 happy_var_4)
	) `HappyStk` happyRest

happyReduce_5 = happyReduce 8 6 happyReduction_5
happyReduction_5 (_ `HappyStk`
	(HappyAbsSyn17  happy_var_7) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn12  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn9  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn6
		 (Func happy_var_1 (Just happy_var_3) happy_var_5 happy_var_7
	) `HappyStk` happyRest

happyReduce_6 = happySpecReduce_2  7 happyReduction_6
happyReduction_6 (HappyAbsSyn7  happy_var_2)
	(HappyAbsSyn8  happy_var_1)
	 =  HappyAbsSyn7
		 (happy_var_1 : happy_var_2
	)
happyReduction_6 _ _  = notHappyAtAll 

happyReduce_7 = happySpecReduce_0  7 happyReduction_7
happyReduction_7  =  HappyAbsSyn7
		 ([]
	)

happyReduce_8 = happyReduce 4 8 happyReduction_8
happyReduction_8 (_ `HappyStk`
	(HappyAbsSyn15  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn8
		 (Decl happy_var_1 happy_var_3
	) `HappyStk` happyRest

happyReduce_9 = happySpecReduce_1  9 happyReduction_9
happyReduction_9 (HappyAbsSyn10  happy_var_1)
	 =  HappyAbsSyn9
		 (happy_var_1
	)
happyReduction_9 _  = notHappyAtAll 

happyReduce_10 = happySpecReduce_0  9 happyReduction_10
happyReduction_10  =  HappyAbsSyn9
		 ([]
	)

happyReduce_11 = happySpecReduce_3  10 happyReduction_11
happyReduction_11 (HappyAbsSyn10  happy_var_3)
	_
	(HappyAbsSyn11  happy_var_1)
	 =  HappyAbsSyn10
		 (happy_var_1 : happy_var_3
	)
happyReduction_11 _ _ _  = notHappyAtAll 

happyReduce_12 = happySpecReduce_1  10 happyReduction_12
happyReduction_12 (HappyAbsSyn11  happy_var_1)
	 =  HappyAbsSyn10
		 ([happy_var_1]
	)
happyReduction_12 _  = notHappyAtAll 

happyReduce_13 = happySpecReduce_3  11 happyReduction_13
happyReduction_13 (HappyAbsSyn15  happy_var_3)
	_
	(HappyTerminal (Token _ (TIdent happy_var_1)))
	 =  HappyAbsSyn11
		 (Param happy_var_1 happy_var_3
	)
happyReduction_13 _ _ _  = notHappyAtAll 

happyReduce_14 = happySpecReduce_2  12 happyReduction_14
happyReduction_14 (HappyAbsSyn13  happy_var_2)
	_
	 =  HappyAbsSyn12
		 (Just happy_var_2
	)
happyReduction_14 _ _  = notHappyAtAll 

happyReduce_15 = happySpecReduce_0  12 happyReduction_15
happyReduction_15  =  HappyAbsSyn12
		 (Nothing
	)

happyReduce_16 = happySpecReduce_3  13 happyReduction_16
happyReduction_16 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn15  happy_var_1)
	 =  HappyAbsSyn13
		 (Types happy_var_1 happy_var_3
	)
happyReduction_16 _ _ _  = notHappyAtAll 

happyReduce_17 = happySpecReduce_1  13 happyReduction_17
happyReduction_17 (HappyAbsSyn15  happy_var_1)
	 =  HappyAbsSyn13
		 (Types happy_var_1 []
	)
happyReduction_17 _  = notHappyAtAll 

happyReduce_18 = happySpecReduce_3  14 happyReduction_18
happyReduction_18 (HappyAbsSyn14  happy_var_3)
	_
	(HappyAbsSyn15  happy_var_1)
	 =  HappyAbsSyn14
		 (happy_var_1 : happy_var_3
	)
happyReduction_18 _ _ _  = notHappyAtAll 

happyReduce_19 = happySpecReduce_1  14 happyReduction_19
happyReduction_19 (HappyAbsSyn15  happy_var_1)
	 =  HappyAbsSyn14
		 ([happy_var_1]
	)
happyReduction_19 _  = notHappyAtAll 

happyReduce_20 = happySpecReduce_3  15 happyReduction_20
happyReduction_20 _
	_
	(HappyAbsSyn16  happy_var_1)
	 =  HappyAbsSyn15
		 (TypeArray (BType happy_var_1)
	)
happyReduction_20 _ _ _  = notHappyAtAll 

happyReduce_21 = happySpecReduce_1  15 happyReduction_21
happyReduction_21 (HappyAbsSyn16  happy_var_1)
	 =  HappyAbsSyn15
		 (BType happy_var_1
	)
happyReduction_21 _  = notHappyAtAll 

happyReduce_22 = happySpecReduce_1  16 happyReduction_22
happyReduction_22 _
	 =  HappyAbsSyn16
		 (TInt
	)

happyReduce_23 = happySpecReduce_1  16 happyReduction_23
happyReduction_23 _
	 =  HappyAbsSyn16
		 (TBool
	)

happyReduce_24 = happySpecReduce_1  16 happyReduction_24
happyReduction_24 _
	 =  HappyAbsSyn16
		 (TChar
	)

happyReduce_25 = happySpecReduce_1  16 happyReduction_25
happyReduction_25 _
	 =  HappyAbsSyn16
		 (TFloat
	)

happyReduce_26 = happySpecReduce_1  16 happyReduction_26
happyReduction_26 (HappyTerminal (Token _ (TTypeName happy_var_1)))
	 =  HappyAbsSyn16
		 (TID happy_var_1
	)
happyReduction_26 _  = notHappyAtAll 

happyReduce_27 = happySpecReduce_2  17 happyReduction_27
happyReduction_27 (HappyAbsSyn17  happy_var_2)
	(HappyAbsSyn18  happy_var_1)
	 =  HappyAbsSyn17
		 (happy_var_1 : happy_var_2
	)
happyReduction_27 _ _  = notHappyAtAll 

happyReduce_28 = happySpecReduce_0  17 happyReduction_28
happyReduction_28  =  HappyAbsSyn17
		 ([]
	)

happyReduce_29 = happySpecReduce_3  18 happyReduction_29
happyReduction_29 _
	(HappyAbsSyn17  happy_var_2)
	_
	 =  HappyAbsSyn18
		 (CmdBlock happy_var_2
	)
happyReduction_29 _ _ _  = notHappyAtAll 

happyReduce_30 = happyReduce 4 18 happyReduction_30
happyReduction_30 (_ `HappyStk`
	(HappyAbsSyn26  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn24  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdAssign happy_var_1 happy_var_3
	) `HappyStk` happyRest

happyReduce_31 = happyReduce 5 18 happyReduction_31
happyReduction_31 ((HappyAbsSyn18  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn26  happy_var_3) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdIf happy_var_3 happy_var_5
	) `HappyStk` happyRest

happyReduce_32 = happyReduce 7 18 happyReduction_32
happyReduction_32 ((HappyAbsSyn18  happy_var_7) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn18  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn26  happy_var_3) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdIfElse happy_var_3 (Just happy_var_5) (Just happy_var_7)
	) `HappyStk` happyRest

happyReduce_33 = happySpecReduce_3  18 happyReduction_33
happyReduction_33 _
	(HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn18
		 (CmdPrint happy_var_2
	)
happyReduction_33 _ _ _  = notHappyAtAll 

happyReduce_34 = happySpecReduce_3  18 happyReduction_34
happyReduction_34 _
	(HappyAbsSyn24  happy_var_2)
	_
	 =  HappyAbsSyn18
		 (CmdRead happy_var_2
	)
happyReduction_34 _ _ _  = notHappyAtAll 

happyReduce_35 = happyReduce 5 18 happyReduction_35
happyReduction_35 ((HappyAbsSyn18  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn26  happy_var_3) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdIterate happy_var_3 happy_var_5
	) `HappyStk` happyRest

happyReduce_36 = happyReduce 4 18 happyReduction_36
happyReduction_36 (_ `HappyStk`
	(HappyAbsSyn19  happy_var_3) `HappyStk`
	(HappyAbsSyn26  happy_var_2) `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdReturn happy_var_2 happy_var_3
	) `HappyStk` happyRest

happyReduce_37 = happyReduce 8 18 happyReduction_37
happyReduction_37 (_ `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn22  happy_var_6) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn20  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdFuncCall happy_var_1 happy_var_3 happy_var_6
	) `HappyStk` happyRest

happyReduce_38 = happyReduce 5 18 happyReduction_38
happyReduction_38 (_ `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn20  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdFuncCall happy_var_1 happy_var_3 Nothing
	) `HappyStk` happyRest

happyReduce_39 = happySpecReduce_1  18 happyReduction_39
happyReduction_39 (HappyAbsSyn8  happy_var_1)
	 =  HappyAbsSyn18
		 (CmdDecl happy_var_1 Nothing
	)
happyReduction_39 _  = notHappyAtAll 

happyReduce_40 = happyReduce 6 18 happyReduction_40
happyReduction_40 (_ `HappyStk`
	(HappyAbsSyn26  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn15  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn18
		 (CmdDecl (Decl happy_var_1 happy_var_3) (Just happy_var_5)
	) `HappyStk` happyRest

happyReduce_41 = happySpecReduce_3  19 happyReduction_41
happyReduction_41 (HappyAbsSyn19  happy_var_3)
	(HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn19
		 (happy_var_2 : happy_var_3
	)
happyReduction_41 _ _ _  = notHappyAtAll 

happyReduce_42 = happySpecReduce_0  19 happyReduction_42
happyReduction_42  =  HappyAbsSyn19
		 ([]
	)

happyReduce_43 = happySpecReduce_3  20 happyReduction_43
happyReduction_43 (HappyAbsSyn21  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn20
		 (Just (Exps happy_var_1 happy_var_3)
	)
happyReduction_43 _ _ _  = notHappyAtAll 

happyReduce_44 = happySpecReduce_1  20 happyReduction_44
happyReduction_44 (HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn20
		 (Just (Exps happy_var_1 [])
	)
happyReduction_44 _  = notHappyAtAll 

happyReduce_45 = happySpecReduce_0  20 happyReduction_45
happyReduction_45  =  HappyAbsSyn20
		 (Nothing
	)

happyReduce_46 = happySpecReduce_3  21 happyReduction_46
happyReduction_46 (HappyAbsSyn21  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn21
		 (happy_var_1 : happy_var_3
	)
happyReduction_46 _ _ _  = notHappyAtAll 

happyReduce_47 = happySpecReduce_1  21 happyReduction_47
happyReduction_47 (HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn21
		 ([happy_var_1]
	)
happyReduction_47 _  = notHappyAtAll 

happyReduce_48 = happySpecReduce_3  22 happyReduction_48
happyReduction_48 (HappyAbsSyn23  happy_var_3)
	_
	(HappyAbsSyn24  happy_var_1)
	 =  HappyAbsSyn22
		 (Just (LValues happy_var_1 happy_var_3)
	)
happyReduction_48 _ _ _  = notHappyAtAll 

happyReduce_49 = happySpecReduce_1  22 happyReduction_49
happyReduction_49 (HappyAbsSyn24  happy_var_1)
	 =  HappyAbsSyn22
		 (Just (LValues happy_var_1 [])
	)
happyReduction_49 _  = notHappyAtAll 

happyReduce_50 = happySpecReduce_0  22 happyReduction_50
happyReduction_50  =  HappyAbsSyn22
		 (Nothing
	)

happyReduce_51 = happySpecReduce_3  23 happyReduction_51
happyReduction_51 (HappyAbsSyn23  happy_var_3)
	_
	(HappyAbsSyn24  happy_var_1)
	 =  HappyAbsSyn23
		 (happy_var_1 : happy_var_3
	)
happyReduction_51 _ _ _  = notHappyAtAll 

happyReduce_52 = happySpecReduce_1  23 happyReduction_52
happyReduction_52 (HappyAbsSyn24  happy_var_1)
	 =  HappyAbsSyn23
		 ([happy_var_1]
	)
happyReduction_52 _  = notHappyAtAll 

happyReduce_53 = happySpecReduce_1  24 happyReduction_53
happyReduction_53 (HappyTerminal (Token _ (TIdent happy_var_1)))
	 =  HappyAbsSyn24
		 (LID happy_var_1
	)
happyReduction_53 _  = notHappyAtAll 

happyReduce_54 = happySpecReduce_2  24 happyReduction_54
happyReduction_54 (HappyAbsSyn25  happy_var_2)
	(HappyTerminal (Token _ (TIdent happy_var_1)))
	 =  HappyAbsSyn24
		 (LID' happy_var_1 happy_var_2
	)
happyReduction_54 _ _  = notHappyAtAll 

happyReduce_55 = happySpecReduce_3  25 happyReduction_55
happyReduction_55 _
	(HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn25
		 (LArray happy_var_2
	)
happyReduction_55 _ _ _  = notHappyAtAll 

happyReduce_56 = happySpecReduce_2  25 happyReduction_56
happyReduction_56 (HappyTerminal (Token _ (TIdent happy_var_2)))
	_
	 =  HappyAbsSyn25
		 (LComp happy_var_2
	)
happyReduction_56 _ _  = notHappyAtAll 

happyReduce_57 = happyReduce 4 25 happyReduction_57
happyReduction_57 ((HappyAbsSyn25  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn26  happy_var_2) `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn25
		 (LArray' happy_var_2 happy_var_4
	) `HappyStk` happyRest

happyReduce_58 = happySpecReduce_3  25 happyReduction_58
happyReduction_58 (HappyAbsSyn25  happy_var_3)
	(HappyTerminal (Token _ (TIdent happy_var_2)))
	_
	 =  HappyAbsSyn25
		 (LComp' happy_var_2 happy_var_3
	)
happyReduction_58 _ _ _  = notHappyAtAll 

happyReduce_59 = happySpecReduce_3  26 happyReduction_59
happyReduction_59 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :&&: happy_var_3
	)
happyReduction_59 _ _ _  = notHappyAtAll 

happyReduce_60 = happySpecReduce_3  26 happyReduction_60
happyReduction_60 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :==: happy_var_3
	)
happyReduction_60 _ _ _  = notHappyAtAll 

happyReduce_61 = happySpecReduce_3  26 happyReduction_61
happyReduction_61 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :!=: happy_var_3
	)
happyReduction_61 _ _ _  = notHappyAtAll 

happyReduce_62 = happySpecReduce_3  26 happyReduction_62
happyReduction_62 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :<: happy_var_3
	)
happyReduction_62 _ _ _  = notHappyAtAll 

happyReduce_63 = happySpecReduce_3  26 happyReduction_63
happyReduction_63 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :>: happy_var_3
	)
happyReduction_63 _ _ _  = notHappyAtAll 

happyReduce_64 = happySpecReduce_3  26 happyReduction_64
happyReduction_64 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :+: happy_var_3
	)
happyReduction_64 _ _ _  = notHappyAtAll 

happyReduce_65 = happySpecReduce_3  26 happyReduction_65
happyReduction_65 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :-: happy_var_3
	)
happyReduction_65 _ _ _  = notHappyAtAll 

happyReduce_66 = happySpecReduce_3  26 happyReduction_66
happyReduction_66 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :*: happy_var_3
	)
happyReduction_66 _ _ _  = notHappyAtAll 

happyReduce_67 = happySpecReduce_3  26 happyReduction_67
happyReduction_67 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :/: happy_var_3
	)
happyReduction_67 _ _ _  = notHappyAtAll 

happyReduce_68 = happySpecReduce_3  26 happyReduction_68
happyReduction_68 (HappyAbsSyn26  happy_var_3)
	_
	(HappyAbsSyn26  happy_var_1)
	 =  HappyAbsSyn26
		 (happy_var_1 :%: happy_var_3
	)
happyReduction_68 _ _ _  = notHappyAtAll 

happyReduce_69 = happySpecReduce_2  26 happyReduction_69
happyReduction_69 (HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn26
		 (ENot happy_var_2
	)
happyReduction_69 _ _  = notHappyAtAll 

happyReduce_70 = happySpecReduce_2  26 happyReduction_70
happyReduction_70 (HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn26
		 (ENeg happy_var_2
	)
happyReduction_70 _ _  = notHappyAtAll 

happyReduce_71 = happySpecReduce_1  26 happyReduction_71
happyReduction_71 _
	 =  HappyAbsSyn26
		 (EBool True
	)

happyReduce_72 = happySpecReduce_1  26 happyReduction_72
happyReduction_72 _
	 =  HappyAbsSyn26
		 (EBool False
	)

happyReduce_73 = happySpecReduce_1  26 happyReduction_73
happyReduction_73 _
	 =  HappyAbsSyn26
		 (ENull
	)

happyReduce_74 = happySpecReduce_1  26 happyReduction_74
happyReduction_74 (HappyTerminal (Token _ (TIntNumber happy_var_1)))
	 =  HappyAbsSyn26
		 (EInt happy_var_1
	)
happyReduction_74 _  = notHappyAtAll 

happyReduce_75 = happySpecReduce_1  26 happyReduction_75
happyReduction_75 (HappyTerminal (Token _ (TFloatNumber happy_var_1)))
	 =  HappyAbsSyn26
		 (EFloat happy_var_1
	)
happyReduction_75 _  = notHappyAtAll 

happyReduce_76 = happySpecReduce_1  26 happyReduction_76
happyReduction_76 (HappyTerminal (Token _ (TCharacter happy_var_1)))
	 =  HappyAbsSyn26
		 (EChar happy_var_1
	)
happyReduction_76 _  = notHappyAtAll 

happyReduce_77 = happySpecReduce_3  26 happyReduction_77
happyReduction_77 _
	(HappyAbsSyn26  happy_var_2)
	_
	 =  HappyAbsSyn26
		 (EParen happy_var_2
	)
happyReduction_77 _ _ _  = notHappyAtAll 

happyReduce_78 = happyReduce 7 26 happyReduction_78
happyReduction_78 (_ `HappyStk`
	(HappyAbsSyn26  happy_var_6) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn20  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyTerminal (Token _ (TIdent happy_var_1))) `HappyStk`
	happyRest)
	 = HappyAbsSyn26
		 (EFuncCall happy_var_1 happy_var_3 happy_var_6
	) `HappyStk` happyRest

happyReduce_79 = happySpecReduce_1  26 happyReduction_79
happyReduction_79 (HappyAbsSyn24  happy_var_1)
	 =  HappyAbsSyn26
		 (ELValue happy_var_1
	)
happyReduction_79 _  = notHappyAtAll 

happyReduce_80 = happyReduce 5 26 happyReduction_80
happyReduction_80 (_ `HappyStk`
	(HappyAbsSyn21  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn16  happy_var_2) `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn26
		 (ENew (BType happy_var_2) happy_var_4
	) `HappyStk` happyRest

happyNewToken action sts stk
	= lexer(\tk -> 
	let cont i = action i i tk (HappyState action) sts stk in
	case tk of {
	Token _ TEOF -> action 70 70 tk (HappyState action) sts stk;
	Token _ (TIdent happy_dollar_dollar) -> cont 27;
	Token _ (TTypeName happy_dollar_dollar) -> cont 28;
	Token _ (TIntNumber happy_dollar_dollar) -> cont 29;
	Token _ (TFloatNumber happy_dollar_dollar) -> cont 30;
	Token _ (TCharacter happy_dollar_dollar) -> cont 31;
	Token _ TAssign -> cont 32;
	Token _ TRead -> cont 33;
	Token _ TPrint -> cont 34;
	Token _ TIf -> cont 35;
	Token _ TElse -> cont 36;
	Token _ TIterate -> cont 37;
	Token _ TSemi -> cont 38;
	Token _ TColon -> cont 39;
	Token _ TDoubleColon -> cont 40;
	Token _ TDot -> cont 41;
	Token _ TComma -> cont 42;
	Token _ TLParen -> cont 43;
	Token _ TRParen -> cont 44;
	Token _ TLBrace -> cont 45;
	Token _ TRBrace -> cont 46;
	Token _ TLBracket -> cont 47;
	Token _ TRBracket -> cont 48;
	Token _ TPlus -> cont 49;
	Token _ TTimes -> cont 50;
	Token _ TMinus -> cont 51;
	Token _ TDiv -> cont 52;
	Token _ TMod -> cont 53;
	Token _ TEq -> cont 54;
	Token _ TNeq -> cont 55;
	Token _ TLt -> cont 56;
	Token _ TGt -> cont 57;
	Token _ TNot -> cont 58;
	Token _ TAnd -> cont 59;
	Token _ TTInt -> cont 60;
	Token _ TTFloat -> cont 61;
	Token _ TTChar -> cont 62;
	Token _ TTBool -> cont 63;
	Token _ TTrue -> cont 64;
	Token _ TFalse -> cont 65;
	Token _ TNull -> cont 66;
	Token _ TData -> cont 67;
	Token _ TNew -> cont 68;
	Token _ TReturn -> cont 69;
	_ -> happyError' (tk, [])
	})

happyError_ explist 70 tk = happyError' (tk, explist)
happyError_ explist _ tk = happyError' (tk, explist)

happyThen :: () => Alex a -> (a -> Alex b) -> Alex b
happyThen = ((>>=))
happyReturn :: () => a -> Alex a
happyReturn = (return)
happyThen1 :: () => Alex a -> (a -> Alex b) -> Alex b
happyThen1 = happyThen
happyReturn1 :: () => a -> Alex a
happyReturn1 = happyReturn
happyError' :: () => ((Token), [Prelude.String]) -> Alex a
happyError' tk = (\(tokens, _) -> parseError tokens) tk
parser = happySomeParser where
 happySomeParser = happyThen (happyParse action_0) (\x -> case x of {HappyAbsSyn4 z -> happyReturn z; _other -> notHappyAtAll })

happySeq = happyDontSeq


parseError (Token (line, col) lexeme)
  = alexError $ "Parse error while processing lexeme: " ++ show lexeme
                ++ "\n at line " ++ show line ++ ", column " ++ show col

lexer :: (Token -> Alex a) -> Alex a
lexer = (=<< alexMonadScan)

langParser :: String -> Either String Prog
langParser content = runAlex content parser
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
