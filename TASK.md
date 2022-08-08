# Copyright infringement (Pokémon)

In this assignment, you will design and plan for the implementation of a simple turn-based action game using object-oriented design concepts, tailoring your work for an already existing game design.

We will be using a slimmed-down version of the battle logic used in the Pokémon series of games for this task, to hopefully provide you with some extra familiarity (and to make it more fun).

In the Pokémon series, two players (called Pokémon trainers) can battle using their Pokémon, of which each player has six of in a type of "party".

Each Pokémon has their own statistics and a set of up to four attacks. Attacks can do various things - ranging from dealing simple damage to an enemy, to leeching life, to buffing the user.

You do not have to follow the "real" implementation of the game to the letter. Feel free to simplify or come up with your own damage calculations, or come up with your own moves, or whatever you like as long as it is in the spirit of a turn-based battle system.

## Task

Do your own research on the gameplay of Pokémon, distill the features and gameplay that you deem most important (or that provide the best bang for your buck, considering the time limit) and create a design and possibly also prototype implementation of a battle system.

### Required features

Your design should incorporate the following:

```
Turn-to-turn battling
Various moves that either deal damage or heal damage
Pokémon switching
Detecting a winner
Health points (HP)
```

### Suggested limitations

The following features aren't as important and may distract you from the core of the program, but if you have time, feel free to take a crack at them:

```
Pokémon and attack typing (water-type attacks being more effective vs fire-type Pokémon, and such)
Various moves that temporarily buff the user or debuff the opponent
Base stats for Pokémon
Move categories (Special/Physical)
Move priorities (e.g. Quick Attack)
```

### Strong limitations

You are strongly advised not to implement these features unless you have way too much time on your hands and want a challenge:

```
Items or bag (including held items)
Advanced stats (individual values, effort values, etc)
Levels or experience points (assume all 'mons are equal)
Multi-turn attacks (like Solar Beam) unless you really want to
Move Power Points (limiting the number of times a move can be used)
Weather effects
```

### Technical considerations

This is a very open-ended task, and you are encouraged to really think about the way you would like to structure your classes. You are naturally allowed to code from the get-go if you really want to, but you're strongly recommended to eschew your keyboard in favour of pen and paper or a whiteboard in the beginning. Create a mental map of what you want to implement before you start code.

### Classes

You're free to build whatever kind of application you'd like, but some classes that should probably be present in your design include:

```
A Player class, for each controlling player
A Pokemon class
A Move class for the various moves that can be used
A class to manage the over-all state of the battle (such as keeping track of the active player, and so on)
```

Note that the list above is most definitely not all the classes you could feasibly create.

## Submission

Push your source code (.cpp/.h files) for your class/classes, and any design you might've created as part of working towards your implementation.