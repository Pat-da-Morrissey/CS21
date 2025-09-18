/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  readme.txt - Assignment 03 - Quicksort
*/

  In my code, I set my constant for when to call median-of-three when the partition size is greater then 15. I chose this number due to running an experiment that tested different times. In my experiment I 
chose multiple numbers for constants and ran the linux time utility command and recorded it's real time. As test cases I tested several datasets, these datasets were unsorted and sorted prime numbers. Each had
increasing sizes of values, these sizes ranged from: 1000, 10000, 100000, and 1000000 numbers. When I tested different constants I took the average value of the time it took complete 1 dataset and to make it 
more accurate I made the code print into a garbage file instead of the terminal. After I got the data form the datasets I would put them into desmos and have then graph a line of best fit, thankfully desmos is
really good at making a very perscise line, I did this for each constant and I will provide a link to my data below. From my findings I found that median-of-three works best when it's always called 
(mo3MinConst = 0), despite the size however it doesn't always need to be called. Although it has the best/smallest line (times/# of values inserted) I found that constants less then to 100 will run the code 
with up to a 1 second difference when passing in a dataset of a million numbers. While any number within 0 - 100 would have this effiecent output from my testing I found that the constant 15 had the closest 
results compared to when the constant is 0. If I were to do more testing I would pass in datasets that are bigger then 1 million and see if anything changes but do to my limited datasets I still had good data.

Desmos URL for the data: https://www.desmos.com/calculator/fpyqujnxvt
