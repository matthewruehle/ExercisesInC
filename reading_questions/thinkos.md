## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
	- Interpreted languages often allow dynamic typing, while compiled languages typically only support static types.

2) Name two advantages of static typing over dynamic typing.
	- Static typing is less error-prone, since assigning the wrong type of value will produce a compile-time error.
	- Static typing is more memory-efficient, since variable names and "buffer" space must be stored at runtime, rather than simply allocating a memory block.

3) Give an example of a static semantic error.
	- One example of a static semantic error could be passing a non-int as the index of an array - for example,
	int array[6] = {1,2,3,4,5,6} 
	double location = 3.0
	printf("%d\n", array[location]);

4) What are two reasons you might want to turn off code optimization?
	- Code optimization could, potentially, introduce a bug which would be difficult to locate in the code itself. Optimization further requires more time to compile.

5) When you run `gcc` with `-S`, why might the results look different on different computers?
	- The '-S' flag generates assembly code; assembly code, however, varies from computer to computer/processor to processor (e.g., AMD vs Intel vs ...), since it's essentially instructions to the hsardware.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?
	- The error messages change based on what the error the compiler finds - e.g., not finding a reference vs. searching for a nonexistent variable.

7) What is a segmentation fault?
	- A segfault occurs when a program, while running, tries to write to a place in memory that it can't actually write to.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).
	- For a physical option - the "old" netflix (that is to say, the one that sent people DVDs in the mail) allowed subscribers their choice of media, while maintaining only a limited total collection - akin, at least somewhat, to the library example.
	- "Virtual machines" (e.g. vmware, virtualbox) are additional examples of real-world virtualization: the abstraction of hardware/system resources, such that a guest operating system can act as though it's using a physical computer without allocating physical resources directly to it.

2) What is the difference between a program and a process?
	- A process is a program which is in the act of running - the program's instructions itself, and the state of its memory/data which are currently in use.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?
	- Process abstraction is meant to keep programs from interacting negatively with each other - whether through attempting to read and write to the same memory locations, or through competing directly with one another for access to system resources. This leads to the illusion that all processes have access to the entirety of available/permitted resources, when in fact the physical memory/resources are managed externally.

4) What is the kernel?
	- The kernel is the "layer" of the operating system which spawns processes and threads - the "roots" to a group of trees. It connects physical resources, IO, startup, etc., to applications and other programs.

5) What is a daemon?
	- so too was this light more than the absence of darkness. there was a purity to it, a brilliance before which any mortal flesh seemed but filth. it will wash clean our sins, our gluttonies, our wretched memories. we will be pardoned, though our bodies will not survive the journey.
	- a daemon is a system tool, constantly running in the background, managing OS services (e.g., memory cleaning) so that processes don't have to worry about them individually.

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?
	- 6 bits (assuming we don't care about capitalization or other such nonsense).


2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?
	- 2^32, or a bit above 4 billion.

3) What is the difference between "memory" and "storage" as defined in Think OS?
	- Memory is the data held by a running process, often in RAM; storage is the long-term "reference" like that of a disk drive.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?
	- GiB is "gibibyte" - 2^30 bytes; GB is "gigabyte" - 10^9 bytes. GiB is in base 2, to GB's base 10 - a roughly 7% difference in sizes.

5) How does the virtual memory system help isolate processes from each other?
	- Virtual memory allows for processes to have access to a "continuous" space, without potentially reading/writing data that belongs to other processes.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?
	- Both are positioned so that they could, potentially, expand outwards; putting one at the "top" and one at the "bottom" allows each the most potential room to grow without colliding.

7) What Python data structure would you use to represent a sparse array?
	- My first inclination would be a dictionary, where accessing a non-member just returns the null/zero/default value.

8) What is a context switch?
	- The OS stops a current process, saving its state, so that resources can be spent on another process - then, later, the original process can be picked up and re-set to the saved state, allowing it to "pick up where it left off," as it were.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
	- OK.
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  
	- yep.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  
	- also, yep.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.
	- 0x20, or 32 (bytes, I believe).


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.
	- File systems provide abstractions like file names and locations (e.g., hierarchical directories/folders). Implementations, meanwhile, contend with memory based on blocks - rather than the file size itself in bytes - and don't locate all elements within the same "folder space" (or else, any change at all could require the entire disk be rewritten).

2) What information do you imagine is stored in an `OpenFileTableEntry`?
	- The information on an open file - its memory location, where the program is "in" the file, and any buffer for writing data.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?
	- Buffering: pre-loading information, saving data to write and then writing it all at once, etc.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?
	- Most likely, the file output was buffered (since writing to a file is a much lengthier process, time-wise, than the rest of the program may be); the buffer only gets written once the file is "closed," which in this scenario never occurred.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?
	- Inodes live with other blocks of memory, putting them "at" the data they use; FAT, meanwhile, keeps them all centrally. FAT makes it easier to get a "feel" for the land - say, an index or a table of contents - while inodes makes it easier to reference "in the field." (apologies if this is a terrible analogy, it's just the one that came to mind.)

6) What is overhead?  What is fragmentation?
	- Fragmentation is splitting a large file into many smaller files. It allows a large file to be written into space which was freed after being used before, without having to create a single empty series of blocks to store it. Overhead is the space used by the various tools keeping track of metadata, fragmentation, etc. - "wasted" space, in a sense, that isn't used to keep the actual data.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?
	- Having everything act as a file seems useful for network programming - allowing the methods of writing to a file to be used for socket communication; however, it seems like it would be much easier to accidentally mis-use (e.g., writing to a stream instead of a file) than if the "mechanism" were more divorced from file descriptors.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
