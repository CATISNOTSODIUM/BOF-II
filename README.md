# 🧠 BOF - Brainf_ck with macros (C++)✨
While brainf_ck is notoriously known for its minimalistic and impractical, BOF makes programming language in brainf_ck slightly more forgiving with macros and variables.


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

### Todo
- (Debugger) Set up ncurses
