# Connect

## Description
Terminal Game Based off tic tac toe and connect four. 

User enters # of players and # of bots 
diminsion of grid # of cells to connect inorder to win

## How to download
1. Download a zip 
2. Unzip it 
3. In a terminal window enter command $ make 
4. then to playe enter the command $ ./Play

## Techinical Details

Disign is loosly based of module view controller, The model is the Connect.h class, holds grid information 
and play function which contains game logic. The View is responsible for printing the model information 
in a grid pattern, this also utilizes a function to add ansii color to terminal window( View class could have probably been integrated into Connect class. Controller class has two subclasses, one for gathering input from std in User class. And another which is an AI (bot) class used for selecting a random value from the grid. Although as of now it simply just selects a random number. Might try implementing some machine learning stuff
