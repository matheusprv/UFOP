{
module Limp.Frontend.Parser.Parser (impParser) where

import Limp.Frontend.Lexer.Lexer
import Limp.Syntax.Syntax
}

%name parser
%tokentype { Token }
%error     {parseError}

%token
      id        {Token _ (TIdent $$)}
      num       {Token _ (TNumber $$)}
      comment   {Token _ (TComment $$)}
      ':='      {Token _ TAssign}
      'read'    {Token _ TRead}
      'print'   {Token _ TPrint}
      'if'      {Token _ TIf}
      'then'    {Token _ TThen}
      'else'    {Token _ TElse}
      'while'   {Token _ TWhile}
      ';'       {Token _ TSemi}
      '('       {Token _ TLParen}
      ')'       {Token _ TRParen}
      '{'       {Token _ TLBrace}
      '}'       {Token _ TRBrace}
      '+'       {Token _ TPlus}
      '*'       {Token _ TTimes}
      '-'       {Token _ TMinus}
      '/'       {Token _ TDiv}
      '=='      {Token _ TEq}
      '<'       {Token _ TLt}
      '!'       {Token _ TNot}
      '&&'      {Token _ TAnd}
      'int'     {Token _ TTInt}
      'bool'    {Token _ TTBool}
      'true'    {Token _ TTrue}
      'false'   {Token _ TFalse}
      'skip'    {Token _ TSkip}

%left '&&'
%nonassoc '=='
%nonassoc '<'
%left '+'
%left '-'
%left '*'
%left '/'
%left '!'

%%

Program : CommentBefore CodeBlock CommentAfter     { Program (Block (reverse $1 ++ unBlock $2 ++ reverse $3)) }

CommentBefore :                                    { [] }
            | CommentBefore comment                { Comment $2 : $1 }

CommentAfter :                                     { [] }
             | CommentAfter comment                { Comment $2 : $1 }

CodeBlock : '{' ItemList '}'                       { Block (reverse $2) }

ItemList : ItemList Item                           { $2 : $1 }
         |                                         { [] }

Item : Stmt                                        { ItemStmt $1 }
     | comment                                     { Comment $1 }

Stmt : 'skip' ';'                                  { Skip }
     | Id ':=' Exp ';'                             { $1 := $3 }
     | PTy Id Init ';'                             { Def $1 $2 $3 }
     | 'if' Exp 'then' CodeBlock 'else' CodeBlock  { If $2 $4 $6 }
     | 'print' Exp ';'                             { Print $2 }
     | 'read' Id ';'                               { SRead $2 }
     | 'while' Exp CodeBlock                       { While $2 $3 }

Id : id                                            { Var $1 }

PTy : 'int'                                        { TInt }
    | 'bool'                                       { TBool }

Init : ':=' Exp                                    { Just $2 }
     |                                             { Nothing }

Exp : num                                          { EValue (EInt $1) }
    | 'true'                                       { EValue (EBool True) }
    | 'false'                                      { EValue (EBool False) }
    | Id                                           { EVar $1 }
    | Exp '+' Exp                                  { $1 :+: $3 }
    | Exp '*' Exp                                  { $1 :*: $3 }
    | Exp '-' Exp                                  { $1 :-: $3 }
    | Exp '/' Exp                                  { $1 :/: $3 }
    | Exp '<' Exp                                  { $1 :<: $3 }
    | Exp '==' Exp                                 { $1 :==: $3 }
    | Exp '&&' Exp                                 { $1 :&: $3 }
    | '!' Exp                                      { ENot $2 }
    | '(' Exp ')'                                  { $2 }

{
parseError :: [Token] -> a
parseError [] = error "Parse error!"
parseError (t : _) = error $ "Parse error " ++ (show t)

impParser :: String -> Program
impParser = parser . lexer
}
