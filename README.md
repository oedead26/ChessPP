ChessPP
=======
Created by: Aaron Oeder, Jacob Owens, and Trevor Berceau

Overview
--------
Chess++ is a recreation of the classic game of chess using the C++ programming language. This was done as a term-long project for CS 371 (Advanced Object-Oriented Design) at UW-Green Bay.

Features
--------
* Support for human vs. human matches in accordance with standard chess rules
* Ability to save games to and load games from a SQL database
* A complete graphical user interface, built using the Qt application framework

Usage
-----
Either download one of the precompiled binaries (for x86 or x64 Windows machines) or compile the source code using <code>qmake</code>. The program is <i>cross-platform</i>.

Program Operation
-----------------
Upon launch, the user can choose to either start a new chess game or resume a previous one.

![My image](/screenshots/TitleScreen.png)

If choosing to start a new game, the user is prompted to enter the names of the two human players.

![My image](/screenshots/NameEntryScreen.png)

If choosing to resume a previous game, the user is shown a table of previous games. These results can be filtered by player name.

![My image](/screenshots/SelectGameScreen.png)

Once the game begins, users will make moves by first selecting the piece which he/she would like to move. If the piece is able to be moved, its legal moves will be highlighted yellow. After making a move, it will be highlighted red so that the opponent is not left wondering what move was made. A full listing of moves and a graphical display of the pieces that have been captured is included in the panel to the right of the game board. There is also a button to save the game to the database so that it can be played at a later time.

![My image](/screenshots/GameInProgress.png)
