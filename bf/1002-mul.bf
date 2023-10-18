 ++++[>++++[>+++<-]<-]      # this writes 48 / 0x30 / '0' in cell(2)
    ,>,>                    # reads two nums in cell(0) and cell(1)
    [<-<->>-]               # decrements cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      # goes to cell(0)
    [                       # the mulitply loop
        >                   # goes to cell(1)
        [>+>+<<-]           # this moves cell(1) to cell(2) and cell(3)
        >>                  # goes to cell(3)
        [<<+>>-]            # moves cell(3) back to cell(1)
        <<<-                # decrements cell(0)
    ]
    >[-]<                   # sets cell(1) to 0 in order to be utilized as a counter (we're in cell 0)
    ++++[>++++[>+++<-]<-]   # adds 48 / 0x30 / '0' to cell(2) (wich has the result)
    >>.                     # it prints the result (go to cell(2) and print)
