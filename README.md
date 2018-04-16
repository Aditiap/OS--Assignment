# OS--Assignment

**QUESTION**.<br />

Q1. Write a multithreaded program that implements the banker's algorithm. Create n threads that request and release resources
from the bank. The banker will grant the request only if it leaves the system in a safe state. It is important that shared data
be safe from concurrent access. To ensure safe access to shared data, you can use mutex locks..<br />

--------------------------------------------------------------------------------------------------------------------------------


**Instructions**<br />
    1. This assignment is a compulsory CA component.<br />
    2. The assignment is to be done on individual basis (no groups).<br />
    3. The assignment submission mode is Online only. Student has to upload the assignment on or before the last date on UMS only. 
       No submission via e-mail or pen-drive or any media will be accepted.<br />
    4. Non-submission of assignment on UMS till the last date will result in ZERO marks.<br />
    5. The student is supposed to solve the assignment on his/her own. If it is discovered at any stage that       the student has used unfair means like copying from peers or copy pasting the code taken from internet      etc. ZERO marks will be awarded to the student.<br />
    6. The student who shares his assignment with other students (either in same section or different section)     will also get ZERO marks.<br />
    7. If any student is not satisfied with his/her allotted question then he/she can approach me to get the       question changed.In this case he/she will be allotted .<br />
    8.(kindly go through the question before making a change request). But only six students can get their question changed. The decision to change the question will be done on First Come First Serve basis.<br />
       
  ------------------------------------------------------------------------------------------------------------------------------


## Banker's Algorithm Concept 

1.1: There are three major methods for handling deadlock. But actually there are four. Describe these four methods for handling deadlock.<br />

    1)Use a protocol to prevent deadlock, Deadlock Prevention. This ensures that the system will never even       enter a deadlocked state in the first place. (by for example using mutual exclusion)<br />
    2)Allow the system to enter a deadlocked state, but develop a mechanism to detect this and recover from it.   This is called Deadlock Detection <br />
    3)Ignore deadlocks and pretend they will never occur in the system.<br />
    4)Avoiding a deadlock altogether by making the system calculate if any request will leave the system in a     'safe state'. Deadlock Avoidance <br />

1.2: Consider the following snapshot of a system.<br />

Answer the following questions using the banker's algorithm:<br />

a. What is the content of the matrix Need?<br />

Need[i,j] = Max[i,j] - Allocation[i,j]. So starting with resource A:<br />
P0 = 0 - 0 = 0 <br />
P1 = 1 - 1 = 0 <br />
P2 = 2 - 1 = 1 <br />
P3 = 0 - 0 = 0 <br />
P4 = 0 = 0 = 0 <br />


Using this method of calculation we get the following table as a result:<br />

Need
----
P    | 	A |	B |	C |	D <br />
P0   |	0 |	0 |	0 |	0 <br />
P0   | 	0 |	0 |	0 |	0 <br />
P1   |	0 |	7 |	5 |	0 <br />
P2   |	1 |	0 |	0 |	2 <br />
P3   |	0 |	0 |	2 |	0 <br />
P4   |	0 |	6 |	4 |	2 <br />
Total|	1 |	13|	11|	4 <br />

b. Is the system in a safe state?
A system is in a safe state if the amount of resources needed does not exceed the amount of resources available.
           	A 	B 	C 	D
Available 	1 	5 	2 	0

Yes, the system is ** in a safe state**. The amount of resources needed for either Process 3 or Process 0 to run does not exceed the amount of resources available.

c. If a request from process Pi arrives for (0, 4, 2, 0), can the request be granted immediately?
Yes, Pi would be safe to grant resources immediately because 0, 4, 2, 0 does not exceed the available 1, 5, 2, 0 because:
                 	A 	B 	C 	D
Need Pi         	0 	4 	2 	0
Available        	1 	5 	2 	0
Available - Need 	1 	1 	0 	0

The amount of 'needed' resources for Pi does not exceed the amount of available resources.
