/*
We are Given N number of cabinets and every cabinets has a certain amount of files. We want to go through each and every file in these cabinets and for that we have x number of workers. Distribute the work amongst x workers such that the difference between the number of files that two worker goes through is minimised and the amount that one worker does is maximised.
The constraint is - a worker can go through only cabinets that are adjacent.
Return the maximum amount of work (Work is defined as the amount of files a worker has to go through) a worker is doing in such an arrangement.
For Example :-
Given 9 cabinets each containing 10 20 30 40 50 60 70 80 90 folders and with 3 workers, we can divide the cabinets in 10 20 30 40 50 | 60 70 | 80 90 . So in this case output should be 170, as it is the maximum amount of work done by any worker.

Input format :

Line 1 : N (Number of cabinets)

Line 2 : N integers denoting the number of files in the cabinets respectively (separated by space)

Line 3 : x (No. of workers)

Output format : A single integer, denoting the maximum work any worker is doing such that difference in work between two worker is minimised

*/

