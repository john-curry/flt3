After learning c++11 and getting a small project (flt1) worked out, I decided to make a full 2D turn based rpg. I ended up spending a considerable amount of time programming the GUI, which was complicated to say the least. In the end I got it to the New Game/ Load Game screen and that was after a considerable amount of effort and time. If you run the program, it will load some of the json asset files from the assets folder and draw the individual components to the screen. Which assetsheet to use is defined when constructing an instance of the state class.

Uses SDL1.6 for graphics, audio, and controls. json is used to make different views that the game could load such ass messages, dialogs and images. It uses a few design patterns. Observer for the event system, visitor for access the idividual views, and state for changing between what would have been the battles and the dialog parts of the game.


