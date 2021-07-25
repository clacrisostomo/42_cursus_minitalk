# 42_cursus_minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

<h3> Journal </h3>

Day 1: I am studying a little about processes and some functions we can use in this project, such as ```signal```, ```sigaddset```, etc. I also prepared my Makefile draft.

Days 2 - 5: I have studied a little more about the functions used in the project and got some tips on bitshifting. I have started sending the messages using ```signal```, but the I have realised it worked on WSL but not on Ubuntu. I asked for a friend's help (hi Tuca) and she made me realise something I didn't quite catch reading the manual: signal may present undefined behaviour (and that was exactly what was happening).

Day 6: Since using ```signal``` was not such a good idea, I chose to dive into ```sigaction``` and oh boy, never had the expression RTFM made so much sense. The manual almost solves everything!

Day 7: After taking a good read of the manuals, I was able to put the code together.