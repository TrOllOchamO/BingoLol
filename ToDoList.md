# To do List

## Simples tasks

- [ ] found a sound effect for the buttons
- [ ] found an other sound effect for the start button
- [ ] maybe add sounds on hover for some elements
- [ ] implement new missions (need good ideas)

## Larger tasks

### Add an overlay
This would be the most impactfull addition to the project, the ability to see the advecement of the grid without needing to alt + tab the game.
We could see the mission who just validate/invalidate in real time and maybe even see a miniaturised version of the grid to see wich line/column is about to be completed.
This will be likely never implemented by myself since it would requiere to me to learn DirectX and this is not something i'm sure i want to do.

### Rewrite every missions and the request system with QT
Since we use QT for the GUI and it can also handle http request and the parsing would be nice if we could get rid of [CURL](https://curl.se/) and [nlohmann/json](https://github.com/nlohmann/json) in the project. It would mean an easier project to set up to participate.
