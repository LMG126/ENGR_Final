# ENGR_Final

## What does it do?

Running this code will create a game similar to 'Simon Says.<br />
A noise (each light pattern has a different pitch) followed by a sequence of lights is played and the player must do the action that matches the color of the light pattern appearing. Depending on what colors the lights are, a player will press different buttons or make a noise. The lights will slowly increase around the board until the end of your given time is up (when the lights reach the end of the board).<br />
You first choose the difficulty of the game (easy or hard) by choosing if the switch is on the left or the right. After this, you are given a practice round that will run through each light pattern to allow you to learn how to play. Once this is done, the game will randomly choose a light pattern for you to match with the correct action. As you get the colors right you will have less time between the intializing beep and the end of the color (-500 ms). Depending on how the light patterns play, you may reach the end of the levels or the time constraint chosen in easy or hard mode to win.

### KEY:<br />
(holding with cord away from you)<br />
**Switch to Right** = Hard mode<br />
**Switch to Left** = Easy mode<br />
**Green light** = Left button<br />
**Blue light** = Right button<br />
**Orange light** = Make a loud noise<br />

### Scoring?<br />
After the practice round, each light pattern correctly completed is worth 10 points. You win depending on the requirements from your chosen mode or by completing 24 light patterns correctly.
**Hard Mode:** You begin with each light giving you 3000 ms to complete the action. Once your time is at 300 ms or less for any of the light patterns, you win.
**Easy Mode:** YOu begin with each light giving you 5000 ms to complete the action. Once your time is at 900 ms or less for any of the light patterns, you win.

### Rules?
1. Do the corresponding action after the initializing beep and before the lights reach the end of the board/until your time runs out.
2. If you do not do the action before the time runs out, you lose.
