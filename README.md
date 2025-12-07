### TODO
- Support loop operation (make sure to properly handle nested loop)
- Support variable declaration
- Support macro
- (Debugger) Set up ncurses

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