* The grammar for input is:
```Text
    Calculation:
        Statement
        Print
        Help
        Quit
        Calculation Statement

    Statemant:
        Declaration
        Expression

    Print:
        ;

    Quit:
        q

    Declaration:
        "let" Name "=" Expression

    Expression:
        Term
        Expression + Term
        Expression - Term

    Term:
        Secondary
        Term * Secondary
        Term / Secondary
        Term % Secondary

    Secondary:
        Primary "!" 
        "Sqrt (" Expression ")"
        "Pow (" Expression "," Expression ")"

    Primary:
        Number
        ( Expression )
        { Expression }
        - Primary
        + Primary
        Variable
        "sqrt"( Expression )
        "pow(" Expression "," narrow_cast<int>(Expression) ")"
        "sin"( Expression )
        "cos"( Expression )

    Number:
```
