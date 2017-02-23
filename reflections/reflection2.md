Reflection 2 - SoftSys, Olin Sp17 - Matt Ruehle


####Sprint reflection:
For the most part, I would contend that sprint 2 went passably for our team. We wound up bogged down in sending/receiving data between our client and our server - in particular, we got a hard-to-track-down error where we would invariably send gibberish and never finish reading. It took quite a while to debug - during which we tried to take apart nearly every aspect of both the server and the client - before we figured out that we weren't creating an "empty" 256-char array, we were merely allocating that much memory but not clearing any existing contents; clearing this roadblock allowed for significant progress and left us optimistic looking into sprint 3.

This roadblock left us more-or-less on track to finish our project: while during the first few days of the sprint, we thought we would easily finish our MVP quickly, the speed bump has still left us with a reasonable path to completing both our base project and potential "stretch goals." 

Since most of this sprint was spent trying to debug what proved to be a fairly specific, small issue, eduScrum did not prove particularly relevant to our process - we lacked worthwhile "actionable items" to assign/work on.



####HFC, ThinkOS exercises:

I'm still not exactly enamored with Head-First C, and have as a result somewhat neglected it (and the associated exercises) over this past sprint, instead pursuing other avenues and online guides. That said--

	**HFC**:
	[exercise 2.5](https://github.com/matthewruehle/ExercisesInC/tree/master/exercises/ex02.5)
	[exercise 3](https://github.com/matthewruehle/ExercisesInC/tree/master/exercises/ex03)
	**ThinkOS**:
	[chapter 2-4](https://github.com/matthewruehle/ExercisesInC/blob/master/reading_questions/thinkos.md)

	(Also, read/worked through a bunch of Little Book of Semaphores, but I don't think there were any specific deliverables for it.)


####Exam question:
  **Q**: It's quicker for a program to use a file that's stored in a contiguous block of memory - and, it has less overhead. Why do most operating systems support - or even automatically control - fragmentaion?

  **A**: Because being able to add files to whatever space is available means that files don't need to constantly be moved around to "make space" whenever new information is written/deleted - saving on the lengthy process of shuffling an entire file system whenever a large file needs to be written/changed.