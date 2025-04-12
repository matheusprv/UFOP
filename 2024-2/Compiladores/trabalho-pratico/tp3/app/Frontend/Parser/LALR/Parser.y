-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

{
module Frontend.Parser.LALR.Parser (langParser) where

import Syntax.Syntax
import Frontend.Lexer.Lexer hiding (lexer)

}

%name parser Prog
%monad {Alex}{(>>=)}{return}
%tokentype { Token }
%error     { parseError }
%lexer {lexer}{Token _ TEOF}

%token
      id            {Token _ (TIdent $$)}
      typeName      {Token _ (TTypeName $$)}
      intNumber     {Token _ (TIntNumber $$)}
      floatNumber   {Token _ (TFloatNumber $$)}
      character     {Token _ (TCharacter $$)}
      "="           {Token _ TAssign}
      "read"        {Token _ TRead}
      "print"       {Token _ TPrint}
      "if"          {Token _ TIf}
      "else"        {Token _ TElse}
      "iterate"     {Token _ TIterate}
      ";"           {Token _ TSemi}
      ":"           {Token _ TColon}
      "::"          {Token _ TDoubleColon}
      "."           {Token _ TDot}
      ","           {Token _ TComma}
      "("           {Token _ TLParen}
      ")"           {Token _ TRParen}
      "{"           {Token _ TLBrace}
      "}"           {Token _ TRBrace}
      "["           {Token _ TLBracket}
      "]"           {Token _ TRBracket}
      "+"           {Token _ TPlus}
      "*"           {Token _ TTimes}
      "-"           {Token _ TMinus}
      "/"           {Token _ TDiv}
      "%"           {Token _ TMod}
      "=="          {Token _ TEq}
      "!="          {Token _ TNeq}
      "<"           {Token _ TLt}
      ">"           {Token _ TGt}
      "!"           {Token _ TNot}
      "&&"          {Token _ TAnd}
      "Int"         {Token _ TTInt}
      "Float"       {Token _ TTFloat}
      "Char"        {Token _ TTChar}
      "Bool"        {Token _ TTBool}
      "true"        {Token _ TTrue}
      "false"       {Token _ TFalse}
      "null"        {Token _ TNull}
      "data"        {Token _ TData}
      "new"         {Token _ TNew}
      "return"      {Token _ TReturn}
      

%left "&&"
%left "==" "!="
%nonassoc "<" ">"
%left "+" "-"
%left "*" "/" "%"
%right "!"

%%

Prog : Defs { Prog $1 }

Defs : Def Defs { $1 : $2 }
     | { [] }

Def : "data" typeName "{" Decls "}" { DataDef (Data $2 $4) }
    | id "(" Params ")" ReturnType "{" Cmds "}" { Func $1 (Just $3) $5 $7 }

-- Data declarations
Decls : Decl Decls { $1 : $2 }
      | { [] }

Decl : id "::" Type ";" { Decl $1 $3 }

-- Function parameters
Params : ParamList { $1 }
       | { [] }

ParamList : Param "," ParamList { $1 : $3 }
          | Param { [$1] }

Param : id "::" Type { Param $1 $3 }

-- Function return Type(s) 
ReturnType : ":" Types { Just $2 }
           | { Nothing }

Types : Type "," TypeList { Types $1 $3 }
      | Type { Types $1 [] }

TypeList : Type "," TypeList { $1 : $3 }
      | Type { [$1] }

Type : BaseType "[" "]" { TypeArray (BType $1) }
    | BaseType { BType $1 }

BaseType : "Int" { TInt }
         | "Bool" { TBool }
         | "Char" { TChar }
         | "Float" { TFloat }
         | typeName { TID $1 }


Cmds : Cmd Cmds { $1 : $2 }
     | { [] }

Cmd : "{" Cmds "}" { CmdBlock $2 }
    | LValue "=" Exp ";" { CmdAssign $1 $3 }
    | "if" "(" Exp ")" Cmd %shift { CmdIf $3 $5 }
    | "if" "(" Exp ")" Cmd "else" Cmd { CmdIfElse $3 (Just $5) (Just $7) }
    | "print" Exp ";" { CmdPrint $2 }
    | "read" LValue ";" { CmdRead $2 }
    | "iterate" "(" Exp ")" Cmd { CmdIterate $3 $5 }
    | "return" Exp ReturnList ";" { CmdReturn $2 $3 }
    | id "(" Exps ")" "<" LValues ">" ";" { CmdFuncCall $1 $3 $6 }
    | id "(" Exps ")" ";" { CmdFuncCall $1 $3 Nothing }
    | Decl { CmdDecl $1 Nothing }
    | id "::" Type "=" Exp ";" { CmdDecl (Decl $1 $3) (Just $5) }


ReturnList : "," Exp ReturnList { $2 : $3 }
           | { [] }

Exps : Exp "," ExpList { Just (Exps $1 $3) }
     | Exp { Just (Exps $1 []) }
     | { Nothing }

ExpList : Exp "," ExpList { $1 : $3 }
        | Exp { [$1] }

LValues : LValue "," LValueList { Just (LValues $1 $3) }
        | LValue { Just (LValues $1 []) }
        | { Nothing }

LValueList : LValue "," LValueList { $1 : $3 }
           | LValue { [$1] }

LValue : id { LID $1 }
       | id LValueLinha { LID' $1 $2 }

LValueLinha : "[" Exp "]" { LArray $2 }
        | "." id { LComp $2 }
        | "[" Exp "]" LValueLinha { LArray' $2 $4 }
        | "." id LValueLinha { LComp' $2 $3 }

Exp : Exp "&&" Exp { $1 :&&: $3 }
      | Exp "==" Exp { $1 :==: $3 }
      | Exp "!=" Exp { $1 :!=: $3 }
      | Exp "<" Exp { $1 :<: $3 }
      | Exp ">" Exp { $1 :>: $3 }
      | Exp "+" Exp { $1 :+: $3 }
      | Exp "-" Exp { $1 :-: $3 }
      | Exp "*" Exp { $1 :*: $3 }
      | Exp "/" Exp { $1 :/: $3 }
      | Exp "%" Exp { $1 :%: $3 }
      | "!" Exp { ENot $2 }
      | "-" Exp { ENeg $2 }
      | "true" { EBool True }
      | "false" { EBool False }
      | "null" { ENull }
      | intNumber { EInt $1 }
      | floatNumber { EFloat $1 }
      | character { EChar $1 }
      | "(" Exp ")" { EParen $2 }
      | id "(" Exps ")" "[" Exp "]" { EFuncCall $1 $3 $6 }
      | LValue { ELValue $1 }
      | "new" BaseType "[" ExpList "]" { ENew (BType $2) $4 }


{
parseError (Token (line, col) lexeme)
  = alexError $ "Parse error while processing lexeme: " ++ show lexeme
                ++ "\n at line " ++ show line ++ ", column " ++ show col

lexer :: (Token -> Alex a) -> Alex a
lexer = (=<< alexMonadScan)

langParser :: String -> Either String Prog
langParser content = runAlex content parser 
}