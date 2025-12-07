### Quickstart
Simply type `make` to build the executable `bof`.

### BNF
```
<expression>            ::= <basic_expression> 
                          | <loop> 
                          | <variable_declaration>
                          | <macro>

<variable_declaration>  ::= <variable> = <expression>;

<variable>              ::= <symbol>

<macro>                 ::= <symbol> $= <expression>;

<loop>                  ::= [<expression>]

<basic_expression>      ::= + | - | < | > | . | , | <variable>
```