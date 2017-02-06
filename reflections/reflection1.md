Reflection 1 - SoftSys, Olin Sp17 - Matt Ruehle


####Sprint reflection:
All in all, I think sprint 1 went pretty well for us. We've made significant progress with understanding both C in general, and servers in particular; we've further managed to write our own (rudimentary) servers for call-and-response, work our way through/understand other servers, and put together the basics of a file-transfer server; this leaves us with a clear route to making a web server capable of serving pages to a client.

Beyond that, we've also familiarized ourselves (at least, somewhat) with memory allocation, networking/sockets, and the forking of parent/child processes.

Our team followed, to an extent, the eduScrum processes. Although many of the formalities were left by the wayside, we created and maintained a backlog--and met frequently to work through potentially-confusing code as a group.


####HFC, ThinkOS exercises:
- Didn't do a ton of these, for a couple of reasons:
	- Working on server code instead - the web_server exercise, reading chapter 11, and wading through a bunch of architecture readings/exercises for the project.
	- I _really_ don't like reading Head First C, and have been referring to a number of other sources instead. Something about its format just rubs me the wrong way, so to speak.

So -- 
	**HFC**: 
	[exercise 1](https://github.com/matthewruehle/ExercisesInC/tree/master/exercises/ex01)
	[exercise 2](https://github.com/matthewruehle/ExercisesInC/tree/master/exercises/ex02)
	**ThinkOS**:
	[chapter 1](https://github.com/matthewruehle/ExercisesInC/blob/master/reading_questions/thinkos.md)


####Exam question:
  **Q**: Why does a 32-bit OS only allow for up to 4 gb of physical RAM to be used? Why is this problem not present in 64-bit operating systems? (Extra credit: how much memory would we need before a 128-bit OS would become relevant?)

  **A**: Address spaces! When a program needs to refer to a specific location in memory, it uses the "address" - the index of the memory field. A 32-bit address can only show up to 2^32 locations - in other words, any index above (2^32 - 1) _cannot_ be given an address here. 64-bit operating systems allow for addresses of length 64 - 2^64 locations. This would only run out at around sixteen _billion_ gigabytes - so, we should be good for another ecouple of years.